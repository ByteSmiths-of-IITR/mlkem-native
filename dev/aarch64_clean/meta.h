/*
 * Copyright (c) 2024-2025 The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MLKEM_NATIVE_DEV_AARCH64_CLEAN_META_H
#define MLKEM_NATIVE_DEV_AARCH64_CLEAN_META_H
/* ML-KEM arithmetic native profile for clean assembly */

#ifdef MLKEM_NATIVE_ARITH_PROFILE_H
#error Only one MLKEM_ARITH assembly profile can be defined -- did you include multiple profiles?
#else
#define MLKEM_NATIVE_ARITH_PROFILE_H

/* Identifier for this backend so that source and assembly files
 * in the build can be appropriately guarded. */
#define MLKEM_NATIVE_ARITH_BACKEND_AARCH64_CLEAN

#define MLKEM_NATIVE_ARITH_BACKEND_NAME AARCH64_CLEAN

/* Filename of the C backend implementation.
 * This is not inlined here because this header is included in assembly
 * files as well. */
#define MLKEM_NATIVE_ARITH_BACKEND_IMPL "native/aarch64/src/clean_impl.h"

#endif /* MLKEM_NATIVE_ARITH_PROFILE_H */

#endif /* MLKEM_NATIVE_DEV_AARCH64_CLEAN_META_H */
