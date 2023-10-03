/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1
#define MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/lang/sys/Allocator.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::sys {
  class DefaultAllocator;
}  // namespace mframe::lang::sys

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::sys::DefaultAllocator : public mframe::lang::Object,
                                            public mframe::lang::sys::Allocator {
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
   * @brief Construct a new Default Allocator object
   *
   */
  DefaultAllocator(void);

  /**
   * @brief Destroy the Default Allocator object
   *
   */
  virtual ~DefaultAllocator(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> mframe::lang::sys::Allocator
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

#endif /* MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1 */
