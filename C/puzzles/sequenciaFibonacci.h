#include <stdio.h>
#include <string.h>
#include "../puzzles.h"

int DESCRICAO_MAX_SIZE = PUZZLE_DESCRICAO_MAX_SIZE;
int RESPOSTA_MAX_SIZE = PUZZLE_RESPOSTA_MAX_SIZE;

int fibonnaci(int n);
char * descricaoInicio();
Puzzle fibonacciPuzzle(int inicio, int quantidade, int desejado, char * descricaoInicial);

Puzzle fibonacciPuzzle(
  int inicio,
  int quantidade,
  int desejado,
  char * descricaoInicial
) {
  char descricao[DESCRICAO_MAX_SIZE];
  const int bufferSize = sizeof(descricao)/sizeof(descricao[0]) - 1;
  int perElementBufferUsed, bufferUsed = 0;
  int bufferLeft = bufferSize - bufferUsed;

  perElementBufferUsed = snprintf(descricao, bufferSize, "%s", descricaoInicial);
  bufferUsed += perElementBufferUsed;
  bufferLeft -= perElementBufferUsed;

  for (int i = inicio; i <= quantidade; i++) {
    if (bufferLeft >= 0) {
      if (i == quantidade) {
        perElementBufferUsed = snprintf(&descricao[bufferUsed], bufferSize, "%i", fibonnaci(i));
      } else {
        perElementBufferUsed = snprintf(&descricao[bufferUsed], bufferSize, "%i, ", fibonnaci(i));
      }
      bufferUsed += perElementBufferUsed;
      bufferLeft -= perElementBufferUsed;
    }
  }
  if (bufferLeft >= 0) {
    perElementBufferUsed = snprintf(
      &descricao[bufferUsed],
      bufferSize,
      "\n Digite qual é o %i° número da sequência: ",
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
