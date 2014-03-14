#include "systemc"
//
//  Top level of the DUT uses sc_bv<> ports, to allow replacement with a VHDL
//  or Verilog implementation

class Mon;
class Stim;
class SumOfSquares;

class testbench : public sc_core::sc_module
{
 public:
 
  // signals to wire up the device under test
  sc_core::sc_signal<sc_dt::sc_bv<8> > asig, bsig;
  sc_core::sc_signal<sc_dt::sc_bv<17> > csig;

  // declare a clk for the stimulus process
  sc_core::sc_clock testclk;

  // stimulus instance
  Stim * stim1;
  SumOfSquares * dut;
  Mon * mon1;

  testbench(sc_core::sc_module_name nm_);
  ~testbench();
    
};
