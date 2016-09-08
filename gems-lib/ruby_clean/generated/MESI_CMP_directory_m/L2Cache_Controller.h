/** \file L2Cache.h
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:252
  * Created by slicc definition of Module "MOSI Directory L2 Cache CMP"
  */

#ifndef L2Cache_CONTROLLER_H
#define L2Cache_CONTROLLER_H

#include "Global.h"
#include "Consumer.h"
#include "TransitionResult.h"
#include "Types.h"
#include "L2Cache_Profiler.h"

extern stringstream L2Cache_transitionComment;
class L2Cache_Controller : public Consumer {
#ifdef CHECK_COHERENCE
  friend class Chip;
#endif /* CHECK_COHERENCE */
public:
  L2Cache_Controller(Chip* chip_ptr, int version);
  void print(ostream& out) const;
  void wakeup();
  static void dumpStats(ostream& out) { s_profiler.dumpStats(out); }
  static void clearStats() { s_profiler.clearStats(); }
public:
  TransitionResult doTransition(L2Cache_Event event, L2Cache_State state, const Address& addr);  // in L2Cache_Transitions.C
  TransitionResult doTransitionWorker(L2Cache_Event event, L2Cache_State state, L2Cache_State& next_state, const Address& addr);  // in L2Cache_Transitions.C
  Chip* m_chip_ptr;
  NodeID m_id;
  NodeID m_version;
  MachineID m_machineID;
  static L2Cache_Profiler s_profiler;
  // Internal functions
  L2Cache_Entry& L2Cache_getL2CacheEntry(Address param_addr);
  void L2Cache_changeL2Permission(Address param_addr, AccessPermission param_permission);
  string L2Cache_getCoherenceRequestTypeStr(CoherenceRequestType param_type);
  bool L2Cache_isL2CacheTagPresent(Address param_addr);
  bool L2Cache_isOneSharerLeft(Address param_addr, MachineID param_requestor);
  bool L2Cache_isSharer(Address param_addr, MachineID param_requestor);
  void L2Cache_addSharer(Address param_addr, MachineID param_requestor);
  L2Cache_State L2Cache_getState(Address param_addr);
  string L2Cache_getStateStr(Address param_addr);
  void L2Cache_setState(Address param_addr, L2Cache_State param_state);
  L2Cache_Event L2Cache_L1Cache_request_type_to_event(CoherenceRequestType param_type, Address param_addr, MachineID param_requestor);
  // Actions
/** \brief fetch data from memory*/
  void a_issueFetchToMemory(const Address& addr);
/** \brief Forward request to the exclusive L1*/
  void b_forwardRequestToExclusive(const Address& addr);
/** \brief Send data to memory*/
  void c_exclusiveReplacement(const Address& addr);
/** \brief Send ack to memory for clean replacement*/
  void c_exclusiveCleanReplacement(const Address& addr);
/** \brief Send data to memory*/
  void ct_exclusiveReplacementFromTBE(const Address& addr);
/** \brief Send data from cache to reqeustor*/
  void d_sendDataToRequestor(const Address& addr);
/** \brief Send data from cache to reqeustor*/
  void dd_sendExclusiveDataToRequestor(const Address& addr);
/** \brief Send data from cache to reqeustor*/
  void ds_sendSharedDataToRequestor(const Address& addr);
/** \brief Send data from cache to all GetS IDs*/
  void e_sendDataToGetSRequestors(const Address& addr);
/** \brief Send data from cache to all GetS IDs*/
  void ex_sendExclusiveDataToGetSRequestors(const Address& addr);
/** \brief Send data from cache to GetX ID*/
  void ee_sendDataToGetXRequestor(const Address& addr);
/** \brief invalidate sharers for L2 replacement*/
  void f_sendInvToSharers(const Address& addr);
/** \brief invalidate sharers for request*/
  void fw_sendFwdInvToSharers(const Address& addr);
/** \brief invalidate sharers for request, requestor is sharer*/
  void fwm_sendFwdInvToSharersMinusRequestor(const Address& addr);
/** \brief Allocate TBE for internal/external request(isPrefetch=0, number of invalidates=0)*/
  void i_allocateTBE(const Address& addr);
/** \brief Deallocate external TBE*/
  void s_deallocateTBE(const Address& addr);
/** \brief Pop incoming L1 request queue*/
  void jj_popL1RequestQueue(const Address& addr);
/** \brief Pop incoming unblock queue*/
  void k_popUnblockQueue(const Address& addr);
/** \brief Pop Incoming Response queue*/
  void o_popIncomingResponseQueue(const Address& addr);
/** \brief Write data from response queue to cache*/
  void m_writeDataToCache(const Address& addr);
/** \brief Write data from response queue to cache*/
  void mr_writeDataToCacheFromRequest(const Address& addr);
/** \brief update pending ack count*/
  void q_updateAck(const Address& addr);
/** \brief Write data from response queue to TBE*/
  void qq_writeDataToTBE(const Address& addr);
/** \brief Stall*/
  void z_stall(const Address& addr);
/** \brief Record L1 GetS for load response*/
  void ss_recordGetSL1ID(const Address& addr);
/** \brief Record L1 GetX for store response*/
  void xx_recordGetXL1ID(const Address& addr);
/** \brief set the MRU entry*/
  void set_setMRU(const Address& addr);
/** \brief Set L2 cache tag equal to tag of block B.*/
  void qq_allocateL2CacheBlock(const Address& addr);
/** \brief Deallocate L2 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch.*/
  void rr_deallocateL2CacheBlock(const Address& addr);
/** \brief Send writeback ACK*/
  void t_sendWBAck(const Address& addr);
/** \brief Send ACK to upgrader*/
  void ts_sendInvAckToUpgrader(const Address& addr);
/** \brief Profile the demand miss*/
  void uu_profileMiss(const Address& addr);
/** \brief Only profile L2 miss*/
  void llm_profileL2Miss(const Address& addr);
/** \brief Profile this transition at the L2 because Dir won't see the request*/
  void ww_profileMissNoDir(const Address& addr);
/** \brief Add L1 sharer to list*/
  void nn_addSharer(const Address& addr);
/** \brief Add L1 sharer to list*/
  void nnu_addSharerFromUnblock(const Address& addr);
/** \brief Remove L1 Request sharer from list*/
  void kk_removeRequestSharer(const Address& addr);
/** \brief Remove all L1 sharers from list*/
  void ll_clearSharers(const Address& addr);
/** \brief set the exclusive owner*/
  void mm_markExclusive(const Address& addr);
/** \brief set the exclusive owner*/
  void mmu_markExclusiveFromUnblock(const Address& addr);
/** \brief recycle L1 request queue*/
  void zz_recycleL1RequestQueue(const Address& addr);
/** \brief recycle memory request*/
  void zn_recycleResponseNetwork(const Address& addr);
};
#endif // L2Cache_CONTROLLER_H
