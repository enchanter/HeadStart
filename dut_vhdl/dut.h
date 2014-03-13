#ifdef MTI_SYSTEMC

#include "systemc.h"

class SumOfSquares : public sc_foreign_module
{
  public:
    sc_in<sc_bv<8> > i;
    sc_in<sc_bv<8> > q;
    sc_out<sc_bv<17> > o;

    SumOfSquares(sc_module_name nm, const char* hdl_name)
      : sc_foreign_module(nm, hdl_name),
      i("i"),
      q("q"),
      o("o")
      {}

    ~SumOfSquares()
      {}

};

#elif NCSC

#include "systemc.h"
class SumOfSquares : public ncsc_foreign_module
{
  public:

    sc_in<sc_bv<8> > i;
    sc_in<sc_bv<8> > q;
    sc_out<sc_bv<17> > o;

    SumOfSquares(sc_module_name nm) : ncsc_foreign_module(nm),
      i("i"),
      q("q"),
      o("o")
      {}

    const char* hdl_name() const
    {
      return "SumOfSquares";
    }

};

#else

// SystemC implementation
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
