/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */
#include <stdio.h>
#include <string.h>

//-----------------------------------------------------------------------------
#include "StringFormat.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::StringFormat;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */

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
char StringFormat::mFormatBuffer[128];

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
int StringFormat::pointerVa(void* buffer, size_t bufferSize, const char* format, va_list args) {
  return vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
}

//-----------------------------------------------------------------------------
int StringFormat::memoryVa(const mframe::lang::Memory& memory, const char* format, va_list args) {
  if (memory.isReadOnly())
    return 0;

  return vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
}

//-----------------------------------------------------------------------------
int StringFormat::writeBufferVa(mframe::io::WriteBuffer& writeBuffer, const char* format, va_list args) {
  // mframe::lang::System::lock();
  int result = vsnprintf(StringFormat::mFormatBuffer, sizeof(StringFormat::mFormatBuffer), format, args);
  result = writeBuffer.put(StringFormat::mFormatBuffer, result);
  // mframe::lang::System::unlock();
  return result;
}

//-----------------------------------------------------------------------------
int StringFormat::pointer(void* buffer, uint32_t bufferSize, const char* format, ...) {
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
  va_end(args);
  return result;
}

//-----------------------------------------------------------------------------
int StringFormat::memory(const mframe::lang::Memory& memory, const char* format, ...) {
  if (memory.isReadOnly())
    return 0;

  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
  va_end(args);
  return result;
}

//-----------------------------------------------------------------------------
int StringFormat::writeBuffer(mframe::io::WriteBuffer& writeBuffer, const char* format, ...) {
  va_list args;
  va_start(args, format);
  // mframe::lang::System::lock();
  int result = vsnprintf(static_cast<char*>(StringFormat::mFormatBuffer), sizeof(StringFormat::mFormatBuffer), format, args);
  result = writeBuffer.put(StringFormat::mFormatBuffer, result);
  // mframe::lang::System::unlock();
  va_end(args);
  return result;
}

//-----------------------------------------------------------------------------
int StringFormat::scanVa(const char* src, const char* format, va_list args) {
  return vsscanf(src, format, args);
}

//-----------------------------------------------------------------------------
int StringFormat::scan(const char* src, const char* format, ...) {
  va_list args;
  va_start(args, format);
  int result = vsscanf(src, format, args);
  va_end(args);
  return result;
}

/* ****************************************************************************
 * End of file
 */
