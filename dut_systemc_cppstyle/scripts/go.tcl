set cppfilelist [list ../main.cpp ../dut.cpp ../mon.cpp ../stim.cpp ../testbench.cpp ../adder.cpp ../multiplier.cpp]

puts {creating working library...}
vlib lib
vmap work lib


puts {compiling with no optimisation and debugging enabled...}
eval sccom -O0 -g $cppfilelist

puts {linking...}
sccom -link

puts {launching simulation...}
vsim sc_main

puts {adding top level waveforms and running simulation...}
add wave /testbench1/*
run -all
