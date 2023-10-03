/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "Ammeter.h"

//-----------------------------------------------------------------------------
#include "mframe/ctrl/Voltmeter.h"
#include "mframe/hal/AnalogInputPin.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::ctrl::Ammeter;
using mframe::ctrl::Voltmeter;
using mframe::hal::AnalogInputPin;



/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
Ammeter::Ammeter(AnalogInputPin& analogPin, float voltageMin, float voltageMax, float amperDelta) : Voltmeter(analogPin, voltageMin, voltageMax) {
  this->mAmperDelta = amperDelta;
  return;
}

//-----------------------------------------------------------------------------
Ammeter::Ammeter(const Voltmeter& voltmeter, float amperDelta) : Voltmeter(voltmeter) {
  this->mAmperDelta = amperDelta;
  return;
}

//-----------------------------------------------------------------------------
Ammeter::~Ammeter(void) {
  return;
}
/* ****************************************************************************
 * Operator Method
 */



/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
float Ammeter::amper(void) {
  return this->voltage() * this->mAmperDelta;
}

//-----------------------------------------------------------------------------
float Ammeter::amperDelta(void) {
  return this->mAmperDelta;
}

//-----------------------------------------------------------------------------
void Ammeter::amperDelta(float value) {
  this->mAmperDelta = value;
}





/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * End of file
 */
