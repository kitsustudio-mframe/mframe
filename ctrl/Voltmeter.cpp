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
#include "Voltmeter.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::ctrl::Voltmeter;

//-----------------------------------------------------------------------------
using mframe::hal::AnalogInputPin;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
Voltmeter::Voltmeter(AnalogInputPin& analogPin, float voltageMin, float voltageMax) : mAnalogPin(analogPin) {
  this->mVoltageMin = voltageMin;
  this->mVoltageMax = voltageMax;
  this->mVoltageDelta = (voltageMax - voltageMin) / static_cast<float>(analogPin.getConvertLevel());
  return;
}

//-----------------------------------------------------------------------------
Voltmeter::~Voltmeter(void) {
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
float Voltmeter::voltage(void) {
  float result = this->mVoltageDelta * static_cast<float>(this->mAnalogPin.read());
  return (result + this->mVoltageMin);
}

//-----------------------------------------------------------------------------
float Voltmeter::voltageMax(void) {
  return this->mVoltageMax;
}

//-----------------------------------------------------------------------------
void Voltmeter::voltageMax(float value) {
  this->mVoltageMax = value;
  this->mVoltageDelta = (this->mVoltageMax - this->mVoltageMin) / static_cast<float>(this->mAnalogPin.getConvertLevel());
}

//-----------------------------------------------------------------------------
float Voltmeter::voltageMin(void) {
  return this->mVoltageMin;
}

//-----------------------------------------------------------------------------
void Voltmeter::voltageMin(float value) {
  this->mVoltageMin = value;
  this->mVoltageDelta = (this->mVoltageMax - this->mVoltageMin) / static_cast<float>(this->mAnalogPin.getConvertLevel());
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
