/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21
#define MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Data.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Memory;
  class String;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::Memory : public mframe::lang::Data {
  /* **************************************************************************
   * Variable
   */
 private:
  Memory* mNext;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Memory object
   *
   * @param data
   */
  Memory(const Data& data);

  /**
   * @brief Construct a new Memory object
   *
   * @param pointer
   * @param length
   */
  Memory(const void* pointer, int length);

  /**
   * @brief Construct a new Memory object
   *
   * @param pointer
   * @param length
   */
  Memory(void* pointer, int length);

  /**
   * @brief Construct a new Memory object
   *
   * @param length
   */
  Memory(int length);

  /**
   * @brief 淺層克隆建構子
   *
   * @param other
   */
  Memory(const Memory& other);

  /**
   * @brief Destroy the Memory object
   *
   */
  virtual ~Memory(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  inline bool isHeapMemory(void) const {
    return (this->mNext != nullptr);
  }

  /**
   * @brief
   *
   * @param size
   * @return true
   * @return false
   */
  bool resize(int size);

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
  /**
   * @brief
   *
   * @return mframe::lang::Memory
   */
  static mframe::lang::Memory nullMemory(void);
  
};

/* ****************************************************************************
 *  End of file
 */

#endif /* MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21 */
