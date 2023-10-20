/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D058821B_1E72_462D_A6EC_00EA14E01C9D
#define MFRAME_D058821B_1E72_462D_A6EC_00EA14E01C9D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/util/Iterator.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::numb {
  class Floats;
}  // namespace mframe::numb

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::numb::Floats final : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 private:
  /**
   *
   */
  Floats(void) = default;

  /**
   *
   */
  virtual ~Floats(void) override = default;
  /* **************************************************************************
   * Operator Method
   */

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
  static const int MAX_ASCII_VALUE;
  static const float MAX_VALUE;
  static const float MIN_VALUE;
  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief
   *
   * @param iterator
   * @return true
   * @return false
   */
  static bool isFloat(mframe::util::Iterator<char>& iterator);

  /**
   * @brief
   *
   * @param str
   * @return true
   * @return false
   */
  static bool isFloat(const char* str);

  /**
   * @brief
   *
   * @param result
   * @param iterator
   * @return true
   * @return false
   */
  static bool parseFloat(float& result, mframe::util::Iterator<char>& iterator);

  /**
   * @brief
   *
   * @param result
   * @param str
   * @return true
   * @return false
   */
  static bool parseFloat(float& result, const char* str);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_D058821B_1E72_462D_A6EC_00EA14E01C9D */
