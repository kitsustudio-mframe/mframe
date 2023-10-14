/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46
#define MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Memory.h"
#include "mframe/sys/Allocator.h"
#include "mframe/util/Collection.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace mframe::sys {
  class Stacker;
}  // namespace mframe::sys

/* ****************************************************************************
 * Class/Interface/Struct
 */
class mframe::sys::Stacker : public mframe::lang::Memory,
                                   public mframe::util::Collection<void*>,
                                   public mframe::sys::Allocator {
  /* **************************************************************************
   * Variable
   */
 protected:
  uint8_t* mStackPointer;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Stacker object
   *
   * @param buffer
   * @param size
   */
  Stacker(void* buffer, int size);

  /**
   * @brief Construct a new Stacker object
   *
   * @param memory
   */
  Stacker(const mframe::lang::Memory& memory);

  /**
   * @brief Destroy the Stacker object
   *
   */
  virtual ~Stacker(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> mframe::util::Iterable<mframe::lang::Data*>
   */
 public:
  virtual bool peekIndex(int index, void*& result) override;

  /* **************************************************************************
   * Public Method <Override> mframe::util::Collection<mframe::lang::Memory>
   */
 public:
  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

  /* **************************************************************************
   * Public Method <Override> mframe::sys::Allocator
   */
 public:
  virtual void* alloc(int size) override;

  virtual bool free(void* ptr) override;

  virtual bool free(void* ptr, int size) override;

  virtual void* allocAlignment32(int size) override;

  virtual void* allocAlignment64(int size) override;

  virtual int getFree(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemory(int size);

  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemoryAlignment32(int size);

  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemoryAlignment64(int size);

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
 public:
  static Stacker* construct(void* pointer, int size);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46 */
