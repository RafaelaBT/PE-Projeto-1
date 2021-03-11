#include <stdio.h>

/*Textos e imagens dos andares.*/
void andar_texto(int n){
  switch(n){
    case 1: /*Texto do andar 1*/
      printf("\n[ANDAR 1]\n(1) PORTA DIREITA.\n(2) PORTA ESQUERDA.\n(3) CONTINUAR.\nRESPOSTA: ");
      break;
    case 2: /*Texto do andar 2*/
      printf("\n[ANDAR 2]\n(1) PORTA DIREITA.\n(2) PORTA ESQUERDA.\n(3) CONTINUAR.\nRESPOSTA: ");
      break;
    case 3: /*Texto do andar 3*/
      printf("\n[ANDAR 3]\n(1) PORTA DIREITA.\n(2) PORTA ESQUERDA.\n(3) CONTINUAR.\nRESPOSTA: ");
      break;
    case 4: /*Texto do andar 4*/
      printf("\n[ANDAR 4]\nEM CONSTRUCAO.");
      break;
  }
}
