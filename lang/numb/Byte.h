/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_F9B57639_6FC2_4ABB_B8EB_618F2228B096
#define MFRAME_F9B57639_6FC2_4ABB_B8EB_618F2228B096

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
  class Byte;
}  // namespace mframe::lang::numb

/* ****************************************************************************
 * Class Byte
 */
class mframe::lang::numb::Byte final : public mframe::lang::numb::Number {
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
   * @brief Construct a new Byte object
   *
   */
  Byte(void);

  /**
   * @brief Construct a new Byte object
   *
   * @param value
   */
  Byte(char value);

  /**
   * @brief Destroy the Byte object
   *
   */
  virtual ~Byte(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief Construct a new Byte::operator char object
   *
   */
  inline operator char(void) {
    return this->mValue.s8[0];
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(char v) {
    return (this->mValue.s8[0] == static_cast<char>(v));
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(Byte& v) {
    return (this->mValue.s8[0] == v.mValue.s8[0]);
  }

  /**
   * @brief
   *
   * @param v
   * @return char
   */
  char operator=(char v) {
    this->mValue.s8[0] = v;
    return this->mValue.s8[0];
  }

  /**
   * @brief
   *
   * @param v
   * @return Byte
   */
  Byte operator+=(int v) {
    this->mValue.s8[0] += v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Byte
   */
  Byte operator-=(int v) {
    this->mValue.s8[0] -= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Byte
   */
  Byte operator*=(int v) {
    this->mValue.s8[0] *= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Byte
   */
  Byte operator/=(int v) {
    this->mValue.s8[0] /= v;
    return *this;
  }

  /**
   * @brief
   *
   * @return Byte
   */
  Byte operator++(int) {
    Byte tmp = *this;
    ++this->mValue.s8[0];
    return tmp;
  }

  /**
   * @brief
   *
   * @return Byte
   */
  Byte operator++() {
    ++this->mValue.s8[0];
    return *this;
  }

  /**
   * @brief
   *
   * @return Byte
   */
  Byte operator--(int) {
    Byte tmp = *this;
    --this->mValue.s8[0];
    return tmp;
  }

  /**
   * @brief
   *
   * @return Byte&
   */
  Byte& operator--(void) {
    --this->mValue.s8[0];
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

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 *  End of file
 */

#endif /* MFRAME_F9B57639_6FC2_4ABB_B8EB_618F2228B096 */
