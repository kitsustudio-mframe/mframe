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
#include "OutputStream.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/System.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::io::OutputStream;

//-----------------------------------------------------------------------------
using mframe::io::CompletionHandler;
using mframe::io::ReadBuffer;
using mframe::lang::System;
using mframe::util::Future;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
OutputStream::OutputStream(void) {
  this->mAttachment = nullptr;
  this->mCompletionHandler = nullptr;
  this->mReadBuffer = nullptr;
  this->mResult = 0;
  this->mHandling = false;
  return;
}

//-----------------------------------------------------------------------------
OutputStream::~OutputStream(void) {
  this->abortWrite();
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::func::Runnable
 */

//-----------------------------------------------------------------------------
void OutputStream::run(void) {
  CompletionHandler<int, void*>* handler = this->mCompletionHandler;
  void* attachment = this->mAttachment;
  int result = this->mResult;

  this->mResult = 0;
  this->mReadBuffer = nullptr;
  this->mHandling = false;

  if (handler)
    handler->completed(result, attachment);

  return;
}

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
bool OutputStream::abortWrite(void) {
  if (!this->writeBusy())
    return false;

  this->execute();
  return true;
}

//-----------------------------------------------------------------------------
bool OutputStream::writeBusy(void) {
  return ((this->mReadBuffer != nullptr) || this->mHandling);
}

//-----------------------------------------------------------------------------
bool OutputStream::write(ReadBuffer& readBuffer, int timeout) {
  Future future = Future();
  if (this->write(readBuffer, future) == false)
    return false;

  future.waitDone(timeout);
  if (future.isBusy())
    this->abortWrite();

  future.waitDone();
  return true;
}

//-----------------------------------------------------------------------------
bool OutputStream::write(ReadBuffer& readBuffer,
                         void* attachment,
                         CompletionHandler<int, void*>* handler) {
  if (this->writeBusy())
    return false;

  this->mCompletionHandler = handler;
  this->mAttachment = attachment;
  this->mResult = 0;

  if (readBuffer.isEmpty())
    this->execute();

  else
    this->mReadBuffer = &readBuffer;

  this->onWriteEvent();
  return true;
}

//-----------------------------------------------------------------------------
bool OutputStream::write(ReadBuffer& readBuffer, Future& future) {
  if (!future.isIdle())
    return false;

  future.setWait();
  bool result = this->write(readBuffer, nullptr, &future);
  if (result == false)
    future.clear();

  return result;
}

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

//-----------------------------------------------------------------------------
void OutputStream::execute(void) {
  if (!this->writeBusy())
    return;

  if (this->mHandling)
    return;

  this->mHandling = true;
  System::execute(*this);
  return;
}

//-----------------------------------------------------------------------------
void OutputStream::onWriteEvent(void) {
  return;
}

/* ****************************************************************************
 * Static Variable
 */

/* ****************************************************************************
 * Static Method
 */

/* ****************************************************************************
 * End of file
 */
