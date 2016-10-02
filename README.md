# Cheso
Esoteric programming language by Chris

## Description

This is not the first time I have attempted to make my own programming language. Back in high school I started to make a parser for writing Java programs in Spanish so that I could call a language my own. But I wasn't satisfied calling that my own language because it was built in Java and only accepted Java syntax. The motivation for this second attempt was building something in C and brushing up on my memory management and pointer manipulation. Additionally, a main source of inspiration for this project was my Programming Languages course (Tufts COMP105). Some of the languages we studied had interpreters designed by the professor. I was so fascinated by the simplicity of the code that can bring a language into existence that I had to try it out for myself. There is no complex syntax parser or anything like that, but Cheso does have two things going for it. It is Turing complete and the syntax is utterly horrendous.

## Instructions

* Loops - s/e
* Inc/Dec Register - u/d
* Shift Registers - l/r
* Print ascii character - p
* Take character input - i

## Using the Language

To compile the interpreter use the provided Makefile by running `make` in the directory with the source files. Then run a .cheso program file with the command: `./cheso < program.cheso`

## Example Code

`uuuup` > `4`