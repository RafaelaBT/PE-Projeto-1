#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "personagem.h"

struct acaoLuta{
  char titulo [20];
  int tipoAcao;
  int plusAtk;
  int plusDef;
  int plusSrt;
  int plusHp;
  int duracaoEfeito;
  struct acaoLuta* proxAcao;
};

typedef struct acaoLuta acaoLuta;

typedef acaoLuta* listaLuta;

listaLuta* criarListaLuta(){
  listaLuta* lista = malloc(sizeof(listaLuta));
  if(lista!= NULL){
    return lista;
  }
  else{
    printf("Erro!");
    return NULL;
  }
}

void addAcao(listaLuta* lista, acaoLuta* acao){
  
  if(acao == NULL){
    printf("Erro alocacao!\n");
    return;
  }
  
  if(*lista == NULL){
    *lista = acao;
    return;
  }
  else{
    acaoLuta* aux = NULL;
    aux = *lista;
    while(aux->proxAcao != NULL){
      aux = aux->proxAcao;
    }
    aux->proxAcao = acao;
  }
}