/** \file CoherenceRequestType.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef CoherenceRequestType_H
#define CoherenceRequestType_H

#include "Global.h"

/** \enum CoherenceRequestType
  * \brief ...
  */
enum CoherenceRequestType {
  CoherenceRequestType_FIRST,
  CoherenceRequestType_GETX = CoherenceRequestType_FIRST,  /**< Get eXclusive */
  CoherenceRequestType_UPGRADE,  /**< UPGRADE to exclusive */
  CoherenceRequestType_GETS,  /**< Get Shared */
  CoherenceRequestType_GET_INSTR,  /**< Get Instruction */
  CoherenceRequestType_INV,  /**< INValidate */
  CoherenceRequestType_PUTX,  /**< replacement message */
  CoherenceRequestType_NUM
};
CoherenceRequestType string_to_CoherenceRequestType(const string& str);
string CoherenceRequestType_to_string(const CoherenceRequestType& obj);
CoherenceRequestType &operator++( CoherenceRequestType &e);
ostream& operator<<(ostream& out, const CoherenceRequestType& obj);

#endif // CoherenceRequestType_H
