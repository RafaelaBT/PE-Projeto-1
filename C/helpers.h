
#include <stdio.h>
// some_header_file.h
#ifndef HELPERS_H
#define HELPERS_H
int readInt()
{
  int value;
  scanf("%i", &value);
  return value;
}

char readChar()
{
  char value;
  scanf("%c", &value);
  return value;
}

void breakLines(int numeroDeLinhas)
{
  for (int i = 0; i < numeroDeLinhas; i++)
  {
    printf("\n");
  }
}
#endif
