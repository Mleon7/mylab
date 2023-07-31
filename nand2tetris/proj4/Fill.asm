// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// my version

    // @SCREEN
    // D=A
    // @address
    // M=D // address = 16384 (base address of the Hack screen)

    // // R1=8191， 重复8191次
    // @100
    // D=A
    // @R1
    // M=D

// KEYBOARD RAM[24576]

// (BLACK)

//     @R1
//     D=M
//     @END
//     D;JLE // if R1 <= 0 goto END

//     @address
//     A=M
//     M=-1    // RAM[address] = -1 (16 pixels)

//     @1
//     D=A
//     @address
//     M=D+M // address = address + 1

//     @R1
//     M=M-1 // R1 -= 1
//     @BLACK
//     0;JMP // goto BLACK

// (WHITE)

//     @R1
//     D=M
//     @END
//     D;JLE // if R1 <= 0 goto END

//     @address
//     A=M
//     M=0    // RAM[address] = -1 (16 pixels)

//     @1
//     D=A
//     @address
//     M=D+M // address = address + 1

//     @R1
//     M=M-1 // R1 -= 1
//     @WHITE
//     0;JMP // goto WHITE

// (END)
//     @END
//     0;JMP

// https://github.com/PKUFlyingPig/NandToTetris/blob/master/projects/04/project4/Fill.asm
// 这样来看，我的思路应该没错：在一个主循环中判断按键，然后根据按键来跳转到black或white，在里面执行8192次后再跳回主循环。

// len = 8192
    @8192   // 可以将这个值改小，再执行，有助于理解该程序
    D=A
    @len
    M=D

// To check which key is currently pressed:
// + Read the contents of RAM[24576] (address KBD)
// + If the register contains 0, no key is pressed
// + Otherwise, the register contains the scan code of the currently pressed kev
(LOOP1)
    @KBD
    D=M
    @WHITE
    D;JEQ
    @BLACK
    0;JMP

(WHITE)
    @i
    M=0

    (LOOP2)
        // 执行8192次后，跳回主循环
        // len - i == 0 时跳回主循环
        @len
        D=M
        @i
        D=D-M
        @LOOP1
        D;JEQ

        // 将屏幕address + i 对应的值改成0
        @SCREEN
        D=A
        @i
        A=D+M
        M=0

        // i = i + 1
        @i
        M=M+1

        @LOOP2
        0;JMP

(BLACK)
    @i
    M=0

    (LOOP3)
        @len
        D=M
        @i
        D=D-M
        @LOOP1
        D;JEQ

        @SCREEN
        D=A
        @i
        A=D+M
        M=-1

        @i
        M=M+1

        @LOOP3
        0;JMP
