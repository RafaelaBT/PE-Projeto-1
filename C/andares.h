#include "puzzles.h"

/*Controle dos andares / Puzzles Independentes.*/
/*Facilita de não ter uma única função com todos os puzzles.*/
void andar(int n, int caminho){ /*Pega o andar e o caminho do usuário (opção 1 ou 2).*/
  switch(n){
    case 1: /*Andar 1*/
      if (caminho == 1){ /*Puzzle 1*/
        puzzle_1();
      }
      else{ /*Puzzle 2*/
        puzzle_2();
      }
      break;
    case 2: /*Andar 2*/
      if (caminho == 1){ /*Puzzle 3*/
        puzzle_3();
      }
      else{ /*Puzzle 4*/
        puzzle_4();
      }
      break;
    case 3: /*Andar 3*/
      if (caminho == 1){ /*Puzzle 5*/
        puzzle_5();
      }
      else{ /*Puzzle 6*/
        puzzle_6();
      }
      break;
    case 4: /*Andar 4*/
      printf("\nANDAR FINAL.");
      break;
  }
}
