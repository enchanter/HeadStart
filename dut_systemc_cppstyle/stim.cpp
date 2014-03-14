#include "systemc"
//  Arithmetic requires integer data types. The outputs however are now sc_bv

#include "stim.h"

Stim::Stim(sc_core::sc_module_name nm_)
{
  SC_THREAD(action);
  sensitive << clk.pos();
}

void Stim::action()
{
  sc_core::wait();

  for (sc_dt::sc_int<8> i = -10; i < 10; i=i+2) {
    a.write(i);                         // can convert to sc_bv via assignment
    for (sc_dt::sc_int<8> j = -10; j < 10; j=j+2 ) {
      b.write(j);
      sc_core::wait();
    }
  }

  a.write(0);
  b.write(0);
  sc_core::wait();

  sc_core::sc_stop();
}
