#include "armadilhas.h"

/*Mecânica dos andares*/
void andar(int n, int caminho){ /*pega o andar e o caminho do usuário (1 ou 2)*/
  int opcao;
  switch(n){
    case 1: /*Andar 1*/
      if (caminho == 1){ /*Armadilha 1*/
        armadilha_1();
      }
      else{ /*Armadilha 2*/
        armadilha_2();
      }
      break;
    case 2: /*Andar 2*/
      if (caminho == 1){ /*Armadilha 3*/
        armadilha_3();
      }
      else{ /*Armadilha 4*/
        armadilha_4();
      }
      break;
    case 3: /*Andar 3*/
      if (caminho == 1){ /*Armadilha 5*/
        armadilha_5();
      }
      else{ /*Armadilha 6*/
        armadilha_6();
      }
      break;
    case 4: /*Andar 4*/
      break;
    case 5: /*Andar 5*/
      break;
  }
}
