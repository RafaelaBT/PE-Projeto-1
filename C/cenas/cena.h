#ifndef CENA_H
#define CENA_H

#include <stdio.h>
#include <string.h>
#include "../puzzles/puzzle.h"

const int MAX_ESCOLHAS_POSSIVEIS = 10;
typedef struct Cena
{
  int tipo;
  char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
  Puzzle puzzle;
  struct Cena *cenaDeSucesso;
  struct Cena *cenaDeFalha;
  struct Cena *escolhasPossíveis[MAX_ESCOLHAS_POSSIVEIS];
  int maxEscolhas;
} Cena;

#endif
