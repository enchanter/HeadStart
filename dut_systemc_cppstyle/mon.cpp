#include "systemc.h"
//  Inputs are sc_bv, but we convert them to decimal integers for display

#include <iomanip>

#include "mon.h"

Mon::Mon(sc_core::sc_module_name nm_) : sc_core::sc_module(nm_)
{
  SC_THREAD(action);
  sensitive << clk.neg();
}

void Mon::action()
{
  using std::setw;

  // write header
  std::cout << setw(4)  << "a"
    << setw(4)  << "b"
    << setw(4)  << "c" << std::endl;

  for (;;) {
    wait();                             // wait for 1 clock cycle
    std::cout << setw(4)  << a.read().to_int()
      << setw(4)  << b.read().to_int()
      << setw(4)  << c.read().to_int() << std::endl;
  }
}
