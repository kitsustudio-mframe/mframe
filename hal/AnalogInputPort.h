/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B
#define MFRAME_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/hal/Base.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct AnalogInputPort;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，類比輸入訊號。
 *
 */
struct mframe::hal::AnalogInputPort : public mframe::hal::Base {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param channel ADC通道。
   * @return int
   * - >=0 讀數
   * - other 異常
   */
  virtual int read(int channel) abstract;

  /**
   * @brief 取得ADC解析度
   *
   * @return int
   * - >=0 解析度
   * - other 不支援
   */
  virtual int getConvertLevel(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B */
