#include <stdio.h>
#include <stdint.h>
#include <mem.h>

int main() {
  uint16_t b = 2;
  uint16_t &refToB = b; // declare a reference to b
  char aString[30];
  strcpy(aString,"Moose!");
  printf("B is %i and the first character of aString is %c.\n",refToB, aString[0]); // use refToB instead of *addressOfB
  printf("But also, B is %i and the first character of aString is %c.\n",refToB, *aString); // use refToB instead of addressOfB[0]
}

