/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6
#define MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::numb {
  class Bytes;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::numb::Bytes final : public mframe::lang::Object {
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
  Bytes(void);

 public:
  /**
   *
   */
  virtual ~Bytes(void) override;

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
   * @brief
   *
   * @param value
   * @return char
   */
  static inline unsigned char castUnsigned(char value) {
    return static_cast<unsigned char>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return char
   */
  static inline char castSigned(unsigned char value) {
    return static_cast<char>(value);
  }

  /**
   * @brief
   *
   * @param str
   * @return char
   */
  static char valueOf(const char* str);
};

/* ***************************************************************************
 * End of file
 */

#endif /* MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6 */
