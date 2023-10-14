/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_422910B3_C829_4F28_9F7E_4A928F53DA5A
#define MFRAME_422910B3_C829_4F28_9F7E_4A928F53DA5A

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/hal/GeneralPin.h"
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl {
  class VirtualGeneralPin;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 通用引腳模擬。
 *
 */
class mframe::ctrl::VirtualGeneralPin : public mframe::lang::Object,
                                              public mframe::hal::GeneralPin {
  /* **************************************************************************
   * Variable
   */
 private:
  uint8_t mDir;
  uint8_t mValue;
  mframe::hal::GeneralPinMode mGeneralPinMode;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Virtual General Pin object
   *
   */
  VirtualGeneralPin(void);

  /**
   * @brief Destroy the Virtual General Pin object
   *
   */
  virtual ~VirtualGeneralPin(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Static Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */
 public:
  virtual bool getDir(void) override;

  virtual void setDir(bool dir) override;

  virtual mframe::hal::GeneralPinMode getPinMode(void) override;

  virtual mframe::hal::GeneralPinMode setPinMode(mframe::hal::GeneralPinMode mode) override;

  virtual void setHigh(void) override;

  virtual void setInput(void) override;

  virtual void setLow(void) override;

  virtual void setOutput(void) override;

  virtual void setToggle(void) override;

  virtual bool getValue(void) override;

  virtual void setValue(bool level) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief Set the Input Value object
   *
   * @param level
   * @return true
   * @return false
   */
  virtual bool setInputValue(bool level);

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

#endif /* MFRAME_422910B3_C829_4F28_9F7E_4A928F53DA5A */
