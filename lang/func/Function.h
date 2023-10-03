/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE
#define MFRAME_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::func {
  template <typename T, typename R>
  struct Function;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/struct/Struct
 */
template <typename T, typename R>
struct mframe::lang::func::Function : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param t
   * @return R
   */
  virtual R apply(T t) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE */
