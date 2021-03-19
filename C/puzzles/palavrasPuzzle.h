#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "../helpers.h"
#include "../cenas/frases.h"

//incluir nome do puzzle no loopCena, caso 4

void cronometro(int sleepTime){
  for (int i = 10; i >= 0; i--)
  {
    printf("\n\t%d", i); //printa os segundos
    sleep(1);
  }
}

int sizeOf(char * string) {
  int size = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    size++;
  }
  return size;
}

char *embaralha(char * normal){
  int c=0, tamanho = sizeOf(normal);
  char aux; //variável auxiliar
  for (int i=tamanho-1; i>=(tamanho/2); i--){ //conta do fim ao início
    aux = normal[c];
    normal[c] = normal[i];
    normal[i] = aux;
    c += 1; //conta do início ao fim
  }
	return normal; //printa a palavra invertida
}

char *uppercase(char *resposta){
  int tamanho = sizeOf(resposta);
  for (int i=0; i<=tamanho; i++){
    resposta[i] = toupper(resposta[i]); //transforma cada letra em maiúscula
  }
  return resposta; //retorna a frase invertida
}

int palavrasPuzzle(int tempoDeLeitura){
  srand(time(0)); //semente
  char frase[100], frase_copia[100];
  char *resposta = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  strcpy(frase, banco_frases(rand() % 100)); //sorteia uma frase entre as 100
  uppercase(frase); //transforma a frase em letra maiúscula

  printf("Voce pega a pena, a principio, parece conseguir entender as palavras:\n\n");

  breakLines(1);
  printf("'%s'", frase); //printa a frase sorteada
  breakLines(1);
  cronometro(tempoDeLeitura); //inicia o cronômetro

  clrscr(); //limpa a tela aqui

  printf("A frase se transforma diante dos seus olhos em uma língua desconhecida:\n\n");
  strcpy(frase_copia, frase); //cria uma cópia da frase para ser alterada
  printf("'%s'", embaralha(frase_copia)); //printa a frase embaralhada

  breakLines(2);

  printf("Tente traduzir a frase do mesmo jeito (atencao a pontuacao): ");
  lineSize = getline(&resposta, &len, stdin);

  if(strcmp(frase, uppercase(resposta)) == 0){ //verifica se a resposta está certa
    return 1; //ganhou
  }
  else{
    return 0; //perdeu
  }
}
