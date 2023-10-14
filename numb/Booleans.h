/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D
#define MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/util/Iterator.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::numb {
  class Booleans;
}  // namespace mframe::numb

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::numb::Booleans : public mframe::lang::Object {
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
   * @brief Construct a new Booleans object
   *
   */
  Booleans(void) = default;

  /**
   * @brief Destroy the Booleans object
   *
   */
  virtual ~Booleans(void) override = default;

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
  static const char* TEXT_TRUE;
  static const char* TEXT_FALSE;
  static const int TEXT_TRUE_LENGTH;
  static const int TEXT_FALSE_LENGTH;

  /* **************************************************************************
   * Static Method
   */
 public:
  static bool isBoolean(const char* str);

  static bool isBoolean(mframe::util::Iterator<char>& iterator);

  static bool parseBoolean(bool& result, const char* str);

  static bool parseBoolean(bool& result,
                           mframe::util::Iterator<char>& iterable);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D */
