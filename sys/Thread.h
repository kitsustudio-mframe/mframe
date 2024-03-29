/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293
#define MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/func/Runnable.h"
#include "mframe/sys/ThreadPriority.h"
#include "mframe/sys/ThreadState.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  class Thread;
}  // namespace mframe::sys

/* ****************************************************************************
 * Class/struct/Struct
 */
class mframe::sys::Thread : public mframe::lang::Object {
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
   * @brief Construct a new Thread object
   * 
   */
  Thread(void);

  /**
   * @brief Destroy the Thread object
   * 
   */
  virtual ~Thread(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Abstract>
   */
 public:
  /**
   * @brief Get the Thread Name object
   *
   * @return const char*
   */
  virtual const char* getThreadName(void) const abstract;

  /**
   * @brief Get the Priority object
   *
   * @return mframe::sys::ThreadPriority
   */
  virtual mframe::sys::ThreadPriority getPriority(void) const abstract;

  /**
   * @brief Get the State object
   *
   * @return mframe::sys::ThreadState
   */
  virtual mframe::sys::ThreadState getState(void) const abstract;

  /**
   * @brief Get the Stack Size object
   *
   * @return uint32_t
   */
  virtual int getStackSize(void) const abstract;

  /**
   * @brief
   *
   * @param priority
   * @return true
   * @return false
   */
  virtual bool start(const char* name,
                     mframe::sys::ThreadPriority priority) abstract;

  /**
   * @brief
   *
   */
  virtual void notify(void) abstract;

  /**
   * @brief Set the Priority object
   *
   * @param priority
   * @return true
   * @return false
   */
  virtual bool setPriority(mframe::sys::ThreadPriority priority) abstract;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool start(const char* name);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isActive(void);

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

#endif /* MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
