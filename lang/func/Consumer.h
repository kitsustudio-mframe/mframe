/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD
#define MFRAME_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD

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
  template <typename T>
  struct Consumer;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/struct/Struct
 */
template <typename T>
struct mframe::lang::func::Consumer : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param t
   */
  virtual void accept(T t) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD */
