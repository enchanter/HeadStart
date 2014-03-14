#include "multiplier.h"
//  Note that an SC_METHOD always executes from top to bottom in zero time.
//  As out1 is bound to a channel sc_signal, the value will not update until the
//  next delta cycle.

Multiplier::Multiplier(sc_core::sc_module_name nm_) : sc_core::sc_module(nm_)
{
  SC_METHOD(action);                    // register with kernel as a process
  sensitive << in1 << in2;              // react on events on in1 and in2
}

void Multiplier::action()
{
  sc_dt::sc_int<16> out_val = in1.read().to_int() * in2.read().to_int();
  out1 = out_val;                       // conversion by assignment
}
