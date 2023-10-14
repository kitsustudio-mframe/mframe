/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_EFF1A157_A291_4313_A742_99FB124D0B71
#define MFRAME_EFF1A157_A291_4313_A742_99FB124D0B71

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/hal/Base.h"
#include "mframe/hal/EdgeTriggerEventFall.h"
#include "mframe/hal/EdgeTriggerEventRise.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct EdgeTrigger;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，邊緣觸發器。
 *
 */
struct mframe::hal::EdgeTrigger : public mframe::hal::Base {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 啟動或關閉正負緣觸發
   *
   * @param enable
   * - true 啟用
   * - false 禁用
   */
  virtual void enableAll(bool enable) abstract;

  /**
   * @brief 啟用負緣觸發
   *
   * @param enable
   * - true 啟用
   * - false 禁用
   */
  virtual void enableFall(bool enable) abstract;

  /**
   * @brief 啟動正緣觸發
   *
   * @param enable
   * - true 啟用
   * - false 禁用
   */
  virtual void enableRise(bool enable) abstract;

  /**
   * @brief Set the Event Rise object
   *
   * @param event
   */
  virtual void setEdgeTriggerEventRise(mframe::hal::EdgeTriggerEventRise* event) abstract;

  /**
   * @brief Set the Event Fall object
   *
   * @param event
   */
  virtual void setEdgeTriggerEventFall(mframe::hal::EdgeTriggerEventFall* event) abstract;

  /**
   * @brief 讀取是否有發生正緣觸發
   *
   * 嘗試讀取狀態，若發生觸發將回傳true並且清除事件
   *
   *
   * Tips: 若已設定setEdgeTriggerEventRise事件，此方法將永遠回傳false
   *
   * @return true 已發生觸發
   * @return false 尚未發生觸發
   */
  virtual bool readRise(void) abstract;

  /**
   * @brief 讀取是否有發生負緣觸發
   *
   * 嘗試讀取狀態，若發生觸發將回傳true並且清除事件
   *
   *
   * Tips: 若已設定setEdgeTriggerEventFall事件，此方法將永遠回傳false
   *
   * @return true 已發生觸發
   * @return false 尚未發生觸發
   */
  virtual bool readFall(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_EFF1A157_A291_4313_A742_99FB124D0B71 */
