#include <stdio.h>
#include <string.h>
#include "puzzles/sequenciaFibonacci.h"

typedef struct
{
  int tipo;
  char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
  Puzzle puzzle;
  int cenaDeSucesso;
  int cenaDeFalha;
} Cena;
/* Tipo:
0 - Descrição: O jogador só pode seguir para o destino especificado.
1 - Escolha: O jogador pode escolher entre uma das opções disponíveis.
2 - Puzzle: O jogador resolve um Puzzle. Dependendo da resposta ele é levado para a cena de sucesso ou falha.
3 - Fim De Jogo: O jogo acaba nessa cena, não importa se é uma vitória ou derrota.
*/

const int MAX_CENAS = 10;
Cena CENAS[MAX_CENAS];

Cena * carregarCenas() {
  for (int i = 0; i < 3; i++) {
    Cena cena;
    strcpy(cena.descricao, "Uma porta se abre. Tu entra na próxima câmara que tem um quadro negro.\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(1 * (i + 1), 2 * (i+1), 3, "Voce vê no quadro um conjunto de números e um espaço vazio. Os número são: ");
    cena.cenaDeFalha = 9;
    cena.cenaDeSucesso = i + 1;
    CENAS[i] = cena;
  }
  for (int i = 5; i < 10; i++) {
    Cena cena;
    strcpy(cena.descricao, "Teste de cena descritiva. Você não tem opção a não ser ler e ir para a próxima cena determinada.\n");
    cena.tipo = 0;
    cena.cenaDeSucesso = i + 1;
    CENAS[i] = cena;
  }
  for (int i = 3; i < 5; i++) {
    Cena cena;
    strcpy(cena.descricao, "Teste de cenas de Escolha, para continuar digite o indíce da próxima cena.\n");
    cena.tipo = 1;
    CENAS[i] = cena;
  }
  CENAS[9].tipo = 3;
  strcpy(CENAS[9].descricao, "Ao errar uma luz vem dos ceus e fica cada vez mais intensa. Você falhou com o deus da matemática e será punido. Você é instantâneamente vaporizado e morre. Fim de jogo.\n");
  CENAS[8].tipo = 3;
  strcpy(CENAS[8].descricao, "Você é um gênio e os deuses da matemática sorriem para ti em aprovação. Tu ascenderá como o paladino de fibonacci. Fim de jogo\n");
  return CENAS;
}
