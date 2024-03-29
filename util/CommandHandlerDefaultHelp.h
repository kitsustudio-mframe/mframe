/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171
#define UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Object.h"
#include "mframe/util/CommandHandler.h"
#include "mframe/util/Iterator.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  class CommandHandlerDefaultHelp;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::util::CommandHandlerDefaultHelp : public mframe::lang::Object,
                                                public mframe::util::CommandHandler {
  /* **************************************************************************
   * Variable
   */
 private:
  mframe::util::Iterator<CommandHandler*> mCommandIterator;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Command Handler Default Help object
   *
   * @param commandIterator
   */
  CommandHandlerDefaultHelp(const mframe::util::Iterator<CommandHandler*>& commandIterator);

  /**
   * @brief Destroy the Command Handler Default Help object
   *
   */
  virtual ~CommandHandlerDefaultHelp(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
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
 public:
  static const char* TEXT_COMMAND;
  static const char* TEXT_DESCRIPTION;

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* UTIL_80396FB1_BC61_4C99_A388_F1ECB0AC5171 */
