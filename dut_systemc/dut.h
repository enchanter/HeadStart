#ifndef SUMOFSQUARES_H
#define SUMOFSQUARES_H
#include "systemc.h"
//  Inputs/outputs are considered to be signed 2's complement 8 bit numbers

#include "multiplier.h"
#include "adder.h"

SC_MODULE(SumOfSquares)
{
  // ports
  sc_in<sc_bv<8> >  i, q;
  sc_out<sc_bv<17> > o;

  // declare instances of the sub-modules
  Multiplier m1, m2;
  Adder a1;

  // internal signals
  sc_signal<sc_bv<16> >  m1_o, m2_o;

  SC_CTOR(SumOfSquares) : m1("m1"), m2("m2"), a1("a1") {
    // bind ports using named binding
    m1.in1(i);
    m1.in2(i);
    m1.out1(m1_o);

    m2.in1(q);
    m2.in2(q);
    m2.out1(m2_o);

    a1.in1(m1_o);
    a1.in2(m2_o);
    a1.out1(o);

  }
};
#endif
