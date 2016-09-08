// Auto generated C++ code started by symbols/StateMachine.C:473
// Directory: Token protocol

#include "Global.h"
#include "Directory_Controller.h"
#include "Directory_State.h"
#include "Directory_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

#define HASH_FUN(state, event)  ((int(state)*Directory_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (Directory_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (Directory_transitionComment.str(""))

TransitionResult Directory_Controller::doTransition(Directory_Event event, Directory_State state, const Address& addr
)
{
  Directory_State next_state = state;

  DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
  DEBUG_MSG(GENERATED_COMP, MedPrio,*this);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,g_eventQueue_ptr->getTime());
  DEBUG_EXPR(GENERATED_COMP, MedPrio,state);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,event);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,addr);

  TransitionResult result = doTransitionWorker(event, state, next_state, addr);

  if (result == TransitionResult_Valid) {
    DEBUG_EXPR(GENERATED_COMP, MedPrio, next_state);
    DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
    s_profiler.countTransition(state, event);
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("Directory", m_chip_ptr->getID(), m_version, addr, 
        Directory_State_to_string(state), 
        Directory_Event_to_string(event), 
        Directory_State_to_string(next_state), GET_TRANSITION_COMMENT());
    }
    CLEAR_TRANSITION_COMMENT();
    Directory_setState(addr, next_state);
    
  } else if (result == TransitionResult_ResourceStall) {
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("Directory", m_chip_ptr->getID(), m_version, addr, 
        Directory_State_to_string(state), 
        Directory_Event_to_string(event), 
        Directory_State_to_string(next_state), 
        "Resource Stall");
    }
  } else if (result == TransitionResult_ProtocolStall) {
    DEBUG_MSG(GENERATED_COMP,HighPrio,"stalling");
    DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("Directory", m_chip_ptr->getID(), m_version, addr, 
        Directory_State_to_string(state), 
        Directory_Event_to_string(event), 
        Directory_State_to_string(next_state), 
        "Protocol Stall");
    }
  }
  return result;
}

TransitionResult Directory_Controller::doTransitionWorker(Directory_Event event, Directory_State state, Directory_State& next_state, const Address& addr
)
{

  switch(HASH_FUN(state, event)) {
  case HASH_FUN(Directory_State_I, Directory_Event_Fetch):
  {
    if (!(*(m_chip_ptr->m_Directory_memBuffer_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    qf_queueMemoryFetchRequest(addr);
    j_popIncomingRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(Directory_State_I, Directory_Event_Data):
  {
    if (!(*(m_chip_ptr->m_Directory_memBuffer_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    m_writeDataToMemory(addr);
    qw_queueMemoryWBRequest(addr);
    k_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(Directory_State_I, Directory_Event_Memory_Data):
  {
    if (!(*(m_chip_ptr->m_Directory_responseFromDir_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    d_sendData(addr);
    l_popMemQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(Directory_State_I, Directory_Event_Memory_Ack):
  {
    if (!(*(m_chip_ptr->m_Directory_responseFromDir_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    a_sendAck(addr);
    l_popMemQueue(addr);
    return TransitionResult_Valid;
  }
  default:
    WARN_EXPR(m_id);
    WARN_EXPR(m_version);
    WARN_EXPR(g_eventQueue_ptr->getTime());
    WARN_EXPR(addr);
    WARN_EXPR(event);
    WARN_EXPR(state);
    ERROR_MSG("Invalid transition");
  }
  return TransitionResult_Valid;
}
