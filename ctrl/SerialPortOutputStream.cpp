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
#include "SerialPortOutputStream.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::ctrl::SerialPortOutputStream;

//-----------------------------------------------------------------------------



/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
SerialPortOutputStream::SerialPortOutputStream(mframe::hal::Uart& base) : mBase(base) {
  this->mBase.setUartEventTransfer(this);
  return;
}

//-----------------------------------------------------------------------------
SerialPortOutputStream::~SerialPortOutputStream(void) {
  this->mBase.beginTransfer(false);
  this->mBase.setUartEventTransfer(nullptr);
  this->abortWrite();
  return;
}

/* ****************************************************************************
 * Operator Method
 */



/* ****************************************************************************
 * Public Method <Override> - mframe::hal::UartEventTransfer
 */

//-----------------------------------------------------------------------------
bool SerialPortOutputStream::onUartTransfer(uint8_t& data) {
  if (this->mReadBuffer == nullptr)
    return false;

  int result = this->mReadBuffer->pollByte(reinterpret_cast<char&>(data), false);

  if (result >= 0) {
    ++this->mResult;
    return true;

  } else {
    this->execute();
    return false;
  }
}

/* ****************************************************************************
 * Public Method
 */





//-----------------------------------------------------------------------------
void SerialPortOutputStream::onWriteEvent(void) {
  this->mBase.beginTransfer(true);
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
