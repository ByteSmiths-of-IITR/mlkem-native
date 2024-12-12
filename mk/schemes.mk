# SPDX-License-Identifier: Apache-2.0
SOURCES += $(wildcard mlkem/*.c) $(wildcard mlkem/debug/*.c)
ifeq ($(OPT),1)
	SOURCES += $(wildcard mlkem/native/aarch64/*.[csS]) $(wildcard mlkem/native/x86_64/*.[csS])
	CPPFLAGS += -DMLKEM_USE_NATIVE
endif

CPPFLAGS += -Imlkem -Imlkem/sys -Imlkem/native -Imlkem/native/aarch64 -Imlkem/native/x86_64
ALL_TESTS = test_mlkem acvp_mlkem bench_mlkem bench_components_mlkem gen_NISTKAT gen_KAT
NON_NIST_TESTS = $(filter-out gen_NISTKAT,$(ALL_TESTS))

MLKEM512_DIR = $(BUILD_DIR)/mlkem512
MLKEM768_DIR = $(BUILD_DIR)/mlkem768
MLKEM1024_DIR = $(BUILD_DIR)/mlkem1024

# build lib<scheme>.a
define BUILD_LIB
$(TMP_DIR)/libtmp_$(1).a: CFLAGS += -static
$(TMP_DIR)/libtmp_$(1).a: $(call MAKE_OBJS,$(BUILD_DIR)/$(1),$(SOURCES))

# NOTE:
# - The order matters, or else the `MLKEM_K` preprocessor won't be properly set
# - Merging multiple .a files with ar is more complex than building a single library directly from all the object files (.o). Hence, all .o files are added as dependencies here.
$(TMP_DIR)/libtmp_mlkem.a: $(TMP_DIR)/libtmp_$(1).a $(call MAKE_OBJS,$(BUILD_DIR)/$(1),$(SOURCES))
endef

$(TMP_DIR)/libtmp_mlkem512.a: CPPFLAGS += -DMLKEM_K=2
$(TMP_DIR)/libtmp_mlkem768.a: CPPFLAGS += -DMLKEM_K=3
$(TMP_DIR)/libtmp_mlkem1024.a: CPPFLAGS += -DMLKEM_K=4

# build libmlkem512.a libmlkem768.a libmlkem1024.a
$(foreach scheme,mlkem512 mlkem768 mlkem1024, \
	$(eval $(call BUILD_LIB,$(scheme))))

# rules for compilation for all tests: mainly linking with mlkem static link library
define ADD_SOURCE
$(BUILD_DIR)/$(1)/bin/$(2)$(shell echo $(1) | tr -d -c 0-9): LDLIBS += -L$(TMP_DIR) -ltmp_$(1)
$(BUILD_DIR)/$(1)/bin/$(2)$(shell echo $(1) | tr -d -c 0-9): $(BUILD_DIR)/$(1)/test/$(2).c.o $(TMP_DIR)/libtmp_$(1).a
endef

$(MLKEM512_DIR)/bin/%: CPPFLAGS += -DMLKEM_K=2
$(MLKEM768_DIR)/bin/%: CPPFLAGS += -DMLKEM_K=3
$(MLKEM1024_DIR)/bin/%: CPPFLAGS += -DMLKEM_K=4

$(foreach scheme,mlkem512 mlkem768 mlkem1024, \
	$(foreach test,$(ALL_TESTS), \
		$(eval $(call ADD_SOURCE,$(scheme),$(test))) \
	) \
)

# nistkat tests require special RNG
$(MLKEM512_DIR)/bin/gen_NISTKAT512: CPPFLAGS += -Itest/nistrng
$(MLKEM512_DIR)/bin/gen_NISTKAT512: $(call MAKE_OBJS, $(MLKEM512_DIR), $(wildcard test/nistrng/*.c))
$(MLKEM768_DIR)/bin/gen_NISTKAT768: CPPFLAGS += -Itest/nistrng
$(MLKEM768_DIR)/bin/gen_NISTKAT768: $(call MAKE_OBJS, $(MLKEM768_DIR), $(wildcard test/nistrng/*.c))
$(MLKEM1024_DIR)/bin/gen_NISTKAT1024: CPPFLAGS += -Itest/nistrng
$(MLKEM1024_DIR)/bin/gen_NISTKAT1024: $(call MAKE_OBJS, $(MLKEM1024_DIR), $(wildcard test/nistrng/*.c))

# All other tests use test-only RNG
$(NON_NIST_TESTS:%=$(MLKEM512_DIR)/bin/%512): $(call MAKE_OBJS, $(MLKEM512_DIR), $(wildcard test/notrandombytes/*.c))
$(NON_NIST_TESTS:%=$(MLKEM768_DIR)/bin/%768): $(call MAKE_OBJS, $(MLKEM768_DIR), $(wildcard test/notrandombytes/*.c))
$(NON_NIST_TESTS:%=$(MLKEM1024_DIR)/bin/%1024): $(call MAKE_OBJS, $(MLKEM1024_DIR), $(wildcard test/notrandombytes/*.c))
