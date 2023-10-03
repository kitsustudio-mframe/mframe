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
#include "CommandHandlerEvent.h"

//-----------------------------------------------------------------------------
#include "mframe/lang/System.h"
#include "mframe/lang/sys/ErrorCode.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::util::CommandHandlerEvent;

//-----------------------------------------------------------------------------
using mframe::lang::System;
using mframe::lang::sys::ErrorCode;

/* ****************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------
CommandHandlerEvent::CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command, const char* descirption) {
  if (func == nullptr)
    System::error(this, ErrorCode::NULL_POINTER);

  this->mCommand = command;
  this->mDescription = descirption;
  this->mFunc = func;
}

//-----------------------------------------------------------------------------
CommandHandlerEvent::CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command) : CommandHandlerEvent(func, command, "do description.") {
  return;
}

//-----------------------------------------------------------------------------
CommandHandlerEvent::~CommandHandlerEvent(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

const char* CommandHandlerEvent::getDescription(void) {
  return this->mDescription;
}

//-----------------------------------------------------------------------------
const char* CommandHandlerEvent::getCommand(void) {
  return this->mCommand;
}

//-----------------------------------------------------------------------------
bool CommandHandlerEvent::onCommand(CommandExecutor& executor) {
  return this->mFunc(executor);
}

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

/* ****************************************************************************
 * End of file
 */
