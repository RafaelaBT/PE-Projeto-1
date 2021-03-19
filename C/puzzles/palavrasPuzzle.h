#ifndef PALAVRAS_PUZZLE_H
#define PALAVRAS_PUZZLE_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "../helpers.h"
#include "../cenas/frases.h"

void cronometro();
char *embaralha(char *normal);
char *uppercase(char *palavra);
int palavrasPuzzle();

void cronometro(){
  for (int i=10;i>=0;i--){
    printf("\t%i\n", i);
    sleep(1);
  }
}

char *embaralha(char *normal){
  int c = 0, tamanho = strlen(normal);
  char aux; //variável auxiliar
  for (int i = tamanho - 1; i >= (tamanho / 2); i--){ //conta do fim ao início
    aux = normal[c];
    normal[c] = normal[i];
    normal[i] = aux;
    c += 1; //conta do início ao fim
  }
  return normal; //printa a palavra invertida
}

char *uppercase(char *palavra){
  int tamanho = strlen(palavra);
  for (int i = 0; i <= tamanho; i++){
    palavra[i] = toupper(palavra[i]); //transforma cada letra em maiúscula
  }
  return palavra; //retorna a frase invertida
}

int palavrasPuzzle()
{
  srand(time(0)); //semente
  char frase[200], frase_copia[200], resposta[200];
  strcpy(frase, banco_frases(rand() % 100)); //sorteia uma frase entre as 100
  uppercase(frase); //transforma a frase em letra maiúscula
  printf("Voce pega a pena, a principio, parece conseguir entender as palavras:\n\n");
  breakLines(1);
  printf("'%s'\n\n", frase); //printa a frase sorteada
  breakLines(1);
  printf("OBS.: Aguarde terminar tempo para digitar.\n");
  cronometro(); //inicia o cronômetro
  clrscr();
  printf("A frase se transforma diante dos seus olhos em uma língua desconhecida:\n\n");
  strcpy(frase_copia, frase); //cria uma cópia da frase para ser alterada
  printf("'%s'", embaralha(frase_copia)); //printa a frase embaralhada
  breakLines(2);
  printf("\nTente traduzir a frase do mesmo jeito (atencao a pontuacao): \n");
  scanf(" %199[^\n]", resposta);
  printf("\nFrase: %s", frase);
  printf("\nResposta: %s", uppercase(resposta));
  waitForInput();
  if (strcmp(frase, uppercase(resposta))==0){
    return 1;
  }
  else{
    return 0;
  }
}
#endif
