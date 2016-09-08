/** \file L1Cache_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "L1Cache_State.h"

ostream& operator<<(ostream& out, const L1Cache_State& obj)
{
  out << L1Cache_State_to_string(obj);
  out << flush;
  return out;
}

string L1Cache_State_to_string(const L1Cache_State& obj)
{
  switch(obj) {
  case L1Cache_State_NP:
    return "NP";
  case L1Cache_State_I:
    return "I";
  case L1Cache_State_S:
    return "S";
  case L1Cache_State_E:
    return "E";
  case L1Cache_State_M:
    return "M";
  case L1Cache_State_IS:
    return "IS";
  case L1Cache_State_IM:
    return "IM";
  case L1Cache_State_SM:
    return "SM";
  case L1Cache_State_IS_I:
    return "IS_I";
  case L1Cache_State_M_I:
    return "M_I";
  case L1Cache_State_E_I:
    return "E_I";
  case L1Cache_State_SINK_WB_ACK:
    return "SINK_WB_ACK";
  default:
    ERROR_MSG("Invalid range for type L1Cache_State");
    return "";
  }
}

L1Cache_State string_to_L1Cache_State(const string& str)
{
  if (false) {
  } else if (str == "NP") {
    return L1Cache_State_NP;
  } else if (str == "I") {
    return L1Cache_State_I;
  } else if (str == "S") {
    return L1Cache_State_S;
  } else if (str == "E") {
    return L1Cache_State_E;
  } else if (str == "M") {
    return L1Cache_State_M;
  } else if (str == "IS") {
    return L1Cache_State_IS;
  } else if (str == "IM") {
    return L1Cache_State_IM;
  } else if (str == "SM") {
    return L1Cache_State_SM;
  } else if (str == "IS_I") {
    return L1Cache_State_IS_I;
  } else if (str == "M_I") {
    return L1Cache_State_M_I;
  } else if (str == "E_I") {
    return L1Cache_State_E_I;
  } else if (str == "SINK_WB_ACK") {
    return L1Cache_State_SINK_WB_ACK;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L1Cache_State");
  }
}

L1Cache_State& operator++( L1Cache_State& e) {
  assert(e < L1Cache_State_NUM);
  return e = L1Cache_State(e+1);
}
