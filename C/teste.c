#include <stdio.h>
#include <stdlib.h>

int comecarHistoria();

int cena1();
int cena2();
int cena1_1();

void chamarCena(int *cenas, int numCenas, int *cena);
void montarHistoria(int *cenas, int numCenas);


int main()
{
    int cenas [3] = {0, 0, 0};
    montarHistoria(cenas, 3);
    return 0;
}

int comecarHistoria(){
    printf("Inicio da historia!\n\n");
    printf("Escolha um caminho! (1/2):\n-> ");
    int opc;
    int conf = 0;
    scanf("%d", &opc);
    while(conf == 0){
        switch(opc){
        case 1:
            conf = 1;
            return 1;
            break;
        case 2:
            conf = 1;
            return 2;
            break;
        default:
            printf("Opcao invalida! Tente novamente!\n-> ");
            scanf("%d", &opc);
            break;
        }
    }

}

int cena1(){
    int opc;
    printf("Essa eh a cena #1\n");
    printf("Gostaria de ir para cena #1_1? Aperte \"1\" em caso positivo.\n-> ");
    scanf("%d", &opc);
    if(opc == 1){
        return 1;
    }
    else{
        return 99;
    }
}

int cena2(){
    printf("Essa eh a cena #2\n");
    return 99;
}

int cena1_1(){
    printf("Essa eh a cena #1_1\n");
    return 99;
}

void chamarCena(int *cenas, int numCena, int *cena){
    int codigo = 0;
    int fator = 1;
    for(int i = 0; i < numCena; i++){
        int value = cenas[i];
        codigo += fator*value;
        fator *= 10;
    }
    switch(codigo){
    case 1:
       *cena = cena1();
       break;
    case 2:
        *cena = cena2();
        break;
    case 11:
        *cena = cena1_1();
        break;
    }
}

void montarHistoria(int *cenas, int numCenas){
    int i = 0;
    while(cenas[i] == 0){
        cenas[i] = comecarHistoria();
    }
    i++;
    do{
        chamarCena(cenas, i, &cenas[i]);
        i++;
    }
    while(cenas[i-1]!=99);
    printf("Sucesso!\n");
}
