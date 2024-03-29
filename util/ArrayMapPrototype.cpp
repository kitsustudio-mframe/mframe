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
#include "mframe/util/ArrayMapPrototype.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/Class.h"

/* ****************************************************************************
 * Namespace
 */
typedef struct {
  int key;
  void* value;
} array_map_prototype_t;
/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::util::ArrayMapPrototype;

//-----------------------------------------------------------------------------
using mframe::lang::Class;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
ArrayMapPrototype::ArrayMapPrototype(const mframe::lang::Memory& memory) : mMemory(memory) {
  this->mMemory.wipe();
  this->mSize = 0;
  return;
}

ArrayMapPrototype::ArrayMapPrototype(int size) : mMemory(size * 8) {
  this->mMemory.wipe();
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------
ArrayMapPrototype::~ArrayMapPrototype(void) {
  return;
}
/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::Iterable<E>
 */
//-----------------------------------------------------------------------------
bool ArrayMapPrototype::peekIndex(int index, void*& result) {
  if (index < 0)
    return false;

  if (index >= this->size())
    return false;

  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());
  result = static_cast<void*>(p[index].value);
  return true;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::lang::Collection<E>
 */

//-----------------------------------------------------------------------------
void ArrayMapPrototype::clear(void) {
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------
bool ArrayMapPrototype::isEmpty(void) const {
  if (this->mSize)
    return false;

  return true;
}

//-----------------------------------------------------------------------------
int ArrayMapPrototype::size(void) const {
  return this->mSize;
}

/* ****************************************************************************
 * Public Method <Override> - mframe::util::Map<V>
 */

//-----------------------------------------------------------------------------
bool ArrayMapPrototype::prototypeContainsKey(Interface& key) const {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());
  int hashcode = key.getObject().hashcode();

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key) {
      if (p[i].key == hashcode)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------
bool ArrayMapPrototype::prototypeContainsValue(void* value) const {
  if (value == nullptr)
    return false;

  int len = this->size();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key) {
      if (p[i].value == value)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------
void* ArrayMapPrototype::prototypeGet(Interface& key) const {
  int hashcode = key.getObject().hashcode();
  int len = this->size();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key == hashcode) {
      return static_cast<void**>(p[i].value);
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------
void* ArrayMapPrototype::prototypePut(Interface& key, void* value) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;
      p[i].value = value;

      return static_cast<void**>(result);
    }
  }

  if (this->mSize >= this->length()) {  // over length
    bool status = this->mMemory.resize(8 + static_cast<int>(this->mMemory.length() * 1.5));
    if (!status)
      return value;
  }

  p[this->mSize].key = hashcode;
  p[this->mSize].value = value;

  ++this->mSize;
  return nullptr;
}

//-----------------------------------------------------------------------------
void* ArrayMapPrototype::prototypeRemove(Interface& key) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;

      p[i] = p[this->mSize - 1];
      this->mSize--;

      return result;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------
void* ArrayMapPrototype::prototypeReplace(Interface& key, void* value) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;
      p[i].value = value;

      return result;
    }
  }

  return nullptr;
}

/* ****************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------
int ArrayMapPrototype::length(void) const {
  return (this->mMemory.length() / 8);
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
