/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D
#define MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/lang/func/Function.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::func {
  template <typename T, typename R>
  class FunctionEvent;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/struct/Struct
 */
template <typename T, typename R>
class mframe::lang::func::FunctionEvent : public mframe::lang::Object,
                                          public mframe::lang::func::Function<T, R> {
  /* **************************************************************************
   * Variable
   */
 private:
  R(*mMethod)
  (T);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Function Event object
   *
   * @param event
   */
  FunctionEvent(R (*method)(T)) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Function Event object
   *
   */
  virtual ~FunctionEvent(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::func::Function<T, R>
   */
 public:
  /**
   * @brief
   *
   * @param t
   * @return R
   */
  virtual R apply(T t) {
    return this->mMethod(t);
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

#endif /* MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D */
