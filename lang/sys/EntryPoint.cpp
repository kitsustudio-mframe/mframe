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
#include "EntryPoint.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::sys::EntryPoint;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
EntryPoint::EntryPoint(void (*setup)(mframe::lang::sys::Thread*), void (*loop)(mframe::lang::sys::Thread*)) {
  this->mLoop = loop;
  this->mSetup = setup;
  return;
}

//-----------------------------------------------------------------------------
EntryPoint::~EntryPoint(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::func::Runnable
 */

//-----------------------------------------------------------------------------
void EntryPoint::run(void) {
  Thread* thread = this->currentThread();
  this->mSetup(thread);

  while (true) {
    this->mLoop(thread);
  }
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