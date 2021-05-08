#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "../helpers.h"

const int numElementosSeq = 5;

char** elementosSeq;

void carregarElementosSeq() {
	if (elementosSeq == NULL) {
		elementosSeq = malloc(numElementosSeq * sizeof(char*));
		for (int i = 0; i < numElementosSeq; i++) {
			(elementosSeq[i]) = malloc(4 * sizeof(char));
			switch (i) {
			case 0:
				strcpy((elementosSeq[i]), "DO");
				break;
			case 1:
				strcpy((elementosSeq[i]), "RE");
				break;
			case 2:
				strcpy((elementosSeq[i]), "MI");
				break;
			case 3:
				strcpy((elementosSeq[i]), "FA");
				break;
			case 4:
				strcpy((elementosSeq[i]), "SOL");
				break;
			default:
				break;
			}
		}
	}

	return;
}

void limparElementosSeq() {

	if (elementosSeq != NULL) {
		for (int i = 0; i < numElementosSeq; i++) {
			if (elementosSeq[i] != NULL) {
				free(elementosSeq[i]);
				elementosSeq[i] = NULL;
			}
		}
		free(elementosSeq);
		elementosSeq = NULL;
	}

}

void esperarSegundos(int segundos) {
	time_t inicio_t, final_t;
	double dif_t_sec;
	time(&inicio_t);
	do {
		time(&final_t);
		dif_t_sec = difftime(final_t, inicio_t);
	} while (dif_t_sec != segundos);
	//printf("Tempo esperado: %.0lf segundos\n", dif_t_sec);
}

char* gerarElementoAleatorio() {

	int index = rand() % numElementosSeq;

	if (elementosSeq != NULL) {
		return elementosSeq[index];
	}
	else {
		printf("Erro: vetor de elementos nulo.\n");
		return NULL;
	}
}

void imprimirGabarito(char** gabarito, int tam) {
	printf("Gabarito: ");
	for (int i = 0; i < tam; i++) {
		printf("%s ", gabarito[i]);
	}
	printf("\n");
}

void imprimirSequenciaOff() {
	for (int i = 0; i < numElementosSeq; i++) {
		printf("\t%s\n", elementosSeq[i]);
	}
	printf("\n");
}

void imprimirSequenciaOn(char** gabarito, int index) {
	int aux = 0;
	for (int i = 0; i < numElementosSeq; i++) {
		if (strcmp((gabarito[index]), (elementosSeq[i])) == 0) {
			aux = i;
			i = numElementosSeq;
		}
	}
	for (int i = 0; i < numElementosSeq; i++) {
		if (i == aux) {
			printf("\t%s<<\n", elementosSeq[i]);
		}
		else {
			printf("\t%s\n", elementosSeq[i]);
		}
	}
	printf("\n");
}

void stringCaixaAlta(char* string) {
	int i = 0;
	while (string[i]) {
		string[i] = toupper(string[i]);
		i++;
	}
}

void receberResposta(char** resposta, int qtdElementos) {
	printf("Entre sua resposta separada por espacos\n-> ");
	for (int i = 0; i < qtdElementos; i++) {
		resposta[i] = malloc(15 * sizeof(char));
		scanf(" %s", resposta[i]);
		stringCaixaAlta(resposta[i]);
	}
  myflush(stdin);
}

int conferirResposta(char** resposta, char** gabarito, int qtdElementos) {
	int aux = 0;
	for (int i = 0; i < qtdElementos; i++) {
		char* a =  resposta[i];
		char* b = gabarito[i];
		if (strcmp(resposta[i], gabarito[i]) == 0) {
			aux++;
		}
	}
	if (aux == qtdElementos) {
		return 1;
	}
	else {
		return 0;
	}
}

void limparCharPonteio2 (char** ponteiro2, int tam){
  if(ponteiro2 != NULL){
    for(int i = 0; i<tam; i++){
      if(ponteiro2[i]!=NULL){
        free(ponteiro2[i]);
        ponteiro2[i] = NULL;
      }
    }
    free(ponteiro2);
    ponteiro2 = NULL;
  }
  
}

int puzzleSequencia(int nivelDificuldade) {
	char** gabarito = NULL;
	int qtdElementos = nivelDificuldade + 3;
	if (nivelDificuldade == 0 && elementosSeq == NULL) {
		carregarElementosSeq();
	}
	if (nivelDificuldade <= 3 && nivelDificuldade >= 0 && gabarito == NULL) {
		gabarito = malloc((qtdElementos) * sizeof(char*));
		srand(time(NULL));
		for (int i = 0; i < qtdElementos; i++) {
			(gabarito[i]) = malloc(4 * sizeof(char));
			strcpy((gabarito[i]), gerarElementoAleatorio());
		}
	}

	for (int i = 0; i < qtdElementos; i++) {
		imprimirSequenciaOff();
		esperarSegundos(1);
		clrscr();
		imprimirSequenciaOn(gabarito, i);
		esperarSegundos(1);
		clrscr();
	}

	char** resposta = NULL;
	resposta = malloc(qtdElementos * sizeof(char*));
	imprimirGabarito(gabarito, qtdElementos);
	receberResposta(resposta, qtdElementos);

  int conf = conferirResposta(resposta, gabarito, qtdElementos);

  limparCharPonteio2(resposta, qtdElementos);
  limparCharPonteio2(gabarito, qtdElementos);

	/* printf("Resposta: ");
	for (int i = 0; i < qtdElementos; i++) {
		printf("%s ", resposta[i]);
	}
  printf("\n\n"); */

	if(conf){
    if(nivelDificuldade==3){
      printf("\nParabens, voce conseguiu!\n");
      limparElementosSeq();
      waitForInput();
      clrscr();
      return 1;
    }
    else{
      printf("\nO nivel de dificuldade ira aumentar...\n");
      waitForInput();
      clrscr();
      return puzzleSequencia(nivelDificuldade+1);
    }
  }
  else{
    printf("\nVoce errou. Deseja tentar novamente?\n1 - SIM\n2 - NAO\n\n-> ");
    int continuar;
    scanf("%d", &continuar);
    if(continuar==1){
        clrscr();
        return puzzleSequencia(0);
    }
    else{
      clrscr();
    }
  }
	
	return 0;
}