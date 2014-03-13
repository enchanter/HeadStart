#include "systemc.h"
//  This version of the top level should work with Modelsim, or Cadence Incisive
//  or OSCI reference simulator.

#include "testbench.h"

#ifdef MTI_SYSTEMC

// export top level to modelsim
SC_MODULE_EXPORT(testbench);

#elif NCSC

// export top level to Cadence Incisive
NCSC_MODULE_EXPORT(testbench);

#else

// top level instanced in sc_main for use with OSCI 
// reference simulator
int sc_main(int argc, char * argv[])
{
  testbench testbench1("testbench");
  sc_start();
  return 0;
}
#endif
