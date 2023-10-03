/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_E8463782_967B_46FF_930C_98A3EB2CAF31
#define MFRAME_E8463782_967B_46FF_930C_98A3EB2CAF31

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/lang/sys/Thread.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::sys {
  class EntryPoint;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::sys::EntryPoint : public mframe::lang::Object,
                                      public mframe::lang::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 private:
  void (*mSetup)(mframe::lang::sys::Thread*);
  void (*mLoop)(mframe::lang::sys::Thread*);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Entry Point object
   *
   * @param setup
   * @param loop
   */
  EntryPoint(void (*setup)(mframe::lang::sys::Thread*), void (*loop)(mframe::lang::sys::Thread*));

  /**
   * @brief Destroy the Entry Point object
   *
   */
  virtual ~EntryPoint(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>- mframe::lang::func::Runnable
   */
 public:
  virtual void run(void) override;

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_E8463782_967B_46FF_930C_98A3EB2CAF31 */
