/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F33833E8_A946_4AD2_B467_0E7FD2EE8911
#define MFRAME_F33833E8_A946_4AD2_B467_0E7FD2EE8911

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe\io\OutputStream.h"
#include "mframe\io\ReadBuffer.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class OutputStreamReadBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 輸出串流緩衝區 <Class>
 *
 */
class mframe::io::OutputStreamReadBuffer : public mframe::io::OutputStream,
                                           public mframe::io::ReadBuffer {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Output Stream Buffer object
   *
   */
  OutputStreamReadBuffer(void);

  /**
   * @brief Destroy the Output Stream Buffer object
   *
   */
  virtual ~OutputStreamReadBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<char>
   */
 public:
  virtual bool peekIndex(int index, char& result) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::ReadBuffer
   */
 public:
  virtual bool isEmpty(void) const override;

  virtual int avariable(void) const override;

  virtual int pollByte(char& result, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, int length, bool peek) override;

  virtual int poll(void* buffer, int bufferSize, bool peek) override;

  virtual int skip(int value) override;

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */

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

#endif /* MFRAME_F33833E8_A946_4AD2_B467_0E7FD2EE8911 */
