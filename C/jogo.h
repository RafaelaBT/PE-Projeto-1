#pragma once
#include <stdio.h>
#include "cenas.h"
#include "helpers.h"

int proximaCena(Cena cena);
void exibirCena(Cena cena);
void loopDeCenas(int numDaCena);

void novoJogo() {
    printf("Novo Jogo\n");
    carregarCenas();

    loopDeCenas(0);
    /* defini que a cena 0 � a inicial por simplicidade
    Se for o caso podemos transformar em uma Constante e dependendo do jogo come�a em um indice diferente.
    */
}

/* Esse loopDeCenas atua como um fun��o recursiva que explora o uso da vari�vel global com todas as cenas dispon�veis
e recurs�o de cauda ao definir qual � a pr�xima cena.
As principais mec�nicas de jogo v�o ser chamadas aqui atrav�s de outras fun��es que podem ser especializadas.
*/
void loopDeCenas(int numDaCena) {
    //Arrays n�o podem ter indices negativos isso previne qualquer input errado de executar essa fun��o
    if (numDaCena < 0) {
        return;
    }
    else {
        Cena cenaAtiva = CENAS[numDaCena];
        exibirCena(cenaAtiva);
        if (cenaAtiva.fimDeJogo) {
            return;
        }
        else if (cenaAtiva.temPuzzle) {
            int sucesso = chamarPuzzle(cenaAtiva.puzzleId);
            if (sucesso) {
                return loopDeCenas(cenaAtiva.cenaDeSucesso);
            }
            else {
                return loopDeCenas(cenaAtiva.cenaDeFalha);
            }
        }
        else {
            int escolha = proximaCena(cenaAtiva);
            // O retorno � nessa fun��o para utilizar recurs�o de cauda.
            return loopDeCenas(escolha);
        }
    }
}

/* Podemos colocar aqui a forma de exibir a cena.
Podemos evoluir ela para ter outras propriedades a serem exploradas nessa parte do programa */
void exibirCena(Cena cena) {
    printf("\n\n");
    printf("%s", cena.descricao);
}

// Aqui podemos evoluir a cena para ter a lista de pr�ximas cenas dispon�veis e nessa fun��o validar isso. Podemos trazder mais tipos de itera��o tamb�m (como por exemplo se a cena permitir fazer um combate antes de trocar de cena).
int proximaCena(Cena cena) {
    printf("Sua escolha: ");
    return readInt();
}
