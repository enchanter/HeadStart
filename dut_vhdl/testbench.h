#include "systemc.h"
//                    Notes
//  Top level of the DUT uses sc_bv<> ports, to allow replacement with a VHDL
//  or Verilog implementation
//  Note the second parameter to the dut is the foreign name of the module (Verilog)
//  or entity (VHDL), required by Modelsim.
//  Cadence Incisive does not need this extra argument, as it has a method hdl_name
//  to return the name.

#include "stim.h"
#include "dut.h"
#include "mon.h"

SC_MODULE(testbench)
{
  // signals to wire up the device under test
  sc_signal<sc_bv<8> > asig, bsig;
  sc_signal<sc_bv<17> > csig;

  // declare a clk for the stimulus process
  sc_clock testclk;

  // stimulus instance
  Stim stim1;
  SumOfSquares dut;
  Mon mon1;

  SC_CTOR(testbench) : testclk("testclk", 10, SC_NS), stim1("stim1"), 

#ifdef MTI_SYSTEMC
                       dut("dut", "SumOfSquares"), 
#elif NCSC
                       dut("dut"), 
#else
                       dut("dut"),
#endif
                       mon1("mon1") 
  {

    stim1.a(asig);
    stim1.b(bsig);
    stim1.clk(testclk);

    dut.i(asig);
    dut.q(bsig);
    dut.o(csig);

    mon1.a(asig);
    mon1.b(bsig);
    mon1.c(csig);
    mon1.clk(testclk);

  }
};
