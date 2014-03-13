set cppfilelist [list ../mon.cpp ../stim.cpp ../main.cpp]
set vhdfilelist [list ../dut.vhd]

puts {creating working library...}
vlib lib
vmap work lib


puts {compiling with no optimisation and debugging enabled...}
eval sccom -O0 -g $cppfilelist

puts {compiling vhdl files}
eval vcom -93 $vhdfilelist

puts {linking...}
sccom -link

puts {launching simulation...}
vsim testbench

puts {adding top level waveforms and running simulation...}
add wave /*
run -all
