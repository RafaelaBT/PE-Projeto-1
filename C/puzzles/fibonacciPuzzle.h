#ifndef SEQUENCIA_FIBONACCI_H
#define SEQUENCIA_FIBONACCI_H

#include <stdio.h>
#include <string.h>
#include "puzzle.h"

int DESCRICAO_MAX_SIZE = PUZZLE_DESCRICAO_MAX_SIZE;
int RESPOSTA_MAX_SIZE = PUZZLE_RESPOSTA_MAX_SIZE;

int fibonnaci(int n);
Puzzle fibonacciPuzzle(int inicio, int quantidade, int desejado);

Puzzle fibonacciPuzzle(
  int inicio,
  int quantidade,
  int desejado
) {
  char descricao[DESCRICAO_MAX_SIZE];
  const int bufferSize = DESCRICAO_MAX_SIZE;
  int perElementBufferUsed, bufferUsed = 0;
  int bufferLeft = bufferSize - bufferUsed;

  for (int i = inicio; i < inicio + quantidade; i++) {
    if (bufferLeft > 0) {
      perElementBufferUsed = snprintf(&descricao[bufferUsed], bufferSize, "\n\t%i° = %i", i, fibonnaci(i));
      bufferUsed += perElementBufferUsed;
      bufferLeft -= perElementBufferUsed;
    }
  }
  if (bufferLeft >= 0) {
    perElementBufferUsed = snprintf(
      &descricao[bufferUsed],
      bufferSize,
      "\n\nDigite qual é o %i° número da sequência: ",
      desejado
    );
  }

  char resposta[RESPOSTA_MAX_SIZE];
  snprintf(&resposta[0], bufferSize, "%i", fibonnaci(desejado));

  Puzzle puzzle;
  strcpy(puzzle.descricao, descricao);
  strcpy(puzzle.resposta, resposta);
  return puzzle;
}

int fibonnaci(int n) {
  int a = 0;
  int b = 1;
  while (n-- > 1) {
      int t = a;
      a = b;
      b += t;
  }
  return b;
}

#endif
