
#include <stdio.h>
#include "cenas.h"
#include "helpers.h"

int proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(int numDaCena);

void novoJogo() {
  carregarCenas();
  loopDeCenas(0);
}

void loopDeCenas(int numDaCena) {
  if(numDaCena < 0){
    return;
  } else {
    clrscr();
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

      return loopDeCenas(escolha);
    }
  }
}

void exibirCena(Cena cena) {
  printf("\n\n");
  printf("%s", cena.descricao);
}

int proximaCena(Cena cena) {
  printf("Sua escolha: ");
  return readInt();
}
