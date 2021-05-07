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
int tempo = 25;
int intervalo = 111;

void cronometro(int t){
  for (int i=t;i>=0;i--){
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
  char frase[150], frase_copia[150], resposta[150];
  intervalo = intervalo - 8;
  do{
    strcpy(frase, banco_frases(rand() % 100)); //sorteia uma frase entre as 100
  }while(strlen(frase) < intervalo); //maior tempo, mais chance de pegar frases longas
  uppercase(frase); //transforma a frase em letra maiúscula
  printf("'%s'\n\n", frase); //printa a frase sorteada
  tempo = tempo - 5; //reduz o tempo a cada chance
  cronometro(tempo); //inicia o cronômetro
  clrscr();
  printf("A frase se transforma diante dos seus olhos em uma língua desconhecida:\n\n");
  strcpy(frase_copia, frase); //cria uma cópia da frase para ser alterada
  printf("'%s'", embaralha(frase_copia)); //printa a frase embaralhada
  breakLines(1);
  printf("\nTente traduzir a frase do mesmo jeito (atencao a pontuacao): \n");
  scanf(" %150[^\n]", resposta);
  int t;
  while ((t = fgetc(stdin)) != '\n' && t != EOF);
  breakLines(1);
  printf("-----------------------------------------------");
  breakLines(1);
  printf("\nFRASE: %s", frase);
  breakLines(1);
  printf("\nRESPOSTA: %s", uppercase(resposta));
  breakLines(1);
  waitForInput();
  if (strcmp(frase, uppercase(resposta))==0){
    return 1;
  }
  else{
    return 0;
  }
}
#endif
