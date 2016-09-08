/** \file Directory.C
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:327
  * Created by slicc definition of Module "Token protocol"
  */

#include "Global.h"
#include "RubySlicc_includes.h"
#include "Directory_Controller.h"
#include "Directory_State.h"
#include "Directory_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

stringstream Directory_transitionComment;
#define APPEND_TRANSITION_COMMENT(str) (Directory_transitionComment << str)
/** \brief static profiler defn */
Directory_Profiler Directory_Controller::s_profiler;

/** \brief constructor */
Directory_Controller::Directory_Controller(Chip* chip_ptr, int version)
{
  m_chip_ptr = chip_ptr;
  m_id = m_chip_ptr->getID();
  m_version = version;
  m_machineID.type = MachineType_Directory;
  m_machineID.num = m_id*RubyConfig::numberOfDirectoryPerChip()+m_version;
  (*(m_chip_ptr->m_Directory_requestToDir_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_Directory_responseToDir_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_Directory_memBuffer_vec[m_version])).setConsumer(this);

  (*(m_chip_ptr->m_Directory_requestToDir_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", Directory, requestNetwork_in]");
  (*(m_chip_ptr->m_Directory_responseToDir_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", Directory, responseNetwork_in]");
  (*(m_chip_ptr->m_Directory_memBuffer_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", Directory, memQueue_in]");

  s_profiler.possibleTransition(Directory_State_I, Directory_Event_Fetch);
  s_profiler.possibleTransition(Directory_State_I, Directory_Event_Data);
  s_profiler.possibleTransition(Directory_State_I, Directory_Event_Memory_Data);
  s_profiler.possibleTransition(Directory_State_I, Directory_Event_Memory_Ack);
}

void Directory_Controller::print(ostream& out) const { out << "[Directory_Controller " << m_chip_ptr->getID() << " " << m_version << "]"; }

// Actions

/** \brief Send ack to L2*/
void Directory_Controller::a_sendAck(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    MemoryMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<MemoryMsg*>(((*(m_chip_ptr->m_Directory_memBuffer_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_MEMORY_ACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      ((*(m_chip_ptr->m_Directory_responseFromDir_vec[m_version]))).enqueue(out_msg, 1);
    }
  }
}

/** \brief Send data to requestor*/
void Directory_Controller::d_sendData(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    MemoryMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<MemoryMsg*>(((*(m_chip_ptr->m_Directory_memBuffer_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_MEMORY_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
      (out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
      (out_msg).m_Dirty = (false);
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      ((*(m_chip_ptr->m_Directory_responseFromDir_vec[m_version]))).enqueue(out_msg, 1);
    }
  }
}

/** \brief Pop incoming request queue*/
void Directory_Controller::j_popIncomingRequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).dequeue());
}

/** \brief Pop incoming request queue*/
void Directory_Controller::k_popIncomingResponseQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_Directory_responseToDir_vec[m_version]))).dequeue());
}

/** \brief Pop off-chip request queue*/
void Directory_Controller::l_popMemQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_Directory_memBuffer_vec[m_version]))).dequeue());
}

/** \brief Queue off-chip fetch request*/
void Directory_Controller::qf_queueMemoryFetchRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      MemoryMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = MemoryRequestType_MEMORY_READ;
      (out_msg).m_Sender = m_machineID;
      (out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
      (out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
      (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_DataBlk;
      DEBUG_SLICC(MedPrio, ":221: ", out_msg);
;
      ((*(m_chip_ptr->m_Directory_memBuffer_vec[m_version]))).enqueue(out_msg, 1);
    }
  }
}

/** \brief Queue off-chip writeback request*/
void Directory_Controller::qw_queueMemoryWBRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_Directory_responseToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      MemoryMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = MemoryRequestType_MEMORY_WB;
      (out_msg).m_Sender = m_machineID;
      (out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Sender;
      (out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
      (out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
      DEBUG_SLICC(MedPrio, ":237: ", out_msg);
;
      ((*(m_chip_ptr->m_Directory_memBuffer_vec[m_version]))).enqueue(out_msg, 1);
    }
  }
}

/** \brief Write dirty writeback to memory*/
void Directory_Controller::m_writeDataToMemory(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_Directory_responseToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    DEBUG_SLICC(MedPrio, ":245: ", ((*in_msg_ptr)).m_Address);
;
    DEBUG_SLICC(MedPrio, ":246: ", ((*in_msg_ptr)).m_DataBlk);
;
  }
}

