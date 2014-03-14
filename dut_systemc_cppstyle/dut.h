#ifndef SUMOFSQUARES_H
#define SUMOFSQUARES_H
#include "systemc"
//  Inputs/outputs are considered to be signed 2's complement 8 bit numbers

class Multiplier;
class Adder;

class SumOfSquares : public sc_core::sc_module
{
  public:
    // ports
    sc_core::sc_in<sc_dt::sc_bv<8> >  i, q;
    sc_core::sc_out<sc_dt::sc_bv<17> > o;

    // declare instances of the sub-modules
    Multiplier * m1, * m2;
    Adder * a1;

    // internal signals
    sc_core::sc_signal<sc_dt::sc_bv<16> >  m1_o, m2_o;

    SumOfSquares(sc_core::sc_module_name nm_);
    ~SumOfSquares();

};
#endif
