/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_8A512858_44C4_44E4_ADA9_8375937161CA
#define MFRAME_8A512858_44C4_44E4_ADA9_8375937161CA

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/func/BiConsumer.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::func {
  template <class C, class T, class U>
  class BiConsumerMethod;
}  // namespace mframe::func

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C, class T, class U>
class mframe::func::BiConsumerMethod : public mframe::lang::Object,
                                             public mframe::func::BiConsumer<T, U> {
  /* **************************************************************************
   * Variable
   */
 private:
  C& mClass;
  void (C::*mMethod)(T, U);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Bi Consumer Method object
   *
   * @param c
   * @param method
   */
  BiConsumerMethod(C& c, void (C::*method)(T, U)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Bi Consumer Method object
   *
   */
  virtual ~BiConsumerMethod(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::BiConsumer
   */
 public:
  virtual void accept(T t, U u) override {
    (this->mClass.*this->mMethod)(t, u);
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

#endif /* MFRAME_8A512858_44C4_44E4_ADA9_8375937161CA */
