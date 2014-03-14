#include "multiplier.h"
//  Note that an SC_METHOD always executes from top to bottom in zero time.
//  As out1 is bound to a channel sc_signal, the value will not update until the
//  next delta cycle.

void Multiplier::action()
{
  sc_int<16> out_val = in1.read().to_int() * in2.read().to_int();
  out1 = out_val;                       // conversion by assignment
}
