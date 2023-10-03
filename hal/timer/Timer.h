/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA
#define MFRAME_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "./../../hal/Base.h"
#include "./../../hal/timer/EventCancel.h"
#include "./../../hal/timer/EventTrigger.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal::timer {
  struct Timer;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，計時器。
 *
 */
struct mframe::hal::timer::Timer : public mframe::hal::Base {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   */
  virtual void cancel(void) abstract;

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  virtual bool isBusy(void) abstract;

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  virtual bool isDone(void) abstract;

  /**
   * @brief
   *
   */
  virtual void waitDone(void) abstract;

  /**
   * @brief Get the Timer Clock object
   *
   * @return uint32_t hz
   */
  virtual uint32_t getTimerClock(void) abstract;

  /**
   * @brief
   *
   * @param tick
   * @return true
   * @return false
   */
  virtual bool startAtTick(uint32_t tick) abstract;

  /**
   * @brief 設置Timer開始
   *
   * @param second 時間週期
   * @return true 設置成功
   * @return false 設置失敗
   */
  virtual bool startAtTime(float second) abstract;

  /**
   * @brief 設置Timer開始
   *
   * @param hertz 時間週期
   * @return true 設置成功
   * @return false 設置失敗
   */
  virtual bool startAtHertz(float hertz) abstract;

  /**
   * @brief
   *
   * @param tick
   */
  virtual void resetTick(uint32_t tick) abstract;

  /**
   * @brief 設置Timer觸發事件
   *
   *
   * @param event 事件
   */
  virtual void setEventTrigger(mframe::hal::timer::EventTrigger* event) abstract;

  /**
   * @brief 設定Timer終止事件
   *
   * @param event 事件
   */
  virtual void setEventCancel(mframe::hal::timer::EventCancel* event) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA */
