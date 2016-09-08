/** \file Directory_Event.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "Directory_Event.h"

ostream& operator<<(ostream& out, const Directory_Event& obj)
{
  out << Directory_Event_to_string(obj);
  out << flush;
  return out;
}

string Directory_Event_to_string(const Directory_Event& obj)
{
  switch(obj) {
  case Directory_Event_Fetch:
    return "Fetch";
  case Directory_Event_Data:
    return "Data";
  case Directory_Event_Memory_Data:
    return "Memory_Data";
  case Directory_Event_Memory_Ack:
    return "Memory_Ack";
  default:
    ERROR_MSG("Invalid range for type Directory_Event");
    return "";
  }
}

Directory_Event string_to_Directory_Event(const string& str)
{
  if (false) {
  } else if (str == "Fetch") {
    return Directory_Event_Fetch;
  } else if (str == "Data") {
    return Directory_Event_Data;
  } else if (str == "Memory_Data") {
    return Directory_Event_Memory_Data;
  } else if (str == "Memory_Ack") {
    return Directory_Event_Memory_Ack;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type Directory_Event");
  }
}

Directory_Event& operator++( Directory_Event& e) {
  assert(e < Directory_Event_NUM);
  return e = Directory_Event(e+1);
}
