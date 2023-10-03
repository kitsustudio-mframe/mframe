/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F5896110_0162_406F_9ECE_A67699B0938F
#define MFRAME_F5896110_0162_406F_9ECE_A67699B0938F

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct GeneralOutput;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]硬體抽象層，通用引腳輸出。
 *
 */
struct mframe::hal::GeneralOutput : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 設定引腳輸出高電平。
   *
   */
  virtual void setHigh(void) abstract;

  /**
   * @brief 設定引腳輸出低電平。
   *
   */
  virtual void setLow(void) abstract;

  /**
   * @brief 設定引腳輸出反向電平。
   *
   */
  virtual void setToggle(void) abstract;

  /**
   * @brief 設定引腳輸出電平。
   *
   * @param level
   * - true 設定輸出高電平。
   * - false 設定輸出低電平。
   */
  virtual void setValue(bool level) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_F5896110_0162_406F_9ECE_A67699B0938F */
