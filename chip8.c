#include <stdlib.h>
#include <stdio.h>

// Current opcode
unsigned short opcode;

// 4k bytes of memory
unsigned char memory[4096];

// Program counter (pc)
unsigned short pc;

// Display Size
unsigned char gfx[64 * 32];

// Timer to count down to 0
unsigned char delay_timer;
unsigned char sound_timer;

// Keypad
unsigned char key[16];

// Stack with 16 level and stack pointer (sp)
unsigned short stack[16];
unsigned short sp;

int main(int argc, char *argv[])
{

}