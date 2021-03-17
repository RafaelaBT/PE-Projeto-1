#pragma once
#include <stdio.h>
#include <string.h>
#include "puzzle-senha.h"
#define PUZZLE_DESCRICAO_MAX_SIZE 1024
#define PUZZLE_RESPOSTA_MAX_SIZE 1024

typedef struct {
    char descricao[PUZZLE_DESCRICAO_MAX_SIZE];
    char resposta[PUZZLE_RESPOSTA_MAX_SIZE];
} Puzzle;

int respostaCorreta(char* resposta, Puzzle puzzle);
int executarPuzzle(Puzzle puzzle);

int respostaCorreta(char* resposta, Puzzle puzzle) {
    return strcmp(resposta, puzzle.resposta);
}

int executarPuzzle(Puzzle puzzle) {
    printf("%s", puzzle.descricao);
    char resposta[PUZZLE_RESPOSTA_MAX_SIZE];
    scanf(" %s", resposta);
    if (respostaCorreta(resposta, puzzle)) {
        return 0;
    }
    else {
        return 1;
    }
}

//Método utilizado para chamar os puzzles com base em um id
int chamarPuzzle(int idPuzzle) {
    switch (idPuzzle) {
        case ID_PUZZLESENHA: return puzzleSenha();
        //case ID_PUZZLEPOCAO: return puzzlePocao();
        //case ID_PUZZLEFIBONACCI: return puzzleFibonacci();
    }
}
