/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_73D4A5DA_8905_495C_8967_9EF1AAA2FB60
#define MFRAME_73D4A5DA_8905_495C_8967_9EF1AAA2FB60

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/io/Buffer.h"
#include "mframe/io/InputStream.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class InputStreamBuffer;

}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::InputStreamBuffer : public mframe::io::InputStream,
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
   * @brief Construct a new Read Buffer Input Stream object
   *
   * @param buffer
   */
  InputStreamBuffer(void);

  /**
   * @brief Destroy the Read Buffer Input Stream object
   *
   */
  virtual ~InputStreamBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::io::Buffer
   */
 public:
  virtual void flush(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::io::InputStream
   */
 public:
  virtual bool read(mframe::io::WriteBuffer& writeBuffer,
                    void* attachment,
                    mframe::io::CompletionHandler<int, void*>* handler) override;

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

 protected:
  /**
   * @brief 當緩衝區推出字元時調用。
   *
   */
  virtual void onBufferPollEvent(void);

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

#endif /* MFRAME_73D4A5DA_8905_495C_8967_9EF1AAA2FB60 */
