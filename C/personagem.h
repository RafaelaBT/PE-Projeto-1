#pragma once
#include <stdio.h>
#include "lista-de-opcoes.h"
#include "lista-de-opcoes.h"

struct personagem {
	char nome[20];
	int hp;
	int atk;
	int def;
	int srt;
	int temEscudo;
	int temPocaoVida;
	int podeAtaqueEspecial;
};
typedef struct personagem personagem;

personagem defPersonagemPadrao() {
	personagem personagem;
	personagem.hp = 100;
	personagem.atk = 7;
	personagem.def = 10;
	personagem.srt = 5;
	personagem.temEscudo = 0;
	personagem.temPocaoVida = 0;
	personagem.podeAtaqueEspecial = 0;
	return personagem;
}

personagem defVilaoPadrao() {
	personagem vilao;
	vilao.hp = 250;
	vilao.atk = 10;
	vilao.def = 9;
	vilao.srt = 1;
	vilao.temEscudo = 1;
	vilao.temPocaoVida = 1;
	vilao.podeAtaqueEspecial = 0;
	return vilao;
}

listaDeOpcoes opcAcao(personagem *personagem) {
	listaDeOpcoes lista = listaPadrao();
	strcpy(lista.titulo, "Escolha sua ação: ");
	strcpy(lista.opcoes[0], "Ataque 1");
	strcpy(lista.opcoes[1], "Ataque 2");
	strcpy(lista.opcoes[2], "Usar escudo");
	strcpy(lista.opcoes[3], "Usar poçao de vida");
	strcpy(lista.opcoes[4], "Ataque especial");
}

void imprimirBarrasHP(personagem* protagonista, personagem* vilao) {
	int HpPro = protagonista->hp / 2;
	int HpVil = vilao->hp / 5;
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

void luta(personagem* protagonista, personagem* vilao) {
	imprimirBarrasHP(protagonista, vilao);
	do {
		int a = rand() % 21;
		int b = rand() % 21;
		//protagonista->hp -= (vilao->atk + a);
		vilao->hp -= (protagonista->atk + b);
		imprimirBarrasHP(protagonista, vilao);
	} while (protagonista->hp > 0 && vilao->hp > 0);
	if (protagonista->hp <= 0) {
		printf("Protagonista morreu!");
	}
	else if (vilao->hp <= 0) {
		printf("Vilao morreu!");
	}

}
