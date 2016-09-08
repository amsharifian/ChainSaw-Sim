/** \file L1Cache_TBE.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "L1Cache_TBE.h"

/** \brief Print the state of this object */
void L1Cache_TBE::print(ostream& out) const
{
  out << "[L1Cache_TBE: ";
  out << "Address=" << m_Address << " ";
  out << "TBEState=" << m_TBEState << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "isPrefetch=" << m_isPrefetch << " ";
  out << "pendingAcks=" << m_pendingAcks << " ";
  out << "]";
}
