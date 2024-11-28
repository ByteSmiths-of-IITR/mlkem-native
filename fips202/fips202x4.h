// Copyright (c) 2024 The mlkem-native project authors
// SPDX-License-Identifier: Apache-2.0
#ifndef FIPS_202X4_H
#define FIPS_202X4_H

#include <stddef.h>
#include <stdint.h>
#include "fips202.h"
#include "keccakf1600.h"
#include "namespace.h"

#include "cbmc.h"

#define shake128x4_absorb FIPS202_NAMESPACE(shake128x4_absorb)
void shake128x4_absorb(keccakx4_state *state, const uint8_t *in0,
                       const uint8_t *in1, const uint8_t *in2,
                       const uint8_t *in3, size_t inlen);


#define shake256x4_absorb FIPS202_NAMESPACE(shake256x4_absorb)
void shake256x4_absorb(keccakx4_state *state, const uint8_t *in0,
                       const uint8_t *in1, const uint8_t *in2,
                       const uint8_t *in3, size_t inlen)
__contract__(
  requires(memory_no_alias(state, sizeof(keccakx4_state)))
  requires(memory_no_alias(in0, inlen))
  requires(memory_no_alias(in1, inlen))
  requires(memory_no_alias(in2, inlen))
  requires(memory_no_alias(in3, inlen))
  assigns(object_whole(state))
);

#define shake128x4_squeezeblocks FIPS202_NAMESPACE(shake128x4_squeezeblocks)
void shake128x4_squeezeblocks(uint8_t *out0, uint8_t *out1, uint8_t *out2,
                              uint8_t *out3, size_t nblocks,
                              keccakx4_state *state)
__contract__(
  requires(memory_no_alias(state, sizeof(keccakx4_state)))
  requires(memory_no_alias(out0, nblocks * SHAKE128_RATE))
  requires(memory_no_alias(out1, nblocks * SHAKE128_RATE))
  requires(memory_no_alias(out2, nblocks * SHAKE128_RATE))
  requires(memory_no_alias(out3, nblocks * SHAKE128_RATE))
  assigns(memory_slice(out0, nblocks * SHAKE128_RATE),
    memory_slice(out1, nblocks * SHAKE128_RATE),
    memory_slice(out2, nblocks * SHAKE128_RATE),
    memory_slice(out3, nblocks * SHAKE128_RATE),
    object_whole(state))
);

#define shake256x4_squeezeblocks FIPS202_NAMESPACE(shake256x4_squeezeblocks)
void shake256x4_squeezeblocks(uint8_t *out0, uint8_t *out1, uint8_t *out2,
                              uint8_t *out3, size_t nblocks,
                              keccakx4_state *state);

#define shake128x4_ctx_release FIPS202_NAMESPACE(shake128x4_ctx_release)
void shake128x4_ctx_release(keccakx4_state *state);

#define shake256x4_ctx_release FIPS202_NAMESPACE(shake256x4_ctx_release)
void shake256x4_ctx_release(keccakx4_state *state);

#define shake256x4 FIPS202_NAMESPACE(shake256x4)
void shake256x4(uint8_t *out0, uint8_t *out1, uint8_t *out2, uint8_t *out3,
                size_t outlen, uint8_t *in0, uint8_t *in1, uint8_t *in2,
                uint8_t *in3, size_t inlen)
__contract__(
// Refine +prove this spec, e.g. add disjointness constraints?
  requires(readable(in0, inlen))
  requires(readable(in1, inlen))
  requires(readable(in2, inlen))
  requires(readable(in3, inlen))
  requires(writeable(out0, outlen))
  requires(writeable(out1, outlen))
  requires(writeable(out2, outlen))
  requires(writeable(out3, outlen))
  assigns(memory_slice(out0, outlen))
  assigns(memory_slice(out1, outlen))
  assigns(memory_slice(out2, outlen))
  assigns(memory_slice(out3, outlen))
);

#endif
