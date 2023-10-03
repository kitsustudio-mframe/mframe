/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_9CBF1345_9D97_4C6C_A466_2EF635815DB4
#define MFRAME_9CBF1345_9D97_4C6C_A466_2EF635815DB4

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/ctrl/TemperatureSensor.h"
#include "mframe/lang/Object.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl::virt {
  class VirtualTemperatureSensor;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 溫度計模擬。
 *
 */
class mframe::ctrl::virt::VirtualTemperatureSensor : public mframe::lang::Object,
                                                     public mframe::ctrl::TemperatureSensor {
  /* **************************************************************************
   * Variable
   */
 private:
  float mValue;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Temperature Sensor Simulator object
   *
   */
  VirtualTemperatureSensor(void);

  /**
   * @brief Construct a new Temperature Sensor Simulator object
   *
   * @param value
   */
  VirtualTemperatureSensor(float value);

  /**
   * @brief Destroy the Temperature Sensor Simulator object
   *
   */
  virtual ~VirtualTemperatureSensor(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::ctrl::TemperatureSensor
   */
 public:
  virtual float getCelsius(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 設定溫度。
   *
   * @return float 攝氏溫度。
   */
  virtual float setCelsius(float value);

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

#endif /* MFRAME_9CBF1345_9D97_4C6C_A466_2EF635815DB4 */
