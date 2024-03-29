/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D
#define MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/util/ArrayMapPrototype.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class K, class V>
  class ArrayMap;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class K = mframe::lang::Interface, class V = mframe::lang::Interface>
class mframe::util::ArrayMap : public mframe::util::ArrayMapPrototype, public mframe::util::Map<K, V> {
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
   * @brief Construct a new Array Map object
   *
   * @param memory
   */
  ArrayMap(const mframe::lang::Memory& memory) : ArrayMapPrototype(memory) {
    return;
  }

  /**
   * @brief Construct a new Array Map object
   *
   * @param size
   */
  ArrayMap(int size) : ArrayMapPrototype(size) {
    return;
  }

  /**
   * @brief Destroy the Array Map object
   *
   */
  virtual ~ArrayMap(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<E>
   */
 public:
  virtual bool peekIndex(int index, V*& result) override {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-reinterpret-cast"

    return ArrayMapPrototype::peekIndex(index, reinterpret_cast<void*&>(result));

#pragma clang diagnostic pop
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Collection<E>
   */
 public:
  virtual void clear(void) override {
    ArrayMapPrototype::clear();
  }

  virtual bool isEmpty(void) const override {
    return ArrayMapPrototype::isEmpty();
  }

  virtual int size(void) const override {
    return ArrayMapPrototype::size();
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::util::Map<V>
   */
 public:
  virtual bool containsKey(K& key) const override {
    return ArrayMapPrototype::prototypeContainsKey(key);
  }

  virtual bool containsValue(V* value) const override {
    return ArrayMapPrototype::prototypeContainsValue(value);
  }

  virtual V* get(K& key) const override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeGet(key));
  }

  virtual V* put(K& key, V* value) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypePut(key, value));
  }

  virtual V* remove(K& key) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeRemove(key));
  }

  virtual V* replace(K& key, V* value) override {
    return reinterpret_cast<V*>(ArrayMapPrototype::prototypeReplace(key, value));
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
 private:
  using mframe::util::ArrayMapPrototype::peekIndex;

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

#endif /* MFRAME_7EB43082_1596_43AB_9C6E_93D8D36DE60D */
