#include "systemc"
#include "dut.h"
#include "multiplier.h"
#include "adder.h"

SumOfSquares::SumOfSquares(sc_core::sc_module_name nm_) :
sc_core::sc_module(nm_)
{

  m1 = new Multiplier("m1");
  m2 = new Multiplier("m2");
  a1 = new Adder("a1");

  // bind ports using named binding
  m1->in1(i);
  m1->in2(i);
  m1->out1(m1_o);

  m2->in1(q);
  m2->in2(q);
  m2->out1(m2_o);

  a1->in1(m1_o);
  a1->in2(m2_o);
  a1->out1(o);

}

SumOfSquares::~SumOfSquares()
{
  delete m1;
  delete m2;
  delete a1;
}
