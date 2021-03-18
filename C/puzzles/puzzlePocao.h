#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void montarBilhete(int *pocao[], char *cores[]);

int puzzlePocao(){
    int *pocao[4], resposta_quantidade[4], puzzle_certo;
    char *cores[]={"amarelo", "laranja", "lavanda", "magenta"};
    char resposta_cor[4][8];
    char *ordem[]={"primeira", "segunda", "terceira", "quarta"};

    for(int tentativas=0; tentativas<3; tentativas++){
        puzzle_certo=0;

        montarBilhete(pocao, cores);

        system("pause");
        system("cls");

        printf("Pensando isso, o papel se desintegra nas suas maos.\nEspero que voce se lembre dele.\n\n");

        memset(resposta_cor, 0, sizeof(resposta_cor));

        for(int criar_pocao=0; criar_pocao<4; criar_pocao++){
            printf("\nCor da %s pocao: ", ordem[criar_pocao]);
            scanf("%s", &resposta_cor[criar_pocao]);
            resposta_cor[criar_pocao][7] = '\0';

            printf("Quantidade da %s pocao: ", ordem[criar_pocao]);
            scanf("%d", &resposta_quantidade[criar_pocao]);

            if((strcmp(resposta_cor[criar_pocao], cores[criar_pocao])==0) && (resposta_quantidade[criar_pocao] == pocao[criar_pocao])){
                puzzle_certo++;
            }
        }

        //acertou o puzzle
        if(puzzle_certo==4){
            return 1;
        }
        else{
            system("pause");
            system("cls");
            printf("\nAcho que o gas esta afetando seu raciocinio... tente rapidamente fazer o antidoto de novo\n\nPor sorte parece ter outro bilhete\n\n\n");
        }
    }
    return 0;
}

void montarBilhete(int *pocao[], char *cores[]){
    int num_lista=1, cor_aleatoria;
    char bilhete[15][23];
    time_t t;
    srand((unsigned) time(&t));

    //proporções das poções
    for(int cont=0; cont<4; cont++){
        pocao[cont] = (1+rand()%8)*100;
    }

    //colocar as cores em ordem aleatória
    for(int i=0; i<(strlen(cores)+1); i++){
        cor_aleatoria = rand()%strlen(cores);

        const char* temporario = cores[cor_aleatoria];
        cores[cor_aleatoria] = cores[i];
        cores[i] = temporario;
    }

    //montar o bilhete
    strcpy(bilhete[0]," ___________________");
    strcpy(bilhete[14], "|___________________|");

    for(int linha=1; linha<14; linha++){
        //quantidades
        if(linha>2 && linha<12 && linha%2==1){
            if(linha == 3){
                strcpy(bilhete[3], "|    Antidoto Gas   |");
            }
            else{
                snprintf(bilhete[linha], sizeof(bilhete[linha]), "|  %d - %s %d  |", num_lista, cores[num_lista-1], pocao[num_lista-1]);
                num_lista++;
            }
        }
        //partes vazias
        else{
            strcpy(bilhete[linha], "|                   |");
        }
    }

    for(int imprimir=0; imprimir<15; imprimir++){
        printf("%s\n", bilhete[imprimir]);
    }

    printf("\n\nEsse papel parece bem fragil, melhor memorizar isso...\n\n");

    system("pause");
    system("cls");
}
