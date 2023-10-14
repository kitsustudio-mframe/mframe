/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_402C6B69_E296_467A_8D87_290582325A49
#define MFRAME_402C6B69_E296_467A_8D87_290582325A49

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/ReadBuffer.h"
#include "mframe/io/WriteBuffer.h"
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  struct SystemControl;
}  // namespace mframe::sys

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::sys::SystemControl : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 設定自訂讀取緩衝區，接管系統接收緩衝區。
   *
   * @param readBuffer
   */
  virtual void setCustomReadBuffer(mframe::io::ReadBuffer* readBuffer) abstract;

  /**
   * @brief 設定自訂寫入緩衝區，接管系統寫入緩衝區。
   *
   * @param writeBuffer
   */
  virtual void setCustomWriteBuffer(mframe::io::WriteBuffer* writeBuffer) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_402C6B69_E296_467A_8D87_290582325A49 */
