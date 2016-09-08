/** \file Directory_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "Directory_State.h"

ostream& operator<<(ostream& out, const Directory_State& obj)
{
  out << Directory_State_to_string(obj);
  out << flush;
  return out;
}

string Directory_State_to_string(const Directory_State& obj)
{
  switch(obj) {
  case Directory_State_I:
    return "I";
  default:
    ERROR_MSG("Invalid range for type Directory_State");
    return "";
  }
}

Directory_State string_to_Directory_State(const string& str)
{
  if (false) {
  } else if (str == "I") {
    return Directory_State_I;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type Directory_State");
  }
}

Directory_State& operator++( Directory_State& e) {
  assert(e < Directory_State_NUM);
  return e = Directory_State(e+1);
}
