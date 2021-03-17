#pragma once
#include <stdio.h>
#include <string.h>
#include "sequenciaFibonacci.h"
#include "puzzles.h"

typedef struct
{
    int fimDeJogo;
    char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
    int temPuzzle;
    int puzzleId;
    int cenaDeSucesso;
    int cenaDeFalha;
} Cena;

#define MAX_CENAS 10
Cena CENAS[MAX_CENAS];

//Substitui o Puzzle por um id
Cena* carregarCenas() {
    for (int i = 0; i < 8; i++) {
        Cena cena;
        cena.fimDeJogo = 0;
        strcpy(cena.descricao, "Descri��o da cena...\n\n");
        cena.temPuzzle = 1;
        cena.puzzleId = ID_PUZZLESENHA;
        cena.cenaDeFalha = 9;
        cena.cenaDeSucesso = i + 1;
        CENAS[i] = cena;
    }
    for (int i = 8; i < 10; i++) {
        Cena cena;
        cena.fimDeJogo = 0;
        strcpy(cena.descricao, "Teste de cenas, para continuar digite o ind�ce da pr�xima cena.\n");
        cena.temPuzzle = 0;
        CENAS[i] = cena;
    }
    CENAS[9].fimDeJogo = 1;
    strcpy(CENAS[9].descricao, "Ao errar uma luz vem dos ceus e fica cada vez mais intensa. Voc� falhou com o deus da matem�tica e ser� punido. Voc� � instant�neamente vaporizado e morre. Fim de jogo.\n");
    CENAS[8].fimDeJogo = 1;
    strcpy(CENAS[8].descricao, "Voc� � um g�nio e os deuses da matem�tica sorriem para ti em aprova��o. Tu ascender� como o paladino de fibonacci. Fim de jogo\n");
    return CENAS;
}
