/*
 * Copyright (c) 2024 The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * WARNING: This file is auto-generated from scripts/autogen
 *          Do not modify it directly.
 */

#include "common.h"

#if defined(MLKEM_NATIVE_ARITH_BACKEND_X86_64_DEFAULT)

#include <stdint.h>
#include "arith_native_x86_64.h"

/*
 * Lookup table used by rejection sampling of the public matrix.
 * See autogen for details.
 */
ALIGN const uint8_t rej_uniform_table[256][8] = {
    {-1, -1, -1, -1, -1, -1, -1, -1}, {0, -1, -1, -1, -1, -1, -1, -1},
    {2, -1, -1, -1, -1, -1, -1, -1},  {0, 2, -1, -1, -1, -1, -1, -1},
    {4, -1, -1, -1, -1, -1, -1, -1},  {0, 4, -1, -1, -1, -1, -1, -1},
    {2, 4, -1, -1, -1, -1, -1, -1},   {0, 2, 4, -1, -1, -1, -1, -1},
    {6, -1, -1, -1, -1, -1, -1, -1},  {0, 6, -1, -1, -1, -1, -1, -1},
    {2, 6, -1, -1, -1, -1, -1, -1},   {0, 2, 6, -1, -1, -1, -1, -1},
    {4, 6, -1, -1, -1, -1, -1, -1},   {0, 4, 6, -1, -1, -1, -1, -1},
    {2, 4, 6, -1, -1, -1, -1, -1},    {0, 2, 4, 6, -1, -1, -1, -1},
    {8, -1, -1, -1, -1, -1, -1, -1},  {0, 8, -1, -1, -1, -1, -1, -1},
    {2, 8, -1, -1, -1, -1, -1, -1},   {0, 2, 8, -1, -1, -1, -1, -1},
    {4, 8, -1, -1, -1, -1, -1, -1},   {0, 4, 8, -1, -1, -1, -1, -1},
    {2, 4, 8, -1, -1, -1, -1, -1},    {0, 2, 4, 8, -1, -1, -1, -1},
    {6, 8, -1, -1, -1, -1, -1, -1},   {0, 6, 8, -1, -1, -1, -1, -1},
    {2, 6, 8, -1, -1, -1, -1, -1},    {0, 2, 6, 8, -1, -1, -1, -1},
    {4, 6, 8, -1, -1, -1, -1, -1},    {0, 4, 6, 8, -1, -1, -1, -1},
    {2, 4, 6, 8, -1, -1, -1, -1},     {0, 2, 4, 6, 8, -1, -1, -1},
    {10, -1, -1, -1, -1, -1, -1, -1}, {0, 10, -1, -1, -1, -1, -1, -1},
    {2, 10, -1, -1, -1, -1, -1, -1},  {0, 2, 10, -1, -1, -1, -1, -1},
    {4, 10, -1, -1, -1, -1, -1, -1},  {0, 4, 10, -1, -1, -1, -1, -1},
    {2, 4, 10, -1, -1, -1, -1, -1},   {0, 2, 4, 10, -1, -1, -1, -1},
    {6, 10, -1, -1, -1, -1, -1, -1},  {0, 6, 10, -1, -1, -1, -1, -1},
    {2, 6, 10, -1, -1, -1, -1, -1},   {0, 2, 6, 10, -1, -1, -1, -1},
    {4, 6, 10, -1, -1, -1, -1, -1},   {0, 4, 6, 10, -1, -1, -1, -1},
    {2, 4, 6, 10, -1, -1, -1, -1},    {0, 2, 4, 6, 10, -1, -1, -1},
    {8, 10, -1, -1, -1, -1, -1, -1},  {0, 8, 10, -1, -1, -1, -1, -1},
    {2, 8, 10, -1, -1, -1, -1, -1},   {0, 2, 8, 10, -1, -1, -1, -1},
    {4, 8, 10, -1, -1, -1, -1, -1},   {0, 4, 8, 10, -1, -1, -1, -1},
    {2, 4, 8, 10, -1, -1, -1, -1},    {0, 2, 4, 8, 10, -1, -1, -1},
    {6, 8, 10, -1, -1, -1, -1, -1},   {0, 6, 8, 10, -1, -1, -1, -1},
    {2, 6, 8, 10, -1, -1, -1, -1},    {0, 2, 6, 8, 10, -1, -1, -1},
    {4, 6, 8, 10, -1, -1, -1, -1},    {0, 4, 6, 8, 10, -1, -1, -1},
    {2, 4, 6, 8, 10, -1, -1, -1},     {0, 2, 4, 6, 8, 10, -1, -1},
    {12, -1, -1, -1, -1, -1, -1, -1}, {0, 12, -1, -1, -1, -1, -1, -1},
    {2, 12, -1, -1, -1, -1, -1, -1},  {0, 2, 12, -1, -1, -1, -1, -1},
    {4, 12, -1, -1, -1, -1, -1, -1},  {0, 4, 12, -1, -1, -1, -1, -1},
    {2, 4, 12, -1, -1, -1, -1, -1},   {0, 2, 4, 12, -1, -1, -1, -1},
    {6, 12, -1, -1, -1, -1, -1, -1},  {0, 6, 12, -1, -1, -1, -1, -1},
    {2, 6, 12, -1, -1, -1, -1, -1},   {0, 2, 6, 12, -1, -1, -1, -1},
    {4, 6, 12, -1, -1, -1, -1, -1},   {0, 4, 6, 12, -1, -1, -1, -1},
    {2, 4, 6, 12, -1, -1, -1, -1},    {0, 2, 4, 6, 12, -1, -1, -1},
    {8, 12, -1, -1, -1, -1, -1, -1},  {0, 8, 12, -1, -1, -1, -1, -1},
    {2, 8, 12, -1, -1, -1, -1, -1},   {0, 2, 8, 12, -1, -1, -1, -1},
    {4, 8, 12, -1, -1, -1, -1, -1},   {0, 4, 8, 12, -1, -1, -1, -1},
    {2, 4, 8, 12, -1, -1, -1, -1},    {0, 2, 4, 8, 12, -1, -1, -1},
    {6, 8, 12, -1, -1, -1, -1, -1},   {0, 6, 8, 12, -1, -1, -1, -1},
    {2, 6, 8, 12, -1, -1, -1, -1},    {0, 2, 6, 8, 12, -1, -1, -1},
    {4, 6, 8, 12, -1, -1, -1, -1},    {0, 4, 6, 8, 12, -1, -1, -1},
    {2, 4, 6, 8, 12, -1, -1, -1},     {0, 2, 4, 6, 8, 12, -1, -1},
    {10, 12, -1, -1, -1, -1, -1, -1}, {0, 10, 12, -1, -1, -1, -1, -1},
    {2, 10, 12, -1, -1, -1, -1, -1},  {0, 2, 10, 12, -1, -1, -1, -1},
    {4, 10, 12, -1, -1, -1, -1, -1},  {0, 4, 10, 12, -1, -1, -1, -1},
    {2, 4, 10, 12, -1, -1, -1, -1},   {0, 2, 4, 10, 12, -1, -1, -1},
    {6, 10, 12, -1, -1, -1, -1, -1},  {0, 6, 10, 12, -1, -1, -1, -1},
    {2, 6, 10, 12, -1, -1, -1, -1},   {0, 2, 6, 10, 12, -1, -1, -1},
    {4, 6, 10, 12, -1, -1, -1, -1},   {0, 4, 6, 10, 12, -1, -1, -1},
    {2, 4, 6, 10, 12, -1, -1, -1},    {0, 2, 4, 6, 10, 12, -1, -1},
    {8, 10, 12, -1, -1, -1, -1, -1},  {0, 8, 10, 12, -1, -1, -1, -1},
    {2, 8, 10, 12, -1, -1, -1, -1},   {0, 2, 8, 10, 12, -1, -1, -1},
    {4, 8, 10, 12, -1, -1, -1, -1},   {0, 4, 8, 10, 12, -1, -1, -1},
    {2, 4, 8, 10, 12, -1, -1, -1},    {0, 2, 4, 8, 10, 12, -1, -1},
    {6, 8, 10, 12, -1, -1, -1, -1},   {0, 6, 8, 10, 12, -1, -1, -1},
    {2, 6, 8, 10, 12, -1, -1, -1},    {0, 2, 6, 8, 10, 12, -1, -1},
    {4, 6, 8, 10, 12, -1, -1, -1},    {0, 4, 6, 8, 10, 12, -1, -1},
    {2, 4, 6, 8, 10, 12, -1, -1},     {0, 2, 4, 6, 8, 10, 12, -1},
    {14, -1, -1, -1, -1, -1, -1, -1}, {0, 14, -1, -1, -1, -1, -1, -1},
    {2, 14, -1, -1, -1, -1, -1, -1},  {0, 2, 14, -1, -1, -1, -1, -1},
    {4, 14, -1, -1, -1, -1, -1, -1},  {0, 4, 14, -1, -1, -1, -1, -1},
    {2, 4, 14, -1, -1, -1, -1, -1},   {0, 2, 4, 14, -1, -1, -1, -1},
    {6, 14, -1, -1, -1, -1, -1, -1},  {0, 6, 14, -1, -1, -1, -1, -1},
    {2, 6, 14, -1, -1, -1, -1, -1},   {0, 2, 6, 14, -1, -1, -1, -1},
    {4, 6, 14, -1, -1, -1, -1, -1},   {0, 4, 6, 14, -1, -1, -1, -1},
    {2, 4, 6, 14, -1, -1, -1, -1},    {0, 2, 4, 6, 14, -1, -1, -1},
    {8, 14, -1, -1, -1, -1, -1, -1},  {0, 8, 14, -1, -1, -1, -1, -1},
    {2, 8, 14, -1, -1, -1, -1, -1},   {0, 2, 8, 14, -1, -1, -1, -1},
    {4, 8, 14, -1, -1, -1, -1, -1},   {0, 4, 8, 14, -1, -1, -1, -1},
    {2, 4, 8, 14, -1, -1, -1, -1},    {0, 2, 4, 8, 14, -1, -1, -1},
    {6, 8, 14, -1, -1, -1, -1, -1},   {0, 6, 8, 14, -1, -1, -1, -1},
    {2, 6, 8, 14, -1, -1, -1, -1},    {0, 2, 6, 8, 14, -1, -1, -1},
    {4, 6, 8, 14, -1, -1, -1, -1},    {0, 4, 6, 8, 14, -1, -1, -1},
    {2, 4, 6, 8, 14, -1, -1, -1},     {0, 2, 4, 6, 8, 14, -1, -1},
    {10, 14, -1, -1, -1, -1, -1, -1}, {0, 10, 14, -1, -1, -1, -1, -1},
    {2, 10, 14, -1, -1, -1, -1, -1},  {0, 2, 10, 14, -1, -1, -1, -1},
    {4, 10, 14, -1, -1, -1, -1, -1},  {0, 4, 10, 14, -1, -1, -1, -1},
    {2, 4, 10, 14, -1, -1, -1, -1},   {0, 2, 4, 10, 14, -1, -1, -1},
    {6, 10, 14, -1, -1, -1, -1, -1},  {0, 6, 10, 14, -1, -1, -1, -1},
    {2, 6, 10, 14, -1, -1, -1, -1},   {0, 2, 6, 10, 14, -1, -1, -1},
    {4, 6, 10, 14, -1, -1, -1, -1},   {0, 4, 6, 10, 14, -1, -1, -1},
    {2, 4, 6, 10, 14, -1, -1, -1},    {0, 2, 4, 6, 10, 14, -1, -1},
    {8, 10, 14, -1, -1, -1, -1, -1},  {0, 8, 10, 14, -1, -1, -1, -1},
    {2, 8, 10, 14, -1, -1, -1, -1},   {0, 2, 8, 10, 14, -1, -1, -1},
    {4, 8, 10, 14, -1, -1, -1, -1},   {0, 4, 8, 10, 14, -1, -1, -1},
    {2, 4, 8, 10, 14, -1, -1, -1},    {0, 2, 4, 8, 10, 14, -1, -1},
    {6, 8, 10, 14, -1, -1, -1, -1},   {0, 6, 8, 10, 14, -1, -1, -1},
    {2, 6, 8, 10, 14, -1, -1, -1},    {0, 2, 6, 8, 10, 14, -1, -1},
    {4, 6, 8, 10, 14, -1, -1, -1},    {0, 4, 6, 8, 10, 14, -1, -1},
    {2, 4, 6, 8, 10, 14, -1, -1},     {0, 2, 4, 6, 8, 10, 14, -1},
    {12, 14, -1, -1, -1, -1, -1, -1}, {0, 12, 14, -1, -1, -1, -1, -1},
    {2, 12, 14, -1, -1, -1, -1, -1},  {0, 2, 12, 14, -1, -1, -1, -1},
    {4, 12, 14, -1, -1, -1, -1, -1},  {0, 4, 12, 14, -1, -1, -1, -1},
    {2, 4, 12, 14, -1, -1, -1, -1},   {0, 2, 4, 12, 14, -1, -1, -1},
    {6, 12, 14, -1, -1, -1, -1, -1},  {0, 6, 12, 14, -1, -1, -1, -1},
    {2, 6, 12, 14, -1, -1, -1, -1},   {0, 2, 6, 12, 14, -1, -1, -1},
    {4, 6, 12, 14, -1, -1, -1, -1},   {0, 4, 6, 12, 14, -1, -1, -1},
    {2, 4, 6, 12, 14, -1, -1, -1},    {0, 2, 4, 6, 12, 14, -1, -1},
    {8, 12, 14, -1, -1, -1, -1, -1},  {0, 8, 12, 14, -1, -1, -1, -1},
    {2, 8, 12, 14, -1, -1, -1, -1},   {0, 2, 8, 12, 14, -1, -1, -1},
    {4, 8, 12, 14, -1, -1, -1, -1},   {0, 4, 8, 12, 14, -1, -1, -1},
    {2, 4, 8, 12, 14, -1, -1, -1},    {0, 2, 4, 8, 12, 14, -1, -1},
    {6, 8, 12, 14, -1, -1, -1, -1},   {0, 6, 8, 12, 14, -1, -1, -1},
    {2, 6, 8, 12, 14, -1, -1, -1},    {0, 2, 6, 8, 12, 14, -1, -1},
    {4, 6, 8, 12, 14, -1, -1, -1},    {0, 4, 6, 8, 12, 14, -1, -1},
    {2, 4, 6, 8, 12, 14, -1, -1},     {0, 2, 4, 6, 8, 12, 14, -1},
    {10, 12, 14, -1, -1, -1, -1, -1}, {0, 10, 12, 14, -1, -1, -1, -1},
    {2, 10, 12, 14, -1, -1, -1, -1},  {0, 2, 10, 12, 14, -1, -1, -1},
    {4, 10, 12, 14, -1, -1, -1, -1},  {0, 4, 10, 12, 14, -1, -1, -1},
    {2, 4, 10, 12, 14, -1, -1, -1},   {0, 2, 4, 10, 12, 14, -1, -1},
    {6, 10, 12, 14, -1, -1, -1, -1},  {0, 6, 10, 12, 14, -1, -1, -1},
    {2, 6, 10, 12, 14, -1, -1, -1},   {0, 2, 6, 10, 12, 14, -1, -1},
    {4, 6, 10, 12, 14, -1, -1, -1},   {0, 4, 6, 10, 12, 14, -1, -1},
    {2, 4, 6, 10, 12, 14, -1, -1},    {0, 2, 4, 6, 10, 12, 14, -1},
    {8, 10, 12, 14, -1, -1, -1, -1},  {0, 8, 10, 12, 14, -1, -1, -1},
    {2, 8, 10, 12, 14, -1, -1, -1},   {0, 2, 8, 10, 12, 14, -1, -1},
    {4, 8, 10, 12, 14, -1, -1, -1},   {0, 4, 8, 10, 12, 14, -1, -1},
    {2, 4, 8, 10, 12, 14, -1, -1},    {0, 2, 4, 8, 10, 12, 14, -1},
    {6, 8, 10, 12, 14, -1, -1, -1},   {0, 6, 8, 10, 12, 14, -1, -1},
    {2, 6, 8, 10, 12, 14, -1, -1},    {0, 2, 6, 8, 10, 12, 14, -1},
    {4, 6, 8, 10, 12, 14, -1, -1},    {0, 4, 6, 8, 10, 12, 14, -1},
    {2, 4, 6, 8, 10, 12, 14, -1},     {0, 2, 4, 6, 8, 10, 12, 14},
};

#else

/* Dummy declaration for compilers disliking empty compilation units */
#define empty_cu_avx2_rej_uniform_table \
  MLKEM_NAMESPACE(empty_cu_avx2_rej_uniform_table)
int empty_cu_avx2_rej_uniform_table;
#endif
