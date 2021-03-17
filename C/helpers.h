#include <stdio.h>
#include <stdlib.h>

#ifndef HELPERS_H
#define HELPERS_H

int readInt();
char readChar();
void breakLines(int numeroDeLinhas);
void clrscr();
void waitForInput();
void myflush ( FILE *in );

int readInt()
{
  int value;
  scanf("%i", &value);
  return value;
}

char readChar()
{
  char value;
  value = getchar();
  myflush ( stdin );
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

void waitForInput()
{
  printf("Pressione 'Enter' para continuar. . .\n");
  fflush ( stdout );
  getchar();
  myflush ( stdin );
}

void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

#endif
