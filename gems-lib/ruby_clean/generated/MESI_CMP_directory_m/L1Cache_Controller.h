/** \file L1Cache.h
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:252
  * Created by slicc definition of Module "MESI Directory L1 Cache CMP"
  */

#ifndef L1Cache_CONTROLLER_H
#define L1Cache_CONTROLLER_H

#include "Global.h"
#include "Consumer.h"
#include "TransitionResult.h"
#include "Types.h"
#include "L1Cache_Profiler.h"

extern stringstream L1Cache_transitionComment;
class L1Cache_Controller : public Consumer {
#ifdef CHECK_COHERENCE
  friend class Chip;
#endif /* CHECK_COHERENCE */
public:
  L1Cache_Controller(Chip* chip_ptr, int version);
  void print(ostream& out) const;
  void wakeup();
  static void dumpStats(ostream& out) { s_profiler.dumpStats(out); }
  static void clearStats() { s_profiler.clearStats(); }
public:
  TransitionResult doTransition(L1Cache_Event event, L1Cache_State state, const Address& addr);  // in L1Cache_Transitions.C
  TransitionResult doTransitionWorker(L1Cache_Event event, L1Cache_State state, L1Cache_State& next_state, const Address& addr);  // in L1Cache_Transitions.C
  Chip* m_chip_ptr;
  NodeID m_id;
  NodeID m_version;
  MachineID m_machineID;
  static L1Cache_Profiler s_profiler;
  // Internal functions
  L1Cache_Entry& L1Cache_getL1CacheEntry(Address param_addr);
  void L1Cache_changeL1Permission(Address param_addr, AccessPermission param_permission);
  bool L1Cache_isL1CacheTagPresent(Address param_addr);
  L1Cache_State L1Cache_getState(Address param_addr);
  void L1Cache_setState(Address param_addr, L1Cache_State param_state);
  L1Cache_Event L1Cache_mandatory_request_type_to_event(CacheRequestType param_type);
  // Actions
/** \brief Issue GETS*/
  void a_issueGETS(const Address& addr);
/** \brief Issue GETINSTR*/
  void ai_issueGETINSTR(const Address& addr);
/** \brief Issue GETX*/
  void b_issueGETX(const Address& addr);
/** \brief Issue GETX*/
  void c_issueUPGRADE(const Address& addr);
/** \brief send data to requestor*/
  void d_sendDataToRequestor(const Address& addr);
/** \brief send data to the L2 cache because of M downgrade*/
  void d2_sendDataToL2(const Address& addr);
/** \brief send data to requestor*/
  void dt_sendDataToRequestor_fromTBE(const Address& addr);
/** \brief send data to the L2 cache*/
  void d2t_sendDataToL2_fromTBE(const Address& addr);
/** \brief send invalidate ack to requestor (could be L2 or L1)*/
  void e_sendAckToRequestor(const Address& addr);
/** \brief send data to the L2 cache*/
  void f_sendDataToL2(const Address& addr);
/** \brief send data to the L2 cache*/
  void ft_sendDataToL2_fromTBE(const Address& addr);
/** \brief send data to the L2 cache*/
  void fi_sendInvAck(const Address& addr);
/** \brief send data to the L2 cache*/
  void g_issuePUTX(const Address& addr);
/** \brief send unblock to the L2 cache*/
  void j_sendUnblock(const Address& addr);
/** \brief send unblock to the L2 cache*/
  void jj_sendExclusiveUnblock(const Address& addr);
/** \brief If not prefetch, notify sequencer the load completed.*/
  void h_load_hit(const Address& addr);
/** \brief If not prefetch, notify sequencer that store completed.*/
  void hh_store_hit(const Address& addr);
/** \brief Allocate TBE (isPrefetch=0, number of invalidates=0)*/
  void i_allocateTBE(const Address& addr);
/** \brief Pop mandatory queue.*/
  void k_popMandatoryQueue(const Address& addr);
/** \brief Pop incoming request queue and profile the delay within this virtual network*/
  void l_popRequestQueue(const Address& addr);
/** \brief Pop Incoming Response queue and profile the delay within this virtual network*/
  void o_popIncomingResponseQueue(const Address& addr);
/** \brief Deallocate TBE*/
  void s_deallocateTBE(const Address& addr);
/** \brief Write data to cache*/
  void u_writeDataToL1Cache(const Address& addr);
/** \brief Update ack count*/
  void q_updateAckCount(const Address& addr);
/** \brief Stall*/
  void z_stall(const Address& addr);
/** \brief Deallocate L1 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch.*/
  void ff_deallocateL1CacheBlock(const Address& addr);
/** \brief Set L1 D-cache tag equal to tag of block B.*/
  void oo_allocateL1DCacheBlock(const Address& addr);
/** \brief Set L1 I-cache tag equal to tag of block B.*/
  void pp_allocateL1ICacheBlock(const Address& addr);
/** \brief recycle L1 request queue*/
  void zz_recycleRequestQueue(const Address& addr);
/** \brief recycle L1 request queue*/
  void z_recycleMandatoryQueue(const Address& addr);
/** \brief Profile L1 miss*/
  void sk_profileL1CacheMiss(const Address& addr);
};
#endif // L1Cache_CONTROLLER_H
