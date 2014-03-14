#include "systemc.h"
//
//  Top level of the DUT uses sc_bv<> ports, to allow replacement with a VHDL
//  or Verilog implementation

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
  dut("dut"), mon1("mon1") {

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
