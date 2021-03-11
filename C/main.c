#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textos.h"
#include "andares.h"

int main(){
  int loop=1;
  char resposta[1];
  do{
    printf("\nATENCAO: DIGITE O NUMERO QUE CORRESPONDE A OPCAO.\n(1) JOGAR.\n(2) SAIR.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário quiser jogar.*/
      for (int c = 1; c <=3; c++){ /*Percorre os 3 andares com puzzles.*/
        do{
          andar_texto(c); /*Printa o texto do andar.*/
          scanf("%s", &resposta[0]);
          system("clear||cls");
          if (strcmp(resposta, "1") == 0){ /*Opção 1*/
            andar(c, 1); /*Chama o primeiro puzzle do andar.*/
            loop = 0;
          }
          else if (strcmp(resposta, "2") == 0){ /*Opção 2*/
            andar(c, 2); /*Chama o segundo puzzle do andar.*/
            loop = 0;
          }
          else if (strcmp(resposta, "3") == 0){ /*Continuar.*/
            loop = 0;
          }
          else{ /*Opção Inválida*/
            printf("\nOPCAO INVALIDA, TENTE NOVAMENTE.\n");
            loop = 1;
          }
        }
        while(loop != 0); /*Repete o loop enquanto a resposta for inválida.*/
        do{ /*Pergunta se deseja continuar em cada troca de andar.*/
          printf("\nDESEJA CONTINUAR?\n(1) SIM.\n(2) SAIR.\nRESPOSTA: ");
          scanf("%s", &resposta[0]);
          system("clear||cls");
          if (strcmp(resposta, "1") == 0){ /*Continuar*/
            printf("\nSUBINDO DE ANDAR, AGUARDE...\n");
            loop = 0;
          }
          else if (strcmp(resposta, "2") == 0){ /*Sair*/
            printf("\nNOS VEMOS EM BREVE. ATE MAIS!\n");
            exit(0);
          }
          else{ /*Entrada inválida*/
            printf("\nOPCAO INVALIDA, TENTE NOVAMENTE.\n");
            loop = 1;
          }
        }
        while (loop != 0); /*Repete o loop enquanto a resposta for inválida.*/
      }
      andar_texto(4);
      andar(4,0);
      printf("\nAGRADECIMENTOS!");
      printf("\nCREDITOS.");
      printf("\nNOS VEREMOS NOVAMENTE, ATE MAIS!\n");
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o jogador não quiser jogar.*/
      printf("\nNOS VEMOS EM BREVE. ATE MAIS!\n");
      loop = 0;
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA, TENTE NOVAMENTE.\n");
      loop = 1;
    }
  }
  while (loop != 0); /*Repete o loop enquanto a resposta for inválida.*/
}
