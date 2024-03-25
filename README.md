# BitSequenceParser
## Motivation
I wrote this code for a test task. This was my first time coding in tcl. I made a C version (to gain a little confidence mostly) and then I wrote a tcl version.

## Installation
If you want to run the C version you'll need to build it for yourself. I used the following command:
>bit_sequence_parser.c -Wall -std=c99 на gcc 13.2.1

If you want to run tcl version you'll need to make the file executable and run it as
> ./bit_sequence_parser.tcl

Or you can run it with your interpreter, for instance:
> tclsh bit_sequence_parser.tcl
## Usage
The parser has a fixed number set in it. On execution it gets three parameters from this number and presents them to the user.
The number and all the details can be found in the code.
