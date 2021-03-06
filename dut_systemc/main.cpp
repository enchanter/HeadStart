#include "systemc.h"
#include "testbench.h"

#ifdef MTI_SYSTEMC

SC_MODULE_EXPORT(testbench);

#elif NCSC

NCSC_MODULE_EXPORT(testbench);

#else

// top level instanced in sc_main for use with OSCI
// reference simulator
int sc_main(int argc, char * argv[])
{
  testbench testbench1("testbench1");
  sc_start();
  return 0;
}

#endif
