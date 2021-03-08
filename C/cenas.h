#include <stdio.h>
#include <string.h>

/* A estrutura de Cena é essencial para o jogo pois ela guarda toda a informação que precisamos para rodar o
loopDeCenas no jogo. Cada cena sabe se é um fim de jogo, tem uma descrição para o player e conforme formos adicionando complexidade vai ter outros atributos como por exemplo as cenas a que ela leva, se ela possui combate e quais são os oponentes, ou se ela tem efeitos no jogador.
A estrutura básica para ter a história é essa e a ideia é evoluir ela.
*/
typedef struct
{
  int fimDeJogo;
  char descricao[240];
} Cena;

const int MAX_CENAS = 10;
Cena CENAS[MAX_CENAS];

/* esse método deve mudar para algo que leia de algum lugar as cenas. Por simplicidade para o P1 podemos
só declarar todas elas. Para um segundo momento podemos ler do arquivo e iterar.
Esse método pode receber parâmetros no futuro caso tenhamos mais de uma história por exemplo.
*/
Cena * carregarCenas() {
  for (int i = 0; i < 10; i++) {
    Cena cena;
    cena.fimDeJogo = 0;
    strcpy(cena.descricao, "Teste de cenas, para continuar digite o indíce da próxima cena.\n");
    CENAS[i] = cena;
  }
  CENAS[9].fimDeJogo = 1;
  strcpy(CENAS[9].descricao, "Fim de jogo, Você perdeu\n");
  CENAS[8].fimDeJogo = 1;
  strcpy(CENAS[8].descricao, "Fim de jogo, Você ganhou\n");
  return CENAS;
}
