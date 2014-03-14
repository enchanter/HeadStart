#ifndef STIM_H
#define STIM_H
#include "systemc"

class Stim : public sc_core::sc_module
{
  public:
  
  // ports
  sc_core::sc_out<sc_dt::sc_bv<8> > a, b;
  sc_core::sc_in<bool> clk;

  void action();

  Stim(sc_core::sc_module_name nm_);
  SC_HAS_PROCESS(Stim);
  
};
#endif
