/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_21696933_3B6B_4512_922C_4B04E4B28F72
#define MFRAME_21696933_3B6B_4512_922C_4B04E4B28F72

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class HashGenerator;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::HashGenerator final : public mframe::lang::Object {
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
  HashGenerator(void);

 public:
  /**
   *
   */
  virtual ~HashGenerator(void) override;

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

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief Get the Hashcode object
   *
   * @param src 來源
   * @param len 長度
   * @return int hashcode
   */
  static int getHashcode(const void* src, int len);

  /**
   * @brief Get the Hashcode object
   *
   * @param src 來源
   * @return int hashcode
   */
  static int getHashcode(const char* src);

  /**
   * @brief Get the Hashcode Upper Cast object
   *
   * @param src 來源
   * @return int hashcode
   */
  static int getHashcodeUpperCast(const char* src);

  /**
   * @brief Get the Hashcode Lower Cast object
   *
   * @param src 來源
   * @return int hashcode
   */
  static int getHashcodeLowerCast(const char* src);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_21696933_3B6B_4512_922C_4B04E4B28F72 */
