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
#include "Object.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/System.h"
#include "mframe/lang/sys/ErrorCode.h"

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::Object;

//-----------------------------------------------------------------------------
using mframe::lang::System;
using mframe::lang::sys::ErrorCode;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
Object::Object(void) {
  return;
}

//-----------------------------------------------------------------------------
Object::~Object(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */
//-----------------------------------------------------------------------------
void* Object::operator new(size_t n) {
  void* result = ::operator new(n);
  if (result == nullptr)
    System::error("Object new", ErrorCode::INSUFFICIENT_MEMORY);

  return result;
}

//-----------------------------------------------------------------------------
void* Object::operator new(size_t n, void* const p) {
  return p;
}

/* **************************************************************************
 * Public Method <Override> - mframe::lang::Interface
 */
//-----------------------------------------------------------------------------
mframe::lang::Object& Object::getObject(void) {
  return *this;
}

/* ****************************************************************************
 * Public Method
 */
//-----------------------------------------------------------------------------
void Object::delay(int milliseconds) const {
  System::delay(milliseconds);
  return;
}

//-----------------------------------------------------------------------------
bool Object::equals(Object* object) const {
  if (object == nullptr)
    return false;

  return (this->hashcode() == object->hashcode());
}

//-----------------------------------------------------------------------------
bool Object::equals(Object& object) const {
  return (this->hashcode() == object.hashcode());
}

//-----------------------------------------------------------------------------
void Object::wait(void) const {
  System::wait(0);
  return;
}

//-----------------------------------------------------------------------------
bool Object::wait(int timeout) const {
  return System::wait(timeout);
}

//-----------------------------------------------------------------------------
bool Object::yield(void) const {
  return System::yield();
}

//-----------------------------------------------------------------------------
int Object::lock(void) const {
  return System::lock();
}

//-----------------------------------------------------------------------------
int Object::unlock(void) const {
  return System::unlock();
}

//-----------------------------------------------------------------------------
int Object::hashcode(void) const {
  return reinterpret_cast<int>(this);
}

//-----------------------------------------------------------------------------
mframe::lang::sys::Thread* Object::currentThread(void) const {
  return System::currentThread();
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
