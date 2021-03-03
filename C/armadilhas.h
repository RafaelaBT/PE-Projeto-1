#include <stdio.h>

/*char *inventario[][20];*/ /*Inventário do jogador, só podem ter 4 itens, no máximo.*/

int tentar(){
  int tentar = 1, retorno;
  while(tentar!=0){
    printf("\nTENTAR NOVAMENTE?\n(1) SIM.\n(2) NÃO.\nRESPOSTA: ");
    scanf("%d", &tentar);
    switch(tentar){
      case 1:
        retorno = 1;
        tentar = 0;
        break;
      case 2:
        retorno = 0;
        tentar = 0;
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        tentar = 1;
        break;
    }
  }
  return retorno;
}

void armadilha_1(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /*inventario[0] = "ESPADA DE ELENOR";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}

void armadilha_2(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 2] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /**inventario[0] = "ESCUDO DE ELENOR";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}

void armadilha_3(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 3] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /**inventario[1] = "COLAR DE DIAMANTES DE ADURIN";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}

void armadilha_4(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 4] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /**inventario[1] = "COROA DE ISIDRUR";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}

void armadilha_5(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 5] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /**inventario[2] = "LIVRO DE RÚNICAS";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}

void armadilha_6(){
  int teste = 1;
  while(teste!=0){
    printf("\n[ARMADILHA 6] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%d", &teste);
    switch(teste){
      case 1:
        /**inventario[2] = "POÇÃO DA CURA";*/
        teste = 0;
        break;
      case 2:
        teste = tentar();
        break;
      default:
        printf("\nOPÇÃO INVÁLIDA.\n");
        teste = 1;
        break;
    }
  }
}