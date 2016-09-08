/** \file Directory_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef Directory_Event_H
#define Directory_Event_H

#include "Global.h"

/** \enum Directory_Event
  * \brief Directory events
  */
enum Directory_Event {
  Directory_Event_FIRST,
  Directory_Event_Fetch = Directory_Event_FIRST,  /**< A GETX arrives */
  Directory_Event_Data,  /**< A GETS arrives */
  Directory_Event_Memory_Data,  /**< Fetched data from memory arrives */
  Directory_Event_Memory_Ack,  /**< Writeback Ack from memory arrives */
  Directory_Event_NUM
};
Directory_Event string_to_Directory_Event(const string& str);
string Directory_Event_to_string(const Directory_Event& obj);
Directory_Event &operator++( Directory_Event &e);
ostream& operator<<(ostream& out, const Directory_Event& obj);

#endif // Directory_Event_H
