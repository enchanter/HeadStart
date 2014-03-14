//  Note use of read() method to extract value from channels

#include "adder.h"

Adder::Adder(sc_core::sc_module_name nm_) : sc_core::sc_module(nm_)
{
  // SC_THREADs can be suspended
  SC_THREAD(action);                    // register with kernel as a process
  sensitive << in1 << in2;              // react on events on in1 and in2
}

void Adder::action()
{
  sc_dt::sc_int<17> out_val;

  while(true) {

    sc_core::wait();
    out_val = in1.read().to_int() + in2.read().to_int();
    out1 = out_val;
  }
}
