#!/bin/tclsh

proc get_bits {value start end} {
	set width [expr {$end - $start + 1}]
	set mask [expr {(1 << $width) - 1}]
	expr {($value >> $start) & $mask}
}

proc mirror_4_bits {value} {
	set bin_value [format %b $value]
	set len [string length $bin_value]
	set bits [split $bin_value {}]
	set newvalue {}
	foreach {b3 b2 b1 b0} $bits {
		lappend newvalue $b3 $b2 $b1 $b0
	}
	set newvalue [lreplace $newvalue $len end 0]
	expr {[join $newvalue {}]}
}

set value 0x5FABFF01
#param1 - 2nd byte is from 8th bit to 15th
set param1 [get_bits $value 8 15]
puts "param1: [format %x $param1]"
#param2 - inverse of 7th bit
set param2 [expr ![get_bits $value 7 7]]
puts "param2: [format %x $param2]"
#param3 - bits 17th18th19th20th1
set raw_bits [split [get_bits $value 17 20] {}]
puts "param3: [mirror_4_bits $raw_bits]"
