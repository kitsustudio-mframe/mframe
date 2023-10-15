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
#include "PrintBuffer.h"

//-----------------------------------------------------------------------------
#include "mframe/io/RingBuffer.h"
#include "mframe/lang/Memory.h"
#include "mframe/lang/StringFormat.h"
#include "mframe/lang/Strings.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::io::PrintBuffer;

//-----------------------------------------------------------------------------
using mframe::io::RingBuffer;
using mframe::lang::Memory;
using mframe::lang::StringFormat;
using mframe::lang::Strings;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
PrintBuffer::PrintBuffer(const Memory& memory) : RingBuffer(memory) {
  return;
}

//-----------------------------------------------------------------------------
PrintBuffer::PrintBuffer(int length) : RingBuffer(length) {
  return;
}

//-----------------------------------------------------------------------------
PrintBuffer::~PrintBuffer(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(bool b, bool newLine) {
  if (b)
    this->put("True", 4);

  else
    this->put("False", 5);

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(char c, bool newLine) {
  this->putByte(c);

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(double d, bool newLine) {
  mframe::lang::StringFormat::writeBuffer(*this, "%f", d);

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(float f, bool newLine) {
  mframe::lang::StringFormat::writeBuffer(*this, "%f", static_cast<double>(f));

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(int i, bool newLine, bool unsign) {
  if (unsign)
    mframe::lang::StringFormat::writeBuffer(*this, "%d", static_cast<unsigned int>(i));

  else
    mframe::lang::StringFormat::writeBuffer(*this, "%d", i);

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(const Strings& string, bool newLine) {
  this->put(string, string.size());

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(const char* string, bool newLine) {
  this->put(string, Strings::getLength(string));

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::print(ReadBuffer& readBuffer, bool newLine) {
  this->put(readBuffer);

  if (newLine)
    this->println();

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::println(void) {
  this->putByte('\r');
  this->putByte('\n');

  return *this;
}

//-----------------------------------------------------------------------------
PrintBuffer& PrintBuffer::format(const char* format, ...) {
  va_list args;
  va_start(args, format);
  StringFormat::writeBufferVa(*this, format, args);
  va_end(args);

  return *this;
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
