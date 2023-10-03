/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B
#define MFRAME_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B

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
namespace mframe::ctrl {
  class Voltmeter;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 電壓表。
 *
 */
class mframe::ctrl::Voltmeter : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

 private:
  mframe::hal::AnalogInputPin& mAnalogPin;
  float mVoltageMin;
  float mVoltageMax;
  float mVoltageDelta;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Voltmeter object
   *
   * @param analogPin
   * @param voltmeterMin
   * @param voltmeterMax
   */
  Voltmeter(mframe::hal::AnalogInputPin& analogPin, float voltmeterMin, float voltmeterMax);

  /**
   * @brief Destroy the Voltmeter object
   *
   */
  virtual ~Voltmeter(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Static Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 取得電壓。
   *
   * @return float 電壓。
   */
  float voltage(void);

  /**
   * @brief 取得電壓表最大值。
   *
   * @return float 電壓。
   */
  float voltageMax(void);

  /**
   * @brief 設定電壓表最大值。
   *
   * @param value 電壓。
   */
  void voltageMax(float value);

  /**
   * @brief 取得電壓最小值。
   *
   * @return float 電壓。
   */
  float voltageMin(void);

  /**
   * @brief 設定電壓最小值。
   *
   * @param value 電壓。
   */
  void voltageMin(float value);

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B */
