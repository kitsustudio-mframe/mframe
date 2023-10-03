/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324
#define MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/InputStream.h"
#include "mframe/io/PrintBuffer.h"
#include "mframe/io/RingBuffer.h"
#include "mframe/lang/Data.h"
#include "mframe/lang/Object.h"
#include "mframe/lang/func/Runnable.h"
#include "mframe/lang/sys/Allocator.h"
#include "mframe/lang/sys/Kernel.h"
#include "mframe/lang/sys/SystemConfig.h"
#include "mframe/lang/sys/SystemControl.h"
#include "mframe/lang/sys/Thread.h"
#include "mframe/util/ArrayQueue.h"
#include "mframe/util/Future.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::sys {
  class Svchost;
}

/* ****************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::lang::sys::Svchost : public mframe::lang::Object,
                                   public mframe::lang::func::Runnable,
                                   public mframe::io::CompletionHandler<int, void*>,
                                   public mframe::lang::sys::SystemControl {
  /* **************************************************************************
   * Variable
   */
 public:
  mframe::io::OutputStream& mOutputStream;
  mframe::io::InputStream& mInputStream;
  mframe::io::PrintBuffer mPrintBuffer;
  mframe::io::RingBuffer mRingBuffer;

 private:
  mframe::util::ArrayQueue<mframe::lang::func::Runnable> mArrayQueue;
  mframe::lang::sys::Thread* mThread;
  mframe::lang::sys::Thread* mUserThread;
  mframe::io::ReadBuffer* mCustomReadBuffer;
  mframe::io::WriteBuffer* mCustomWriteBuffer;
  bool mStart;
  bool mAction;
  bool mStream;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Svchost object
   *
   * @param systemConfig
   */
  Svchost(mframe::lang::sys::SystemConfig& systemConfig);

  /**
   *
   */
  virtual ~Svchost(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::func::Runnable
   */
 public:
  virtual void run(void) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::CompletionHandler<int, void*>
   */
 public:
  virtual void completed(int result, void* attachment) override;

  virtual void failed(void* exc, void* attachment) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::sys::SystemControl
   */
 public:
  virtual void setCustomReadBuffer(mframe::io::ReadBuffer* readBuffer) override;

  virtual void setCustomWriteBuffer(mframe::io::WriteBuffer* writeBuffer) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param task
   * @param stackSize
   * @return true
   * @return false
   */
  bool start(mframe::lang::func::Runnable& task, int stackSize);

  /**
   * @brief 停止執行svchost
   *
   */
  void stop(void);

  /**
   * @brief 執行使用者事件
   *
   * @param task 使用者指定事件
   * @return true 只用者事件排定成功
   * @return false 使用者事件排定失敗
   */
  bool execute(mframe::lang::func::Runnable& task);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool action(void);

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */
 private:
  bool checkOutputStream(void);
  bool checkInputStream(void);

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

#endif /* MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324 */
