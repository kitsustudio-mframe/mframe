/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE
#define UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/util/CommandHandler.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  template <class C>
  class CommandHandlerMethod;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C>
class mframe::util::CommandHandlerMethod : public mframe::func::FunctionMethod<C, CommandExecutor&, bool>,
                                           public mframe::util::CommandHandler {
  /* **************************************************************************
   * Variable
   */
 private:
  const char* mCommand;
  const char* mDescription;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Command Handler Method object
   *
   * @param c
   * @param method
   * @param command
   * @param description
   */
  CommandHandlerMethod(C& c,
                       bool (C::*method)(CommandExecutor&),
                       const char* command,
                       const char* description) : mframe::func::FunctionMethod<C, CommandExecutor&, bool>(c, method) {
    this->mDescription = description;
    this->mCommand = command;
    return;
  }

  /**
   * @brief Construct a new Command Handler Method object
   *
   * @param c
   * @param method
   * @param command
   */
  CommandHandlerMethod(C& c,
                       bool (C::*method)(CommandExecutor&),
                       const char* command) : CommandHandlerMethod(c, method, command, "no description.") {
    return;
  }

  /**
   * @brief Destroy the Command Handler Method object
   *
   */
  virtual ~CommandHandlerMethod(void) override {
    return;
  }

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */
 public:
  virtual const char* getDescription(void) override {
    return this->mDescription;
  }

  virtual const char* getCommand(void) override {
    return this->mCommand;
  }

  virtual bool onCommand(CommandExecutor& executor) override {
    return this->apply(executor);
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

#endif /* UTIL_725C70AC_977E_4B0D_B01D_89AD302D24CE */
