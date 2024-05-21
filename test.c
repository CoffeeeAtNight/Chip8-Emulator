#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 0xF; // 15 == 11110000
  int b = 0x8; //  8 == 00001000
                    //  00001000
  a = b << 1;

  printf("%d\n", a);

  return 0;
}
