#ifndef POTION_DOMINO_H
#define POTION_DOMINO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../helpers.h"

typedef struct PecaDomino
{
    int lado_1; //esquerda
    int lado_2; //direita
    int direcao;
    struct PecaDomino *proxima;
}PecaDomino;

typedef struct Valores
{
    int numero_1;
    int numero_2;
}Valores;

int horizontal = 0, vertical = 1, qntPecas = 28, pecasUtilizadas = 0, empate = 0;
PecaDomino *monte, *tabuleiro_esquerda, *tabuleiro_direita;

PecaDomino* criarMonte();
void imprimirPecas(PecaDomino *pecasImprimir);
void imprimirVertical(PecaDomino *peca, int linha);
void imprimirHorizontal(PecaDomino *peca, int linha);
PecaDomino* comprarPecas(PecaDomino *monte_adicionar, int quantidade);
int checarSeConsegueJogar(PecaDomino *monteChecar, int lado);
PecaDomino* adicionarAoTabuleiro(PecaDomino *jogador, int peca, int lado);
PecaDomino* vezDoJogador(PecaDomino *jogador, int podeComprar);
PecaDomino* vezDoComputador(PecaDomino* computador, int podeComprar);
void limparMemoria(PecaDomino* monteParaApagar);

PecaDomino* criarMonte()
{
    //colocar peças em ordem aleatória
    Valores valor[qntPecas];
    int contador = 0;
    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i < 7; i++)
    {
        for(int j = i; j < 7; j++)
        {
            valor[contador].numero_1 = i;
            valor[contador].numero_2 = j;
            contador++;
        }
    }

    for(int i = 0; i < qntPecas; i++)
    {
        int peca_aleatoria = rand()%qntPecas;

        Valores temporario;
        temporario.numero_1 = valor[peca_aleatoria].numero_1;
        temporario.numero_2 = valor[peca_aleatoria].numero_2;

        valor[peca_aleatoria] = valor[i];
        valor[i] = temporario;
    }


    //criar as peças já em ordem aleatória
    PecaDomino *monte_head = NULL, *temp = NULL, *cont = NULL;

    for(int i = 0; i < qntPecas; i++)
    {
        PecaDomino *temp = malloc(sizeof(PecaDomino));

        temp->lado_1 = valor[i].numero_1;
        temp->lado_2 = valor[i].numero_2;

        if(valor[i].numero_1 == valor[i].numero_2)
        {
            temp->direcao = vertical;
        }
        else
        {
            temp->direcao = horizontal;
        }

        temp->proxima = NULL;

        if(monte_head == NULL)
        {
            monte_head = temp;
        }
        else
        {
            cont = monte_head;
            while(cont->proxima != NULL)
            {
                cont = cont->proxima;
            }
            cont->proxima = temp;
        }
    }

    return monte_head;
}

void imprimirVertical(PecaDomino *peca, int linha)
{
    switch(linha)
    {
        case 0:
            printf("  _  ");
            break;
        case 1:
            printf(" |%d| ", peca->lado_1);
            break;
        case 2:
            printf(" |-| ");
            break;
        case 3:
            printf(" |%d| ", peca->lado_2);
            break;
        case 4:
            printf("     ");
            break;
    }
}

void imprimirHorizontal(PecaDomino *peca, int linha)
{
    switch(linha){
        case 0:
            printf("     ");
            break;
        case 1:
            printf(" ___ ");
            break;
        case 2:
            printf("|%d|%d|", peca->lado_1, peca->lado_2);
            break;
        case 3:
            printf("     ");
            break;
        case 4:
            printf("     ");
            break;
    }
}

void imprimirPecas(PecaDomino *pecasImprimir)
{
    PecaDomino *cont = pecasImprimir;
    for(int linha = 0; linha < 5; linha++)
    {
        while(cont != NULL)
        {
            if(cont->direcao == vertical)
            {
                imprimirVertical(cont, linha);
            }
            else
            {
                imprimirHorizontal(cont, linha);
            }
            cont = cont->proxima;
        }
        printf("\n");
        cont = pecasImprimir;
    }

}

PecaDomino* comprarPecas(PecaDomino *monte_adicionar, int quantidade)
{
    PecaDomino *temp = NULL;
    for(int i = 0; i < quantidade; i++)
    {
        if(monte == NULL)
        {
            printf("Nao ha mais pecas no monte de compra.\n");
            empate++;
            return NULL;
        }
        else
        {
            temp = monte;
            monte = monte->proxima;
            temp->proxima = monte_adicionar;
            monte_adicionar = temp;
        }
    }
    return monte_adicionar;
}

int checarSeConsegueJogar(PecaDomino *pecaChecar, int lado)
{
    switch(lado){
        case 1: //esquerda
            if((pecaChecar->lado_1 == tabuleiro_esquerda->lado_1) || (pecaChecar->lado_2 == tabuleiro_esquerda->lado_1))
            {
                return 1;
            }
            break;
        case 2: //direita
            if((pecaChecar->lado_1 == tabuleiro_direita->lado_2) || (pecaChecar->lado_2 == tabuleiro_direita->lado_2))
            {
                return 1;
            }
            break;
    }
    return 0;
}

PecaDomino* adicionarAoTabuleiro(PecaDomino *jogador, int peca, int lado)
{
    int podeJogar, cont = 1, aux;
    PecaDomino *pecaParaJogar = NULL, *anterior = NULL, *temp = NULL;
    pecaParaJogar = jogador;

    while(cont != peca)
    {
        anterior = pecaParaJogar;
        pecaParaJogar = pecaParaJogar->proxima;
        cont++;
    }

    podeJogar = checarSeConsegueJogar(pecaParaJogar, lado);

    if(podeJogar == 1)
    {
        //arrumar a mao do jogador
        if(peca == 1)
        {
            jogador = jogador->proxima;
        }
        else
        {
            anterior->proxima = pecaParaJogar->proxima;
        }

        //adicionar ao tabuleiro
        switch(lado){
            case 1: //esquerda
                if(tabuleiro_esquerda->lado_1 != pecaParaJogar->lado_2) //precisa mudar a posicao
                {
                    aux = pecaParaJogar->lado_1;
                    pecaParaJogar->lado_1 = pecaParaJogar->lado_2;
                    pecaParaJogar->lado_2 = aux;
                }
                pecaParaJogar->proxima = tabuleiro_esquerda;
                tabuleiro_esquerda = pecaParaJogar;
                break;

            case 2: //direita
                if(tabuleiro_direita->lado_2 != pecaParaJogar->lado_1) //precisa mudar a posicao
                {
                    aux = pecaParaJogar->lado_1;
                    pecaParaJogar->lado_1 = pecaParaJogar->lado_2;
                    pecaParaJogar->lado_2 = aux;
                }
                pecaParaJogar->proxima = NULL;
                tabuleiro_direita->proxima = pecaParaJogar;
                tabuleiro_direita = pecaParaJogar;
                break;
        }
    }
    else
    {
        printf("\nEssa peca nao pode ser jogada nesse lado do tabuleiro, tente de novo.");
        vezDoJogador(jogador, 1);
    }

    return jogador;
}

PecaDomino* vezDoJogador(PecaDomino *jogador, int podeComprar)
{
    int pecaEscolhida, qnt = 1, podeJogar = 0, ladoEscolhido;
    PecaDomino *cont = NULL;

    waitForInput();
    clrscr();

    printf("Tabuleiro:\n");
    imprimirPecas(tabuleiro_esquerda);
    printf("Sua mao:\n");
    imprimirPecas(jogador);

    cont = jogador;
    while(cont != NULL)
    {
        podeJogar += checarSeConsegueJogar(cont, 1); //lado esquerdo do tabuleiro
        podeJogar += checarSeConsegueJogar(cont, 2); //lado direito do tabuleiro
        printf("  %d  ", qnt);
        qnt++;
        cont = cont->proxima;
    }

    if(podeJogar >= 1)
    {
        printf("\n\nQual peca voce vai jogar?\n\nDigite um numero: ");
        scanf("%d", &pecaEscolhida);

        printf("\n\nEm qual lado do tabuleiro voce quer jogar?\n[1] Esquerda     [2] Direita\n\nDigite um numero: ");
        scanf("%d", &ladoEscolhido);

        jogador = adicionarAoTabuleiro(jogador, pecaEscolhida, ladoEscolhido);

        imprimirPecas(tabuleiro_esquerda);
    }
    else
    {
        if(podeComprar == 1)
        {
            printf("\n\nVoce nao pode jogar nenhuma das suas pecas e compra uma do monte\n");
            podeComprar = 0;
            jogador = comprarPecas(jogador, 1);

            jogador = vezDoJogador(jogador, podeComprar);
        }
        else
        {
            printf("\n\nVoce nao possui nenhum movimento disponivel\n");
            empate++;
        }
    }
    return jogador;
}

PecaDomino* vezDoComputador(PecaDomino* computador, int podeComprar)
{
    PecaDomino *cont = NULL;
    int podeJogar = 0, lado = 0, aux, peca = 0;

    waitForInput();
    clrscr();

    cont = computador;
    while(cont != NULL)
    {
        peca++;
        podeJogar += checarSeConsegueJogar(cont, 1); //lado esquerdo do tabuleiro
        podeJogar += checarSeConsegueJogar(cont, 2); //lado direito do tabuleiro
        if(podeJogar != 0)
        {
            break;
        }
        cont = cont->proxima;
    }

    if(podeJogar != 0)
    {
        lado = checarSeConsegueJogar(cont, 1); //pode jogar no lado esquerdo
        if(lado == 1)
        {
            computador = adicionarAoTabuleiro(computador, peca, 1);
        }
        else
        {
            computador = adicionarAoTabuleiro(computador, peca, 2);
        }

        printf("Jogou uma peca no tabuleiro.\n\n");
    }
    else
    {
        if(podeComprar == 1)
        {
            printf("Seu oponente comprou uma peca.\n\n");
            comprarPecas(computador, 1);
            podeComprar = 0;
            vezDoComputador(computador, podeComprar);
        }
        else
        {
            printf("Passou a vez.\n\n");
            empate++;
        }
    }
    return computador;
}

void limparMemoria(PecaDomino* monteParaApagar)
{
    if(monteParaApagar != NULL)
    {
        PecaDomino *apagar;
        while(monteParaApagar != NULL)
        {
            apagar = monteParaApagar;
            monteParaApagar = monteParaApagar->proxima;
            free(apagar);
        }
        free(monteParaApagar);
    }
}

int puzzleDomino()
{
  PecaDomino *monteJogador = NULL;
  PecaDomino *monteComputador = NULL;
  for(int tentativas = 0; tentativas < 3; tentativas++){

      monte = criarMonte();

      //criar monte do jogador e do computador
      monteJogador = NULL;
      monteJogador = comprarPecas(monteJogador, 7);

      monteComputador = NULL;
      monteComputador = comprarPecas(monteComputador, 7);

      //iniciar o tabuleiro
      tabuleiro_esquerda = NULL;
      tabuleiro_direita = NULL;
      tabuleiro_esquerda = comprarPecas(tabuleiro_esquerda, 1);
      tabuleiro_direita = tabuleiro_esquerda;


      while(empate < 4){
          empate = 0;

          monteJogador = vezDoJogador(monteJogador, 1);

          if(monteJogador == NULL){
              break;
          }

          monteComputador = vezDoComputador(monteComputador, 1);

          imprimirPecas(tabuleiro_esquerda);

          if(monteComputador == NULL){
              break;
          }
      }

      waitForInput();
      clrscr();

      if(monteJogador == NULL){
          printf("Vitoria!!!!");
          return 1;
      }
      else if(monteComputador == NULL){
          printf("Nao foi dessa vez... Tente de novo");
      }
      else{
          printf("Parece que foi um empate :(\n\nTente de novo...");
      }
    }

    limparMemoria(monte);
    limparMemoria(monteComputador);
    limparMemoria(monteJogador);
    limparMemoria(tabuleiro_esquerda);
    limparMemoria(tabuleiro_direita);

    return 0;
}

#endif
