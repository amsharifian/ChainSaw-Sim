/** \file RequestMsg.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef RequestMsg_H
#define RequestMsg_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "CoherenceRequestType.h"
#include "AccessModeType.h"
#include "MachineID.h"
#include "NetDest.h"
#include "MessageSizeType.h"
#include "DataBlock.h"
#include "PrefetchBit.h"
#include "NetworkMessage.h"
class RequestMsg :  public NetworkMessage {
public:
  RequestMsg() 
  : NetworkMessage()
  {
    // m_Address has no default
    m_Type = CoherenceRequestType_NUM; // default value of CoherenceRequestType
    m_AccessMode = AccessModeType_UserMode; // default value of AccessModeType
    // m_Requestor has no default
    // m_Destination has no default
    m_MessageSize = MessageSizeType_Undefined; // default value of MessageSizeType
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    m_Prefetch = PrefetchBit_No; // default value of PrefetchBit
  }
  ~RequestMsg() { };
  RequestMsg(const Address& local_Address, const CoherenceRequestType& local_Type, const AccessModeType& local_AccessMode, const MachineID& local_Requestor, const NetDest& local_Destination, const MessageSizeType& local_MessageSize, const DataBlock& local_DataBlk, const bool& local_Dirty, const PrefetchBit& local_Prefetch)
  : NetworkMessage()
  {
    m_Address = local_Address;
    m_Type = local_Type;
    m_AccessMode = local_AccessMode;
    m_Requestor = local_Requestor;
    m_Destination = local_Destination;
    m_MessageSize = local_MessageSize;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_Prefetch = local_Prefetch;
  }
  Message* clone() const { checkAllocator(); return s_allocator_ptr->allocate(*this); }
  void destroy() { checkAllocator(); s_allocator_ptr->deallocate(this); }
  static Allocator<RequestMsg>* s_allocator_ptr;
  static void checkAllocator() { if (s_allocator_ptr == NULL) { s_allocator_ptr = new Allocator<RequestMsg>; }}
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for Type field.
  * \return Type field
  */
  const CoherenceRequestType& getType() const { return m_Type; }
/** \brief Const accessor method for AccessMode field.
  * \return AccessMode field
  */
  const AccessModeType& getAccessMode() const { return m_AccessMode; }
/** \brief Const accessor method for Requestor field.
  * \return Requestor field
  */
  const MachineID& getRequestor() const { return m_Requestor; }
/** \brief Const accessor method for Destination field.
  * \return Destination field
  */
  const NetDest& getDestination() const { return m_Destination; }
/** \brief Const accessor method for MessageSize field.
  * \return MessageSize field
  */
  const MessageSizeType& getMessageSize() const { return m_MessageSize; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for Prefetch field.
  * \return Prefetch field
  */
  const PrefetchBit& getPrefetch() const { return m_Prefetch; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for Type field.
  * \return Type field
  */
  CoherenceRequestType& getType() { return m_Type; }
/** \brief Non-const accessor method for AccessMode field.
  * \return AccessMode field
  */
  AccessModeType& getAccessMode() { return m_AccessMode; }
/** \brief Non-const accessor method for Requestor field.
  * \return Requestor field
  */
  MachineID& getRequestor() { return m_Requestor; }
/** \brief Non-const accessor method for Destination field.
  * \return Destination field
  */
  NetDest& getDestination() { return m_Destination; }
/** \brief Non-const accessor method for MessageSize field.
  * \return MessageSize field
  */
  MessageSizeType& getMessageSize() { return m_MessageSize; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for Prefetch field.
  * \return Prefetch field
  */
  PrefetchBit& getPrefetch() { return m_Prefetch; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for Type field */
  void setType(const CoherenceRequestType& local_Type) { m_Type = local_Type; }
/** \brief Mutator method for AccessMode field */
  void setAccessMode(const AccessModeType& local_AccessMode) { m_AccessMode = local_AccessMode; }
/** \brief Mutator method for Requestor field */
  void setRequestor(const MachineID& local_Requestor) { m_Requestor = local_Requestor; }
/** \brief Mutator method for Destination field */
  void setDestination(const NetDest& local_Destination) { m_Destination = local_Destination; }
/** \brief Mutator method for MessageSize field */
  void setMessageSize(const MessageSizeType& local_MessageSize) { m_MessageSize = local_MessageSize; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for Prefetch field */
  void setPrefetch(const PrefetchBit& local_Prefetch) { m_Prefetch = local_Prefetch; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Physical address for this request*/
  CoherenceRequestType m_Type; /**< Type of request (GetS, GetX, PutX, etc)*/
  AccessModeType m_AccessMode; /**< user/supervisor access type*/
  MachineID m_Requestor; /**< What component request*/
  NetDest m_Destination; /**< What components receive the request, includes MachineType and num*/
  MessageSizeType m_MessageSize; /**< size category of the message*/
  DataBlock m_DataBlk; /**< Data for the cache line (if PUTX)*/
  bool m_Dirty; /**< Dirty bit*/
  PrefetchBit m_Prefetch; /**< Is this a prefetch request*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const RequestMsg& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const RequestMsg& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // RequestMsg_H
