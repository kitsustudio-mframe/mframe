/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311
#define MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/WriteBuffer.h"
#include "mframe/lang/Memory.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class StringFormat;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::StringFormat final : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 private:
  /**
   * @brief Construct a new String Format object
   *
   */
  StringFormat(void);

 public:
  /**
   * @brief Destroy the String Format object
   *
   */
  virtual ~StringFormat(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */
 private:
  static char mFormatBuffer[];

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief
   *
   * @param buffer
   * @param bufferSize
   * @param format
   * @param arg
   * @return int
   */
  static int pointerVa(void* buffer, size_t bufferSize, const char* format, va_list args);

  /**
   * @brief
   *
   * @param memory
   * @param format
   * @param arg
   * @return int
   */
  static int memoryVa(const mframe::lang::Memory& memory, const char* format, va_list args);

  /**
   * @brief
   *
   * @param writeBuffer
   * @param format
   * @param arg
   * @return int
   */
  static int writeBufferVa(mframe::io::WriteBuffer& writeBuffer, const char* format, va_list args);

  /**
   * @brief
   *
   * @param buffer
   * @param bufferSize
   * @param format
   * @param ...
   * @return int
   */
  static int pointer(void* buffer, unsigned int bufferSize, const char* format, ...);

  /**
   * @brief
   *
   * @param memory
   * @param format
   * @param ...
   * @return int
   */
  static int memory(const mframe::lang::Memory& memory, const char* format, ...);

  /**
   * @brief
   *
   * @param writeBuffer
   * @param format
   * @param ...
   * @return int
   */
  static int writeBuffer(mframe::io::WriteBuffer& writeBuffer, const char* format, ...);

  /**
   * @brief
   *
   * @param src
   * @param format
   * @param args
   * @return int
   */
  static int scanVa(const char* src, const char* format, va_list args);

  /**
   * @brief
   *
   * @param src
   * @param format
   * @param ...
   * @return int
   */
  static int scan(const char* src, const char* format, ...);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311 */
