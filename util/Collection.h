/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4
#define MFRAME_B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"
#include "mframe/lang/Iterable.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class T>
  struct Collection;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct
 */
template <class T>
struct mframe::util::Collection : public virtual mframe::lang::Iterable<T> {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 從此集合中刪除所有元素(可選操作)。此方法返回後，集合將為空。
   *
   */
  virtual void clear(void) abstract;

  /**
   * @brief 如果此集合不包含元素，則返回true。
   *
   * @return
   * true如果此集合不包含元素
   */
  virtual bool isEmpty(void) const abstract;

  /**
   * @brief 返回此集合中的元素數。
   *
   * 如果此收藏包含超過 Integer.MAX_VALUE個元素，則返回Integer.MAX_VALUE。
   *
   * @return uint32_t - 此集合中的元素数
   */
  virtual int size(void) const abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_.B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4 */
