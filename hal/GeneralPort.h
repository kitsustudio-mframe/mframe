/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_DA8BBDE6_3AFE_4070_945C_08F9966A0B20
#define MFRAME_DA8BBDE6_3AFE_4070_945C_08F9966A0B20

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "./../hal/Base.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct GeneralPort;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，通用引腳輸入埠。
 *
 */
struct mframe::hal::GeneralPort : public mframe::hal::Base {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 讀取通用埠輸入輸出方向。
   *
   * @param port 埠號碼。
   * @return uint32_t 返回通用埠輸入輸出方向
   *
   * - 0 輸入。
   * - 1 輸出。
   */
  virtual uint32_t dir(uint32_t port) abstract;

  /**
   * @brief 讀取通用埠輸入輸出方向。
   *
   * @param port
   * @param value
   */
  virtual void dir(uint32_t port, uint32_t value) abstract;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void dirClear(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief
   *
   * @param port
   * @param mask
   */
  virtual void dirSet(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief Get port value.
   *
   * @param port GPIO port.
   * @return pin value 0 = low, 1 = high.
   */
  virtual uint32_t pin(uint32_t port) abstract;

  /**
   * @brief Set port value.
   *
   * @param port GPIO port.
   * @param value 0 = low,
   *              1 = high.
   */
  virtual void pin(uint32_t port, uint32_t value) abstract;

  /**
   * @brief Set port mask low.
   *
   * @param port GPIO port.
   * @param value 0 = No operation.
   *              1 = Set output bit low.
   */
  virtual void pinClear(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief Set port mask high.
   *
   * @param port GPIO port.
   * @param value 0 = No operation.
   *              1 = Set output bit high.
   */
  virtual void pinSet(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief Set port mask toggle.
   *
   * @param port GPIO port.
   * @param value 0 = No operation.
   *              1 = Set output bit toggle.
   */
  virtual void pinToggle(uint32_t port, uint32_t mask) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
