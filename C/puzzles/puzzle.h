#ifndef PUZZLES_H
#define PUZZLES_H

#include <stdio.h>
#include <string.h>
const int PUZZLE_DESCRICAO_MAX_SIZE = 1024;
const int PUZZLE_RESPOSTA_MAX_SIZE = 1024;

typedef struct {
  char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
  char resposta[PUZZLE_RESPOSTA_MAX_SIZE];
} Puzzle;

int respostaCorreta(char * resposta, Puzzle puzzle);
int executarPuzzle(Puzzle puzzle);

int respostaCorreta(char * resposta, Puzzle puzzle) {
  return strcmp(resposta, puzzle.resposta);
}

int executarPuzzle(Puzzle puzzle) {
  printf("%s", puzzle.descricao);
  char resposta[PUZZLE_RESPOSTA_MAX_SIZE];
  scanf(" %s", resposta);
  if (respostaCorreta(resposta, puzzle)) {
    return 0;
  } else {
    return 1;
  }
}

#endif
