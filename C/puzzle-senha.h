#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define QUANT_NUM_COR 3
#define QUANT_NUM_ERR 5
#define MAX_PUZZLESENHA 8
#define VAL_PAD_PUZZLESENHA 100

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
    for (int i = 0; i < ceil((float)tam/2); i++) {
        int index = rand() % tam;
        vetAux[i] = numeros[i];
        memcpy(&numeros[i], &numeros[index], sizeof(int));
        memcpy(&numeros[index], &vetAux[i], sizeof(int));
    }
}

void imprimirValoresSenha(int* corretos, int* errados) {
    printf("Corretos:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", corretos[i]);
    }
    printf("Errados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", errados[i]);
    }
}

void preencherMatrizRef(int (*ref)[3], int linhas, int colunas) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            *ref[i] = VAL_PAD_PUZZLESENHA;
        }
    }

}

void puzzleSenha() {

    int numeros[8];
    gerarNumerosAleatorios(numeros, 8);
    
    int corretos[3];
    int errados[5];

    //A função sizeof(tipo) retorna um long que é o número de bytes ocupados na memória para determinado tipo de dado
    //(vetorDestino, &vetorFonte[posição inicial], tamanhoDaMemória)
    memcpy(corretos, &numeros[0], 3 * sizeof(int));
    memcpy(errados, &numeros[3], 5 * sizeof(int));

    imprimirValoresSenha(corretos, errados);

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
    memcpy(&erradosDuplicados[0], &errados[0], 5 * sizeof(int));
    //Impede que em uma mesma dica tenham dois números errados iguais
    do {
        embaralharNumeros(errados, 5);
    } while (erradosDuplicados[4] == errados[0]);
    memcpy(&erradosDuplicados[5], &errados[0], 5 * sizeof(int));

    //Índices que vão auxiliar no acesso dos vetores de nums corretos e errados
    int ordenadorC = 0;
    int ordenadorE = 0;

    //{1}Um numero correto, mas no lugar errado
    //{2}Um numero correto e no lugar correto
    //{3}Nada esta correto
    //{4}Dois numeros corretos, mas nos lugares errados
    //{5}Um numero correto, mas no lugar errado

    //Índices que vão auxiliar na alocação com base na posição dos números corretos
    int index = rand() % 3;
    int index2;

    //Todos os números corretos devem estar presentes pelo menos 1 vez
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

    //Numeros corretos restantes: {4} 2 nums corretos, poss erradas ---- !!!!!
    ordenadorC = 0;
    embaralharNumeros(corretos, 3);
    do {
        index = rand() % 3;
    }while (ref[0][index] == corretos[ordenadorC]);
    ref[4][index] = corretos[ordenadorC];
    ordenadorC++;
    
    index2 = index;
    do {
        index = rand() % 3;
    } while (ref[0][index] == corretos[ordenadorC] || index == index2);
    ref[4][index] = corretos[ordenadorC];

    //Numeros errados: {1}{2}{3}{4}{5} ocupam todas as posições restantes
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (ref[i][j] == VAL_PAD_PUZZLESENHA) {
                ref[i][j] = erradosDuplicados[ordenadorE];
                ordenadorE++;
            }
        }
    }

    printf("[%d - %d - %d] <- Um numero correto, mas no lugar errado\n", ref[1][0], ref[1][1], ref[1][2]);
    printf("[%d - %d - %d] <- Um numero correto e no lugar correto\n", ref[2][0], ref[2][1], ref[2][2]);
    printf("[%d - %d - %d] <- Nada esta correto\n", ref[3][0], ref[3][1], ref[3][2]);
    printf("[%d - %d - %d] <- Dois numeros corretos, mas nos lugares errados\n", ref[4][0], ref[4][1], ref[4][2]);
    printf("[%d - %d - %d] <- Um numero correto, mas no lugar errado\n", ref[5][0], ref[5][1], ref[5][2]);

    printf("\nEntre a senha separada por espacos\n-> ");
    int d1, d2, d3;
    scanf("%d %d %d", &d1, &d2, &d3);

    if (d1 == ref[0][0] && d2 == ref[0][1] && d3 == ref[0][2]) {
        printf("\nSenha correta! :)\n\n");
    }
    else {
        printf("\nSenha errada! >:(\n\n");
    }

    //{0}Numeros corretos (na ordem correta)
    //{1}Um numero correto, mas no lugar errado
    //{2}Um numero correto e no lugar correto: numeros
    //{3}Nada esta correto
    //{4}Dois numeros corretos, mas nos lugares errados
    //{5}Um numero correto, mas no lugar errado

}