/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9
#define MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/numb/Integer.h"
#include "mframe/util/Iterator.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::numb {
  class Integers;
}  // namespace mframe::numb

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::numb::Integers final : public mframe::lang::Object {
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
  Integers(void) = default;

  /**
   *
   */
  virtual ~Integers(void) override = default;
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
  static const char* TEXT_MAX_VALUE;
  static const char* TEXT_MIN_VALUE;
  static const int MAX_ASCII_VALUE;

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief
   *
   * @param value
   * @return Integer
   */
  static inline unsigned int castUnsigned(int value) {
    return static_cast<unsigned int>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return Integer
   */
  static inline int castSigned(unsigned int value) {
    return static_cast<int>(value);
  }

  /**
   * @brief
   *
   * @param iterator
   * @return true
   * @return false
   */
  static bool isInteger(mframe::util::Iterator<char>& iterator);

  /**
   * @brief
   *
   * @param str
   * @return true
   * @return false
   */
  static bool isInteger(const char* str);

  /**
   * @brief
   *
   * @param result
   * @param iterator
   * @return true
   * @return false
   */
  static bool parseInteger(int& result, mframe::util::Iterator<char>& iterator);

  /**
   * @brief
   *
   * @param result
   * @param str
   * @return true
   * @return false
   */
  static bool parseInteger(int& result, const char* str);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9 */
