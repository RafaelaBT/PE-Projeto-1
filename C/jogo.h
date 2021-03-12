
#include <stdio.h>
#include "cenas.h"
#include "helpers.h"

int proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(int numDaCena);

void novoJogo() {
  printf("Novo Jogo\n");
  carregarCenas();

  loopDeCenas(0);
  /* defini que a cena 0 é a inicial por simplicidade
  Se for o caso podemos transformar em uma Constante e dependendo do jogo começa em um indice diferente.
  */
}

/* Esse loopDeCenas atua como um função recursiva que explora o uso da variável global com todas as cenas disponíveis
e recursão de cauda ao definir qual é a próxima cena.
As principais mecânicas de jogo vão ser chamadas aqui através de outras funções que podem ser especializadas.
*/
void loopDeCenas(int numDaCena) {
  //Arrays não podem ter indices negativos isso previne qualquer input errado de executar essa função
  if(numDaCena < 0){
    return;
  } else {
    Cena cenaAtiva = CENAS[numDaCena];
    exibirCena(cenaAtiva);
    if(cenaAtiva.fimDeJogo) {
      return;
    } else if (cenaAtiva.temPuzzle) {
      int sucesso = executarPuzzle(cenaAtiva.puzzle);
      if (sucesso) {
        return loopDeCenas(cenaAtiva.cenaDeSucesso);
      } else {
        return loopDeCenas(cenaAtiva.cenaDeFalha);
      }
    } else {
      int escolha = proximaCena(cenaAtiva);
      // O retorno é nessa função para utilizar recursão de cauda.
      return loopDeCenas(escolha);
    }
  }
}

/* Podemos colocar aqui a forma de exibir a cena.
Podemos evoluir ela para ter outras propriedades a serem exploradas nessa parte do programa */
void exibirCena(Cena cena) {
  printf("\n\n");
  printf("%s", cena.descricao);
}

// Aqui podemos evoluir a cena para ter a lista de próximas cenas disponíveis e nessa função validar isso. Podemos trazder mais tipos de iteração também (como por exemplo se a cena permitir fazer um combate antes de trocar de cena).
int proximaCena(Cena cena) {
  printf("Sua escolha: ");
  return readInt();
}
