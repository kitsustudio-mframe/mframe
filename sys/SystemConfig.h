/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B
#define MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/InputStream.h"
#include "mframe/io/OutputStream.h"
#include "mframe/lang/Interface.h"
#include "mframe/sys/Allocator.h"
#include "mframe/sys/HardwareInfo.h"
#include "mframe/sys/Kernel.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  struct SystemConfig;
}  // namespace mframe::sys

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::sys::SystemConfig {
  struct {
    int stackSize;
    int taskQuantity;
  } svchost;

  struct {
    mframe::io::InputStream* inputStream;    ///< Console輸入串流
    mframe::io::OutputStream* outputStream;  ///< Console輸出串流
    int sizeScanner;                         ///< Scanner buffer size
    int sizePrintBiffer;                     ///< PrintBuffer buffer size
  } console;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B */
