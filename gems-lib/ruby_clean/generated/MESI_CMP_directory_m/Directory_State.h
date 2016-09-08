/** \file Directory_State.h
  * 
  * Auto generated C++ code started by symbols/Type.C:520
  */
#ifndef Directory_State_H
#define Directory_State_H

#include "Global.h"

/** \enum Directory_State
  * \brief Directory states
  */
enum Directory_State {
  Directory_State_FIRST,
  Directory_State_I = Directory_State_FIRST,  /**< Owner */
  Directory_State_NUM
};
Directory_State string_to_Directory_State(const string& str);
string Directory_State_to_string(const Directory_State& obj);
Directory_State &operator++( Directory_State &e);
ostream& operator<<(ostream& out, const Directory_State& obj);

#endif // Directory_State_H
