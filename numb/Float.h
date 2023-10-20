/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_55C55E8C_894B_425F_8421_0100EE370D17
#define MFRAME_55C55E8C_894B_425F_8421_0100EE370D17

/* ****************************************************************************
 * Float
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/numb/Number.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::numb {
  class Float;
}  // namespace mframe::numb

/* ****************************************************************************
 * Class Float
 */
class mframe::numb::Float final : public mframe::numb::Number {
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
   * @brief Construct a new Float object
   *
   */
  Float(void);

  /**
   * @brief Construct a new Float object
   *
   * @param value
   */
  Float(float value);

  /**
   * @brief Destroy the Float object
   *
   */
  virtual ~Float(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @return float
   */
  inline operator float(void) {
    return this->mValue.f32;
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(float v);

  /**
   * @brief
   *
   * @param v
   * @return inlien
   */
  bool operator==(Float& v);
  
  /**
   * @brief
   *
   * @param v
   * @return float
   */
  inline float operator=(float v) {
    this->mValue.f32 = v;
    return this->mValue.f32;
  }

  /**
   * @brief
   *
   * @param v
   * @return Float
   */
  inline Float operator+=(float v) {
    this->mValue.f32 += v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Float
   */
  inline Float operator-=(float v) {
    this->mValue.f32 -= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Float
   */
  inline Float operator*=(float v) {
    this->mValue.f32 *= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Float
   */
  inline Float operator/=(float v) {
    this->mValue.f32 /= v;
    return *this;
  }

  /**
   * @brief
   *
   * @return Float
   */
  inline Float operator++(int) {
    Float tmp = *this;
    ++this->mValue.f32;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Float
   */
  inline Float operator++() {
    ++this->mValue.f32;
    return *this;
  }

  /**
   * @brief
   *
   * @return Float
   */
  inline Float operator--(int) {
    Float tmp = *this;
    --this->mValue.f32;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Float&
   */
  inline Float& operator--(void) {
    --this->mValue.f32;
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
  static const int SIZE;
  static const float EQUAL_EPSILIN;

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 *  End of file
 */

#endif /* MFRAME_55C55E8C_894B_425F_8421_0100EE370D17 */
