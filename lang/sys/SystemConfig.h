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
#include "mframe/lang/sys/Allocator.h"
#include "mframe/lang/sys/HardwareInfo.h"
#include "mframe/lang/sys/Kernel.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::sys {
  struct SystemConfig;
}  // namespace mframe::lang::sys

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::lang::sys::SystemConfig {
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

  struct {
    mframe::lang::sys::Kernel* kernel;              ///< operator system
    mframe::lang::sys::Allocator* allocator;        ///< memory pool
    mframe::lang::sys::HardwareInfo* hardwareInfo;  ///< 硬體資訊
  } system;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B */
