/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655
#define MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/func/Supplier.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class C, class R>
  class SupplierMethod;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C, class R>
class mframe::lang::SupplierMethod : public mframe::lang::Object,
                                     public mframe::lang::Supplier<R> {
  /* **************************************************************************
   * Variable
   */
 private:
  C& mClass;
  R(C::*mMethod)
  (void);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Supplier Method object
   *
   * @param c
   * @param method
   */
  SupplierMethod(C& c, R (C::*method)(void)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Supplier Method object
   *
   */
  virtual ~SupplierMethod(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Supplier
   */
 public:
  /**
   * @brief
   *
   * @return R
   */
  virtual R get(void) override {
    return (this->mClass.*this->mMethod)();
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

#endif /* MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655 */
