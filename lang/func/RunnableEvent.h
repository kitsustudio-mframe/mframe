/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE
#define MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/lang/func/Runnable.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::func {
  class RunnableEvent;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::func::RunnableEvent final : public mframe::lang::Object,
                                                public mframe::lang::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 private:
  void (*mFunction)(void);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Runnable Event object
   *
   */
  RunnableEvent(void);

  /**
   * @brief Construct a new Runnable Event object
   *
   * @param function
   */
  RunnableEvent(void (*function)(void));

  /**
   * @brief Destroy the Runnable Event object
   *
   */
  virtual ~RunnableEvent(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::func::Runnable
   */
 public:
  /**
   * @brief
   *
   */
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

#endif /* MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE */
