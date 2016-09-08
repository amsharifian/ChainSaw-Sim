/** \file CoherenceRequestType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:601
  */

#include "CoherenceRequestType.h"

ostream& operator<<(ostream& out, const CoherenceRequestType& obj)
{
  out << CoherenceRequestType_to_string(obj);
  out << flush;
  return out;
}

string CoherenceRequestType_to_string(const CoherenceRequestType& obj)
{
  switch(obj) {
  case CoherenceRequestType_GETX:
    return "GETX";
  case CoherenceRequestType_UPGRADE:
    return "UPGRADE";
  case CoherenceRequestType_GETS:
    return "GETS";
  case CoherenceRequestType_GET_INSTR:
    return "GET_INSTR";
  case CoherenceRequestType_INV:
    return "INV";
  case CoherenceRequestType_PUTX:
    return "PUTX";
  default:
    ERROR_MSG("Invalid range for type CoherenceRequestType");
    return "";
  }
}

CoherenceRequestType string_to_CoherenceRequestType(const string& str)
{
  if (false) {
  } else if (str == "GETX") {
    return CoherenceRequestType_GETX;
  } else if (str == "UPGRADE") {
    return CoherenceRequestType_UPGRADE;
  } else if (str == "GETS") {
    return CoherenceRequestType_GETS;
  } else if (str == "GET_INSTR") {
    return CoherenceRequestType_GET_INSTR;
  } else if (str == "INV") {
    return CoherenceRequestType_INV;
  } else if (str == "PUTX") {
    return CoherenceRequestType_PUTX;
  } else {
    WARN_EXPR(str);
    ERROR_MSG("Invalid string conversion for type CoherenceRequestType");
  }
}

CoherenceRequestType& operator++( CoherenceRequestType& e) {
  assert(e < CoherenceRequestType_NUM);
  return e = CoherenceRequestType(e+1);
}
