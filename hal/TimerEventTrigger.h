/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_DF0EC699_78D6_4243_A75D_F321C92D88BB
#define MFRAME_DF0EC699_78D6_4243_A75D_F321C92D88BB

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct TimerEventTrigger;
}  // namespace mframe::hal

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]計時器，觸發事件。
 *
 */
struct mframe::hal::TimerEventTrigger : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 計時器觸發事件
   *
   * 當計時器下數歸零時呼叫此事件
   */
  virtual void onTimerTrigger(void) abstract;
};

#endif /* MFRAME_DF0EC699_78D6_4243_A75D_F321C92D88BB */
