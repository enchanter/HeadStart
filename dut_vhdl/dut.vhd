--  Inputs/outputs are considered to be signed 2's complement 8 bit numbers

library IEEE;
use IEEE.std_logic_1164.all;

entity SumOfSquares is
  port ( i : in std_logic_vector(7 downto 0);
         q : in std_logic_vector(7 downto 0);
         o : out std_logic_vector(16 downto 0)
      );
end entity SumOfSquares;

library IEEE;
use IEEE.Numeric_Std.all;
architecture RTL of SumOfSquares is

begin
  
  
  SoS: process (i, q) is
    variable iv, qv : SIGNED(i'RANGE);
    variable ov : SIGNED(o'RANGE);
  begin
    iv := SIGNED(i);
    qv := SIGNED(i);
    
    ov := RESIZE(iv*iv,17) + RESIZE(qv*qv,17);
    
    o <= STD_LOGIC_vector(ov);
  end process SoS;
  
end architecture RTL;
