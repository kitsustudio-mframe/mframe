/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_A1F76CE0_6517_42C6_A5DF_F88FC434FC37
#define MFRAME_A1F76CE0_6517_42C6_A5DF_F88FC434FC37

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/ReadBuffer.h"
#include "mframe/io/WriteBuffer.h"
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class ReadBufferMonitor;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::ReadBufferMonitor : public mframe::lang::Object,
                                      public mframe::io::ReadBuffer {
  /* **************************************************************************
   * Variable
   */

 private:
  mframe::io::ReadBuffer& mReadBuffer;
  mframe::io::WriteBuffer* mMonitor;
  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  ReadBufferMonitor(mframe::io::ReadBuffer& readBuffer);

  virtual ~ReadBufferMonitor(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<char>
   */
 public:
  virtual bool peekIndex(int index, char& result) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::io::ReadBuffer
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
   * @brief 設定監視器
   *
   * @param monitor
   * - null 取消監聽
   * - other 建立監聽事件
   */
  virtual void setMonitor(mframe::io::WriteBuffer* monitor);

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

#endif /* MFRAME_A1F76CE0_6517_42C6_A5DF_F88FC434FC37 */
