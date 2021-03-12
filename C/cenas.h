#include <stdio.h>
#include <string.h>
#include "puzzles/sequenciaFibonacci.h"

typedef struct
{
  int fimDeJogo;
  char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
  int temPuzzle;
  Puzzle puzzle;
  int cenaDeSucesso;
  int cenaDeFalha;
} Cena;

const int MAX_CENAS = 10;
Cena CENAS[MAX_CENAS];

Cena * carregarCenas() {
  for (int i = 0; i < 8; i++) {
    Cena cena;
    cena.fimDeJogo = 0;
    strcpy(cena.descricao, "Uma porta se abre. Tu entra na próxima câmara que tem um quadro negro.\n");
    cena.temPuzzle = 1;
    cena.puzzle = fibonacciPuzzle(1 * (i + 1), 2 * (i+1), 3 * (i + 1), "Voce vê no quadro um conjunto de números e um espaço vazio. Os número são: ");
    cena.cenaDeFalha = 9;
    cena.cenaDeSucesso = i + 1;
    CENAS[i] = cena;
  }
  for (int i = 8; i < 10; i++) {
    Cena cena;
    cena.fimDeJogo = 0;
    strcpy(cena.descricao, "Teste de cenas, para continuar digite o indíce da próxima cena.\n");
    cena.temPuzzle = 0;
    CENAS[i] = cena;
  }
  CENAS[9].fimDeJogo = 1;
  strcpy(CENAS[9].descricao, "Ao errar uma luz vem dos ceus e fica cada vez mais intensa. Você falhou com o deus da matemática e será punido. Você é instantâneamente vaporizado e morre. Fim de jogo.\n");
  CENAS[8].fimDeJogo = 1;
  strcpy(CENAS[8].descricao, "Você é um gênio e os deuses da matemática sorriem para ti em aprovação. Tu ascenderá como o paladino de fibonacci. Fim de jogo\n");
  return CENAS;
}
