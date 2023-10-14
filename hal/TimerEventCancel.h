/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_BBBD0380_DB14_422C_BED7_CF09F8A9BA5A
#define MFRAME_BBBD0380_DB14_422C_BED7_CF09F8A9BA5A

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct TimerEventCancel;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]計時器，停止事件。
 *
 */
struct mframe::hal::TimerEventCancel : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 計時器取消事件
   *
   * 當計時器取消時呼叫此事件
   */
  virtual void onTimerCancel(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_BBBD0380_DB14_422C_BED7_CF09F8A9BA5A */
