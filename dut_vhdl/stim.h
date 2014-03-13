#ifndef STIM_H
#define STIM_H
#include "systemc.h"

SC_MODULE(Stim)
{
  // ports
  sc_out<sc_bv<8> > a, b;
  sc_in<bool> clk;

  void action();

  SC_CTOR(Stim) {
    SC_THREAD(action);
    sensitive << clk.pos();
  }
};
#endif
