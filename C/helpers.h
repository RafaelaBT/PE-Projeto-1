#include <stdio.h>
#include <stdlib.h>

#ifndef HELPERS_H
#define HELPERS_H

int readInt();
char readChar();
void breakLines(int numeroDeLinhas);
void clrscr();

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

void clrscr()
{
  if (system("CLS")) system("clear");
}

#endif
