/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_5D254320_94DB_4B27_879F_9BDACF1C3A0E
#define MFRAME_5D254320_94DB_4B27_879F_9BDACF1C3A0E

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/hal/AnalogInputPin.h"
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl::virt {
  class VirtualAnalogInputPin;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 類比輸入引腳模擬。
 *
 */
class mframe::ctrl::virt::VirtualAnalogInputPin : public mframe::lang::Object,
                                                  public mframe::hal::AnalogInputPin {
  /* **************************************************************************
   * Variable
   */

 private:
  int mLevel;
  int mValue;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Virtual Analog Input Pin object
   *
   */
  VirtualAnalogInputPin(void);

  /**
   * @brief Destroy the Virtual Analog Input Pin object
   *
   */
  virtual ~VirtualAnalogInputPin(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Static Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::AnalogInputPin
   */
 public:
  virtual int read(void) override;

  virtual int getConvertLevel(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief Set the Value object
   *
   * @param value
   */
  virtual void setValue(int value);

  /**
   * @brief Set the Convert Level object
   *
   * @param level
   */
  virtual void setConvertLevel(int level);

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

#endif /* MFRAME_5D254320_94DB_4B27_879F_9BDACF1C3A0E */
