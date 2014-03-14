#include "systemc"
#include "testbench.h"

// top level instanced in sc_main for use with OSCI
// reference simulator
int sc_main(int argc, char * argv[])
{
  testbench testbench1("testbench1");
  sc_core::sc_start();
  return 0;
}
