/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_BA359EBF_505B_445E_8A31_2AB82A22FEB8
#define MFRAME_BA359EBF_505B_445E_8A31_2AB82A22FEB8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/Buffer.h"
#include "mframe/lang/Memory.h"

/* ****************************************************************************
 * Macro
 */

#pragma push_macro("VACCESS")
#ifdef VACCESS
#undef VACCESS
#endif
#define VACCESS(type, target) (*static_cast<volatile type*>(&target))

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class RingBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct
 */
class mframe::io::RingBuffer : public mframe::lang::Memory,
                               public mframe::io::Buffer {
  /* **************************************************************************
   * Variable
   */

 private:
  volatile uint32_t mCount;
  volatile uint32_t mHead;
  volatile uint32_t mTail;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param memory
   */
  RingBuffer(const mframe::lang::Memory& memory);

  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param length
   */
  RingBuffer(int length);

  /**
   * @brief Destroy the Ring Buffer object
   *
   */
  virtual ~RingBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Buffer
   */
 public:
  /**
   * @brief
   *
   */
  virtual inline void flush(void) override {
    RingBuffer::mHead = RingBuffer::mTail = 0;
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<char>
   */
 public:
  virtual bool peekIndex(int index, char& result) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::io::ReadBuffer
   */
 public:
  virtual inline bool isEmpty(void) const override {
    return (this->mHead == this->mTail);
  }

  virtual inline int avariable(void) const override {
    return static_cast<int>(this->mHead - this->mTail);
  }

  virtual int pollByte(char& result, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, bool peek) override;

  virtual int poll(mframe::io::WriteBuffer& writeBuffer, int length, bool peek) override;

  virtual int poll(void* buffer, int bufferSize, bool peek) override;

  virtual int skip(int value) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::WriteBuffer
   */
 public:
  virtual inline bool isFull(void) const override {
    return (RingBuffer::avariable() >= static_cast<int>(RingBuffer::mCount));
  }

  virtual inline int remaining(void) const override {
    return (static_cast<int>(RingBuffer::mCount) - RingBuffer::avariable());
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
   * @brief Return size the ring buffer.
   *
   * @return int Size of the ring buffer in bytes.
   */
  inline int getSize(void) {
    return static_cast<int>(RingBuffer::mCount);
  }

  /**
   * @brief Get the Head Position object
   *
   * @return int
   */
  inline int getHeadPosition(void) {
    return static_cast<int>((this->mHead & (RingBuffer::mCount - 1)));
  }

  /**
   * @brief Get the Tail Position object
   *
   * @return int
   */
  inline int getTailPosition(void) {
    return static_cast<int>((this->mTail & (RingBuffer::mCount - 1)));
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
 private:
  void init(void);

  int pollMult(mframe::io::WriteBuffer* writeBuffer, void* buffer, int length, bool isPeek);

  int putMult(mframe::io::ReadBuffer* readBuffer, const void* buffer, int length);

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
#pragma pop_macro("VACCESS")
#endif /* MFRAME_BA359EBF_505B_445E_8A31_2AB82A22FEB8 */
