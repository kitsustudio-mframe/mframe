/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_24732F21_BBC1_4AB0_8238_ACE2005FF0DF
#define MFRAME_24732F21_BBC1_4AB0_8238_ACE2005FF0DF

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/InputStream.h"
#include "mframe/lang/func/Runnable.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class InputStreamWriteBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::InputStreamWriteBuffer : public mframe::io::InputStream,
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
   * @brief Construct a new Input Stream Buffer object
   *
   */
  InputStreamWriteBuffer(void);

  /**
   * @brief Destroy the Input Stream Buffer object
   *
   */
  virtual ~InputStreamWriteBuffer(void) override;

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

#endif /* MFRAME_24732F21_BBC1_4AB0_8238_ACE2005FF0DF */
