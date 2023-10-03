/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE
#define MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include "mframe/lang/Interface.h"

/* ****************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Object;
  namespace sys {
    class Thread;
  }  // namespace sys
}  // namespace mframe::lang

/* ****************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::Object : virtual public mframe::lang::Interface {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract Method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Object object
   *
   */
  Object(void);

  /**
   * @brief Destroy the Object object
   *
   */
  virtual ~Object(void) override;

  /* **************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param n
   * @return void*
   */
  void* operator new(size_t n);

  /**
   * @brief
   *
   * @param n
   * @param p
   * @return void*
   */
  void* operator new(size_t n, void* p);

  /* **************************************************************************
   * Public Method <Override> - mframe::lang::Interface
   */
 public:
  mframe::lang::Object& getObject(void) override;

  /* **************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   * 函數 delay 等待內核滴答中指定的時間段。 對於1的值，系統等待直到下一個計時器滴答發生。
   * 實際時間延遲最多可能比指定時間少一個計時器滴答聲，即在下一個系統滴答聲發生之前立即調用
   * osDelay(1)，線程會立即重新安排。
   *
   *
   * @param milliseconds - time ticks value
   */
  void delay(int milliseconds) const;

  /**
   * @brief
   * 函數 delay 等待內核滴答中指定的時間段。 對於1的值，系統等待直到下一個計時器滴答發生。
   * 實際時間延遲最多可能比指定時間少一個計時器滴答聲，即在下一個系統滴答聲發生之前立即調用
   * osDelay(1)，線程會立即重新安排。
   *
   * equals方法在非空對象引用上實現等價關係：
   *
   *  - 自反性：對於任何非空的參考值 x ， x.equals(x)應該返回 true 。
   *  - 它是對稱的：對於任何非空引用值x和y，x.equals(y)應該返回true當且僅當 y.equals(x)回報 true 。
   *  - 傳遞性：對於任何非空引用值x，y和z，如果x.equals(y)回報true個y.equals(z)回報true，然後x.equals(z)應該返回true 。
   *  - 它是一致的：對於任何非空引用值x和y，多次調用 x.equals(y)始終返回true或始終返回false，沒有設置中使用的信息 equals比較上的對像被修改。
   *  - 對於任何非空的參考值x，x.equals(null)應該返回 false 。
   *
   *
   * 該 equals類方法 Object實現對像上差別可能性最大的相等關係;
   * 也就是說，對於任何非空的參考值x和y，當且僅當 x和 y引用相同的對象（ x == y具有值 true ）時，該方法返回 true 。
   *
   * 請注意，無論何時覆蓋該方法，通常需要覆蓋 hashCode方法，以便維護 hashCode方法的通用合同，該方法規定相等的對象必須具有相等的哈希碼。
   *
   * @param object - 與之比較的參考對象，指標型態。
   * @return true - 如果此對象與object參數相同。
   * @return false - 如果此對象與object參數不相同。
   */
  bool equals(Object* object) const;

  /**
   * @brief
   * 函數 delay 等待內核滴答中指定的時間段。 對於1的值，系統等待直到下一個計時器滴答發生。
   * 實際時間延遲最多可能比指定時間少一個計時器滴答聲，即在下一個系統滴答聲發生之前立即調用
   * osDelay(1)，線程會立即重新安排。
   *
   * equals方法在非空對象引用上實現等價關係：
   *
   *  - 自反性：對於任何非空的參考值 x ， x.equals(x)應該返回 true 。
   *  - 它是對稱的：對於任何非空引用值x和y，x.equals(y)應該返回true當且僅當 y.equals(x)回報 true 。
   *  - 傳遞性：對於任何非空引用值x，y和z，如果x.equals(y)回報true個y.equals(z)回報true，然後x.equals(z)應該返回true 。
   *  - 它是一致的：對於任何非空引用值x和y，多次調用 x.equals(y)始終返回true或始終返回false，沒有設置中使用的信息 equals比較上的對像被修改。
   *  - 對於任何非空的參考值x，x.equals(null)應該返回 false 。
   *
   *
   * 該 equals類方法 Object實現對像上差別可能性最大的相等關係;
   * 也就是說，對於任何非空的參考值x和y，當且僅當 x和 y引用相同的對象（ x == y具有值 true ）時，該方法返回 true 。
   *
   * 請注意，無論何時覆蓋該方法，通常需要覆蓋 hashCode方法，以便維護 hashCode方法的通用合同，該方法規定相等的對象必須具有相等的哈希碼。
   *
   * @param object - 與之比較的參考對象，參考型態。
   * @return true - 如果此對象與object參數相同。
   * @return false - 如果此對象與object參數不相同。
   */
  bool equals(Object& object) const;

  /**
   * @brief
   * 導致當前線程等待，直到另一個線程調用此對象的 notify()方法或 notifyAll()方法，或其他一些線程中斷當前線程，或一定量的實時時間。
   *
   * 這種方法類似於一個參數的 wait方法，但它允許對放棄之前等待通知的時間進行更精細的控制。 以納秒為單位的實時數量由下式給出：
   *
   * 1000000*超時+納米
   *
   * 在所有其他方面，該方法與一個參數的方法 wait(long)相同。 特別是， wait(0, 0)意味著同樣的事情 wait(0) 。
   *
   * 當前的線程必須擁有該對象的顯示器。 線程釋放此監視器的所有權，並等待直到發生以下兩種情況之一：
   *
   *
   * - 另一個線程通知等待該對象的監視器的線程通過調用 notify方法或 notifyAll方法來喚醒。
   * - timeout毫秒加 nanos納秒參數指定的超時時間已過。
   *
   *
   * 然後線程等待，直到它可以重新獲得監視器的所有權並恢復執行。
   *
   * 像在一個參數版本中，中斷和虛假喚醒是可能的，並且該方法應該始終在循環中使用：
   *
   *
   * ```CPP
   * while(<condition does not hold>){
   *   this->wait(timeout);
   *   ... // Perform action appropriate to condition
   * }
   * ```
   *
   * @param timeout - 以毫秒為單位等待的最長時間。
   *
   *
   * @return true
   *  - 執行含式成功並且已被notify
   *  - 已經到達timeout時間
   *
   * @return false
   *  - 如果超時值為負值或是值不在0-999999範圍內。
   *  - 無法在中斷時被呼叫。
   */
  void wait(void) const;

  /**
   * @brief
   * 導致當前線程等待，直到另一個線程調用此對象的notify()方法或notifyAll()方法，或指定的時間已過。
   *
   *
   * 當前的線程必須擁有該對象的顯示器。
   *
   *
   * 此方法使當前線程（稱為T ）將其放置在該對象的等待集中，然後放棄對該對象的任何和所有同步聲明。
   * 線程T變得禁用線程調度目的，並且休眠，直到發生四件事情之一：
   *
   *
   *   - 一些其他線程調用該對象的notify方法，並且線程T恰好被任意選擇為被喚醒的線程。
   *   - 某些其他線程調用此對象的notifyAll方法。
   *   - 一些其他線程interrupts線程T。
   *
   *
   * 然後從該對象的等待集中刪除線程T ，並重新啟用線程調度。然後它以通常的方式與其他線程競爭在對像上進行同步的權限;
   * 一旦獲得了對象的控制，其對對象的所有同步聲明就恢復到現狀 - 也就是在調用wait方法之後的情況。
   * 線程T然後從調用wait方法返回。因此，從返回wait方法，對象和線程的同步狀態T正是因為它是當wait被調用的方法。
   *
   *
   * 線程也可以喚醒，而不會被通知，中斷或超時，即所謂的虛假喚醒 。雖然這在實踐中很少會發生，
   * 但應用程序必須通過測試應該使線程被喚醒的條件來防範，並且如果條件不滿足則繼續等待。
   * 換句話說，等待應該總是出現在循環中，就像這樣：
   *
   *
   * ```CPP
   * while(<condition does not hold>){
   *   this->wait();
   *   ... // Perform action appropriate to condition
   * }
   * ```
   *
   *
   * @return true:
   *  - 執行含式成功並且已被notify
   *
   *
   * @return false:
   *  - 無法在中斷時被呼叫。
   */
  bool wait(int timeout) const;

  /**
   * @brief
   * 函數yield()將控制權傳遞給處於READY狀態且具有相同優先級的下一個線程。
   * 如果在READY狀態下沒有其他優先級相同的線程，則當前線程繼續執行，不會發生線程切換。
   *
   *
   * 函數yield()不會將線程設置為BLOCKED狀態。 因此，即使處於READY狀態的線程可用，也不會調度優先級較低的線程。
   *
   *
   * @return true
   *  - 成功發生線程切換
   *
   *
   * @return false
   *  - 無發生現程切換，可能無相同優先級需求
   *  - 無法在中斷時被呼叫。
   */
  bool yield(void) const;

  /**
   * @brief 核心鎖定，在調用systemUnlock以前將不會進行執行緒切換
   *
   * @return int lock調用層數
   */
  int lock(void) const;

  /**
   * @brief
   *
   * @return int lock調用剩餘層數，當值為0時核心解鎖，開始執行緒切換
   */
  int unlock(void) const;

  /**
   * @brief 取得當前的執行緒
   *
   * @return null 執行緒取得失敗，可能正在執行中斷事件或是系統並未啟動
   * @return Thread 當前執行緒
   */
  mframe::lang::sys::Thread* currentThread(void) const;

  /**
   * @brief 返回對象的哈希碼值。支持這種方法是為了散列表，如HashMap提供的那樣。
   *
   * @return uint32_t 該對象的哈希碼值。
   */
  virtual int hashcode(void) const;

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
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */
};

using mframe::lang::Object;
/* ****************************************************************************
 * End of file
 */

#endif /* MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE */
