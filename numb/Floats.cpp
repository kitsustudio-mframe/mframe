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
#include "Floats.h"

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
using mframe::numb::Floats;

//-----------------------------------------------------------------------------
using mframe::lang::Character;

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
const int Floats::MAX_ASCII_VALUE = 40;
const float Floats::MAX_VALUE = 3.40282E+038f;
const float Floats::MIN_VALUE = 1.17549E-038f;

/* ****************************************************************************
 * Static Method
 */
//-----------------------------------------------------------------------------
bool Floats::isFloat(mframe::util::Iterator<char>& iterator) {
  char cache[Floats::MAX_ASCII_VALUE];
  for (int i = 0; i < Floats::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Floats::isFloat(cache);
}

//-----------------------------------------------------------------------------
bool Floats::isFloat(const char* str) {
  if (str == nullptr)
    return false;

  if (!(MACRO_IS_NUMB(str[0]) || (str[0] == '-')))
    return false;

  int i = 1;
  int point = 0;

  for (; i < Floats::MAX_ASCII_VALUE; ++i) {
    if (str[i] == '.')
      ++point;

    else if (!MACRO_IS_NUMB(str[i]))
      break;
  }

  if(point > 1)
    return false;
    
  return Character::isNextSymbol(str[i]);
}

//-----------------------------------------------------------------------------
bool Floats::parseFloat(float& result, mframe::util::Iterator<char>& iterator) {
  char cache[Floats::MAX_ASCII_VALUE];
  for (int i = 0; i < Floats::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Floats::parseFloat(result, cache);
}

//-----------------------------------------------------------------------------
bool Floats::parseFloat(float& result, const char* str) {
  if (!Floats::isFloat(str))
    return false;

  result = strtof(str, nullptr);
  return true;
}

/* ****************************************************************************
 * End of file
 */
