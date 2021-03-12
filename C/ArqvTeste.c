#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "puzzle-senha.h"
#include "lista-de-opcoes.h"

int main() {

    printf("ArqvTeste.c\n\n");

    puzzleSenha();
    printf("Voce ganhou acesso a uma nova parte do castelo!\n\n");
    listaDeOpcoes lista;
    //para alocar a palavra/frase em uma string, utiliza-se a função 'strcpy' da biblioteca <string.h>
    strcpy(lista.titulo, "Desconhecido proximo! O que deseja fazer?");

    strcpy(lista.opcoes[0], "Correr");
    strcpy(lista.opcoes[1], "Esconder");
    strcpy(lista.opcoes[2], "Lutar");
    strcpy(lista.opcoes[3], "Aliar");
    //Utilizando a plavara "NULL" para indicar a ausência da opção
    strcpy(lista.opcoes[4], "NULL");

    //Utilizando ">>" para indicar o ponteiro
    strcpy(lista.ponteiro[0], ">>");
    //Utilizando "  " para indicar a ausência do ponteiro
    strcpy(lista.ponteiro[1], "  ");
    strcpy(lista.ponteiro[2], "  ");
    strcpy(lista.ponteiro[3], "  ");
    strcpy(lista.ponteiro[4], "  ");

    impListOpc(&lista);
    int escolha = escolherOpc(&lista);
    printf("A escolha foi: %s\n", lista.opcoes[escolha]);
    return 0;

}