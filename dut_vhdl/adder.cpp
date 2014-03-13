//  Note use of read() method to extract value from channels

#include "adder.h"
void Adder::action()
{
  sc_int<17> out_val;

  while(true) {

    wait();
    out_val = in1.read().to_int() + in2.read().to_int();
    out1 = out_val;
  }
}
