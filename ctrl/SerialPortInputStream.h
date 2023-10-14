/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_DB068A0B_C322_4F94_95C6_77512B353910
#define MFRAME_DB068A0B_C322_4F94_95C6_77512B353910

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/hal/Uart.h"
#include "mframe/io/InputStream.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::ctrl {
  class SerialPortInputStream;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 序列埠輸入串流。
 *
 */
class mframe::ctrl::SerialPortInputStream : public mframe::io::InputStream,
                                            public mframe::hal::usart::UartEventReceiver {
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
   * @brief Construct a new Serial Port Input Stream object
   *
   * @param base
   */
  SerialPortInputStream(mframe::hal::usart::Uart& base);

  /**
   * @brief Destroy the Serial Port Input Stream object
   *
   */
  virtual ~SerialPortInputStream(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::hal::usart::UartEventReceiver
   */
 public:
  virtual bool onUartReceiver(const uint8_t data) override;

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method <Override> - mframe::lang::InputStream
   */
 protected:
  virtual void onReadEvent(void) override;

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

#endif /* MFRAME_DB068A0B_C322_4F94_95C6_77512B353910 */
