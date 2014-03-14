#ifndef MON_H
#define MON_H
#include "systemc"
//  Triggered on the negative edge of the clock for convenience. Outputs are
//  therefore stable as inputs are applied on the rising edge of the clock.

class Mon: public sc_core::sc_module
{
  public:
    // ports
    sc_core::sc_in<sc_dt::sc_bv<8> >  a, b;
    sc_core::sc_in<sc_dt::sc_bv<17> > c;
    sc_core::sc_in<bool> clk;

    void action();

    Mon(sc_core::sc_module_name nm_);
    SC_HAS_PROCESS(Mon);
};
#endif
