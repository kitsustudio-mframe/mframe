/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977
#define MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/func/Consumer.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::func {
  template <typename T>
  class ConsumerEvent;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/struct/Struct
 */
template <typename T>
class mframe::func::ConsumerEvent : public mframe::lang::Object,
                                          public mframe::func::Consumer<T> {
  typedef void (*Method)(T);
  /* **************************************************************************
   * Variable
   */
 private:
  Method mMethod;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Consumer Event object
   *
   * @param event
   */
  ConsumerEvent(Method method) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Consumer Event object
   *
   */
  virtual ~ConsumerEvent(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::func::Consumer<T>
   */
 public:
  /**
   * @brief
   *
   * @param t
   */
  virtual void accept(T t) {
    this->mMethod(t);
  }

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

#endif /* MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977 */
