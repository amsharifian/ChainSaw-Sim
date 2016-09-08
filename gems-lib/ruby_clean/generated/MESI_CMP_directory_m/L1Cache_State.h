/** \file L1Cache_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef L1Cache_State_H
#define L1Cache_State_H

#include "Global.h"

/** \enum L1Cache_State
  * \brief Cache states
  */
enum L1Cache_State {
  L1Cache_State_FIRST,
  L1Cache_State_NP = L1Cache_State_FIRST,  /**< Not present in either cache */
  L1Cache_State_I,  /**< a L1 cache entry Idle */
  L1Cache_State_S,  /**< a L1 cache entry Shared */
  L1Cache_State_E,  /**< a L1 cache entry Exclusive */
  L1Cache_State_M,  /**< a L1 cache entry Modified */
  L1Cache_State_IS,  /**< L1 idle, issued GETS, have not seen response yet */
  L1Cache_State_IM,  /**< L1 idle, issued GETX, have not seen response yet */
  L1Cache_State_SM,  /**< L1 idle, issued GETX, have not seen response yet */
  L1Cache_State_IS_I,  /**< L1 idle, issued GETS, saw Inv before data because directory doesn't block on GETS hit */
  L1Cache_State_M_I,  /**< L1 replacing, waiting for ACK */
  L1Cache_State_E_I,  /**< L1 replacing, waiting for ACK */
  L1Cache_State_SINK_WB_ACK,  /**< This is to sink WB_Acks from L2. Race between WB and another access */
  L1Cache_State_NUM
};
L1Cache_State string_to_L1Cache_State(const string& str);
string L1Cache_State_to_string(const L1Cache_State& obj);
L1Cache_State &operator++( L1Cache_State &e);
ostream& operator<<(ostream& out, const L1Cache_State& obj);

#endif // L1Cache_State_H
