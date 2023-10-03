/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_9E61DE90_7223_4EE7_BB33_FE3C45509F28
#define MFRAME_9E61DE90_7223_4EE7_BB33_FE3C45509F28

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct InterruptEvent;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]硬體抽象層，硬體中斷觸發事件。
 *
 */
struct mframe::hal::InterruptEvent : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 硬體中斷觸發事件
   *
   */
  virtual void interruptEvent(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_9E61DE90_7223_4EE7_BB33_FE3C45509F28 */
