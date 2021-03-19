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
  char * participantes[5] = {
    "Yves-Medhard Tibe da Cunha Tibe-Bi - RA: 21074414",
    "Lucas Emanuel Andrada Barboza - RA: 11201920925",
    "Carolina Baratto Barone - RA: 11201921793"
  };
  printf("Esse jogo é parte das avaliações da matéria de PE da UFABC Q1/21 feito por:\n");
  for (int i = 0; i < 5; i++)
  {
    if(participantes[i] != NULL)
      printf("\t%s\n", participantes[i]);

  }
}

void agradecimentos()
{
  printf("Obrigado por jogar Torre do Dragão.");
}

int menuDeEscolha()
{
  clrscr();
  printf("Digite uma das opções e pressione Enter para confirmar:\n1: Jogo Torre do Dragão\ns: Sair\nSua Escolha: ");
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
  return escolha == 0 ||
         escolha == 1;
}

void menuLoop()
{
  int sair = 0;
  do
  {
    int opcaoEscolhida = menuDeEscolha();
    if (escolhaValida(opcaoEscolhida))
    {
      if (opcaoEscolhida == 0)
      {
        sair = 1;
      }
      else
      {
        novoJogo(opcaoEscolhida);
      }
    }
    else
    {
      opcaoEscolhida = 3;
    }
  } while (sair != 1);
  free(CENAS);
}
