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
#include "VirtualGeneralPin.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::ctrl::virt::VirtualGeneralPin;

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
VirtualGeneralPin::VirtualGeneralPin(void) {
  this->mDir = 0;
  this->mValue = 0;
  this->mGeneralPinMode = mframe::hal::GeneralPinMode::PUSH_PULL;
  return;
}

//-----------------------------------------------------------------------------
VirtualGeneralPin::~VirtualGeneralPin(void) {
  this->mDir = 0;
  this->mValue = 0;
  this->mGeneralPinMode = mframe::hal::GeneralPinMode::PUSH_PULL;
  return;
}
/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

//-----------------------------------------------------------------------------
bool VirtualGeneralPin::getDir(void) {
  return this->mDir;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setDir(bool dir) {
  this->mDir = dir;
}

//-----------------------------------------------------------------------------
mframe::hal::GeneralPinMode VirtualGeneralPin::getPinMode(void) {
  return this->mGeneralPinMode;
}

//-----------------------------------------------------------------------------
mframe::hal::GeneralPinMode VirtualGeneralPin::setPinMode(mframe::hal::GeneralPinMode mode) {
  this->mGeneralPinMode = mode;
  return this->mGeneralPinMode;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setHigh(void) {
  this->setValue(true);
  return;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setInput(void) {
  this->setDir(false);
  return;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setLow(void) {
  this->setValue(false);
  return;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setOutput(void) {
  this->setDir(true);
  return;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setToggle(void) {
  if (this->getDir() == false)
    return;

  this->setValue(!this->getValue());
  return;
}

//-----------------------------------------------------------------------------
bool VirtualGeneralPin::getValue(void) {
  return this->mValue;
}

//-----------------------------------------------------------------------------
void VirtualGeneralPin::setValue(bool level) {
  if (this->getDir() == false)
    return;

  this->mValue = getValue();
  return;
}

/* ****************************************************************************
 * Public Method
 */

/**
 * @brief Set the Input Value object
 *
 * @param level
 * @return true
 * @return false
 */
bool VirtualGeneralPin::setInputValue(bool level) {
  if (this->getDir() == true)
    return false;

  this->mValue = level;
  return true;
}

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * Static Variable
 */

/* ****************************************************************************
 * Static Method
 */

/* ****************************************************************************
 * End of file
 */
