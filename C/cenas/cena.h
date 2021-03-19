#ifndef CENA_H
#define CENA_H

#include <stdio.h>
#include <string.h>
#include "../puzzles/puzzle.h"

const int MAX_ESCOLHAS_POSSIVEIS = 10;
typedef struct Cena
{
  int id;
  int tipo;
  char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
  Puzzle puzzle;
  struct Cena *cenaDeSucesso;
  struct Cena *cenaDeFalha;
  struct Cena *escolhasPossiveis[MAX_ESCOLHAS_POSSIVEIS];
  int maxEscolhas;
} Cena;
/* Cenas Tipo:
0 - Descricão
1 - Escolha
2 - Puzzle
3 - Fim de Jogo
4 - Senha
5 - Poções
6 - Palavras
7 - Imagem ASCII
*/

int CURRENT_CENAS = 1; // The Cena 0 is reserved to the intro Cena tha is not a pointer.
Cena *CENAS;
Cena *adicionarCena(Cena cena);
Cena *encontrarCena(int id);
int cenaRegistrada(Cena cena);

Cena *adicionarCena(Cena cena)
{
  printf("Identificador de Cena %i\n", cena.id);
  if (cenaRegistrada(cena))
  {
    return encontrarCena(cena.id);
  }
  else
  {
    printf("Adicionando Cena %i\n", CURRENT_CENAS);
    CENAS[CURRENT_CENAS] = cena;
    return &CENAS[CURRENT_CENAS++];
  }
}

int cenaRegistrada(Cena cena)
{
  for (int i = 0; i <= CURRENT_CENAS; i++)
  {
    if (CENAS[i].id == cena.id)
    {
      return 1;
    }
  }
  return 0;
}

Cena *encontrarCena(int id)
{
  int i = -1;
  for (int i = 0; i <= CURRENT_CENAS; i++)
  {
    if (CENAS[i].id == id)
    {
      return &CENAS[i];
      break;
    }
  }
  return NULL;
}
#endif
