/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_4DC8702A_119D_4444_AC76_BE736044C70E
#define MFRAME_4DC8702A_119D_4444_AC76_BE736044C70E

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct UartEventReceiver;
}  // namespace mframe::hal

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]同步非同步收發器接收事件。
 *
 */
struct mframe::hal::UartEventReceiver : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 接收緩衝滿事件。
   *
   * @param data 接收資料
   * @return true 持續接收下一個資料
   * @return false 取消接收下一個資料，並關閉接收緩衝器滿的事件監聽。
   */
  virtual bool onUartReceiver(const uint8_t data) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_4DC8702A_119D_4444_AC76_BE736044C70E */
