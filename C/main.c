#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "helpers.h"

int escolhaValida(int escolha);
int menuDeEscolha();
void agradecimentos();
void creditos();
void menuLoop();

int main()
{
  creditos();
  menuLoop();
  agradecimentos();
}

void creditos()
{
  printf("Esse jogo é parte das avaliações da matéria de PE da UFABC.. feito por....");
  breakLines(2);
}

void agradecimentos()
{
  printf("Obrigado por jogar Nome do Jogo");
  breakLines(1);
}

// Essas duas funções são relacionadas ao menu de escolhas do jogo.
int menuDeEscolha()
{
  breakLines(1);
  printf("----------------------------------------");
  breakLines(2);
  printf("DIGITE J PARA JOGAR ou S PARA SAIR: ");
  int escolha = readChar();
  switch (escolha) {
  case 'S':
    return 0;
    break;
  case 'J':
    return 1;
    break;
  default:
    return menuDeEscolha();
    break;
  }
}

int escolhaValida(int escolha)
{
  return escolha == 1 || escolha == 0;
}

void menuLoop()
{
  int sair = 0;
  do
  {
    int opcaoEscolhida = menuDeEscolha();
    if (escolhaValida(opcaoEscolhida))
    {
      switch (opcaoEscolhida)
      {
      case 1:
        novoJogo();
        break;
      case 0:
        sair = 1;
        break;
      default:
        break;
      }
    } else {
      opcaoEscolhida = 3;
    }
  } while (sair != 1);
}
