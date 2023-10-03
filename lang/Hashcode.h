/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_49192D91_B2E2_4241_93F9_E0873CE7DF81
#define MFRAME_49192D91_B2E2_4241_93F9_E0873CE7DF81

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Hashcode;
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::Hashcode : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */
 private:
  int mHahscode;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Hashcode object
   *
   * @param interface
   */
  Hashcode(mframe::lang::Interface& interface);

  /**
   * @brief Construct a new Hashcode object
   *
   * @param hashcode
   */
  Hashcode(int hashcode);

  /**
   * @brief Destroy the Hashcode object
   *
   */
  virtual ~Hashcode(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Object
   */
 public:
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
 * End of file
 */

#endif /* MFRAME_49192D91_B2E2_4241_93F9_E0873CE7DF81 */
