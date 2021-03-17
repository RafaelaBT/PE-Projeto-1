#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Estrutura da lista de opções: facilita o acesso aos textos das opções
//Tomei como base 5 opções por decisão a ser tomada
//O ponteio indica qual é a posição selecionada (>>)
typedef struct {
    char titulo[280];
    char ponteiro[5][3];
    char opcoes[5][20];
}listaDeOpcoes;

//Acessa os atributos da estrutura para imprimir o poneiro junto a opção
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

//Possibilida o movimento do ponteiro, trocando o valor (>>) com o possível valor nulo (  ) de seus vizinhos
void mudarOpc(listaDeOpcoes* lista) {

    //"aux" indica a posição em que o ponteiro está
    int aux = 0;
    //Percorre as opções buscando onde está o ponteiro
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
        //Imprime a lista atualizada a cada modificação
        impListOpc(lista);
    }
}

//Possibilita estabelecer um retorno/ação com base na opção escolhida com o ponteiro (>>)
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
            //Utilizando "  " para indicar a ausência do ponteiro
            strcpy(lista.ponteiro[i], "  ");
        }
        //Utilizando a plavara "NULL" para indicar a ausência da opção
        strcpy(lista.opcoes[i], "NULL");
    }
    return lista;
}
