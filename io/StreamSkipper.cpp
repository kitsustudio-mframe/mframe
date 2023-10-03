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
#include "StreamSkipper.h"

//-----------------------------------------------------------------------------
#include "mframe/io/ReadBuffer.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */
using mframe::io::StreamSkipper;

//-----------------------------------------------------------------------------
using mframe::io::ReadBuffer;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
StreamSkipper::StreamSkipper(void) {
  this->mPosition = 0;
  this->mCapacity = 0;
  return;
}

//-----------------------------------------------------------------------------
StreamSkipper::~StreamSkipper(void) {
  this->mPosition = 0;
  this->mCapacity = 0;
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::InputBuffer
 */

//-----------------------------------------------------------------------------
int StreamSkipper::putByte(const char result) {
  if (this->isFull())
    return -1;

  ++this->mPosition;
  return this->remaining();
}

//-----------------------------------------------------------------------------
int StreamSkipper::put(ReadBuffer& readBuffer) {
  return this->put(readBuffer, readBuffer.avariable());
}

//-----------------------------------------------------------------------------
int StreamSkipper::put(ReadBuffer& readBuffer, int length) {
  if (length <= 0)
    return 0;

  int max = this->remaining();
  if (length > max)
    length = max;

  int result = readBuffer.skip(length);
  this->mPosition += result;
  return result;
}

//-----------------------------------------------------------------------------
int StreamSkipper::put(const void* buffer, int length) {
  if (this->isFull())
    return 0;

  int result = this->remaining();
  if (result > length)
    result = length;

  this->mPosition += result;
  return result;
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
