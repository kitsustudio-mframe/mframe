/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A
#define MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::func {
  struct Runnable;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/struct/Struct
 */
struct mframe::func::Runnable : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 執行方法。
   *
   */
  virtual void run(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A */
