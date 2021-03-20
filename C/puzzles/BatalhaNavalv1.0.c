#include <stdio.h>
#include <stdlib.h>

void PosicionaNavio(int navios[][2], int tam, int *seq){
    while(1){
        srand(time(NULL));      //passa parâmetro inicial p/ rand() baseado no RTC
        int eixonavio=rand()%2, //sorteia orientação horizontal(0) ou vertical(1)
        lim=11-tam;             //limitação da coordenada pelo tamanho do navio

        //caso orientação horizontal
        if(eixonavio=0){
            navios[*seq][0]=rand()%10;
            navios[*seq][1]=rand()%lim;   //máxima coluna inicial limitada pelo tamanho do navio
            if(TemNavioAqui(navios, navios[*seq][0], navios[*seq][1], *seq)==0){   //Só segue se não tiver navio na posição inicial sorteada,

                //loop para escrever as coordenadas das próximas unidades do navio
                for(int k=1; k<=tam; k++){

                    //caso último loop, todas as unidades do navio foram posicionadas sem coincidir com outros navios
                    if(k==tam){
                        *seq=*seq+tam; //atualiza seq (parâmetro externo)
                        return;      //encerra a função
                    }

                    //caso não seja o último loop
                    else{

                        //Se já tem navio na coordenada da unidade, encerra o loop e a função reinicia
                        if (TemNavioAqui(navios, navios[*seq][0], navios[*seq][1]+k, *seq)){
                            k=tam;
                        }

                        //Caso a coordenada esteja livre, escreve na posição seq+k do array navios[][]
                        else{
                            navios[*seq+k][0]=navios[*seq][0];    //coordenada da linha é igual à da primeira unidade
                            navios[*seq+k][1]=navios[*seq][1]+k;     //coordenada da coluna é igual à da primeira unidade + k
                        }
                    }
                }
            }
        }

        //caso orientação vertical (operação equivalente, desta vez fixando a coordenada da coluna)
        else{
            navios[*seq][0]=rand()%lim;
            navios[*seq][1]=rand()%10;
            if(TemNavioAqui(navios, navios[*seq][0], navios[*seq][1], *seq)==0){
                for(int k=1; k<=tam; k++){
                    if(k==tam){
                        *seq=*seq+tam;
                        return;
                    }
                    else{
                        if (TemNavioAqui(navios, navios[*seq][0]+k, navios[*seq][1], *seq)){
                            k=tam;
                        }
                        else{
                            navios[*seq+k][0]=navios[*seq][0]+k;
                            navios[*seq+k][1]=navios[*seq][1];
                        }
                    }
                }
            }
        }
    }
}

//Checa se tem alguma unidade de navio com a coordenada i,j (até a posição maxpos)
int TemNavioAqui(int navios[][2], int i, int j, int maxpos){
    for(int k=0; k<maxpos; k++){
        if(navios[k][0]==i && navios[k][1]==j){
            return 1;
        }
    }
    return 0;
}

//Dica informa quantos alvos há na linha e na coluna inseridas
void dica(int tiro[2], int navios[][2], int tentativa){
    int linha=0, coluna=0;
    for(int k=0; k<44; k++){
        if(navios[k][0]==tiro[0]){
            linha++;
        }
        if(navios[k][1]==tiro[1]){
                coluna++;
        }
    }
    printf("\nDica:\nlinha %d -> %d alvos\ncoluna %d -> %d alvos\n",tiro[0]+1,linha,tiro[1]+1,coluna);
}


#define UnidadesNavios 44 //Alterar aqui o valor total de unidades de navios de acordo com o total de navios inicializados

int main() {
    char tabuleiro[10][10]; //tabuleiro[i][j] - i: linhas - j: colunas
    int navios[UnidadesNavios][2],      //navios[k][c] - k: unidades dos navios - c: coordenadas da unidade ([0] linha, [1] coluna)
    tiro[2],                //coordenadas do tiro ([0] linha, [1] coluna)
    tiros=60, acertos=0, seq=0;     //contadores

    //Inicializa tabuleiro
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabuleiro[i][j]='~';
        }
    }

    //Inicializa navios
    PosicionaNavio(navios, 5, &seq);
    PosicionaNavio(navios, 4, &seq);
    PosicionaNavio(navios, 4, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 3, &seq);
    PosicionaNavio(navios, 2, &seq);
    PosicionaNavio(navios, 2, &seq);
    PosicionaNavio(navios, 2, &seq);
    PosicionaNavio(navios, 2, &seq);
    PosicionaNavio(navios, 2, &seq);

//REVELA POSIÇÕES DOS NAVIOS
//    for(int k=0; k<UnidadesNavios; k++){
//        tabuleiro[navios[k][0]][navios[k][1]]='X';
//    }

    //Loop abre uma nova jogada enquanto restarem tiros e não acertar todos os navios
    while(tiros>0 && acertos<UnidadesNavios){

        //Apresentar tabuleiro
        printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
        printf("\n\n\n");
        for(int i=0; i<10; i++){
            printf("%d",i+1);
            for(int j=0; j<10; j++){
                printf("\t%c", tabuleiro[i][j]);
            }
            printf("\n\n\n");
        }
        printf("Voce tem %d tiros restantes.\n", tiros);

        //Ler coordenadas do tiro
        printf("Linha: ");
        scanf("%d",&tiro[0]);
        while(tiro[0]<1 || tiro[0]>10){  //caso a coordenada inserida seja inválida
            printf("Insira um valor de 1 a 10.\n");
            printf("Linha: ");
            scanf("%d",&tiro[0]);
        }
        tiro[0]--;  //ajusta o índice da coordenada inserida
        printf("Coluna: ");
        scanf("%d", &tiro[1]);
        while(tiro[1]<1 || tiro[1]>10){  //caso a coordenada inserida seja inválida
            printf("Insira um valor de 1 a 10.\n");
            printf("Coluna: ");
            scanf("%d", &tiro[1]);
        }
        tiro[1]--;  //ajusta o índice da coordenada inserida
        tiros--;

        //Resultado da jogada, atualiza tabuleiro e acertos
        if(TemNavioAqui(navios, tiro[0], tiro[1], UnidadesNavios)){
            printf("***BUUUMMM***\nVoce acertou uma parte de um navio na linha %d, coluna%d.\n", tiro[0]+1, tiro[1]+1);
            tabuleiro[tiro[0]][tiro[1]]='X';
            acertos++;
        }
        else{
            printf("```CHUAAA´´´\nVoce perdeu o tiro na linha %d, coluna%d.\n", tiro[0]+1, tiro[1]+1);
            tabuleiro[tiro[0]][tiro[1]]='*';
        }
        getch();

        //dica(tiro,navios,tiros);

    }

    printf("\n\n\nJOGO ENCERRADO");

    //Apresentar tabuleiro
    printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10");
    printf("\n\n\n");
    for(int i=0; i<10; i++){
        printf("%d",i+1);
        for(int j=0; j<10; j++){
            printf("\t%c", tabuleiro[i][j]);
        }
        printf("\n\n\n");
    }

    if(acertos=UnidadesNavios){
        return 1;
    }
    else{
        return 0;
    }
}
