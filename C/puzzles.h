#include <stdio.h>
#include <stdlib.h>

int loop = 1;
char resposta[1];

int tentar(){ /*Pergunta se o usuário quer tentar novamente.*/
  int retorno;
  do{
    printf("\nTENTAR NOVAMENTE?\n(1) SIM.\n(2) NAO.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      retorno = 1;
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      retorno = 0;
      loop = 0;
    }
    else{
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
  while(loop!=0);
  return retorno;
}

void puzzle_1(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}

void puzzle_2(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}

void puzzle_3(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}

void puzzle_4(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}

void puzzle_5(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}

void puzzle_6(){
  do{
    printf("\n[ARMADILHA 1] APENAS TESTE, DIGITE CORRETAMENTE:\n(1) GANHAR.\n(2) PERDER.\nRESPOSTA: ");
    scanf("%s", &resposta[0]);
    system("clear||cls");
    if (strcmp(resposta, "1") == 0){ /*Se o usuário ganhar.*/
      loop = 0;
    }
    else if (strcmp(resposta, "2") == 0){ /*Se o usuário perder.*/
      loop = tentar();
    }
    else{ /*Se a entrada for inválida*/
      printf("\nOPCAO INVALIDA.\n");
      loop = 1;
    }
  }
   while(loop!=0); /*Repete o loop enquanto a resposta for inválida.*/
}
