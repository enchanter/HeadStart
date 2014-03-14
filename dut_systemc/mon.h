#ifndef MON_H
#define MON_H
#include "systemc.h"
//  Triggered on the negative edge of the clock for convenience. Outputs are
//  therefore stable as inputs are applied on the rising edge of the clock.

SC_MODULE(Mon)
{
  // ports
  sc_in<sc_bv<8> >  a, b;
  sc_in<sc_bv<17> > c;
  sc_in<bool> clk;

  void action();

  SC_CTOR(Mon) {
    SC_THREAD(action);
    sensitive << clk.neg();
  }
};
#endif
