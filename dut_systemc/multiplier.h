#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include "systemc.h"
SC_MODULE(Multiplier)
{
  // ports
  sc_in<sc_bv<8> >  in1, in2;
  sc_out<sc_bv<16> > out1;

  // process definitions
  void action();

  SC_CTOR(Multiplier) {
    SC_METHOD(action);                  // register with kernel as a process
    sensitive << in1 << in2;            // react on events on in1 and in2
  }
};
#endif
