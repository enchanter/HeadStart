#include "systemc"
#include "testbench.h"
#include "dut.h"
#include "mon.h"
#include "stim.h"

testbench::testbench(sc_core::sc_module_name nm_) : sc_core::sc_module(nm_),
testclk("testclk", 10, sc_core::SC_NS)
{
  dut = new SumOfSquares("dut");
  stim1 = new Stim("stim1");
  mon1 = new Mon("mon1");

  stim1->a(asig);
  stim1->b(bsig);
  stim1->clk(testclk);

  dut->i(asig);
  dut->q(bsig);
  dut->o(csig);

  mon1->a(asig);
  mon1->b(bsig);
  mon1->c(csig);
  mon1->clk(testclk);

}

testbench::~testbench()
{
  delete dut;
  delete stim1;
  delete mon1;
}
