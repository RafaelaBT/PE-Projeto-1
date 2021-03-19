#ifndef PASSWORD_PUZZLE_H
#define PASSWORD_PUZZLE_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../helpers.h"

#define QUANT_NUM_COR 3
#define QUANT_NUM_ERR 5
#define QUANT_DICAS_PUZZLESENHA 5
#define MAX_PUZZLESENHA 8
#define VAL_PAD_PUZZLESENHA 100
#define ID_PUZZLESENHA 4

void gerarNumerosAleatorios(int* numeros, int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        numeros[i] = rand() % 100;
    }
    for (int i = 1; i < tam; i++) {
        int aux = 0;
        for (int j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                aux++;
            }
        }
        if (aux != 0) {
            numeros[i] = rand() % 100;
            i--;
        }
    }
}

void embaralharNumeros(int* numeros, int tam) {
    int vetAux[MAX_PUZZLESENHA];
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        int index = rand() % tam;
        vetAux[i] = numeros[i];
        memcpy(&numeros[i], &numeros[index], sizeof(int));
        memcpy(&numeros[index], &vetAux[i], sizeof(int));
    }
}

void imprimirValoresSenha(int* corretos, int* errados) {
    printf("Corretos: ");
    for (int i = 0; i < QUANT_NUM_COR; i++) {
        if (i != QUANT_NUM_COR - 1) {
            printf("%d, ", corretos[i]);
        }
        else {
            printf("%d.\n", corretos[i]);
        }
    }
    printf("Errados: ");
    for (int i = 0; i < QUANT_NUM_ERR; i++) {
        if (i != QUANT_NUM_ERR - 1) {
            printf("%d, ", errados[i]);
        }
        else {
            printf("%d.\n\n", errados[i]);
        }
    }
}

void imprimirDicasSenha(int* valoresOrdenados, int linha) {
    
    char textoDica[50];
    switch (linha) {
    case 1:
        strcpy(textoDica, "Um numero correto, mas no lugar errado");
        break;
    case 2:
        strcpy(textoDica, "Um numero correto e no lugar correto");
        break;
    case 3:
        strcpy(textoDica, "Nada esta correto");
        break;
    case 4:
        strcpy(textoDica, "Dois numeros corretos, mas nos lugares errados");
        break;
    case 5:
        strcpy(textoDica, "Um numero correto, mas no lugar errado");
        break;
    }  
    if (linha <= QUANT_DICAS_PUZZLESENHA) {
        printf("[");
        for (int i = QUANT_NUM_COR * (linha - 1); i < QUANT_NUM_COR * linha; i++) {
            if (i != QUANT_NUM_COR * linha - 1) {
                if (valoresOrdenados[i] < 10) {
                    printf("0%d - ", valoresOrdenados[i]);
                }
                else {
                    printf("%d - ", valoresOrdenados[i]);
                }
            }
            else {
                if (valoresOrdenados[i] < 10) {
                    printf("0%d] <- %s", valoresOrdenados[i], textoDica);
                }
                else {
                    printf("%d] <- %s", valoresOrdenados[i], textoDica);
                }
            }
        }
        printf("\n");
        linha += 1;
        imprimirDicasSenha(valoresOrdenados, linha);
    }
    else {
        return;
    }
    
}

void receberSenha(int *senha) {
    scanf("%d %d %d", &senha[0], &senha[1], &senha[2]);
    return;
}

int verificarSenha(int* senha, int* corretos) {
    int aux = 0;
    for (int i = 0; i < QUANT_NUM_COR; i++) {
        if (senha[i] == corretos[i]) {
            aux += 1;
        }
    }
    if (aux == QUANT_NUM_COR) {
        return 1;
    }
    else {
        return 0;
    }
}

int puzzleSenha() {

    int numeros[8];
    gerarNumerosAleatorios(numeros, 8);

    int corretos[3];
    int errados[5];

    //A fun�o sizeof(tipo) retorna um long que � o n�mero de bytes ocupados na mem�ria para determinado tipo de dado
    //(vetorDestino, &vetorFonte[posi�o inicial], tamanhoDaMem�ria)
    memcpy(corretos, &numeros[0], 3 * sizeof(int));
    memcpy(errados, &numeros[3], 5 * sizeof(int));

    int ref[6][3];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            ref[i][j] = VAL_PAD_PUZZLESENHA;
        }
    }

    //{0}Numeros corretos (na ordem correta)
    for (int i = 0; i < 3; i++) {
        ref[0][i] = corretos[i];
    }

    embaralharNumeros(corretos, 3);
    embaralharNumeros(errados, 5);

    int erradosDuplicados[10];
    memcpy(&erradosDuplicados[0], &errados[0], QUANT_NUM_ERR * sizeof(int));
    //Impede que em uma mesma dica (dica {3}) tenham dois n�meros errados iguais
    do {
        embaralharNumeros(errados, 5);
    } while (erradosDuplicados[4] == errados[0] || erradosDuplicados[4] == errados[1]);
    memcpy(&erradosDuplicados[5], &errados[0], QUANT_NUM_ERR * sizeof(int));

    //�ndices que v�o auxiliar no acesso dos vetores de nums corretos e errados
    int ordenadorC = 0;
    int ordenadorE = 0;

    //{1}Um numero correto, mas no lugar errado
    //{2}Um numero correto e no lugar correto
    //{3}Nada esta correto
    //{4}Dois numeros corretos, mas nos lugares errados
    //{5}Um numero correto, mas no lugar errado

    //�ndices que v�o auxiliar na aloca�o com base na posi�o dos n�meros corretos
    int index = rand() % 3;
    int index2;

    //Todos os n�meros corretos devem estar presentes pelo menos 1 vez
    //Numero correto [0] necessariamente presente: {1} num correto, pos errada
    do {
        index = rand() % 3;
    } while (ref[0][index] == corretos[ordenadorC]);
    ref[1][index] = corretos[ordenadorC];
    ordenadorC++;

    //Numero correto [1] necessariamente presente: {2} num correto, pos correta
    for (int i = 0; i < 3; i++) {
        if (ref[0][i] == corretos[ordenadorC]) {
            ref[2][i] = corretos[ordenadorC];
        }
    }
    ordenadorC++;

    //Numero correto [2] necessariamente presente {5}
    do {
        index = rand() % 3;
    } while (ref[0][index] == corretos[ordenadorC]);
    ref[5][index] = corretos[ordenadorC];

    //Numeros corretos restantes: {4} 2 nums corretos, poss erradas
    ordenadorC = 0;
    embaralharNumeros(corretos, 3);
    do {
        index = rand() % 3;
    } while (ref[0][index] == corretos[ordenadorC]);
    ref[4][index] = corretos[ordenadorC];
    ordenadorC++;

    index2 = index;
    do {
        index = rand() % 3;
    } while (ref[0][index] == corretos[ordenadorC] || index == index2);
    ref[4][index] = corretos[ordenadorC];

    //Numeros errados: {1}{2}{3}{4}{5} ocupam todas as posi�es restantes
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (ref[i][j] == VAL_PAD_PUZZLESENHA) {
                ref[i][j] = erradosDuplicados[ordenadorE];
                ordenadorE++;
            }
        }
    }

    int valoresOrdenados[15];
    int aux = 0;
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            valoresOrdenados[aux] = ref[i][j];
            aux++;
        }
    }
    
    for (int i = 0; i < QUANT_NUM_COR; i++) {
        corretos[i] = ref[0][i];
    }

    int chances = 3;
    int senhaCorreta = 0;
    do {
        //imprimirValoresSenha(corretos, errados);
        imprimirDicasSenha(valoresOrdenados, 1);

        printf("\nEntre a senha separada por espacos\n-> ");
        int senha[QUANT_NUM_COR];
        receberSenha(senha);

        if (verificarSenha(senha, corretos)){
            printf("\nSenha correta! :)\n\n");
            chances = 0;
            senhaCorreta = 1;
            waitForInput();
            clrscr();
        }
        else {
            printf("\nSenha errada! >:(\n\n");
            chances--;
            if (chances == 2) {
                printf("Parece que ainda ha uma chance...\n\n");
            }
            else if (chances == 1) {
                printf("Ja nao da para saber quantas tentativas restam...\n\n");
            }
            waitForInput();
            clrscr();
        }
    } while (chances > 0);
    
    return senhaCorreta;
}

#endif