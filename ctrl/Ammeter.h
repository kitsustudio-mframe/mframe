/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_9791505C_A013_4AE8_9EF4_F082A616F700
#define MFRAME_9791505C_A013_4AE8_9EF4_F082A616F700

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/ctrl/Voltmeter.h"
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl {
  class Ammeter;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 電流表。
 *
 */
class mframe::ctrl::Ammeter : public mframe::ctrl::Voltmeter {
  /* **************************************************************************
   * Variable
   */

 private:
  float mAmperDelta;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Ammeter object
   *
   * @param analogPin 類比輸入引腳。
   * @param voltageMin 電壓下限。
   * @param voltageMax 電壓上限。
   * @param amperDelta 每伏特對應的電流比。
   */
  Ammeter(mframe::hal::AnalogInputPin& analogPin, float voltageMin, float voltageMax, float amperDelta);

  /**
   * @brief Construct a new Ammeter object
   *
   * @param voltmeter 電壓表。
   * @param amperDelta 每伏特對應的電流比。
   */
  Ammeter(const mframe::ctrl::Voltmeter& voltmeter, float amperDelta);

  /**
   * @brief Destroy the Ammeter object
   *
   */
  virtual ~Ammeter(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 取得電流。
   *
   * @return float 電流值。
   */
  float amper(void);

  /**
   * @brief 取得電壓對電流的比例。
   *
   * @return float 每伏特對應的電流比。
   */
  float amperDelta(void);

  /**
   * @brief 設定電壓對電流的比例。
   *
   * @param value 每伏特對應的電流比。
   */
  void amperDelta(float value);

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

#endif /* MFRAME_9791505C_A013_4AE8_9EF4_F082A616F700 */
