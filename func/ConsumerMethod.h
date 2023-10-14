/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0
#define MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0

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
  template <class C, class T>
  class ConsumerMethod;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C, class T>
class mframe::func::ConsumerMethod : public mframe::lang::Object,
                                           public mframe::func::Consumer<T> {
  /* **************************************************************************
   * Variable
   */
 private:
  C& mClass;
  void (C::*mMethod)(T);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Consumer Method object
   *
   * @param c
   * @param method
   */
  ConsumerMethod(C& c, void (C::*method)(T)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Consumer Method object
   *
   */
  virtual ~ConsumerMethod(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::func::Consumer
   */
 public:
  virtual void accept(T t) override {
    (this->mClass.*this->mMethod)(t);
    return;
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

#endif /* MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0 */
