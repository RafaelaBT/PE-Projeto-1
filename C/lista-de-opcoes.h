#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Estrutura da lista de op��es: facilita o acesso aos textos das op��es
//Tomei como base 5 op��es por decis�o a ser tomada
//O ponteio indica qual � a posi��o selecionada (>>)
typedef struct {
    char titulo[280];
    char ponteiro[5][3];
    char opcoes[5][20];
}listaDeOpcoes;

//Acessa os atributos da estrutura para imprimir o poneiro junto a op��o
void impListOpc(listaDeOpcoes* lista) {

    printf("%s\n", lista->titulo);
    for (int i = 0; i < 5; i++) {
        if (strcmp(lista->opcoes[i], "NULL") != 0) {
            printf("%s ", lista->ponteiro[i]);
            printf(" | ");
            printf("%s\n", lista->opcoes[i]);
        }
    }
}

//Possibilida o movimento do ponteiro, trocando o valor (>>) com o poss�vel valor nulo (  ) de seus vizinhos
void mudarOpc(listaDeOpcoes* lista) {

    //"aux" indica a posi��o em que o ponteiro est�
    int aux = 0;
    //Percorre as op��es buscando onde est� o ponteiro
    for (int i = 0; i < 5; i++) {
        if (strcmp(lista->ponteiro[i], ">>") == 0) {
            aux = i;
            i = 5;
        }
        int codigoTecla = 0;
        //d = 100 ASCII
        //O loop espera as entradas para movimentar o ponteiro (w/s) e fazer a escolha (d)
        while (codigoTecla != 100) {
            codigoTecla = getchar();
            //w = 119 ASCII
            //Verifica se o ponteiro pode ser movido pra cima
            if (codigoTecla == 119) {
                for (int i = aux - 1; i >= 0; i--) {
                    if ((strcmp(lista->ponteiro[i], "  ") == 0) && (strcmp(lista->opcoes[i], "NULL") != 0)) {
                        strcpy(lista->ponteiro[aux], "  ");
                        strcpy(lista->ponteiro[i], ">>");
                        aux = i;
                        i = -1;
                        impListOpc(lista);
                    }
                }
            }
            //s = 115 ASCII
            //Verifica se o ponteiro pode ser movido pra baixo
            if (codigoTecla == 115) {
                for (int i = aux + 1; i < 5; i++) {
                    if ((strcmp(lista->ponteiro[i], "  ") == 0) && (strcmp(lista->opcoes[i], "NULL") != 0)) {
                        strcpy(lista->ponteiro[aux], "  ");
                        strcpy(lista->ponteiro[i], ">>");
                        aux = i;
                        i = 6;
                        impListOpc(lista);
                    }
                }
            }
        }
        //Imprime a lista atualizada a cada modifica��o
        impListOpc(lista);
    }
}

//Possibilita estabelecer um retorno/a��o com base na op��o escolhida com o ponteiro (>>)
int escolherOpc(listaDeOpcoes* lista) {
    int escolha = 0;
    mudarOpc(lista);
    for (int i = 0; i < 5; i++) {
        if (strcmp(lista->ponteiro[i], ">>") == 0) {
            escolha = i;
            i = 6;
        }
    }
    return escolha;
}

listaDeOpcoes listaPadrao() {
    listaDeOpcoes lista;
    strcpy(lista.titulo, "NULL");
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            //Utilizando ">>" para indicar o ponteiro
            strcpy(lista.ponteiro[i], ">>");
        }
        else {
            //Utilizando "  " para indicar a aus�ncia do ponteiro
            strcpy(lista.ponteiro[i], "  ");
        }
        //Utilizando a plavara "NULL" para indicar a aus�ncia da op��o
        strcpy(lista.opcoes[i], "NULL");
    }
    return lista;
}
