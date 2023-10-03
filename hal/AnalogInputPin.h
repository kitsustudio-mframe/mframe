/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA
#define MFRAME_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "./../hal/Base.h"
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct AnalogInputPin;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，類比輸入訊號引腳。
 *
 */
struct mframe::hal::AnalogInputPin : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 2j類比訊號。
   *
   * @return int
   * - >=0 讀數
   * - other 異常
   */
  virtual int read(void) abstract;

  /**
   * @brief 取得ADC解析度。
   * .
   * @return int
   * - >=0 解析度
   * - other 不支援
   */
  virtual int getConvertLevel(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA */
