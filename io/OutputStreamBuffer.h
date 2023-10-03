/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F49C4A53_E633_4A18_B37A_23E496773E8D
#define MFRAME_F49C4A53_E633_4A18_B37A_23E496773E8D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/Buffer.h"
#include "mframe/io/OutputStream.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class OutputStreamBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::OutputStreamBuffer : public mframe::io::OutputStream,
                                       public mframe::io::Buffer {
  /* **************************************************************************
   * Variable
   */
 protected:
  mframe::io::Buffer* mBuffer;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Output Stream Buffer object
   *
   */
  OutputStreamBuffer(void);

  /**
   * @brief Destroy the Output Stream Buffer object
   *
   */
  virtual ~OutputStreamBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::io::Buffer
   */
 public:
  virtual void flush(void) override;

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
   * Public Method <Override> - mframe::lang::Iterable<char>
   */
 public:
  virtual bool peekIndex(int index, char& result) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::ReadBuffer
   */
 public:
  virtual bool isEmpty(void) const override;

  virtual int avariable(void) const override;

  virtual int pollByte(char& result, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, int length, bool peek) override;

  virtual int poll(void* buffer, int bufferSize, bool peek) override;

  virtual int skip(int value) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief Set the Default Buffer object
   *
   * @param buffer
   */
  virtual void setDefaultBuffer(mframe::io::Buffer* buffer);

  /* **************************************************************************
   * Protected Method
   */
 protected:
  /**
   * @brief 當有字元寫入至緩衝區時調用。
   *
   */
  virtual void onBufferPutEvent(void);

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

#endif /* MFRAME_F49C4A53_E633_4A18_B37A_23E496773E8D */
