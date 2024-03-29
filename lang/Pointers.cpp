/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */
#include <string.h>

//-----------------------------------------------------------------------------
#include "Pointers.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::Pointers;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * Static Variable
 */

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
mframe::lang::Pointer Pointers::nullPointer(void) {
  return mframe::lang::Pointer();
}

//-----------------------------------------------------------------------------
void Pointers::copy(void* destination, const void* source, int length) {
  memcpy(destination, source, static_cast<size_t>(length));
}

//-----------------------------------------------------------------------------
void Pointers::move(void* destination, const void* source, int length) {
  memmove(destination, source, static_cast<size_t>(length));
}

//-----------------------------------------------------------------------------
int Pointers::compare(const void* src1, const void* src2, int length) {
  return memcmp(src1, src2, static_cast<size_t>(length));
}

//-----------------------------------------------------------------------------
void Pointers::wipe(void* src, int value, int length) {
  memset(src, value, static_cast<size_t>(length));
}

//-----------------------------------------------------------------------------
void Pointers::wipe(void* src, int length) {
  Pointers::wipe(src, 0x00, length);
}

/* ****************************************************************************
 * End of file
 */
