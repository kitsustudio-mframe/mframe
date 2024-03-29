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
#include "SerialPort.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::ctrl::SerialPort;

//-----------------------------------------------------------------------------
using mframe::io::InputStream;
using mframe::io::OutputStream;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
SerialPort::SerialPort(mframe::hal::Uart& base) : mBase(base),
                                                  mSerialPortInputStream(base),
                                                  mSerialPortOutputStream(base) {
  return;
}

//-----------------------------------------------------------------------------
SerialPort::~SerialPort(void) {
  this->close();
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::Closeable
 */

//-----------------------------------------------------------------------------
void SerialPort::close(void) {
  this->mBase.deinit();
  return;
}

//-----------------------------------------------------------------------------
bool SerialPort::isOpen(void) {
  return this->mBase.isInit();
}

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
bool SerialPort::open(void) {
  return this->mBase.init();
}

//-----------------------------------------------------------------------------
uint32_t SerialPort::setBaudrate(uint32_t baudrate) {
  return this->mBase.setBaudrate(baudrate);
}

//-----------------------------------------------------------------------------
uint32_t SerialPort::getBaudrate(void) {
  return this->mBase.getBaudrate();
}

//-----------------------------------------------------------------------------
OutputStream& SerialPort::getOutputStream(void) {
  return this->mSerialPortOutputStream;
}

//-----------------------------------------------------------------------------
InputStream& SerialPort::getInputStream(void) {
  return this->mSerialPortInputStream;
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
