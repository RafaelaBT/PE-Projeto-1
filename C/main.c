#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textos.h"
#include "andares.h"

int main(){
  int resposta = 1, tamanho;
  while (resposta != 0){ /*Enquanto o usuário quiser jogar.*/
    printf("\nATENCAO: DIGITE O NUMERO QUE CORRESPONDE A OPCAO.\n(1) JOGAR.\n(2) SAIR.\nRESPOSTA: ");
    scanf("%d",&resposta);
    printf("\n");
    switch(resposta){
      case 1: /*Se o usuário quiser jogar.*/
        for (int c=1; c<=3; c++){ /*Loop para percorrer os 3 andares com armadilhas.*/
          int resp = 1;
          int escolha = 1;
          while (escolha!=0){ /*Enquanto a resposta for inválida.*/
            andar_texto(c); /*Texto do andar c.*/
            scanf("%d", &escolha);
            switch (escolha) { /*Escolha do caminho do andar.*/
              case 1:
                andar(c,1);
                escolha = 0; /*Para o loop, vai para o próximo andar.*/
                break;
              case 2:
                andar(c,2);
                escolha = 0; /*Para o loop, vai para o próximo andar.*/
                break;
              case 3: /*Opção continuar*/
                escolha = 0; /*Para o loop, vai para o próximo andar.*/
                break;
              default: /*Caso a entrada seja inválida.*/
                printf("\nOPCAO INVALIDA, TENTE NOVAMENTE.\n");
                escolha = 1; /*Retorna ao loop*/
                break;
            }
          }
          while (resp != 0){ /*Pergunta se deseja continuar ou sair a cada andar.*/
            printf("\nDESEJA CONTINUAR?\n(1) SIM.\n(2) SAIR.\nRESPOSTA: ");
            scanf("%d", &resp);
            switch (resp){
              case 1: /*Apenas continua.*/
                printf("\nSUBINDO DE ANDAR, AGUARDE...\n");
                resp = 0;
                break;
              case 2: /*Encerra o programa.*/
                printf("\nNOS VEMOS EM BREVE. ATE MAIS!\n");
                exit(0);
              default: /*Entrada inválida.*/
                printf("\nOPCAO INVALIDA, TENTE NOVAMENTE.\n");
                resp = 1;
                break;
            }
          }
        }
      /*Fim do jogo*/
      printf("\nPARABENS, VOCE ZEROU!");
      /*printf("\nITENS GANHOS:");
      printf("ITENS:");
        for (int c=0; c<=3; c++){
          printf("\n%s", *inventario[c]);
        }*/
      printf("\nNOS VEREMOS NOVAMENTE, ATE MAIS!");
      resposta = 0;
      break;
    case 2: /*Se o jogador não quiser jogar.*/
      printf("NOS VEMOS EM BREVE. ATE MAIS!");
      resposta = 0; /*Para o loop*/
      break;
    default: /*Se a entrada for inválida*/
      printf("OPCAO INVALIDA, TENTE NOVAMENTE.\n");
      resposta = 1; /*Retornar ao loop*/
      break;
    }
  }
}
