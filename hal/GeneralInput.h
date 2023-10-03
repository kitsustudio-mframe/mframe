/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_9C655B34_D715_4F1E_957C_F1BFB3213FB8
#define MFRAME_9C655B34_D715_4F1E_957C_F1BFB3213FB8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe\lang\Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::hal {
  struct GeneralInput;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief [Interface]硬體抽象層，通用引腳輸入。
 *
 */
struct mframe::hal::GeneralInput : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 取得引腳電平。
   *
   * @return true 高電平。
   * @return false 低電平。
   */
  virtual bool getValue(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_9C655B34_D715_4F1E_957C_F1BFB3213FB8 */
