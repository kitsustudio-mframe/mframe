/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_EED8B891_287B_4333_8669_6523A44D8CCC
#define MFRAME_EED8B891_287B_4333_8669_6523A44D8CCC

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "./../../lang/Interface.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal::usart {
  struct EventTransfer;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]同步非同步收發器傳輸事件。
 *
 */
struct mframe::hal::usart::EventTransfer : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 傳輸緩衝空事件。
   *
   * @param data 預發送資料
   * @return true 發送該筆資料
   * @return false 取消發送資料，並結束輸出緩衝器空的事件間聽。
   */
  virtual bool onUartTransfer(uint8_t& data) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_EED8B891_287B_4333_8669_6523A44D8CCC */
