/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_BA8DBAF0_DCE9_4F33_B776_7C5470172961
#define MFRAME_BA8DBAF0_DCE9_4F33_B776_7C5470172961

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct EdgeTriggerEventRise;
}  // namespace mframe::hal

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]邊緣觸發器，正觸發事件。
 *
 */
struct mframe::hal::EdgeTriggerEventRise : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param status
   */
  virtual void onEdgeTriggerRise(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
