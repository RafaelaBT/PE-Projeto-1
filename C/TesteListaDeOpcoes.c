#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaDeOpcoes {

    char titulo [280];
    char ponteiro[5][3];
    char opcoes [5][20];
};


void impListOpc(struct listaDeOpcoes *lista){

  printf("%s\n", lista->titulo);
  for(int i = 0; i<5; i++){
    if(strcmp(lista->opcoes[i], "NULL") != 0){
      printf("%s ", lista->ponteiro[i]);
      printf(" | ");
      printf("%s\n", lista->opcoes[i]);
    }
  }
}

void mudarOpcao(struct listaDeOpcoes *lista){
  int aux = 0;
  for(int i = 0; i<5; i++){
    if(strcmp(lista->ponteiro[i], ">>") == 0){
      aux = i;
      i = 5;
    }
  }
  int codigoTecla = 0;
  //d = 100 ASCII
  while(codigoTecla != 100){

    codigoTecla = getchar();

    //w = 119 ASCII
    if(codigoTecla == 119){
      for(int i = aux -1; i >= 0; i--){
        if( (strcmp(lista->ponteiro[i], "  ") == 0) && (strcmp(lista->opcoes[i], "NULL") != 0) ){
          strcpy(lista->ponteiro[aux], "  ");
          strcpy(lista->ponteiro[i], ">>");
          aux = i;
          i = -1;
          impListOpc(lista);
        }
      }
    }

    //s = 115 ASCII
    if(codigoTecla == 115){
      for(int i = aux + 1; i <5; i++){
        if( (strcmp(lista->ponteiro[i], "  ") == 0) && (strcmp(lista->opcoes[i], "NULL") != 0) ){
          strcpy(lista->ponteiro[aux], "  ");
          strcpy(lista->ponteiro[i], ">>");
          aux = i;
          i = 6;
          impListOpc(lista);
        }
      }
    }
  }

  impListOpc(lista);

}

int main() {

  struct listaDeOpcoes lista;
  //para alocar a palavra/frase em uma string, utiliza-se a função 'strcpy' da biblioteca <string.h>
  strcpy(lista.titulo, "Desconhecido proximo! O que deseja fazer?");

  strcpy(lista.opcoes[0], "Correr");
  strcpy(lista.opcoes[1], "Esconder");
  strcpy(lista.opcoes[2], "Lutar");
  strcpy(lista.opcoes[3], "Aliar");
  strcpy(lista.opcoes[4], "NULL");

  strcpy(lista.ponteiro[0], ">>");
  strcpy(lista.ponteiro[1], "  ");
  strcpy(lista.ponteiro[2], "  ");
  strcpy(lista.ponteiro[3], "  ");
  strcpy(lista.ponteiro[4], "  ");

  impListOpc(&lista);
  mudarOpcao(&lista);
  return 0;

}
