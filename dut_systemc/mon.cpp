#include "systemc.h"
//  Inputs are sc_bv, but we convert them to decimal integers for display

#include <iomanip>
using std::setw;

#include "mon.h"

void Mon::action()
{

  // write header
  cout << setw(4) << "a"
       << setw(4) << "b"
       << setw(4) << "c" << endl;

  for (;;) {
    wait();                             // wait for 1 clock cycle
    cout << setw(4) << a.read().to_int()
         << setw(4) << b.read().to_int()
         << setw(4) << c.read().to_int() << endl;
  }
}
