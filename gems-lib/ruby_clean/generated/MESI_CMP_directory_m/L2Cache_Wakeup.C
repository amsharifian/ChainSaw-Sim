// Auto generated C++ code started by symbols/StateMachine.C:425
// L2Cache: MOSI Directory L2 Cache CMP

#include "Global.h"
#include "RubySlicc_includes.h"
#include "L2Cache_Controller.h"
#include "L2Cache_State.h"
#include "L2Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

void L2Cache_Controller::wakeup()
{

int counter = 0;
  while (true) {
    // Some cases will put us into an infinite loop without this limit
    assert(counter <= RubyConfig::L2CacheTransitionsPerCycle());
    if (counter == RubyConfig::L2CacheTransitionsPerCycle()) {
      g_system_ptr->getProfiler()->controllerBusy(m_machineID); // Count how often we're fully utilized
      g_eventQueue_ptr->scheduleEvent(this, 1); // Wakeup in another cycle and try again
      break;
    }
    // L2CacheInPort L1unblockNetwork_in
      if ((((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).isReady())) {
        {
          ResponseMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
                    if (ASSERT_FLAG && !(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
            cerr << "Runtime Error at :305, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_EXCLUSIVE_UNBLOCK)) {
                        {
              Address addr = ((*in_msg_ptr)).m_Address;
              TransitionResult result = doTransition(L2Cache_Event_Exclusive_Unblock, L2Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_UNBLOCK)) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L2Cache_Event_Unblock, L2Cache_getState(addr), addr);
                if (result == TransitionResult_Valid) {
                  counter++;
                  continue; // Check the first port again
                }
                if (result == TransitionResult_ResourceStall) {
                  g_eventQueue_ptr->scheduleEvent(this, 1);
                  // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                }
              }
;
            } else {
                            cerr << "Runtime Error at :311, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("unknown unblock message") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
            }
          }
        }
      }

    // L2CacheInPort responseIntraChipL2Network_in
      if ((((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).isReady())) {
        {
          ResponseMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
                    if (ASSERT_FLAG && !(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
            cerr << "Runtime Error at :322, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if (((machineIDToMachineType(((*in_msg_ptr)).m_Sender)) == MachineType_L1Cache)) {
            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
              if (((*in_msg_ptr)).m_Dirty) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L2Cache_Event_WB_Data, L2Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              } else {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L2Cache_Event_WB_Data_clean, L2Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              }
            } else {
              if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_ACK)) {
                if (((((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
                    TransitionResult result = doTransition(L2Cache_Event_Ack_all, L2Cache_getState(addr), addr);
                    if (result == TransitionResult_Valid) {
                      counter++;
                      continue; // Check the first port again
                    }
                    if (result == TransitionResult_ResourceStall) {
                      g_eventQueue_ptr->scheduleEvent(this, 1);
                      // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                    }
                  }
;
                } else {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
                    TransitionResult result = doTransition(L2Cache_Event_Ack, L2Cache_getState(addr), addr);
                    if (result == TransitionResult_Valid) {
                      counter++;
                      continue; // Check the first port again
                    }
                    if (result == TransitionResult_ResourceStall) {
                      g_eventQueue_ptr->scheduleEvent(this, 1);
                      // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                    }
                  }
;
                }
              } else {
                                cerr << "Runtime Error at :337, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("unknown message type") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
              }
            }
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_MEMORY_DATA)) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L2Cache_Event_Mem_Data, L2Cache_getState(addr), addr);
                if (result == TransitionResult_Valid) {
                  counter++;
                  continue; // Check the first port again
                }
                if (result == TransitionResult_ResourceStall) {
                  g_eventQueue_ptr->scheduleEvent(this, 1);
                  // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                }
              }
;
            } else {
              if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_MEMORY_ACK)) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L2Cache_Event_Mem_Ack, L2Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              } else {
                                cerr << "Runtime Error at :347, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("unknown message type") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
              }
            }
          }
        }
      }

    // L2CacheInPort L1RequestIntraChipL2Network_in
      if ((((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).isReady())) {
        {
          RequestMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          DEBUG_SLICC(MedPrio, ":358: ", ((*in_msg_ptr)).m_Address);
;
          DEBUG_SLICC(MedPrio, ":359: ", m_chip_ptr->getID());
;
          DEBUG_SLICC(MedPrio, ":360: ", (L2Cache_getState(((*in_msg_ptr)).m_Address)));
;
          DEBUG_SLICC(MedPrio, ":361: ", ((*in_msg_ptr)).m_Requestor);
;
          DEBUG_SLICC(MedPrio, ":362: ", ((*in_msg_ptr)).m_Type);
;
          DEBUG_SLICC(MedPrio, ":363: ", ((*in_msg_ptr)).m_Destination);
;
                    if (ASSERT_FLAG && !(((machineIDToMachineType(((*in_msg_ptr)).m_Requestor)) == MachineType_L1Cache))) {
            cerr << "Runtime Error at :364, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
                    if (ASSERT_FLAG && !(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
            cerr << "Runtime Error at :365, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
                        {
              Address addr = ((*in_msg_ptr)).m_Address;
              TransitionResult result = doTransition((L2Cache_L1Cache_request_type_to_event(((*in_msg_ptr)).m_Type, ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor)), L2Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          } else {
            if ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).cacheAvail(((*in_msg_ptr)).m_Address))) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition((L2Cache_L1Cache_request_type_to_event(((*in_msg_ptr)).m_Type, ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor)), L2Cache_getState(addr), addr);
                if (result == TransitionResult_Valid) {
                  counter++;
                  continue; // Check the first port again
                }
                if (result == TransitionResult_ResourceStall) {
                  g_eventQueue_ptr->scheduleEvent(this, 1);
                  // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                }
              }
;
            } else {
              if (((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address))))).m_Dirty) {
                                {
                  Address addr = (((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                  TransitionResult result = doTransition(L2Cache_Event_L2_Replacement, L2Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              } else {
                                {
                  Address addr = (((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                  TransitionResult result = doTransition(L2Cache_Event_L2_Replacement_clean, L2Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              }
            }
          }
        }
      }

    break;  // If we got this far, we have nothing left todo
  }
}

