/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7
#define UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/io/PrintBuffer.h"
#include "mframe/lang/Executor.h"
#include "mframe/lang/Strings.h"
#include "mframe/util/ArrayMap.h"
#include "mframe/util/CommandHandler.h"
#include "mframe/util/CommandHandlerDefaultHelp.h"
#include "mframe/util/Scanner.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::util {
  class CommandExecutor;
}  // namespace mframe::util

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::util::CommandExecutor : public mframe::lang::Object,
                                      public mframe::lang::Executor {

 private:
  ArrayMap<mframe::lang::Object, CommandHandler> mCommandMap;
  CommandHandlerDefaultHelp mCommandHandlerDefaultHelp;
  mframe::lang::Strings mBuffer;
  mframe::util::Scanner mInput;
  mframe::io::PrintBuffer& mOutput;

  CommandHandler* mCommandHandler;
  const char* mHostname;
  void* mAttachment;
  char mSplitCharacter;
  bool mPause;
  bool mResult;
  bool mAutoNextLine;

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Command Executor object
   *
   * @param mapSize 指令地圖的預設大小
   * @param commandSize 支援最大的指令長度
   * @param output 輸出
   * @param input 輸入
   */
  CommandExecutor(int mapSize, int commandSize, mframe::io::PrintBuffer& output, mframe::io::ReadBuffer& input);

  /**
   * @brief Destroy the Command Executor object
   *
   */
  virtual ~CommandExecutor(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Executor
   */
 public:
  virtual void execute(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 取得使用者參數
   *
   * @tparam T 類型
   * @param cast 轉換類型，請使用Class<T>::cast()
   * @return T* 返回類型
   */
  template <class T>
  inline T* getAttachment(const T* cast) const {
    return static_cast<T*>(this->mAttachment);
  }

  /**
   * @brief 設定使用者參數
   *
   * @param attachment
   */
  inline CommandExecutor& setAttachment(void* attachment) {
    this->mAttachment = attachment;
    return *this;
  }

  /**
   * @brief Get the Auto Next Line object
   * 
   * @return true 
   * @return false 
   */
  inline bool getAutoNextLine(void){
    return this->mAutoNextLine;
  }

  /**
   * @brief Set the Auto Next Line object
   * 
   * @param enable 
   * @return CommandExecutor& 
   */
  inline CommandExecutor& setAutoNextLine(bool enable){
    this->mAutoNextLine = enable;
    return *this;
  }

  /**
   * @brief 取得分割字元
   *
   * @return char
   */
  inline char getSplitCharacter(void) {
    return this->mSplitCharacter;
  }

  /**
   * @brief
   *
   * @param enable
   */
  inline void pause(bool enable) {
    this->mPause = enable;
    return;
  }

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  inline bool pause(void) {
    return this->mPause;
  }

  /**
   * @brief Get the Last Command Result object
   *
   * @return true
   * @return false
   */
  inline bool getLastCommandResult(void) {
    return this->mResult;
  }

  /**
   * @brief 取得輸出串流
   *
   * @return mframe::io::PrintBuffer&
   */
  virtual mframe::io::PrintBuffer& out(void);

  /**
   * @brief 取得輸入串流
   *
   * @return mframe::io::ReadBuffer&
   */
  virtual mframe::util::Scanner& in(void);

  /**
   * @brief 新增指令
   *
   * @param command 指令
   * @param commandHandler 指令執行程序
   * @return true 成功新增指令
   * @return false 新增指令失敗，指令已存在
   */
  virtual bool put(CommandHandler& commandHandler);

  /**
   * @brief 取得指令
   *
   * @param command 指令
   * @return CommandHandler*
   *  - nullptr 指令未找到
   *  - other 指令執行程序
   */
  virtual CommandHandler* get(const char* command);

  /**
   * @brief 移除指令
   *
   * @param command 指令
   * @return true 成功找到指令並移除
   * @return false 尚未找到指令
   */
  virtual bool remove(const char* command);

  /**
   * @brief Get the Buffer object
   *
   * @return Strings&
   */
  virtual mframe::lang::Strings& getBuffer(void);

  /**
   * @brief Set the Hostname object
   *
   * @param hostname
   */
  virtual void setHostname(const char* hostname);

  /**
   * @brief Get the Hostname object
   *
   * @return const char*
   */
  virtual const char* getHostname(void);

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
  static const char* TEXT_UNKNOWN_COMMAND;

  /* **************************************************************************
   * Static Method
   */
};

/* ****************************************************************************
 * End of file
 */

#endif /* UTIL_5D93A9A6_BCB1_43C0_B93F_8EEABFA4B2E7 */
