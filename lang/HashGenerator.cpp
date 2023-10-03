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
#include "HashGenerator.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/Character.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::lang::HashGenerator;

//-----------------------------------------------------------------------------
using mframe::lang::Character;

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
HashGenerator::HashGenerator(void) {
  return;
}

//-----------------------------------------------------------------------------
HashGenerator::~HashGenerator(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */

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
//-----------------------------------------------------------------------------
int HashGenerator::getHashcode(const void* src, int len) {
  int result = 0;
  for (int i = 0; i < len; ++i)
    result = 31 * result + reinterpret_cast<const unsigned char*>(src)[i];

  return result;
}

//-----------------------------------------------------------------------------
int HashGenerator::getHashcode(const char* src) {
  int result = 0;
  for (int i = 0; src[i] != 0; ++i)
    result = 31 * result + reinterpret_cast<const unsigned char*>(src)[i];

  return result;
}

//-----------------------------------------------------------------------------
int HashGenerator::getHashcodeUpperCast(const char* src) {
  int result = 0;
  char c;
  for (int i = 0; src[i] != 0; ++i) {
    c = Character::toUpperCase(src[i]);
    result = 31 * result + static_cast<const unsigned char>(c);
  }

  return result;
}

//-----------------------------------------------------------------------------
int HashGenerator::getHashcodeLowerCast(const char* src) {
  int result = 0;
  char c;
  for (int i = 0; src[i] != 0; ++i) {
    c = Character::toLowerCase(src[i]);
    result = 31 * result + static_cast<const unsigned char>(c);
  }

  return result;
}

/* ****************************************************************************
 * End of file
 */
