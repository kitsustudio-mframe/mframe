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
#include "mframe/sys/Thread.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  class EntryPoint;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::sys::EntryPoint : public mframe::lang::Object,
                                      public mframe::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 private:
  void (*mSetup)(mframe::sys::Thread*);
  void (*mLoop)(mframe::sys::Thread*);

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
  EntryPoint(void (*setup)(mframe::sys::Thread*), void (*loop)(mframe::sys::Thread*));

  /**
   * @brief Destroy the Entry Point object
   *
   */
  virtual ~EntryPoint(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>- mframe::func::Runnable
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
