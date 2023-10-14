/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B
#define MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B

/* ****************************************************************************
 * Include
 */

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/func/Runnable.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::func {
  template <class C>
  class RunnableMethod;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C>
class mframe::func::RunnableMethod : public mframe::lang::Object,
                                           public mframe::func::Runnable {
  /* **************************************************************************
   * Variable
   */
 private:
  C& mClass;
  void (C::*mMethod)(void);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Runnable Method object
   *
   * @param c
   * @param method
   */
  RunnableMethod(C& c, void (C::*method)(void)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Runnable Method object
   *
   */
  virtual ~RunnableMethod(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::func::Runnable
   */
 public:
  virtual void run(void) override {
    (this->mClass.*this->mMethod)();
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

#endif /* MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B */
