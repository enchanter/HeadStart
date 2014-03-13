#include "systemc.h"
//  Arithmetic requires integer data types. The outputs however are now sc_bv

#include "stim.h"

void Stim::action()
{
  wait();

  for (sc_int<8> i = -10; i < 10; i=i+2) {
    a.write(i);                         // can convert to sc_bv via assignment
    for (sc_int<8> j = -10; j < 10; j=j+2 ) {
      b.write(j);
      wait();
    }
  }

  a.write(0);
  b.write(0);
  wait();

  sc_stop();
}
