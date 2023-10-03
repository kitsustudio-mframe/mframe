/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6
#define MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang::numb {
  class Shorts;
}  // namespace mframe::lang::numb

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::numb::Shorts final : public mframe::lang::Object {
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
   * @brief Construct a new Shorts object
   *
   */
  Shorts(void);

 public:
  /**
   * @brief Destroy the Shorts object
   *
   */
  virtual ~Shorts(void) override;

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
   * @brief 轉換為無符號
   *
   * @param value 來源
   * @return unsigned short 結果
   */
  static inline unsigned short castUnsigned(short value) {
    return static_cast<unsigned short>(value);
  }

  /**
   * @brief 轉換為有符號
   *
   * @param value 來源
   * @return short 結果
   */
  static inline short castSigned(unsigned short value) {
    return static_cast<short>(value);
  }

  /**
   * @brief 將字串轉換為數字
   *
   * @param str 來源字串
   * @return short 結果
   */
  static short valueOf(const char* str);
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6 */
