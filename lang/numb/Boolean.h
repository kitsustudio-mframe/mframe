/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A
#define MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/numb/Number.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::numb {
  class Boolean;
}  // namespace mframe::lang::numb

/* ****************************************************************************
 * Class Boolean
 */
class mframe::lang::numb::Boolean final : public mframe::lang::numb::Number {
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
   * @brief Construct a new Boolean object
   *
   */
  Boolean(void);

  /**
   * @brief Construct a new Boolean object
   *
   * @param value
   */
  Boolean(bool value);

  /**
   * @brief Destroy the Boolean object
   *
   */
  virtual ~Boolean(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief Construct a new operator bool object
   *
   */
  operator bool(void) {
    return Boolean::mValue.b;
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(bool v) {
    return (static_cast<bool>(Boolean::mValue.b) == v);
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(Boolean& v) {
    return (Boolean::mValue.b == v.mValue.b);
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator=(bool v) {
    Boolean::mValue.b = v;
    return Boolean::mValue.b;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator+=(int v) {
    if (v > 0)
      Boolean::mValue.b = true;

    else if (v < 0)
      Boolean::mValue.b = false;

    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator-=(int v) {
    if (v < 0)
      Boolean::mValue.b = true;

    else if (v > 0)
      Boolean::mValue.b = false;

    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator*=(int v) {
    Boolean::mValue.b *= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator/=(int v) {
    Boolean::mValue.b /= v;
    return *this;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator++(int) {
    Boolean tmp = *this;
    Boolean::mValue.b = true;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator++() {
    Boolean::mValue.b = true;
    return *this;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator--(int) {
    Boolean tmp = *this;
    Boolean::mValue.b = false;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Boolean&
   */
  Boolean& operator--() {
    Boolean::mValue.b = false;
    return *this;
  }

  /* **************************************************************************
   * Public Method <Override>
   */

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
 public:
  static const bool VALUE_TRUE = true;
  static const bool VALUE_FALSE = false;
  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 *  End of file
 */

#endif /* MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A */
