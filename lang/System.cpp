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
#include "System.h"

//-----------------------------------------------------------------------------
#include "mframe/io/PrintBuffer.h"
#include "mframe/sys/ErrorCode.h"
#include "mframe/sys/Kernel.h"
#include "mframe/sys/Svchost.h"

/* ****************************************************************************
 * Namespace
 */

/* ****************************************************************************
 * Extern
 */

/* ****************************************************************************
 * Using
 */
using mframe::lang::System;

//-----------------------------------------------------------------------------
using mframe::io::PrintBuffer;
using mframe::lang::Data;
using mframe::func::Runnable;
using mframe::sys::Allocator;
using mframe::sys::ErrorCode;
using mframe::sys::HardwareInfo;
using mframe::sys::Kernel;
using mframe::sys::Svchost;
using mframe::sys::Thread;
/* ****************************************************************************
 * Global Operator
 */
//-----------------------------------------------------------------------------
void* operator new(size_t n) {
  if (System::mAllocator)
    return System::mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-----------------------------------------------------------------------------
void* operator new[](size_t n) {
  if (System::mAllocator)
    return System::mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-----------------------------------------------------------------------------
void operator delete(void* p) {
  if (System::mAllocator)
    System::mAllocator->free(p);

  else
    free(p);
}

/* ****************************************************************************
 * Static Variable
 */

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
System::System(void) {
  return;
}

//-----------------------------------------------------------------------------
System::~System(void) {
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
mframe::sys::Allocator* System::mAllocator = nullptr;
mframe::sys::Kernel* System::mKernel = nullptr;
mframe::sys::HardwareInfo* System::mHardwareInfo = nullptr;
Svchost* System::mSvchost = nullptr;

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
PrintBuffer& System::out(void) {
  return mSvchost->mPrintBuffer;
}

//-----------------------------------------------------------------------------
mframe::io::ReadBuffer& System::in(void) {
  return mSvchost->mRingBuffer;
}

//-----------------------------------------------------------------------------
void System::reboot(void) {
  System::mKernel->reboot();
  return;
}

//-----------------------------------------------------------------------------
void System::setup(mframe::sys::SystemConfig& systemConfig) {
  if (mSvchost)
    return;

  if (System::mKernel->initialize() == false)
    System::error("SYSTEM", mframe::sys::ErrorCode::SYSTEM_ERROR);

  mSvchost = new Svchost(systemConfig);
  return;
}

//-----------------------------------------------------------------------------
void System::start(Runnable& task, int stackSize) {
  if (mSvchost->start(task, stackSize))
    System::mKernel->start();

  return;
}

//-----------------------------------------------------------------------------
void System::error(const void* address, ErrorCode code) {
  /*
  bool result = false;
  if(System::mSystemRegister->mErrorCodeHandler){
    result = System::mSystemRegister->mErrorCodeHandler(address, code);
  }

  if(result)
    return;
  */
  while (1)
    ;
}

//-----------------------------------------------------------------------------
void System::throwError(const char* message, const char* path, ErrorCode code) {
  while (1)
    ;
}

//-----------------------------------------------------------------------------
int System::getCoreClock(void) {
  if (System::mHardwareInfo)
    return System::mHardwareInfo->systemClock();

  else
    return -1;
}

//-----------------------------------------------------------------------------
void System::execute(Runnable& runnable) {
  if (mSvchost->execute(runnable))
    return;

  runnable.run();
  return;
}

//-----------------------------------------------------------------------------
Thread& System::allocThread(Runnable& runnable, int stackSize) {
  Thread* result = System::mKernel->allocThread(runnable, stackSize);

  if (result == nullptr)
    System::error("SYSTEM", ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-----------------------------------------------------------------------------
Thread& System::allocThread(Runnable& runnable, Data& stackMemory) {
  Thread* result = System::mKernel->allocThread(runnable, stackMemory);

  if (result == nullptr)
    System::error("SYSTEM", ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-----------------------------------------------------------------------------
void System::lowerDelay(uint32_t times) {
#pragma clang optimize off
  while (times) {
    --times;
  }
#pragma clang optimize on
}

//-----------------------------------------------------------------------------
bool System::delay(int milliseconds) {
  return mKernel->systemDelay(static_cast<uint32_t>(milliseconds));
}

//-----------------------------------------------------------------------------
void System::wait(void) {
  System::wait(0);
}

//-----------------------------------------------------------------------------
bool System::wait(int timeout) {
  return mKernel->systemWait(static_cast<uint32_t>(timeout));
}

//-----------------------------------------------------------------------------
bool System::yield(void) {
  return mKernel->systemYield();
}

//-----------------------------------------------------------------------------
Thread* System::currentThread(void) {
  return mKernel->getCurrentThread();
}

//-----------------------------------------------------------------------------
int System::lock(void) {
  return mKernel->systemLock();
}

//-----------------------------------------------------------------------------
int System::unlock(void) {
  return mKernel->systemUnlock();
}

/* ****************************************************************************
 * End of file
 */
