#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include "cenas/cena.h"
#include "cenas/torreDoDragao.h"
#include "helpers.h"
#include "images/image.h"

void novoJogo(int jogoEscolhido);
Cena carregarJogo(int jogo);
Cena jogoNaoImplementado();
Cena proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(Cena cenaAtiva);
Cena proximaCenaPuzzle(Cena cenaAtiva, int sucesso);

void novoJogo(int jogoEscolhido)
{
  Cena inicio = carregarJogo(jogoEscolhido);
  loopDeCenas(inicio);
}

Cena carregarJogo(int jogo)
{
  switch (jogo)
  {
  case 1:
    return jogoTorreDoDragao();
    break;
  default:
    printf("Erro de Jogo: Jogo nao implementado");
    return jogoNaoImplementado();
    break;
  }
}

void loopDeCenas(Cena cenaAtiva)
{
  clrscr();

  int escolha;
  int sucesso;
  switch (cenaAtiva.tipo)
  {
  case 0:
    exibirCena(cenaAtiva);
    waitForInput();
    return loopDeCenas(*cenaAtiva.cenaDeSucesso);
    break;
  case 1:
    exibirCena(cenaAtiva);
    return loopDeCenas(proximaCena(cenaAtiva));
    break;
  case 2:
    exibirCena(cenaAtiva);
    sucesso = executarPuzzle(cenaAtiva.puzzle);
    return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
    break;
  case 3:
    exibirCena(cenaAtiva);
    waitForInput();
    return;
    break;
  case 4:
    exibirCena(cenaAtiva);
    sucesso = puzzleSenha();
    return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
    break;
  case 5:
    exibirCena(cenaAtiva);
    sucesso = puzzlePocao();
    return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
    break;
  case 6:
    exibirCena(cenaAtiva);
    sucesso = palavrasPuzzle(5);
    return loopDeCenas(proximaCenaPuzzle(cenaAtiva, sucesso));
    break;
  case 7:
    printImage(cenaAtiva.descricao);
    waitForInput();
    return loopDeCenas(*cenaAtiva.cenaDeSucesso);
    break;
  default:
    printf("Erro de Cena: Tipo nao implementado");
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
  if (escolha >= 0 && escolha < cenaAtiva.maxEscolhas)
  {
    return *cenaAtiva.escolhasPossiveis[escolha];
  }
  else
  {
    printf("Escolha invalida. Por favor escolha novamente\n");
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

Cena jogoNaoImplementado()
{
  Cena cena;
  cena.tipo = 3;
  strcpy(cena.descricao, "Jogo nao implementado, Escolha outro jogo");
  return cena;
}

#endif
