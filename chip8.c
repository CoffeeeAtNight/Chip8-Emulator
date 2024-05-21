#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

typedef struct
{
  uint8_t memory[4096]; // Memory of Chip8
  uint8_t V[16];        // General purpose registers
  uint16_t I;           // Index register
  uint16_t pc;          // Program counter
  uint8_t gfx[64 * 32]; // Display
  uint8_t keypad[16];   // Keypad state
  uint16_t stack[16];   // Stack in Chip8
  uint8_t sp;           // Stack pointer
  uint8_t delay_timer;  // Delay timer
  uint8_t sound_timer;  // Sound timer
} Chip8;

void initialize(Chip8 *chip8);
void loadROM(Chip8 *chip8, const char *filename);
void emulateCycle(Chip8 *chip8);
void clearScreen(Chip8 *chip8);
void push(Chip8 *chip8, uint16_t value);
uint16_t pop(Chip8 *chip8);
void updateTimers(Chip8 *chip8);

int main(int argc, char **argv)
{
  Chip8 chip8;
  initialize(&chip8);

  if (argc < 2)
  {
    printf("Usage: %s <ROM file>\n", argv[0]);
    return 1;
  }

  while (1)
  {
    emulateCycle(&chip8);
  }
}

void initialize(Chip8 *chip8)
{
  chip8->pc = 0x200;
  chip8->I = 0;
  chip8->sp = 0;
  chip8->sound_timer = 0;
  chip8->delay_timer = 0;

  memset(chip8->memory, 0, 4096);
  memset(chip8->V, 0, 16);
  memset(chip8->stack, 0, 16);
  memset(chip8->keypad, 0, 16);
  memset(chip8->stack, 0, 64*32);
}

void loadROM(Chip8 *chip8, const char *filename)
{
}

void emulateCycle(Chip8 *chip8)
{
  // Fetch opcode
  uint16_t opcode = chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
  chip8->pc += 2;

  // Decode opcode

  // Execute opcode
}

void clearScreen(Chip8 *chip8)
{
}

void push(Chip8 *chip8, uint16_t value)
{
}

uint16_t pop(Chip8 *chip8)
{
  return 0;
}

void updateTimers(Chip8 *chip8)
{
}
