/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */
#include <stdlib.h>

//-----------------------------------------------------------------------------
#include "DefaultAllocator.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::sys::DefaultAllocator;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
DefaultAllocator::DefaultAllocator(void) {
  return;
}

//-----------------------------------------------------------------------------
DefaultAllocator::~DefaultAllocator(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> mframe::sys::Allocator
 */

//-----------------------------------------------------------------------------
void* DefaultAllocator::alloc(int size) {
  return ::malloc(static_cast<uint32_t>(size));
}

//-----------------------------------------------------------------------------
bool DefaultAllocator::free(void* ptr) {
  ::free(ptr);
  return true;
}

//-----------------------------------------------------------------------------
bool DefaultAllocator::free(void* ptr, int size) {
  ::free(ptr);
  return true;
}

//-----------------------------------------------------------------------------
void* DefaultAllocator::allocAlignment32(int size) {
  uint32_t sz = static_cast<uint32_t>(size);
  if (sz & 0x00000003U)
    sz = ((sz + 0x00000003U) & ~0x00000003U);

  return malloc(sz);
}

//-----------------------------------------------------------------------------
void* DefaultAllocator::allocAlignment64(int size) {
  uint32_t sz = static_cast<uint32_t>(size);
  if (sz & 0x00000007U)
    sz = ((sz + 0x00000007U) & ~0x00000007U);

  return ::malloc(sz);
}

//-----------------------------------------------------------------------------
int DefaultAllocator::getFree(void) {
  return 0;
}

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

/* ****************************************************************************
 * End of file
 */
