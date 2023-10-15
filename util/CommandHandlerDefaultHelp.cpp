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
#include "CommandHandlerDefaultHelp.h"

//-----------------------------------------------------------------------------
#include "mframe/util/CommandExecutor.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------
using mframe::util::CommandHandlerDefaultHelp;

//-----------------------------------------------------------------------------

const char* CommandHandlerDefaultHelp::TEXT_COMMAND = "help";
const char* CommandHandlerDefaultHelp::TEXT_DESCRIPTION = "show all command description.";

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
CommandHandlerDefaultHelp::CommandHandlerDefaultHelp(const Iterator<CommandHandler*>& commandIterator) : mCommandIterator(commandIterator) {
  return;
}

//-----------------------------------------------------------------------------
CommandHandlerDefaultHelp::~CommandHandlerDefaultHelp(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override> - mframe::util::CommandHandler
 */
//-----------------------------------------------------------------------------
const char* CommandHandlerDefaultHelp::getDescription(void) {
  return CommandHandlerDefaultHelp::TEXT_DESCRIPTION;
}

//-----------------------------------------------------------------------------
const char* CommandHandlerDefaultHelp::getCommand(void) {
  return CommandHandlerDefaultHelp::TEXT_COMMAND;
}

//-----------------------------------------------------------------------------
bool CommandHandlerDefaultHelp::onCommand(CommandExecutor& executor) {
  executor.in().skipNextLine();
  executor.out() << "Help list:\r\n";
  this->mCommandIterator.reset();

  CommandHandler* c = nullptr;
  while (this->mCommandIterator.next(c)) {
    executor.out() << "  " << c->getCommand() << " - " << c->getDescription() << "\r\n";
  }

  return true;
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
