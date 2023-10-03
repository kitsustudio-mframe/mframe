/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_191BC7E7_9B06_42F9_A2A6_564525AECDC8
#define MFRAME_191BC7E7_9B06_42F9_A2A6_564525AECDC8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/WriteBuffer.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class StreamSkipper;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::io::StreamSkipper : public mframe::lang::Object,
                                  public mframe::io::WriteBuffer {
  /* **************************************************************************
   * Variable
   */

 private:
  int mPosition;
  int mCapacity;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Stream Skipper object
   *
   */
  StreamSkipper(void);

  /**
   * @brief Destroy the Stream Skipper object
   *
   */
  virtual ~StreamSkipper(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   *
   */
  inline int operator=(int v) {
    this->position(v);
    return this->position();
  }

  /**
   *
   */
  inline void operator+=(int shift) {
    this->position(this->position() + shift);
  }

  /**
   *
   */
  inline void operator-=(int shift) {
    this->position(this->position() - shift);
  }

  /**
   *
   */
  inline unsigned int operator++(void) {
    this->position(this->position() + 1);
    return static_cast<unsigned int>(this->position());
  }

  /**
   *
   */
  inline unsigned int operator--(void) {
    this->position(this->position() - 1);
    return static_cast<unsigned int>(this->position());
  }

  /**
   *
   */
  inline unsigned int operator++(int) {
    unsigned int result = static_cast<unsigned int>(this->position());
    this->position(this->position() + 1);
    return result;
  }

  /**
   *
   */
  inline unsigned int operator--(int) {
    unsigned int result = static_cast<unsigned int>(this->position());
    this->position(this->position() - 1);
    return result;
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::InputBuffer
   */
 public:
  inline virtual bool isFull(void) const override {
    return (this->mPosition >= this->mCapacity);
  }

  inline virtual int remaining(void) const override {
    return (this->mCapacity - this->mPosition);
  }

  virtual int putByte(const char data) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer, int length) override;

  virtual int put(const void* buffer, int length) override;

  /* **************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   *
   * @param v
   */
  inline void position(int v) {
    if (v < 0)
      v abstract;

    if (v > this->mCapacity)
      v = this->mCapacity;

    this->mPosition = v;
    return;
  }

  /**
   * @brief
   *
   * @return int
   */
  inline int position(void) {
    return this->mPosition;
  }

  /**
   * @brief
   *
   * @param v
   */
  inline void capacity(int v) {
    if (v < 0)
      v abstract;

    if (this->mPosition > v)
      this->mPosition = v;

    this->mCapacity = v;
    return;
  }

  /**
   * @brief
   *
   * @return int
   */
  inline int capacity(void) {
    return this->mCapacity;
  }

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

#endif /* MFRAME_191BC7E7_9B06_42F9_A2A6_564525AECDC8 */
