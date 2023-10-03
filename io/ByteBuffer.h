/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_C76BAF3F_EE1F_46A3_A050_9CD1057055E5
#define MFRAME_C76BAF3F_EE1F_46A3_A050_9CD1057055E5

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/Buffer.h"
#include "mframe/lang/Memory.h"
#include "mframe/lang/Strings.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::io {
  class ByteBuffer;
}  // namespace mframe::io

/* ****************************************************************************
 * Class/Interface/Struct
 */
class mframe::io::ByteBuffer : public mframe::lang::Memory,
                               public mframe::io::Buffer {
  /* **************************************************************************
   *  Variable
   */
 private:
  int mMark;
  int mLimit;
  int mPosition;

  /* **************************************************************************
   *  Abstract Method
   */

  /* **************************************************************************
   *  Construct Method
   */
 public:
  /**
   * @brief Construct a new Byte Buffer object
   *
   * @param memory
   */
  ByteBuffer(const mframe::lang::Memory& memory);

  /**
   * @brief Construct a new Byte Buffer object
   *
   * @param length
   */
  ByteBuffer(int length);

  /**
   * @brief Destroy the Byte Buffer object
   *
   */
  virtual ~ByteBuffer(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param c
   * @return ByteBuffer&
   */
  inline ByteBuffer& operator<<(char c) {
    ByteBuffer::putByte(c);
    return *this;
  }

  /**
   * @brief
   *
   * @param s
   * @return ByteBuffer&
   */
  inline ByteBuffer& operator<<(short s) {
    ByteBuffer::putShort(s);
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return ByteBuffer&
   */
  inline ByteBuffer& operator<<(int v) {
    ByteBuffer::putInt(v);
    return *this;
  }

  /**
   * @brief
   *
   * @param string
   * @return ByteBuffer&
   */
  inline ByteBuffer& operator<<(const char* string) {
    ByteBuffer::put(string);
    return *this;
  }

  /**
   * @brief
   *
   * @param string
   * @return ByteBuffer&
   */
  inline ByteBuffer& operator<<(mframe::lang::Strings& string) {
    ByteBuffer::put(string);
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return int
   */
  inline int operator=(int v) {
    ByteBuffer::position(v);
    return ByteBuffer::position();
  }

  /**
   * @brief
   *
   * @param shift
   */
  inline void operator+=(int shift) {
    ByteBuffer::position(ByteBuffer::position() + shift);
  }

  /**
   * @brief
   *
   * @param shift
   */
  inline void operator-=(int shift) {
    ByteBuffer::position(ByteBuffer::position() - shift);
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline unsigned int operator++(void) {
    ByteBuffer::position(ByteBuffer::position() + 1);
    return static_cast<unsigned int>(ByteBuffer::position());
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline unsigned int operator--(void) {
    ByteBuffer::position(ByteBuffer::position() - 1);
    return static_cast<unsigned int>(ByteBuffer::position());
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline unsigned int operator++(int) {
    unsigned int result = static_cast<unsigned int>(ByteBuffer::position());
    ByteBuffer::position(ByteBuffer::position() + 1);
    return result;
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline unsigned int operator--(int) {
    unsigned int result = static_cast<unsigned int>(ByteBuffer::position());
    ByteBuffer::position(ByteBuffer::position() - 1);
    return result;
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Memory
   */
 public:
  virtual int indexOf(char ch, int offset) const override;

  virtual int indexOfData(const void* destination, int destinationLen, int start) const override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Iterable<char>
   */
 public:
  virtual bool peekIndex(int index, char& result) override;

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Buffer
   */
 public:
  virtual inline void flush(void) override {
    ByteBuffer::mPosition = 0;
    ByteBuffer::mMark = 0;
    ByteBuffer::mLimit = static_cast<uint16_t>(ByteBuffer::length());
    return;
  }

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::ReadBuffer
   */
 public:
  virtual inline bool isEmpty(void) const override {
    return (ByteBuffer::mPosition >= ByteBuffer::mLimit);
  }

  virtual inline int avariable(void) const override {
    return (ByteBuffer::mLimit - ByteBuffer::mPosition);
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
    return (ByteBuffer::mPosition >= ByteBuffer::mLimit);
  }

  virtual inline int remaining(void) const override {
    return (ByteBuffer::mLimit - ByteBuffer::mPosition);
  }

  virtual int putByte(const char result) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer) override;

  virtual int put(mframe::io::ReadBuffer& readBuffer, int length) override;

  virtual int put(const void* buffer, int bufferSize) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return unsigned int
   */
  inline int limit(void) const {
    return ByteBuffer::mLimit;
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline int capacity(void) const {
    return ByteBuffer::length();
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline int position(void) const {
    return ByteBuffer::mPosition;
  }

  /**
   * @brief
   *
   */
  inline void reset(void) {
    ByteBuffer::position(ByteBuffer::mMark);
    return;
  }

  /**
   * @brief
   *
   */
  inline void mark(void) {
    ByteBuffer::mMark = mPosition;
    return;
  }

  /**
   * @brief
   *
   */
  inline void rewind(void) {
    ByteBuffer::mPosition = 0;
    ByteBuffer::mMark = 0;
    return;
  }

  /**
   * @brief Get the Byte object
   *
   * @param result
   * @return true
   * @return false
   */
  inline bool pollByte(uint8_t& result) {
    return this->pollByte(reinterpret_cast<char&>(result), false);
  }

  /**
   * @brief Get the Short object
   *
   * @param result
   * @return true
   * @return false
   */
  inline bool pollShort(uint16_t& result) {
    return ByteBuffer::pollShort(reinterpret_cast<short&>(result));
  }

  /**
   * @brief Get the Short Msb object
   *
   * @param result
   * @return true
   * @return false
   */
  inline bool pollShortMsb(uint16_t& result) {
    return ByteBuffer::pollShortMsb(reinterpret_cast<short&>(result));
  }

  /**
   * @brief Get the Int object
   *
   * @param result
   * @return true
   * @return false
   */
  inline bool pollInt(unsigned int& result) {
    return ByteBuffer::pollInt(reinterpret_cast<int&>(result));
  }

  /**
   * @brief Get the Int Msb object
   *
   * @param result
   * @return true
   * @return false
   */
  inline bool pollIntMsb(unsigned int& result) {
    return ByteBuffer::pollIntMsb(reinterpret_cast<int&>(result));
  }

  /**
   * @brief
   *
   * @param newLimit
   * @return true
   * @return false
   */
  bool limit(int newLimit);

  /**
   * @brief
   *
   * @param newPosition
   * @return true
   * @return false
   */
  bool position(int newPosition);

  /**
   * @brief
   *
   */
  void flip(void);

  /**
   * @brief
   *
   * @param string
   * @return true
   * @return false
   */
  bool put(const char* string);

  /**
   * @brief
   *
   * @param string
   * @return true
   * @return false
   */
  bool put(const mframe::lang::Strings& string);

  /**
   * @brief
   *
   * @param format
   * @param ...
   * @return int
   */
  int putFormat(const char* format, ...);

  /**
   * @brief
   *
   * @param format
   * @param args
   * @return int
   */
  int putFormat(const char* format, va_list args);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putShort(const short value);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putShortMsb(const short value);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putInt(const int value);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putFloat(const float value);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putFloatMsb(const float value);

  /**
   * @brief
   *
   * @param value
   * @return true
   * @return false
   */
  bool putIntMsb(const int value);

  /**
   * @brief Get the Short object
   *
   * @param result
   * @return true
   * @return false
   */
  bool pollShort(short& result);

  /**
   * @brief Get the Short Msb object
   *
   * @param result
   * @return true
   * @return false
   */
  bool pollShortMsb(short& result);

  /**
   * @brief Get the Int object
   *
   * @param result
   * @return true
   * @return false
   */
  bool pollInt(int& result);

  /**
   * @brief Get the Int Msb object
   *
   * @param result
   * @return true
   * @return false
   */
  bool pollIntMsb(int& result);

  /**
   * @brief Get the Float object
   *
   * @param result
   * @return true
   * @return false
   */
  bool pollFloat(float& result);

  /**
   * @brief
   *
   */
  bool pollFloatMsb(float& result);

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
 *    End of file
 */

#endif /* MFRAME_C76BAF3F_EE1F_46A3_A050_9CD1057055E5 */
