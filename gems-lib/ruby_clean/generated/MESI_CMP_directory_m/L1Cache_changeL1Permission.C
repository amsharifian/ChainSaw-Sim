/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

void L1Cache_Controller::L1Cache_changeL1Permission(Address param_addr, AccessPermission param_permission)
{
  if ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(param_addr))) {
    return (((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).changePermission(param_addr, param_permission));
  } else {
    if ((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(param_addr))) {
      return (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).changePermission(param_addr, param_permission));
    } else {
            cerr << "Runtime Error at :187, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("cannot change permission, L1 block not present") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
    }
  }
}

