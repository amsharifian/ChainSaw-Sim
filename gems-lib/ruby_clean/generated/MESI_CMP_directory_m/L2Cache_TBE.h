/** \file L2Cache_TBE.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L2Cache_TBE_H
#define L2Cache_TBE_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "L2Cache_State.h"
#include "DataBlock.h"
#include "NetDest.h"
#include "MachineID.h"
class L2Cache_TBE {
public:
  L2Cache_TBE() 
  {
    // m_Address has no default
    m_TBEState = L2Cache_State_NP; // default value of L2Cache_State
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    // m_L1_GetS_IDs has no default
    // m_L1_GetX_ID has no default
    m_isPrefetch = false; // default value of bool
    m_pendingAcks = 0; // default value of int
  }
  ~L2Cache_TBE() { };
  L2Cache_TBE(const Address& local_Address, const L2Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const NetDest& local_L1_GetS_IDs, const MachineID& local_L1_GetX_ID, const bool& local_isPrefetch, const int& local_pendingAcks)
  {
    m_Address = local_Address;
    m_TBEState = local_TBEState;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_L1_GetS_IDs = local_L1_GetS_IDs;
    m_L1_GetX_ID = local_L1_GetX_ID;
    m_isPrefetch = local_isPrefetch;
    m_pendingAcks = local_pendingAcks;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for TBEState field.
  * \return TBEState field
  */
  const L2Cache_State& getTBEState() const { return m_TBEState; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for L1_GetS_IDs field.
  * \return L1_GetS_IDs field
  */
  const NetDest& getL1_GetS_IDs() const { return m_L1_GetS_IDs; }
/** \brief Const accessor method for L1_GetX_ID field.
  * \return L1_GetX_ID field
  */
  const MachineID& getL1_GetX_ID() const { return m_L1_GetX_ID; }
/** \brief Const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  const bool& getisPrefetch() const { return m_isPrefetch; }
/** \brief Const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  const int& getpendingAcks() const { return m_pendingAcks; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for TBEState field.
  * \return TBEState field
  */
  L2Cache_State& getTBEState() { return m_TBEState; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for L1_GetS_IDs field.
  * \return L1_GetS_IDs field
  */
  NetDest& getL1_GetS_IDs() { return m_L1_GetS_IDs; }
/** \brief Non-const accessor method for L1_GetX_ID field.
  * \return L1_GetX_ID field
  */
  MachineID& getL1_GetX_ID() { return m_L1_GetX_ID; }
/** \brief Non-const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  bool& getisPrefetch() { return m_isPrefetch; }
/** \brief Non-const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  int& getpendingAcks() { return m_pendingAcks; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for TBEState field */
  void setTBEState(const L2Cache_State& local_TBEState) { m_TBEState = local_TBEState; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for L1_GetS_IDs field */
  void setL1_GetS_IDs(const NetDest& local_L1_GetS_IDs) { m_L1_GetS_IDs = local_L1_GetS_IDs; }
/** \brief Mutator method for L1_GetX_ID field */
  void setL1_GetX_ID(const MachineID& local_L1_GetX_ID) { m_L1_GetX_ID = local_L1_GetX_ID; }
/** \brief Mutator method for isPrefetch field */
  void setisPrefetch(const bool& local_isPrefetch) { m_isPrefetch = local_isPrefetch; }
/** \brief Mutator method for pendingAcks field */
  void setpendingAcks(const int& local_pendingAcks) { m_pendingAcks = local_pendingAcks; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Physical address for this TBE*/
  L2Cache_State m_TBEState; /**< Transient state*/
  DataBlock m_DataBlk; /**< Buffer for the data block*/
  bool m_Dirty; /**< Data is Dirty*/
  NetDest m_L1_GetS_IDs; /**< Set of the internal processors that want the block in shared state*/
  MachineID m_L1_GetX_ID; /**< ID of the L1 cache to forward the block to once we get a response*/
  bool m_isPrefetch; /**< Set if this was caused by a prefetch*/
  int m_pendingAcks; /**< number of pending acks for invalidates during writeback*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L2Cache_TBE& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L2Cache_TBE& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L2Cache_TBE_H
