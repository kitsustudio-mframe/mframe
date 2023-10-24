/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */
#include <stdlib.h>

//-----------------------------------------------------------------------------
#include "Integers.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/Character.h"
#include "mframe/util/Iterator.h"

/* ****************************************************************************
 * Macro
 */
#define MACRO_IS_NUMB(c) ((c >= '0') && (c <= '9'))

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::numb::Integers;

//-----------------------------------------------------------------------------
using mframe::lang::Character;
using mframe::util::Iterator;

/* ****************************************************************************
 * Abstract Method
 */

/* ****************************************************************************
 * Construct Method
 */

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
const char* Integers::TEXT_MAX_VALUE = "2147483647";
const char* Integers::TEXT_MIN_VALUE = "-2147483648";
const int Integers::MAX_ASCII_VALUE = static_cast<int>(sizeof("-2147483648"));

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
bool Integers::isInteger(mframe::util::Iterator<char>& iterator) {
  char cache[Integers::MAX_ASCII_VALUE];
  for (int i = 0; i < Integers::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Integers::isInteger(cache);
}

//-----------------------------------------------------------------------------
bool Integers::isInteger(const char* str) {
  if (str == nullptr)
    return false;

  int i = 1;

  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    i = 2;
    for (; i < Integers::MAX_ASCII_VALUE; ++i) {
      if (str[i] >= '0' && str[i] <= '9')
        continue;

      if (str[i] >= 'a' && str[i] <= 'f')
        continue;

      if (str[i] >= 'A' && str[i] <= 'F')
        continue;

      break;
    }

  } else if (str[0] == '0') {
    for (; i < Integers::MAX_ASCII_VALUE; ++i) {
      if (str[i] >= '0' && str[i] <= '7')
        continue;

      break;
    }

  } else {
    if(str[0] == '-')
      i = 1;

    for (; i < Integers::MAX_ASCII_VALUE; ++i) {
      if (str[i] >= '0' && str[i] <= '9')
        continue;

      break;
    }
  }

  return Character::isNextSymbol(str[i]);
}

//-----------------------------------------------------------------------------
bool Integers::parseInteger(int& result, mframe::util::Iterator<char>& iterator) {
  char cache[Integers::MAX_ASCII_VALUE];
  for (int i = 0; i < Integers::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Integers::parseInteger(result, cache);
}

//-----------------------------------------------------------------------------
bool Integers::parseInteger(int& result, const char* str) {
  if (!Integers::isInteger(str))
    return false;

  result = strtol(str, nullptr, 0);
  return true;
}

/* ****************************************************************************
 * End of file
 */
