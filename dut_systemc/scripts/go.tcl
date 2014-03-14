set cppfilelist [list ../main.cpp  ../mon.cpp ../stim.cpp ../adder.cpp ../multiplier.cpp]

puts {creating working library...}
vlib work


puts {compiling with no optimisation and debugging enabled...}
eval sccom -O0 -g $cppfilelist

puts {linking...}
sccom -link

puts {launching simulation...}
vsim testbench

puts {adding top level waveforms and running simulation...}
add wave /*
run -all
