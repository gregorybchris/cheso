# Cheso
Esoteric programming language by Chris (Pronounced CHAY-so)

## Project Description

This is not the first time I have attempted to make my own programming language. Back in high school I started to make a parser for writing Java programs in Spanish so that I could call a language my own. But I wasn't satisfied calling that my own language because it was built in Java and only accepted Java syntax. The motivation for this second attempt was building something in C and brushing up on my memory management and pointer manipulation. Additionally, a main source of inspiration for this project was my Programming Languages course (Tufts COMP105). Some of the languages we studied had interpreters designed by the professor. I was so fascinated by the simplicity of the code that can bring a language into existence that I had to try it out for myself. There is no complex syntax parser or anything like that, but Cheso does have two things going for it. It is Turing complete and the programs are horribly difficult to write. As you may note if you are familiar with esoteric programming languages, Cheso is a less legible and less vulgar version of the language BF.

## Compiling the Source

To compile the interpreter use the provided Makefile by running the `make` command in the directory with the source files. Then run a .cheso program file with the command: `./cheso program.cheso`

## Writing a Program

### Foundation

A Cheso program is a string of instructions. Each instruction is one character and blank space is ignored. There is an arbitrarily large number of registers to work with and each register can hold a large non-negative integer. The ASCII character corresponding to the integer in a register can be printed and the opposite operation is possible for inputting a character. Loops will continue to run as long as the current register is non-zero at the end of the loop.

### Syntax

* Start/end a loop - s/e
* Increment/decrement the current register - u/d
* Shift left or right one register - l/r
* Print the ASCII character in the current register - p
* Place a character taken as input in the current register - i

### Example Cheso Code

The following code will output `Hello intrepid programmer!`

```bash
uuuuuuuuuuuuuuu
s
ruruuuruuuuruuuuuruuuuuuruuruuuuuuuruuuuuuuu
lllllllld
e

rrrrdddp
rrrddddp
uuuuuuupp
uuup
luup
rddddddp
uuuuup
rddddp
ddp
ldddddddddp
rddp
luuuup
dddddp
lp
rrp
uup
dddp
luuup
ruuup
lddddddp
rdddddpp
luuuup
ruuuuup
llup
```