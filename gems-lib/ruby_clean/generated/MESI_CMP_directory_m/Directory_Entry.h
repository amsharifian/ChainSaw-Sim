/** \file Directory_Entry.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef Directory_Entry_H
#define Directory_Entry_H

#include "Global.h"
#include "Allocator.h"
#include "DataBlock.h"
class Directory_Entry {
public:
  Directory_Entry() 
  {
    // m_DataBlk has no default
  }
  ~Directory_Entry() { };
  Directory_Entry(const DataBlock& local_DataBlk)
  {
    m_DataBlk = local_DataBlk;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }

  // Mutator methods for each field
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }

  void print(ostream& out) const;
//private:
  DataBlock m_DataBlk; /**< data for the block*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const Directory_Entry& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const Directory_Entry& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // Directory_Entry_H
