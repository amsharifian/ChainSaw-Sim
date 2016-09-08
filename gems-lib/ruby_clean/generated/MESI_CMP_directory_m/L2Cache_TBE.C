/** \file L2Cache_TBE.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "L2Cache_TBE.h"

/** \brief Print the state of this object */
void L2Cache_TBE::print(ostream& out) const
{
  out << "[L2Cache_TBE: ";
  out << "Address=" << m_Address << " ";
  out << "TBEState=" << m_TBEState << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "L1_GetS_IDs=" << m_L1_GetS_IDs << " ";
  out << "L1_GetX_ID=" << m_L1_GetX_ID << " ";
  out << "isPrefetch=" << m_isPrefetch << " ";
  out << "pendingAcks=" << m_pendingAcks << " ";
  out << "]";
}
