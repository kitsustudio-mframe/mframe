/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F3E849F4_8586_4E91_A6EA_D93B8BD6D448
#define MFRAME_F3E849F4_8586_4E91_A6EA_D93B8BD6D448

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/hal/Uart.h"
#include "mframe/io/OutputStream.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl {
  class SerialPortOutputStream;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 序列埠輸出串流。
 *
 */
class mframe::ctrl::SerialPortOutputStream : public mframe::io::OutputStream,
                                             public mframe::hal::usart::UartEventTransfer {
  /* **************************************************************************
   * Variable
   */

 private:
  mframe::hal::usart::Uart& mBase;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Serial Port Output Stream object
   *
   * @param base
   */
  SerialPortOutputStream(mframe::hal::usart::Uart& base);

  /**
   * @brief Destroy the Serial Port Output Stream object
   *
   */
  virtual ~SerialPortOutputStream(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::usart::UartEventTransfer
   */
 public:
  virtual bool onUartTransfer(uint8_t& data) override;

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */
 protected:
  virtual void onWriteEvent(void) override;

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

#endif /* MFRAME_F3E849F4_8586_4E91_A6EA_D93B8BD6D448 */
