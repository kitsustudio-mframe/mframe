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
#include "ReadOnlyBuffer.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/Character.h"
#include "mframe/lang/Class.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */
using mframe::io::ReadOnlyBuffer;

//-----------------------------------------------------------------------------
using mframe::io::WriteBuffer;
using mframe::lang::Character;
using mframe::lang::Class;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
ReadOnlyBuffer::ReadOnlyBuffer(const char* str) : Data(str, Character::length(str)) {
  this->mPosition = 0;
  return;
}

//-----------------------------------------------------------------------------
ReadOnlyBuffer::ReadOnlyBuffer(const void* pointer, int length) : Data(pointer, length) {
  this->mPosition = 0;
  return;
}

//-----------------------------------------------------------------------------
ReadOnlyBuffer::~ReadOnlyBuffer(void) {
  this->mPosition = 0;
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::Iterable<char>
 */

//-----------------------------------------------------------------------------
bool ReadOnlyBuffer::peekIndex(int index, char& result) {
  if (index >= this->avariable())
    return false;

  result = *(this->pointer((this->mPosition + index), Class<char>::cast()));
  return true;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::ReadBuffer
 */

//-----------------------------------------------------------------------------
int ReadOnlyBuffer::pollByte(char& result, bool peek) {
  if (this->isEmpty())
    return -1;

  result = *this->pointer(this->mPosition, Class<char>::cast());

  if (!peek)
    ++this->mPosition;

  return this->avariable();
}

//-----------------------------------------------------------------------------
int ReadOnlyBuffer::poll(WriteBuffer& writeBuffer, bool peek) {
  return ReadOnlyBuffer::poll(writeBuffer, this->avariable(), peek);
}

//-----------------------------------------------------------------------------
int ReadOnlyBuffer::poll(WriteBuffer& writeBuffer, int length, bool peek) {
  if (length <= 0)
    return 0;

  if (this->isEmpty())
    return 0;

  int max = this->avariable();
  if (length > max)
    length = max;

  int result = writeBuffer.put(this->pointer(mPosition), this->avariable());

  if (!peek)
    this->mPosition += result;

  return result;
}

//-----------------------------------------------------------------------------
int ReadOnlyBuffer::poll(void* buffer, int bufferSize, bool peek) {
  if (this->isEmpty())
    return 0;

  int result = this->length();
  if (result >= bufferSize)
    bufferSize = result;

  if (buffer != nullptr)
    this->copyTo(buffer, 0, this->mPosition, bufferSize);

  if (!peek)
    this->mPosition += result;

  return result;
}

//-----------------------------------------------------------------------------
int ReadOnlyBuffer::skip(int value) {
  int max = this->avariable();
  if (value > max)
    value = max;

  this->mPosition += value;
  return value;
}

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
bool ReadOnlyBuffer::position(int newPosition) {
  if (newPosition < 0)
    return false;

  if (newPosition > this->capacity())
    return false;

  this->mPosition = newPosition;
  return true;
}

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
