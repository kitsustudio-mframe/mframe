/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA
#define MFRAME_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::numb {
  class Number;
}  // namespace mframe::numb

/* ****************************************************************************
 * Class Integer
 */
class mframe::numb::Number : public mframe::lang::Object {
  /* **************************************************************************
   * Subclass
   */
 protected:
  union Value {
    bool b;
    uint8_t u8[4];
    char s8[4];
    uint16_t u16[2];
    short s16[2];
    uint32_t u32;
    int s32;
  };

  /* **************************************************************************
   * Variable
   */
 protected:
  Value mValue;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Number object
   *
   */
  Number(void);

  /**
   * @brief Destroy the Number object
   *
   */
  virtual ~Number(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  inline bool operator==(Number& v) {
    return (Number::mValue.u32 == v.mValue.u32);
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Object
   */
 public:
  /**
   * @brief 返回對象的哈希碼值。支持這種方法是為了散列表，如HashMap提供的那樣。
   *
   * @return uint32_t 該對象的哈希碼值。
   */
  virtual int hashcode(void) const override;

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
 *  End of file
 */

#endif /* MFRAME_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA */
