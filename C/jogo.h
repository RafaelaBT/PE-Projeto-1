#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include "cenas/cena.h"
#include "cenas/torreDoDragao.h"
#include "helpers.h"

void novoJogo(int jogoEscolhido);
Cena carregarJogo(int jogo);
Cena jogoNãoImplementado();
Cena proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(Cena cenaAtiva);
Cena proximaCenaPuzzle(Cena cenaAtiva, int sucesso);


void novoJogo(int jogoEscolhido)
{
  Cena inicio = carregarJogo(jogoEscolhido);
  loopDeCenas(inicio);
}

Cena carregarJogo(int jogo) {
  switch (jogo)
  {
  case 1:
    return jogoTorreDoDragão();
    break;
  default:
    printf("Erro de Jogo: Jogo não implementado");
    return jogoNãoImplementado();
    break;
  }
}

void loopDeCenas(Cena cenaAtiva)
{
  clrscr();
  exibirCena(cenaAtiva);
  int escolha;
  int sucesso;
  switch (cenaAtiva.tipo)
  {
  case 0:
    waitForInput();
    return loopDeCenas(*cenaAtiva.cenaDeSucesso);
    break;
  case 1:
    return loopDeCenas(proximaCena(cenaAtiva));
    break;
  case 2:
    sucesso = executarPuzzle(cenaAtiva.puzzle);
    return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
    break;
  case 3:
    waitForInput();
    return;
    break;
  // case 4:
  //   sucesso = chamarDiretoUmPuzzleEspecifico();
  //   return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
  //   break;
  default:
    printf("Erro de Cena: Tipo não implementado");
    break;
  }
}

void exibirCena(Cena cena)
{
  printf("%s", cena.descricao);
}

Cena proximaCena(Cena cenaAtiva)
{
  printf("\n\nSua escolha: ");
  int escolha = readInt();
  if (escolha >= 0 && escolha < cenaAtiva.maxEscolhas){
    return *cenaAtiva.escolhasPossiveis[escolha];
  } else {
    printf("Escolha inválida. Por favor escolha novamente\n");
    return proximaCena(cenaAtiva);
  }
}

Cena proximaCenaPuzzle(Cena cenaAtiva, int sucesso)
{
  if (sucesso)
  {
    return *cenaAtiva.cenaDeSucesso;
  }
  else
  {
    return *cenaAtiva.cenaDeFalha;
  }
}

Cena jogoNãoImplementado() {
  Cena cena;
  cena.tipo = 3;
  strcpy(cena.descricao, "Jogo não implementado, Escolha outro jogo");
  return cena;
}

#endif
