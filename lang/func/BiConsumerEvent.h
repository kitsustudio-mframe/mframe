/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263
#define MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/func/BiConsumer.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::func {
  template <typename T, typename U>
  class BiConsumerEvent;
}  // namespace mframe::lang::func

/* ****************************************************************************
 * Class/struct/Struct
 */
template <class T, class U>
class mframe::lang::func::BiConsumerEvent : public mframe::lang::Object,
                                            public mframe::lang::func::BiConsumer<T, U> {
  /* **************************************************************************
   * Variable
   */
 private:
  void (*mEvent)(T, U);

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Bi Consumer Event object
   *
   * @param event
   */
  BiConsumerEvent(void (*event)(T, U)) {
    this->mEvent = event;
    return;
  }

  /**
   * @brief Destroy the Bi Consumer Event object
   *
   */
  ~BiConsumerEvent() = default;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::BiConsumer<T, U>
   */
 public:
  /**
   * @brief
   *
   * @param t
   * @param u
   */
  virtual void accept(T t, U u) {
    this->mEvent(t, u);
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

#endif /* MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263 */
