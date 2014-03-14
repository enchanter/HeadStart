#ifndef ADDER_H
#define ADDER_H
#include "systemc"
//  Version sc_int ports

class Adder : public sc_core::sc_module
{
  public:
    // ports
    sc_core::sc_in<sc_dt::sc_bv<16> >  in1, in2;
    sc_core::sc_out<sc_dt::sc_bv<17> > out1;

    // process definitions
    void action();

    Adder(sc_core::sc_module_name nm_);
    SC_HAS_PROCESS(Adder);

};
#endif
