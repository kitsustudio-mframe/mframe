/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B
#define UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/util/CommandHandler.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  class CommandHandlerEvent;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::util::CommandHandlerEvent : public mframe::lang::Object,
                                          public mframe::util::CommandHandler {
  /* **************************************************************************
   * Variable
   */
 private:
  bool (*mFunc)(CommandExecutor& executor);
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
   * @brief Construct a new Command Handler Event object
   *
   * @param func
   * @param command 指令
   * @param descirption 指令描述
   */
  CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command, const char* descirption);

  /**
   * @brief Construct a new Command Handler Event object
   *
   * @param func
   * @param command 指令
   */
  CommandHandlerEvent(bool (*func)(CommandExecutor& executor), const char* command);

  /**
   * @brief Destroy the Command Handler Event object
   *
   */
  virtual ~CommandHandlerEvent(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::util::CommandHandler
   */
 public:
  virtual const char* getDescription(void) override;

  virtual const char* getCommand(void) override;

  virtual bool onCommand(CommandExecutor& executor) override;
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

#endif /* UTIL_91741AE6_8AB5_4802_A30F_52D738500D9B */
