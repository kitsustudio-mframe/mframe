/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_5764966F_889C_4856_97F7_96396168CDD2
#define MFRAME_5764966F_889C_4856_97F7_96396168CDD2

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/func/Runnable.h"
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  class Timer;
}  // namespace mframe::sys

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::sys::Timer : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Timer object
   *
   */
  Timer(void);

  /**
   * @brief Destroy the Timer object
   *
   */
  virtual ~Timer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief Cancels this timer task. If the task has been scheduled for one-time execution
   *        and has not yet run, or has not yet been scheduled, it will never run. If the
   *        task has been scheduled for repeated execution, it will never run again. (If
   *        the task is running when this call occurs, the task will run to completion,
   *        but will never run again.)
   *
   *        Note that calling this method from within the run method of a repeating timer
   *        task absolutely guarantees that the timer task will not run again.
   *
   *        This method may be called repeatedly; the second and subsequent calls have no
   *        effect.
   *
   * @return true
   * @return false
   */
  virtual bool cancel(void);

  /**
   * @brief 計時器是否正在運作
   *
   * @return true
   * @return false
   */
  virtual bool isRunning(void);

  /**
   * @brief Schedules the specified task for execution after the specified delay.
   *
   * @param task task to be scheduled.
   * @param delay  delay in milliseconds before task is to be executed.
   * @return true successful.
   * @return false
   */
  virtual bool schedule(mframe::func::Runnable& task, uint32_t delay);

  /**
   * @brief
   *
   * @param task
   * @param delay
   * @param period
   * @return true successful
   * @return false this task was already scheduled or cancelled.
   */
  virtual bool scheduleAtFixedRate(mframe::func::Runnable& task, uint32_t delay);

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

#endif /* MFRAME_5764966F_889C_4856_97F7_96396168CDD2 */
