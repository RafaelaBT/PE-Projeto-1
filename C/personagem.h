#pragma once
#include <stdio.h>
#include "lista-luta.h"
#include "helpers.h"

typedef struct {
	char nome[20];
  int maxHp;
	int hp;
	int atk;
	int def;
	int srt;
	listaLuta* listaAcoes;
} personagem;

personagem* defPersonagemPadrao(char* nome) {
	personagem* protagonista = malloc(sizeof(personagem));
	protagonista->maxHp = 100;
  protagonista->hp = protagonista->maxHp;
	protagonista->atk = 20;
	protagonista->def = 5;
	protagonista->srt = 0;
  strcpy(protagonista->nome, nome);
  protagonista->listaAcoes = criarListaLuta();
	return protagonista;
}

personagem* defVilaoPadrao(char* nome) {
	personagem* vilao = malloc(sizeof(personagem));
	vilao->maxHp = 100;
  vilao->hp = vilao->maxHp;
	vilao->atk = 25;
	vilao->def = 5;
	vilao->srt = 0;
  strcpy(vilao->nome, nome);
  vilao->listaAcoes = NULL;
	return vilao;
}

void imprimirBarrasHP(personagem* protagonista, personagem* vilao) {

	int HpPro = 50 * ((float) protagonista->hp / protagonista->maxHp);
	int HpVil = 50 * ((float) vilao->hp / vilao->maxHp);
	char hpBarPro[53];
	char hpBarVil[53];
	for (int i = 0; i < 52; i++) {
		if (i == 0) {
			hpBarPro[i] = '[';
			hpBarVil[i] = '[';
		}
		else if (i == 51) {
			hpBarPro[i] = ']';
			hpBarVil[i] = ']';
		}
		else {
			if (i <= HpPro) {
				hpBarPro[i] = '#';
			}
			else{
				hpBarPro[i] = ' ';
			}
			if (i <= HpVil) {
				hpBarVil[i] = '#';
			}
			else {
				hpBarVil[i] = ' ';
			}
		}
	}
	hpBarPro[52] = '\0';
	hpBarVil[52] = '\0';
	
	printf("%s - %s\n", hpBarPro, protagonista->nome);
	printf("%s - %s\n\n", hpBarVil, vilao->nome);
}

acaoLuta* ataqueBasico(personagem* per, int dado){
  acaoLuta* al = malloc(sizeof(acaoLuta));
  strcpy(al->titulo, "Atacar");
  al->tipoAcao = 1;
  al->plusAtk = (float)dado/10*per->atk;
  al->plusDef = (float)dado/10*per->def;
  al->plusSrt = 0;
  al->plusHp = 0;
  al->duracaoEfeito = 0;
  al->proxAcao = NULL;
  return al;
}

acaoLuta* defesaPersonagem(personagem* per, int dado){
  acaoLuta* al = malloc(sizeof(acaoLuta));
  strcpy(al->titulo, "Defender");
  al->tipoAcao = 2;
  al->plusAtk = 0;
  al->plusDef = per->def + (float)dado/20*per->def;
  al->plusSrt = 0;
  al->plusHp = 0;
  al->duracaoEfeito = 0;
  al->proxAcao = NULL;
  return al;
}

acaoLuta* sortePersonagem(personagem* per, int dado){
  acaoLuta* al = malloc(sizeof(acaoLuta));
  strcpy(al->titulo, "Esquivar");
  al->tipoAcao = 3;
  al->plusAtk = 0;
  al->plusDef = (float)dado/10*per->def;;
  al->plusSrt = dado;
  al->plusHp = 0;
  al->duracaoEfeito = 0;
  al->proxAcao = NULL;
  return al;
}

acaoLuta* acessoAoInventario(personagem* per){
  acaoLuta* al = malloc(sizeof(acaoLuta));
  strcpy(al->titulo, "Acessar o Inventario");
  al->tipoAcao = 4;
  al->plusAtk = 0;
  al->plusDef = 0;
  al->plusSrt = 0;
  al->plusHp = 0;
  al->duracaoEfeito = 0;
  al->proxAcao = NULL;
  return al;
}

void carregarAcoesBasicas(personagem* per){
  srand(time(NULL));
  int dado = (1+rand()%10);
  addAcao(per->listaAcoes, ataqueBasico(per, dado));
  addAcao(per->listaAcoes, defesaPersonagem(per, dado));
  addAcao(per->listaAcoes, sortePersonagem(per, dado));
  //addAcao(per->listaAcoes, acessoAoInventario(per));
}

void desalocarAcoes(personagem* per){
  acaoLuta* aux = NULL;
  acaoLuta* ant = NULL;
  aux = *(per->listaAcoes);
  if(aux->proxAcao == NULL){
    *(per->listaAcoes) = aux->proxAcao;
    free(aux);
    aux = NULL;
  }
  else{
    while(aux->proxAcao != NULL){
      ant = aux;
      aux = aux->proxAcao;
    }
    ant->proxAcao = NULL;
    free(aux);
    aux = NULL;
    desalocarAcoes(per);
  }
}

void imprimirAcoes(personagem* per){
  int i = 1;
  acaoLuta* aux = NULL;
  aux = *(per->listaAcoes);
  if(aux != NULL){
    
    printf("%d - %s\n", i, aux->titulo);
    i++;

    while(aux->proxAcao !=NULL){
      aux = aux->proxAcao;
      printf("%d - %s\n", i, aux->titulo);
      i++;
    }
  }
}

acaoLuta* escolherAcao(personagem* per, int index){
  int indexAux = 1;
  acaoLuta* aux = NULL;
  aux = *(per->listaAcoes);
  if(index == 1){
    return aux;
  } 
  while(aux->proxAcao != NULL){
    aux = aux->proxAcao;
    indexAux++;
    if(index == indexAux){
      return aux;
    }
  }

  printf("Erro! Acao nao existente!\n");
  return NULL;
}

void realizarAcao(personagem* per, personagem* alvo, int escolha){
  acaoLuta* auxPer = NULL;
  auxPer = escolherAcao(per, escolha);
  int dado, dano, danoVilao, defesa, sorte, hpExtra;

  //DADO VARIA DE 1 A 10
  dado = 1 + rand()%10;
  dano = (auxPer->plusAtk - alvo->def);
  defesa = auxPer->plusDef;
  sorte = auxPer->plusSrt;
  danoVilao = ((float)(1+rand()%10)/10*alvo->atk) - defesa;
  hpExtra = 1 + rand()%5;

  switch(auxPer->tipoAcao){
    //1 - ATAQUE
    case 1:
      if(dado<7){
        if(danoVilao < 0){
          danoVilao = 0;
        }
        per->hp-=danoVilao;
        printf("%s causou %d de dano em %s!\n", alvo->nome, danoVilao, per->nome);
      }
      else{
        printf("%s decidiu descansar esse turno...\n", alvo->nome);
      }
      if(per->hp >= 0){
        if(dano<0){
          dano = 0;
        }
        alvo->hp-=dano;
        printf("%s causou %d de dano em %s!\n", per->nome, dano, alvo->nome);
        auxPer->plusAtk = ((float)(1+rand()%10))/10*per->atk;
      }
      break;
    //2 - DEFESA
    case 2:
      if(dado < 7){
        if(danoVilao < 0){
          danoVilao = 0;
        }
        per->hp-=danoVilao;
        printf("%s causou apenas %d de dano em %s, pois esse equipou %d pontos de defesa!\n", alvo->nome, danoVilao, per->nome, auxPer->plusDef);
        auxPer->plusDef = per->def+(float)dado/20*per->def;
      }
      else{
        if(per->hp+hpExtra > per->maxHp){
          hpExtra = per->maxHp-per->hp;
          per->hp = per->maxHp;
        }
        else{
          per->hp+=hpExtra;
        }
        printf("%s decidiu descansar esse turno... Os pontos extras de defesa utilizados por %s foram convertidos em %d pontos de HP!\n", alvo->nome, per->nome, hpExtra);
      }
      break;
      //3 - ESQUIVA / SORTE
    case 3:
      if(sorte > 5 && dado < 7){
        printf("%s atacou, mas %s conseguiu esquivar com sucesso!\n", alvo->nome, per->nome);
      }
      else if(sorte > 5 && dado >= 7){
        if(per->hp+hpExtra > per->maxHp){
          hpExtra = per->maxHp-per->hp;
          per->hp = per->maxHp;
        }
        else{
          per->hp+=hpExtra;
        }
        printf("%s decidiu descansar esse turno... %s poupou a energia que utilizaria para esquivar-se e ganhou %d pontos de HP!\n", alvo->nome, per->nome, hpExtra);
      }
      else{
        per->def = 0;
        per->hp-=danoVilao;
         printf("%s causou %d de dano em %s, pois esse nao se esquivou com sucesso!\n", alvo->nome, danoVilao, per->nome);
      }
      auxPer->plusSrt = 1+rand()%10;
      break;
  }
}

int luta(personagem* protagonista, personagem* vilao) {
	imprimirBarrasHP(protagonista, vilao);
	do {
    imprimirAcoes(protagonista);
		int escolha;
    printf(">> ");
    scanf(" %d", &escolha);
    printf("\n");
		realizarAcao(protagonista, vilao, escolha);
    printf("\n");
    waitForInput();
    clrscr();
		imprimirBarrasHP(protagonista, vilao);
	} while (protagonista->hp > 0 && vilao->hp > 0);
	if (protagonista->hp <= 0) {
		printf("Protagonista morreu!\n");
    waitForInput();
    clrscr();
    desalocarAcoes(protagonista);
    free(vilao);
    vilao = NULL;
    return 0;
	}
	else {
		printf("Vilao morreu!\n");
    waitForInput();
    clrscr();
    desalocarAcoes(protagonista);
    free(vilao);
    vilao = NULL;
    return 1;
	}

}