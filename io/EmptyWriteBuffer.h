/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_53B50485_918E_4B71_A576_99D31C076375
#define MFRAME_53B50485_918E_4B71_A576_99D31C076375

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe\io\WriteBuffer.h"
#include "mframe\lang\Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class EmptyWriteBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::EmptyWriteBuffer : public mframe::lang::Object,
                                     public mframe::io::WriteBuffer {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Empty Write Buffer object
   *
   */
  EmptyWriteBuffer(void);

  /**
   * @brief Destroy the Empty Write Buffer object
   *
   */
  virtual ~EmptyWriteBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::WriteBuffer
   */
 public:
  virtual bool isFull(void) const override;

  virtual int remaining(void) const override;

  virtual int putByte(const char data) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer, int length) override;

  virtual int put(const void* buffer, int length) override;

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

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_53B50485_918E_4B71_A576_99D31C076375 */
