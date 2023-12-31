// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

// init R2=0
@R2
D=0
M=D

// while R[1] != 0: R[1] -= 1
(LOOP)

    @R1
    D=M
    @END
    D;JLE // if R1 <= 0 goto END

    // RAM[2] = RAM[2] + RAM[0]
    @R0
    D=M

    @R2
    D = D + M
    M = D

    @R1
    M=M-1 // R1 -= 1
    @LOOP
    0;JMP // goto loop

(END)
    @END
    0;JMP