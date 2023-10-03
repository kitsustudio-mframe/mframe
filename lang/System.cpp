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
#include "mframe/lang/sys/ErrorCode.h"
#include "mframe/lang/sys/Kernel.h"
#include "mframe/lang/sys/Svchost.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  static mframe::lang::sys::Kernel* mKernel = nullptr;
  static mframe::lang::sys::HardwareInfo* mHardwareInfo = nullptr;
  static mframe::lang::sys::Allocator* mAllocator = nullptr;
  static mframe::lang::sys::Svchost* mSvchost = nullptr;
}  // namespace mframe::lang

/* ****************************************************************************
 * Extern
 */

/* ****************************************************************************
 * Using
 */
using mframe::lang::System;

//-----------------------------------------------------------------------------
using mframe::io::PrintBuffer;
using mframe::lang::sys::ErrorCode;
using mframe::lang::sys::Kernel;
using mframe::lang::sys::Svchost;

/* ****************************************************************************
 * Global Operator
 */
//-----------------------------------------------------------------------------
void* operator new(size_t n) {
  if (mframe::lang::mAllocator)
    return mframe::lang::mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-----------------------------------------------------------------------------
void* operator new[](size_t n) {
  if (mframe::lang::mAllocator)
    return mframe::lang::mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-----------------------------------------------------------------------------
void operator delete(void* p) {
  if (mframe::lang::mAllocator)
    mframe::lang::mAllocator->free(p);

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
  mKernel->reboot();
  return;
}

//-----------------------------------------------------------------------------
void System::setup(mframe::lang::sys::SystemConfig& systemConfig) {
  if (mSvchost)
    return;

  mKernel = systemConfig.system.kernel;
  mAllocator = systemConfig.system.allocator;
  mHardwareInfo = systemConfig.system.hardwareInfo;

  if (mKernel->initialize() == false)
    System::error("SYSTEM", mframe::lang::sys::ErrorCode::SYSTEM_ERROR);

  mSvchost = new Svchost(systemConfig);
  return;
}

//-----------------------------------------------------------------------------
void System::start(mframe::lang::func::Runnable& task, int stackSize) {
  if (mSvchost->start(task, stackSize))
    mKernel->start();

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
  if (mHardwareInfo)
    return mHardwareInfo->systemClock();

  else
    return -1;
}

//-----------------------------------------------------------------------------
void System::execute(mframe::lang::func::Runnable& runnable) {
  if (mSvchost->execute(runnable))
    return;

  runnable.run();
  return;
}

//-----------------------------------------------------------------------------
mframe::lang::sys::Thread& System::allocThread(mframe::lang::func::Runnable& runnable, int stackSize) {
  mframe::lang::sys::Thread* result = mKernel->allocThread(runnable, stackSize);

  if (result == nullptr)
    System::error("SYSTEM", mframe::lang::sys::ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-----------------------------------------------------------------------------
mframe::lang::sys::Thread& System::allocThread(mframe::lang::func::Runnable& runnable, mframe::lang::Data& stackMemory) {
  mframe::lang::sys::Thread* result = mKernel->allocThread(runnable, stackMemory);

  if (result == nullptr)
    System::error("SYSTEM", mframe::lang::sys::ErrorCode::SYSTEM_ERROR);

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
mframe::lang::sys::Thread* System::currentThread(void) {
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

//-----------------------------------------------------------------------------
mframe::lang::sys::Allocator* System::getAllocator(void) {
  return mAllocator;
}

//-----------------------------------------------------------------------------
mframe::lang::sys::SystemControl& System::getControl(void) {
  return *mSvchost;
}

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

/* ****************************************************************************
 * End of file
 */
