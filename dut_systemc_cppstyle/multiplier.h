#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include "systemc"

class Multiplier : public sc_core::sc_module
{
  public:
    // ports
    sc_core::sc_in<sc_dt::sc_bv<8> >  in1, in2;
    sc_core::sc_out<sc_dt::sc_bv<16> > out1;

    // process definitions
    void action();

    Multiplier(sc_core::sc_module_name nm_);
    SC_HAS_PROCESS(Multiplier);

};
#endif
