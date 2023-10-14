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
#include "RunnableEntity.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::func::RunnableEntity;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
RunnableEntity::RunnableEntity(void) : RunnableEntity(nullptr) {
  return;
}

//-----------------------------------------------------------------------------
RunnableEntity::RunnableEntity(mframe::func::Runnable& runnable) : mRunnableEvent(nullptr) {
  this->mRunnable = &runnable;
  return;
}

//-----------------------------------------------------------------------------
RunnableEntity::RunnableEntity(void (*function)(void)) : mRunnableEvent(function) {
  this->mRunnable = &this->mRunnableEvent;
  return;
}

//-----------------------------------------------------------------------------
RunnableEntity::RunnableEntity(const RunnableEntity& source) : mRunnableEvent(source.mRunnableEvent) {
  this->mRunnable = source.mRunnable;

  if (source.mRunnable == &source.mRunnableEvent) {
    RunnableEntity::mRunnable = &(RunnableEntity::mRunnableEvent);
  }

  return;
}

//-----------------------------------------------------------------------------
RunnableEntity::~RunnableEntity(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::func::Runnable
 */

//-----------------------------------------------------------------------------
void RunnableEntity::run(void) {
  this->mRunnable->run();
  return;
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
