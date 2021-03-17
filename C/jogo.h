#include <stdio.h>
#include "cenas.h"
#include "helpers.h"

int proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(int numDaCena);
int proximaCenaPuzzle(Cena cenaAtiva, int sucesso);

void novoJogo()
{
  carregarCenas();
  loopDeCenas(0);
}

void loopDeCenas(int numDaCena)
{
  if (numDaCena < 0)
  {
    return;
  }
  else
  {
    clrscr();
    Cena cenaAtiva = CENAS[numDaCena];
    exibirCena(cenaAtiva);
    int escolha;
    int sucesso;
    switch (cenaAtiva.tipo)
    {
    case 0:
      waitForInput();
      return loopDeCenas(cenaAtiva.cenaDeSucesso);
      break;
    case 1:
      escolha = proximaCena(cenaAtiva);
      return loopDeCenas(escolha);
      break;
    case 2:
      sucesso = executarPuzzle(cenaAtiva.puzzle);
      escolha = proximaCenaPuzzle(cenaAtiva, sucesso);
      return loopDeCenas(escolha);
      break;
    case 3:
      waitForInput();
      return;
      break;
    // case 4:
    //   sucesso = chamarDiretoUmPuzzleEspecífico();
    //   escolha = proximaCenaPuzzle(cenaAtiva, sucesso);
    //   return loopDeCenas(escolha);
    //   break;
    default : printf("Erro de Cena: Tipo não implementado");
      break;
    }
  }
}

void exibirCena(Cena cena)
{
  printf("%s", cena.descricao);
}

int proximaCena(Cena cena)
{
  printf("Sua escolha: ");
  return readInt();
}

int proximaCenaPuzzle(Cena cenaAtiva, int sucesso)
{
  if (sucesso)
  {
    return cenaAtiva.cenaDeSucesso;
  }
  else
  {
    return cenaAtiva.cenaDeFalha;
  }
}
