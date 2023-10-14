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
#include "SerialPortInputStream.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */
using mframe::ctrl::SerialPortInputStream;

//-----------------------------------------------------------------------------



/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
SerialPortInputStream::SerialPortInputStream(mframe::hal::usart::Uart& base) : mBase(base) {
  this->mBase.setUartEventReceiver(this);
  return;
}

//-----------------------------------------------------------------------------
SerialPortInputStream::~SerialPortInputStream(void) {
  this->mBase.beginReceiver(false);
  this->mBase.setUartEventReceiver(nullptr);
  this->abortRead();
  return;
}

/* ****************************************************************************
 * Operator Method
 */



/* ****************************************************************************
 * Public Method <Override>
 */

//-----------------------------------------------------------------------------
bool SerialPortInputStream::onUartReceiver(const uint8_t data) {
  if (this->mWriteBuffer == nullptr)
    return false;

  int result = this->mWriteBuffer->putByte(reinterpret_cast<const char&>(data));

  if (result >= 0)
    ++this->mResult;

  if (result <= 0) {
    this->execute();
    return false;

  } else {
    return true;
  }
}

/* ****************************************************************************
 * Public Method
 */





//-----------------------------------------------------------------------------
void SerialPortInputStream::onReadEvent(void) {
  this->mBase.beginReceiver(true);
  return;
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
