/** \file L2Cache_Entry.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L2Cache_Entry_H
#define L2Cache_Entry_H

#include "Global.h"
#include "Allocator.h"
#include "L2Cache_State.h"
#include "NetDest.h"
#include "MachineID.h"
#include "DataBlock.h"
#include "AbstractCacheEntry.h"
class L2Cache_Entry :  public AbstractCacheEntry {
public:
  L2Cache_Entry() 
  : AbstractCacheEntry()
  {
    m_CacheState = L2Cache_State_NP; // default value of L2Cache_State
    // m_Sharers has no default
    // m_Exclusive has no default
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
  }
  ~L2Cache_Entry() { };
  L2Cache_Entry(const L2Cache_State& local_CacheState, const NetDest& local_Sharers, const MachineID& local_Exclusive, const DataBlock& local_DataBlk, const bool& local_Dirty)
  : AbstractCacheEntry()
  {
    m_CacheState = local_CacheState;
    m_Sharers = local_Sharers;
    m_Exclusive = local_Exclusive;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for CacheState field.
  * \return CacheState field
  */
  const L2Cache_State& getCacheState() const { return m_CacheState; }
/** \brief Const accessor method for Sharers field.
  * \return Sharers field
  */
  const NetDest& getSharers() const { return m_Sharers; }
/** \brief Const accessor method for Exclusive field.
  * \return Exclusive field
  */
  const MachineID& getExclusive() const { return m_Exclusive; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for CacheState field.
  * \return CacheState field
  */
  L2Cache_State& getCacheState() { return m_CacheState; }
/** \brief Non-const accessor method for Sharers field.
  * \return Sharers field
  */
  NetDest& getSharers() { return m_Sharers; }
/** \brief Non-const accessor method for Exclusive field.
  * \return Exclusive field
  */
  MachineID& getExclusive() { return m_Exclusive; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }

  // Mutator methods for each field
/** \brief Mutator method for CacheState field */
  void setCacheState(const L2Cache_State& local_CacheState) { m_CacheState = local_CacheState; }
/** \brief Mutator method for Sharers field */
  void setSharers(const NetDest& local_Sharers) { m_Sharers = local_Sharers; }
/** \brief Mutator method for Exclusive field */
  void setExclusive(const MachineID& local_Exclusive) { m_Exclusive = local_Exclusive; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }

  void print(ostream& out) const;
//private:
  L2Cache_State m_CacheState; /**< cache state*/
  NetDest m_Sharers; /**< tracks the L1 shares on-chip*/
  MachineID m_Exclusive; /**< Exclusive holder of block*/
  DataBlock m_DataBlk; /**< data for the block*/
  bool m_Dirty; /**< data is dirty*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L2Cache_Entry& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L2Cache_Entry& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L2Cache_Entry_H
