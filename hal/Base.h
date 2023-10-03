/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_C49120BF_2531_4068_86B3_87BA2D347ED7
#define MFRAME_C49120BF_2531_4068_86B3_87BA2D347ED7

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct Base;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，初始化共基類。
 *
 */
struct mframe::hal::Base : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 硬體去初始化。
   *
   * @return true 去初始化成功。
   * @return false 去初始化失敗，可能原因如下：
   * - 設備尚未初始化。
   * - 設備異常。
   */
  virtual bool deinit(void) abstract;

  /**
   * @brief 硬體初始化。
   *
   * @return true 初始化成功
   * @return false 初始化失敗，可能原因如下：
   * - 設備已經初始化。
   * - 設備異常。
   */
  virtual bool init(void) abstract;

  /**
   * @brief 取得硬體是否已初始化。
   *
   * @return true 設備上會初始化。
   * @return false 設備已經初始化。
   */
  virtual bool isInit(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_C49120BF_2531_4068_86B3_87BA2D347ED7 */
