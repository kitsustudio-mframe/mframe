/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8
#define MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Memory.h"
#include "mframe/util/ArrayPrototype.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <typename E>
  class Array;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct
 */
template <typename E>
class mframe::util::Array : public mframe::util::ArrayPrototype {
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
   * @brief Construct a new Array object
   *
   * @param memory
   */
  Array(const mframe::lang::Memory& memory) : mframe::util::ArrayPrototype(memory, sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param e
   * @param length
   */
  Array(E* e, int length) : mframe::util::ArrayPrototype(mframe::lang::Memory(e, sizeof(E) * length), sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param e
   * @param length
   */
  Array(const E* e, int length) : mframe::util::ArrayPrototype(mframe::lang::Memory(e, sizeof(E) * length), sizeof(E)) {
    return;
  }

  /**
   * @brief Construct a new Array object
   *
   * @param length
   */
  Array(int length) : mframe::util::ArrayPrototype(length, sizeof(E)) {
    return;
  }

  /**
   * @brief Destroy the Array object
   *
   */
  virtual ~Array(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param index
   * @return E
   */
  E operator[](int index) const {
    return static_cast<E*>(this->pointer())[index];
  }

  /**
   * @brief
   *
   * @param index
   * @return E&
   */
  E& operator[](int index) {
    return static_cast<E*>(this->pointer())[index];
  }

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   * 返回此陣列的長度。
   *
   * @return uint32_t 由該對象表示的陣列的長度。
   */
  inline int length(void) const {
    return this->mElementLength;
  }

  /**
   * @brief
   * 返回此列表中指定元素的第一次出現的索引，如果此列表不包含元素，則返回-1。
   *
   * @param e - 要搜索的元素
   * @return int 此列表中指定元素的首次出現的索引，如果此列表不包含元素，則為-1
   */
  inline int indexOf(const E& e) const {
    return this->ArrayPrototype::indexOf(&e);
  }

  /**
   * @brief
   * 如果此列表包含指定的元素，則返回true。
   *
   * @param e - 要在此列表中存在的元素要測試的元素
   * @return true 如果此列表包含指定的元素
   */
  inline bool contains(const E& e) const {
    return (this->ArrayPrototype::indexOf(&e) != -1);
  }

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

#endif /* MFRAME_FCCC3E6F_E524_4464_BA6F_FF9492970DA8 */
