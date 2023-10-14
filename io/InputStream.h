/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_1A551970_54AE_4519_9794_2271AD01B24B
#define MFRAME_1A551970_54AE_4519_9794_2271AD01B24B

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/CompletionHandler.h"
#include "mframe/io/WriteBuffer.h"
#include "mframe/lang/Interface.h"
#include "mframe/lang/Object.h"
#include "mframe/util/Future.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class InputStream;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 輸入串流 <Protected Class>
 *
 * 此類別無法被直接建構，須被繼承後並實現字節從輸入裝置至寫緩衝區。
 * 此類別無法再多線程下作業。
 *
 */
class mframe::io::InputStream : public mframe::lang::Object,
                                public mframe::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 protected:
  mframe::io::WriteBuffer* mWriteBuffer;
  mframe::io::CompletionHandler<int, void*>* mCompletionHandler;
  void* mAttachment;
  int mResult;
  bool mHandling;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 protected:
  /**
   * @brief Construct a new Input Stream object
   *
   */
  InputStream(void);

 public:
  /**
   * @brief Destroy the Input Stream object
   *
   */
  virtual ~InputStream(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::func::Runnable
   */
 public:
  virtual void run(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  virtual bool abortRead(void);

  /**
   * @brief
   *
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool readBusy(void);

  /**
   * @brief 阻塞式讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * 當寫緩衝區滿或是超時返回。
   *
   * @param writeBuffer 寫緩衝區。
   * @param timeout 超時，單位毫秒。
   * @return true 操作成功或讀取超時。
   * @return false 操作失敗，輸入串流正在忙碌。
   */
  virtual bool read(mframe::io::WriteBuffer& writeBuffer, int timeout);

  /**
   * @brief 非同步讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * 當寫緩衝區滿時將調用handler進行非同步事件。
   *
   * tips. 此方法調用後不論狀態將立即返回。
   *
   * @param writeBuffer 寫緩衝區。
   * @param attachment 使用者參數，將再調用handler時傳入。
   * @param handler 事件處理器。
   * @return true 建立非同步讀取成功。
   * @return false 建立非同步讀取失敗，輸入串流正在忙碌。
   */
  virtual bool read(mframe::io::WriteBuffer& writeBuffer,
                    void* attachment,
                    mframe::io::CompletionHandler<int, void*>* handler);

  /**
   * @brief 非阻塞讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * @param writeBuffer 寫緩衝區。
   * @param future 未來的計算結果。
   * @return true 建立非阻塞讀取成功。
   * @return false 建立非阻塞讀取失敗，輸入串流正在忙碌。
   */
  virtual bool read(mframe::io::WriteBuffer& writeBuffer, mframe::util::Future& future);

  /* **************************************************************************
   * Protected Method
   */
 protected:
  /**
   * @brief 處理事件，當讀取串流事件完成時呼叫此方法，完成非同步，非阻塞事件更新。
   *
   * 重寫此方法將改變處理方法。
   */
  virtual void execute(void);

  /**
   * @brief 當read被調用後且成功建立讀取事件，將呼叫此方法。
   *
   * 重寫此方法將改變處理方法。
   */
  virtual void onReadEvent(void);

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

#endif /* MFRAME_1A551970_54AE_4519_9794_2271AD01B24B */
