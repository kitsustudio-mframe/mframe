/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_477CBD58_814E_44DC_AC26_88630DD5162D
#define MFRAME_477CBD58_814E_44DC_AC26_88630DD5162D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct EdgeTriggerEventFall;
}  // namespace mframe::hal

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]邊緣觸發器，負觸發事件。
 *
 */
struct mframe::hal::EdgeTriggerEventFall : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param status
   */
  virtual void onEdgeTriggerFall(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_477CBD58_814E_44DC_AC26_88630DD5162D */
