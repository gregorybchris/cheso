# Cheso

## About

Cheso is an esoteric programming language (Pronounced CHAY-so) with an interpreter written in C. It's about as simple as a language can get while still being Turing complete. Cheso is a less legible and less vulgar version of the language [BrainF**k](https://en.wikipedia.org/wiki/Brainfuck).

## Compiling the Source

To compile the interpreter use the provided Makefile by running the `make` command in the directory with the source files. Then run a .cheso program file with the command: `./cheso program.cheso`

## Writing a Program

A Cheso program is a string of instructions. Each instruction is one character and blank space is ignored. The number of registers available is limited only by physical memory and each register can hold a large non-negative integer. The ASCII character corresponding to the integer in a register can be printed and the inverse operation is possible for reading a character. Loops will continue to run as long as the current register is non-zero at the end of each iteration.

- Start/end a loop - `s`/`e`
- Increment/decrement the current register - `u`/`d`
- Shift left or right one register - `l`/`r`
- Print the ASCII character in the current register - `p`
- Place a character taken as input in the current register - `i`

## Example

The following code will output `I <3 chips and Cheso`

```txt
uuuuuuuuuuuuuuu
s
ru
ruuu
ruuuu
ruuuuu
ruuuuuu
ruu
ruuuuuuu
ruuuuuuuu
lllllllld
e

rrrrddp
rruup
lllp
luuuuuup
rrrrp
rddddddp
uuuuup
up
uuuuuuup
uuup
lp
luuuuuuup
rrdddddp
lluuup
rp
llddddddp
ruuuup
dddp
rruuuuup
ddddp
```