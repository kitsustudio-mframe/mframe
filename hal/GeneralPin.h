/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164
#define MFRAME_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "./../hal/GeneralInput.h"
#include "./../hal/GeneralOutput.h"
#include "./../hal/GeneralPinMode.h"

/* ****************************************************************************
 * Namespace
 */

namespace mframe::hal {
  struct GeneralPin;
}

/* ****************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief [Interface]硬體抽象層，通用引腳輸入輸出。
 *
 */
struct mframe::hal::GeneralPin : public mframe::hal::GeneralOutput,
                                 public mframe::hal::GeneralInput {
  /* **************************************************************************
   * Method
   */

  /**
   * @brief 取得引腳工作模式。
   *
   * @return mframe::hal::GeneralPinMode
   * - GeneralPinMode::PUSH_PULL 推輓輸出
   * - GeneralPinMode::PULL_UP 引腳上拉
   * - GeneralPinMode::PULL_DOWN 引腳下拉
   * - GeneralPinMode::OPEN_DRAIN 開路模式
   */
  virtual mframe::hal::GeneralPinMode getPinMode(void) abstract;

  /**
   * @brief 設定引腳工作模式。
   *
   * @param mode 工作模式，該參數可以是以下值之一：
   * - GeneralPinMode::PUSH_PULL 推輓輸出
   * - GeneralPinMode::PULL_UP 引腳上拉
   * - GeneralPinMode::PULL_DOWN 引腳下拉
   * - GeneralPinMode::OPEN_DRAIN 開路模式
   *
   * @return mframe::hal::GeneralPinMode
   * - GeneralPinMode::PUSH_PULL 推輓輸出
   * - GeneralPinMode::PULL_UP 引腳上拉
   * - GeneralPinMode::PULL_DOWN 引腳下拉
   * - GeneralPinMode::OPEN_DRAIN 開路模式
   */
  virtual mframe::hal::GeneralPinMode setPinMode(mframe::hal::GeneralPinMode mode) abstract;

  /**
   * @brief 取得引腳的輸出輸入方向。
   *
   * @return true 輸出。
   * @return false 輸入。
   */
  virtual bool getDir(void) abstract;

  /**
   * @brief 設定引腳的輸出輸入方向。
   *
   * @param dir 設定方向。該參數可以是以下值之一：
   * - true 設定為輸出。
   * - false 設定為輸入。
   */
  virtual void setDir(bool dir) abstract;

  /**
   * @brief 設定引腳模式為輸入。
   *
   */
  virtual void setInput(void) abstract;

  /**
   * @brief 設定引腳模式為輸出。
   *
   */
  virtual void setOutput(void) abstract;
};

/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164 */
