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
#include "Bytes.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::numb::Bytes;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
Bytes::Bytes(void) {
  return;
}

//-----------------------------------------------------------------------------
Bytes::~Bytes(void) {
  return;
}

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
char Bytes::valueOf(const char* str) {
  return static_cast<char>(atoi(str));
}

/* ****************************************************************************
 * End of file
 */
