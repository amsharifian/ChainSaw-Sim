/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L2Cache_Controller.h"

void L2Cache_Controller::L2Cache_setState(Address param_addr, L2Cache_State param_state)
{
  if ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).isPresent(param_addr))) {
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(param_addr))).m_TBEState = param_state;
  }
  if ((L2Cache_isL2CacheTagPresent(param_addr))) {
    ((L2Cache_getL2CacheEntry(param_addr))).m_CacheState = param_state;
    if ((param_state == L2Cache_State_SS)) {
      (L2Cache_changeL2Permission(param_addr, AccessPermission_Read_Only));
    } else {
      if ((param_state == L2Cache_State_M)) {
        (L2Cache_changeL2Permission(param_addr, AccessPermission_Read_Write));
      } else {
        if ((param_state == L2Cache_State_MT)) {
          (L2Cache_changeL2Permission(param_addr, AccessPermission_Stale));
        } else {
          (L2Cache_changeL2Permission(param_addr, AccessPermission_Busy));
        }
      }
    }
  }
}

