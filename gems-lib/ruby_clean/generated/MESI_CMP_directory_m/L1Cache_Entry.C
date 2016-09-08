/** \file L1Cache_Entry.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "L1Cache_Entry.h"

/** \brief Print the state of this object */
void L1Cache_Entry::print(ostream& out) const
{
  out << "[L1Cache_Entry: ";
  out << "CacheState=" << m_CacheState << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "]";
}
