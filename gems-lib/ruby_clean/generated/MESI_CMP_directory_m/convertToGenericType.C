/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"

GenericRequestType Chip::convertToGenericType(CoherenceRequestType param_type)
{
  if ((param_type == CoherenceRequestType_PUTX)) {
    return GenericRequestType_PUTX;
  } else {
    if ((param_type == CoherenceRequestType_GETS)) {
      return GenericRequestType_GETS;
    } else {
      if ((param_type == CoherenceRequestType_GET_INSTR)) {
        return GenericRequestType_GET_INSTR;
      } else {
        if ((param_type == CoherenceRequestType_GETX)) {
          return GenericRequestType_GETX;
        } else {
          if ((param_type == CoherenceRequestType_UPGRADE)) {
            return GenericRequestType_UPGRADE;
          } else {
            if ((param_type == CoherenceRequestType_INV)) {
              return GenericRequestType_INV;
            } else {
              DEBUG_SLICC(MedPrio, ":132: ", param_type);
;
                            cerr << "Runtime Error at :133, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("invalid CoherenceRequestType") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
            }
          }
        }
      }
    }
  }
}

