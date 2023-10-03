/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F
#define MFRAME_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  enum struct GeneralPinMode : char;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief 通用引腳模式
 *
 */
enum struct mframe::hal::GeneralPinMode : char {
  NOT_SUPPORT,  ///< 不支援該功能
  PUSH_PULL,    ///< 推輓輸出
  PULL_UP,      ///< 引腳上拉
  PULL_DOWN,    ///< 引腳下拉
  OPEN_DRAIN    ///< 開路模式
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F */
