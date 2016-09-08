/** \file L2Cache_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "L2Cache_State.h"

ostream& operator<<(ostream& out, const L2Cache_State& obj)
{
  out << L2Cache_State_to_string(obj);
  out << flush;
  return out;
}

string L2Cache_State_to_string(const L2Cache_State& obj)
{
  switch(obj) {
  case L2Cache_State_NP:
    return "NP";
  case L2Cache_State_SS:
    return "SS";
  case L2Cache_State_M:
    return "M";
  case L2Cache_State_MT:
    return "MT";
  case L2Cache_State_M_I:
    return "M_I";
  case L2Cache_State_MT_I:
    return "MT_I";
  case L2Cache_State_MCT_I:
    return "MCT_I";
  case L2Cache_State_I_I:
    return "I_I";
  case L2Cache_State_S_I:
    return "S_I";
  case L2Cache_State_ISS:
    return "ISS";
  case L2Cache_State_IS:
    return "IS";
  case L2Cache_State_IM:
    return "IM";
  case L2Cache_State_SS_MB:
    return "SS_MB";
  case L2Cache_State_MT_MB:
    return "MT_MB";
  case L2Cache_State_M_MB:
    return "M_MB";
  case L2Cache_State_MT_IIB:
    return "MT_IIB";
  case L2Cache_State_MT_IB:
    return "MT_IB";
  case L2Cache_State_MT_SB:
    return "MT_SB";
  default:
    ERROR_MSG("Invalid range for type L2Cache_State");
    return "";
  }
}

L2Cache_State string_to_L2Cache_State(const string& str)
{
  if (false) {
  } else if (str == "NP") {
    return L2Cache_State_NP;
  } else if (str == "SS") {
    return L2Cache_State_SS;
  } else if (str == "M") {
    return L2Cache_State_M;
  } else if (str == "MT") {
    return L2Cache_State_MT;
  } else if (str == "M_I") {
    return L2Cache_State_M_I;
  } else if (str == "MT_I") {
    return L2Cache_State_MT_I;
  } else if (str == "MCT_I") {
    return L2Cache_State_MCT_I;
  } else if (str == "I_I") {
    return L2Cache_State_I_I;
  } else if (str == "S_I") {
    return L2Cache_State_S_I;
  } else if (str == "ISS") {
    return L2Cache_State_ISS;
  } else if (str == "IS") {
    return L2Cache_State_IS;
  } else if (str == "IM") {
    return L2Cache_State_IM;
  } else if (str == "SS_MB") {
    return L2Cache_State_SS_MB;
  } else if (str == "MT_MB") {
    return L2Cache_State_MT_MB;
  } else if (str == "M_MB") {
    return L2Cache_State_M_MB;
  } else if (str == "MT_IIB") {
    return L2Cache_State_MT_IIB;
  } else if (str == "MT_IB") {
    return L2Cache_State_MT_IB;
  } else if (str == "MT_SB") {
    return L2Cache_State_MT_SB;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type L2Cache_State");
  }
}

L2Cache_State& operator++( L2Cache_State& e) {
  assert(e < L2Cache_State_NUM);
  return e = L2Cache_State(e+1);
}
