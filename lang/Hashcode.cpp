/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "Hashcode.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::Hashcode;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
Hashcode::Hashcode(mframe::lang::Interface& interface) {
  this->mHahscode = interface.getObject().hashcode();
  return;
}

//-----------------------------------------------------------------------------
Hashcode::Hashcode(int hashcode) {
  this->mHahscode = hashcode;
  return;
}

//-----------------------------------------------------------------------------
Hashcode::~Hashcode(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::Object
 */
//-----------------------------------------------------------------------------
int Hashcode::hashcode(void) const {
  return this->mHahscode;
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