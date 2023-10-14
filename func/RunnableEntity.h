/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB
#define MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/func/Runnable.h"
#include "mframe/func/RunnableEvent.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::func {
  class RunnableEntity;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::func::RunnableEntity final : public mframe::lang::Object,
                                                 public mframe::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 private:
  mframe::func::RunnableEvent mRunnableEvent;
  mframe::func::Runnable* mRunnable;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Runnable Entity object
   *
   */
  RunnableEntity(void);

  /**
   * @brief Construct a new Runnable Entity object
   *
   * @param runnable
   */
  RunnableEntity(mframe::func::Runnable& runnable);

  /**
   * @brief Construct a new Runnable Entity object
   *
   * @param function
   */
  RunnableEntity(void (*function)(void));

  /**
   * @brief 複製建構子
   *
   * @param source
   */
  RunnableEntity(const RunnableEntity& source);

  /**
   * @brief Destroy the Runnable Entity object
   *
   */
  virtual ~RunnableEntity(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::func::Runnable
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

#endif /* MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB */
