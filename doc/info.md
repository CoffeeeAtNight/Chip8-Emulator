System Memory Map

0x000 - 0x1FF - Chip 8 Interpreter (contains font set in emulator)
0x050 - 0x0A0 - Used for the built in 4x5 pixel font set (0-F)
0x200 - 0xFFF - Program ROM and work RAM


Sound

Whenever the sound timer reaches `0`, the system buzzes a sound.