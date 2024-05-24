#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <SFML/Graphics.h>

typedef struct
{
  uint8_t memory[4096];     // Memory of Chip8
  uint8_t V[16];            // General purpose registers
  uint16_t I;               // Index register
  uint16_t pc;              // Program counter
  uint8_t display[64 * 32]; // Display
  uint8_t keypad[16];       // Keypad state
  uint16_t stack[16];       // Stack in Chip8
  uint8_t sp;               // Stack pointer
  uint8_t delay_timer;      // Delay timer
  uint8_t sound_timer;      // Sound timer
  uint8_t current_opcode;   // Opcode currently in use
} Chip8;

void initialize(Chip8 *chip8);
void loadROM(Chip8 *chip8, const char *filename);
void emulateCycle(Chip8 *chip8);
uint8_t fetchOpcode(Chip8 *chip8);
void execute_instruction(Chip8 *chip8, uint8_t);
void clearScreen(Chip8 *chip8);
void push(Chip8 *chip8, uint16_t value);
uint16_t pop(Chip8 *chip8);
void updateTimers(Chip8 *chip8);

int main(int argc, char *argv[])
{
  Chip8 chip8;
  initialize(&chip8);

  if (argc < 2)
  {
    printf("Usage: %s <ROM file>\n", argv[0]);
    return 1;
  }

  loadROM(&chip8, argv[1]);
  // for (size_t i = 0; i < 10; i++)
  // {
  //   emulateCycle(&chip8); // DEBUG
  // }

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
  memset(chip8->display, 0, 64 * 32);
}

void loadROM(Chip8 *chip8, const char *filename)
{
  // Open a file stream from the ROM
  FILE *pRom = fopen(filename, "rb");
  if (pRom == NULL)
  {
    fputs("Error occurred reading rom", stdout);
    exit(-1);
  }

  // Get the file size
  fseek(pRom, 0, SEEK_END);
  long romSize = ftell(pRom);
  rewind(pRom);

  printf("Filesize: %d\n", (int)romSize);

  // Read ROM data into chip8 memory at offset 0x200
  size_t bytesRead = fread(&chip8->memory[0x200], 1, 4096 - 0x200, pRom);
  if (bytesRead != romSize)
  {
    perror("Failed to read ROM");
    fclose(pRom);
    exit(-1);
  }

  fclose(pRom);
}

void emulateCycle(Chip8 *chip8)
{
  // Fetch opcode
  uint8_t opcode = fetchOpcode(chip8);

  // Decode & execute instruction
  execute_instruction(chip8, opcode);
}

uint8_t fetchOpcode(Chip8 *chip8)
{
  uint8_t opcode = chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
  chip8->pc += 2;
  return opcode;
}

void execute_instruction(Chip8 *chip8, uint8_t opcode)
{

  switch (opcode & 0xF000)
  {
    case 0x0000:
      switch (opcode & 0x00FF)
      {
        case 0x00E0:
          printf("Instruction Clear screen (00E0)\n");
          clear_display();
          break;

        case 0x00EE:
          printf("Instruction Return from Subroutine (00EE)\n");
          //return_from_subroutine(chip8);
          break;

        default:
          printf("ERROR: Unrecognized opcode 0x%X\n", opcode);
          exit(EXIT_FAILURE);
      }
    break;

    // case 0x00E0:
    //   printf("Instruction Jump (1NNN)\n");
    //   clear_display(chip8);
    //   break;
  }
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

void logOpcode(uint16_t opcode)
{
  const char *fileName = "./roms/ibm-logo/log/opcode_list";
  FILE *pLog;
  if (access(fileName, F_OK) != 0)
  {
    pLog = fopen(fileName, "w");
    if (pLog == NULL)
    {
      fputs("Error occurred creating opcode log", stdout);
      exit(-1);
    }

    return;
  }

  FILE *pRom = fopen(fileName, "a");
  if (pRom == NULL)
  {
    fputs("Error occurred creating opcode log", stdout);
    exit(-1);
  }
}
