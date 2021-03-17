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
  clrscr();
  creditos();
  waitForInput();
  menuLoop();
  agradecimentos();
}

void creditos()
{
  printf("Esse jogo é parte das avaliações da matéria de PE da UFABC.. feito por....");
}

void agradecimentos()
{
  printf("Obrigado por jogar Torre do Dragão");
}

int menuDeEscolha()
{
  clrscr();
  printf("Digite uma das opções e pressione Enter para confimrar:\n1: Jogo Torre do Dragão\ns: Sair\nSua Escolha: ");
  int escolha = readChar();
  switch (escolha)
  {
  case 'S':
    return 0;
    break;
  case 's':
    return 0;
    break;
  case '1':
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
        novoJogo(opcaoEscolhida);
        break;
      case 0:
        sair = 1;
        break;
      default:
        break;
      }
    }
    else
    {
      opcaoEscolhida = 3;
    }
  } while (sair != 1);
}
