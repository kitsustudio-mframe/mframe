/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69
#define MFRAME_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe\lang\Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl {
  struct TemperatureSensor;
}

/**
 * @brief [Interface]抽象介面，溫度計。
 *
 */
/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::ctrl::TemperatureSensor : public virtual mframe::lang::Interface {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief Get the Celsius object
   *
   * @return float
   */
  virtual float getCelsius(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69 */
