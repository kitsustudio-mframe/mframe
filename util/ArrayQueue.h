/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_EABFB0E9_4CE7_4009_A990_B20F60799B41
#define MFRAME_EABFB0E9_4CE7_4009_A990_B20F60799B41

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/util/ArrayQueuePrototype.h"
#include "mframe/util/Collection.h"
#include "mframe/util/Queue.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class E>
  class ArrayQueue;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct
 */
template <class E = mframe::lang::Interface>
class mframe::util::ArrayQueue : public mframe::util::ArrayQueuePrototype,
                                 public mframe::lang::Queue<E> {
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
   * @brief Construct a new Array Queue object
   *
   * @param memory
   */
  ArrayQueue(const Memory& memory) : mframe::util::ArrayQueuePrototype(memory) {
    return;
  }

  /**
   * @brief Construct a new Array Queue object
   *
   * @param length
   */
  ArrayQueue(int length) : mframe::util::ArrayQueuePrototype(length) {
    return;
  }

  /**
   * @brief Destroy the Array Queue object
   *
   */
  virtual ~ArrayQueue(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Queue<E>
   */
 public:
  virtual bool offer(E* e) override {
    return this->ArrayQueuePrototype::offerPointer(e);
  }

  virtual E* poll(void) override {
    return static_cast<E*>(this->ArrayQueuePrototype::pollPointer());
  }

  virtual E* peek(void) override {
    return static_cast<E*>(this->ArrayQueuePrototype::peekPointer());
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::util::Collection<E>
   */
 public:
  virtual void clear(void) override {
    return this->ArrayQueuePrototype::clear();
  }

  virtual bool isEmpty(void) const override {
    return this->ArrayQueuePrototype::isEmpty();
  }

  virtual int size(void) const override {
    return this->ArrayQueuePrototype::size();
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iteraable<E>
   */
 public:
  virtual bool peekIndex(int index, E*& result) override {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-reinterpret-cast"

    return ArrayQueuePrototype::peekIndex(index, reinterpret_cast<void*&>(result));

#pragma clang diagnostic pop
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
  using ArrayQueuePrototype::clear;
  using ArrayQueuePrototype::isEmpty;
  using ArrayQueuePrototype::peekIndex;
  using ArrayQueuePrototype::size;

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

#endif /* MFRAME_EABFB0E9_4CE7_4009_A990_B20F60799B41 */
