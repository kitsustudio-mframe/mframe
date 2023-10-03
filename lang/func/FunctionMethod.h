/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_744A7D50_87F7_4559_993A_9FA307345979
#define MFRAME_744A7D50_87F7_4559_993A_9FA307345979

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
  template <class T, class U, class E>
  class FunctionMethod;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief
 *
 * @tparam T 輸入類型
 * @tparam R 返回類型
 * @tparam C 類別類型
 */
template <class C, class T, class R>
class mframe::lang::func::FunctionMethod : public mframe::lang::Object,
                                           public mframe::lang::func::Function<T, R> {
  /* **************************************************************************
   * Variable
   */
 private:
  C& mClass;
  R(C::*mMethod)
  (T);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Function Method object
   *
   * @param c
   * @param method
   */
  FunctionMethod(C& c, R (C::*method)(T)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Function Method object
   *
   */
  virtual ~FunctionMethod(void) override {
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
  virtual R apply(T t) override {
    return (this->mClass.*this->mMethod)(t);
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

#endif /* MFRAME_744A7D50_87F7_4559_993A_9FA307345979 */
