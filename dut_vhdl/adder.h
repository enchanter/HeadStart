#ifndef ADDER_H
#define ADDER_H
#include "systemc.h"
//  Version sc_int ports

SC_MODULE(Adder)
{
  // ports
  sc_in<sc_bv<16> >  in1, in2;
  sc_out<sc_bv<17> > out1;

  // process definitions
  void action();

  SC_CTOR(Adder) {
    // SC_THREADs can be suspended
    SC_THREAD(action);                  // register with kernel as a process
    sensitive << in1 << in2;            // react on events on in1 and in2
  }
};
#endif
