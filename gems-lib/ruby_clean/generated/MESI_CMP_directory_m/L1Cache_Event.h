/** \file L1Cache_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef L1Cache_Event_H
#define L1Cache_Event_H

#include "Global.h"

/** \enum L1Cache_Event
  * \brief Cache events
  */
enum L1Cache_Event {
  L1Cache_Event_FIRST,
  L1Cache_Event_Load = L1Cache_Event_FIRST,  /**< Load request from the home processor */
  L1Cache_Event_Ifetch,  /**< I-fetch request from the home processor */
  L1Cache_Event_Store,  /**< Store request from the home processor */
  L1Cache_Event_Inv,  /**< Invalidate request from L2 bank */
  L1Cache_Event_L1_Replacement,  /**< L1 Replacement */
  L1Cache_Event_Fwd_GETX,  /**< GETX from other processor */
  L1Cache_Event_Fwd_GETS,  /**< GETS from other processor */
  L1Cache_Event_Fwd_GET_INSTR,  /**< GET_INSTR from other processor */
  L1Cache_Event_Data,  /**< Data for processor */
  L1Cache_Event_Data_Exclusive,  /**< Data for processor */
  L1Cache_Event_DataS_fromL1,  /**< data for GETS request, need to unblock directory */
  L1Cache_Event_Data_all_Acks,  /**< Data for processor, all acks */
  L1Cache_Event_Ack,  /**< Ack for processor */
  L1Cache_Event_Ack_all,  /**< Last ack for processor */
  L1Cache_Event_WB_Ack,  /**< Ack for replacement */
  L1Cache_Event_NUM
};
L1Cache_Event string_to_L1Cache_Event(const string& str);
string L1Cache_Event_to_string(const L1Cache_Event& obj);
L1Cache_Event &operator++( L1Cache_Event &e);
ostream& operator<<(ostream& out, const L1Cache_Event& obj);

#endif // L1Cache_Event_H
