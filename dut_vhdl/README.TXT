This example includes a VHDL DUT and a simple SystemC testbench.

stim.h
stim.cpp
mon.h
mon.cpp
dut.h
testbench.h
testbench.cpp


These files use macros defined by Modelsim and Cadence Incisive to 
export the top level of the design to either Modelsim or ncsim.

The same macros are also used 

  a) to select a "wrapper" architecture in dut.h for either Modelsim
     or Incisive
     
  b) to modify the instantiation of the dut in testbench.h.
     This is because Modelsim requires an extra constructor argument
     to specify the name of the foreign module to the wrapper.
     Cadence does not require this argument.
    

Running the code
----------------
The code has been written so it can be compiled with either

Modelsim: type
cd scripts
./start_modelsim.bat

or on Windows, double-click scripts\start_modelsim.bat

Cadence: type
cd scripts
./start_ncsim.csh

To clean up type:
./clean.csh

What the scripts do
-------------------
For modelsim, the script file launches Modelsim, and then runs a 
Tcl script file go.tcl. go.tcl contains the commands to compile, link,
view, and run the simulation.

For cadence, the script file compiles,links, and runs using the command
irun which is part of the Cadence from version 5.7 onwards.

