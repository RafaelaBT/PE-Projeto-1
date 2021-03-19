#ifndef TORRE_DO_DRAGAO_H
#define TORRE_DO_DRAGAO_H

#include "../puzzles/fibonacciPuzzle.h"
#include "../puzzles/puzzlePocao.h"
#include "../puzzles/puzzle-senha.h"
#include "../puzzles/palavrasPuzzle.h"
#include "cena.h"
#include <string.h>

// Prototypes da funções
Cena jogoTorreDoDragao();
Cena introducao();
Cena *cena1();
Cena *cena2();
Cena *cena3();
Cena *cena4();
Cena *cena5();
Cena *cena6();
Cena *cena7();
Cena *cena8();
Cena *cena9();
Cena *cena10();
Cena *cena11();
Cena *cena12();
Cena *cena13();
Cena *cena14();
Cena *cena15();
Cena *cena16();
Cena *cena17();
Cena *cena18();
Cena *imagemInicio();

Cena jogoTorreDoDragao()
{
    int numDeCenas = 21;
    free(CENAS);
    CENAS = (Cena *)malloc(sizeof(Cena) * numDeCenas);

    return introducao();
}

Cena introducao()
{
    Cena cena;
    cena.id = 1;
    strcpy(cena.descricao, "Voce eh um heroi renomado passando por uma vila praticamente destruida, os moradores contam que um dragao vive em um castelo no topo da montanha e recentemente vem atacando a vila.\n\nTodos ficam aliviados quando seus serviços sao oferecidos, e assim você parte para o castelo - mas será que sobreviverá as inumeras armadilhas do local e a força de um dragao?");
    cena.tipo = 0;
    cena.id = 0;
    cena.cenaDeSucesso = imagemInicio();
    CENAS[CURRENT_CENAS] = cena;
    return CENAS[CURRENT_CENAS++];
}

Cena *imagemInicio()
{
    Cena cena;
    cena.id = 2;
    strcpy(cena.descricao, "./C/images/inicio.txt");
    cena.tipo = 7;
    cena.id = 1;
    cena.cenaDeSucesso = cena1();
    return adicionarCena(cena);
}

Cena *cena1()
{
    Cena cena;
    cena.id = 3;
    strcpy(cena.descricao, "Em uma terra muito distante, voce eh um heroi renomado passando por uma vila praticamente em ruinas.\n\nSe aproximando, voce encontra um morador e pergunta sobre o motivo de toda essa destruicao, que conta: \n\n     - Oh grande heroi! Um dragao anda atormentando nossa vila, roubando o gado e ateando fogo em nossas casas. Ele vive no castelo no topo daquela montanha... Por favor, nos ajude! Nao vamos sobreviver muito mais tempo nesse estado. \n\nConcordando em os ajudar, voce segue rumo ao castelo...");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena2();
    return adicionarCena(cena);
}

Cena *cena2()
{
    Cena cena;
    cena.id = 4;
    strcpy(cena.descricao, "Apos um dia de viagem, voce finalmente se encontra na porta do castelo. Mas antes de abrir suas grandes portas escuta uma voz muito antiga e poderosa, sem duvida do proprio dragao: \n\n    - Hummm, o que temos aqui? Um heroi? HAHAHAHA… Nao pense que pode chegar aqui e lutar comigo, poucos possuem essa honra. Voce tera que se provar merecedor, passando por todas minhas armadilhas antes de me alcancar. Vamos ver quanto tempo voce dura...\n\nFalando isso as portas se abrem, como que por vontade propria, lhe chamando para os perigos adentro. Assim que você atravessa elas imediatamente se fecham novamente, lhe prendendo no castelo. Agora o unico jeito de sair eh derrotando o dragao ou morrendo no processo.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena3();
    return adicionarCena(cena);
}

Cena *cena3()
{
    Cena cena;
    cena.id = 5;
    char cenaDescricao[] = "Apos atravessar o hall de entrada, você entra em um quarto iluminado por velas e com inumeros pergaminhos e livros espalhados pelo chao. No centro da sala, se encontra uma mesa com um livro e uma pena de escrever.\n\nVoce escuta uma voz amargurada, mas parece que ela esta muito distante e vai se esvaindo com o passar do tempo.\n\n\t'A memoria é uma dadiva...\n\tProteja-a ou ela sera levada.\n\tO tempo nao espera nem o seu mais fiel amigo...'\n\nDe repente, o livro se abre, suas paginas sao reviradas freneticamente e param..., acompanhadas de um silencio profundo. So ha voce na sala.\nPalavras comecam a serem escritas no livro.";
    strcpy(cena.descricao, cenaDescricao);
    cena.tipo = 0;
    cena.cenaDeSucesso = cena4();
    return adicionarCena(cena);
}

Cena *cena4()
{
    Cena cena;
    cena.id = 6;
    char cenaDescricao[] = "Voce se sente atordoado, parece que algo esta testando sua sanidade.\n\nVoce se aproxima do livro.\n\nMas sera que voce esta pronto? Ao tocar a pena, o tempo passara a correr.\n\n(NOTA: As frases adaptadas desse puzzle foram retiradas de 'CEM TROVAS POPULARES (anonimas)' da Colecao 'Trovadores Brasileiros' - Organizacao de Luiz Otavio e J. G. de Araujo Jorge.)";
    strcpy(cena.descricao, cenaDescricao);
    cena.tipo = 0;
    cena.cenaDeSucesso = cena5();
    return adicionarCena(cena);
}

Cena *cena5()
{
    Cena cena;
    cena.id = 7;
    cena.tipo = 6;
    strcpy(cena.descricao, "");
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena6();
    return adicionarCena(cena);
}

Cena *cena6()
{
    Cena cena;
    cena.id = 8;
    strcpy(cena.descricao, "As palavras desaparecem. Voce se sente mais tonto e se apoia na mesa, olhando ao redor. Aquela pilha de livros estava ali antes? Voce nao tem mais certeza... nao, foco! Voce nao pode desistir, nao agora. Voce ainda tem muito o que percorrer\nVoce tenta se recompor.");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena7();
    return adicionarCena(cena);
}

Cena *cena7()
{
    Cena cena;
    cena.id = 9;
    strcpy(cena.descricao, "Voce se sente esgotado e sua visao vai se fechando, quase nao consegue segurar mais a pena. Coitado. Por que voce veio? Ou melhor, quando? Voce nao se lembra... mas sabe que precisa tentar mais uma vez, e a sua unica chance de sair daqui.\n\nCom toda a sua força restante, voce se aproxima novamente.");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena8();
    return adicionarCena(cena);
}

Cena *cena8()
{
    Cena cena;
    cena.id = 10;
    strcpy(cena.descricao, "Voce se sente esgotado e sua visao vai se fechando, quase nao consegue segurar mais a pena. Coitado. Por que voce veio? Ou melhor, quando? Voce nao se lembra... mas sabe que precisa tentar mais uma vez, e a sua unica chance de sair daqui.\n\nCom toda a sua força restante, voce se aproxima novamente.");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena9();
    return adicionarCena(cena);
}

Cena *cena9()
{
    Cena cena;
    cena.id = 11;
    strcpy(cena.descricao, "Voce se apaga...\nAo se levantar, voce nao consegue se lembrar mais de nada. O breu da sala e o frio gelam os seus ossos. O livro drenou sua memoria e voce nao consegue nem mais saber quem e.\n\nOs dias passam sem voce conseguir sair. Sem comer e sem beber, voce morre lentamente, se tornando mais um dos esqueletos do castelo... Voce não deveria ter vindo.\n\nFim de jogo.");
    cena.tipo = 3;
    return adicionarCena(cena);
}

Cena *cena10()
{
    Cena cena;
    cena.id = 12;
    strcpy(cena.descricao, "As paginas são reviradas de novo, mas ao contrario, e o livro se fecha. O silencio total reina novamente.\n\nBAM!\n\nAs grades enferrujadas caem e voce escuta uma voz ja conhecida:\n\n - Muito bem, heroi! Voce passou meu primeiro enigma. Mas ainda ha um grande caminho pela frente...\n\nVoce atravessa a sala e passa a porta para o proximo desafio.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena11();
    return adicionarCena(cena);
}

Cena *cena11()
{
    Cena cena;
    cena.tipo = 13;
    strcpy(cena.descricao, "Ao sair da sala do livro voce percorre um corredor de pedra polida em paralelepípedos, com bastante limo nas partes mais baixas. Por um longo tempo não há portas até que você chega em uma grande de metal com um ar sólido. Você a observa por um tempo e depois testa a maceneta. Ela gira e a porta abre. Tomando fôlego você passa para dentro da próxima sala.");
    cena.cenaDeSucesso = cena12();
    return adicionarCena(cena);
}

Cena *cena12()
{
    Cena cena;
    cena.id = 14;
    strcpy(cena.descricao, "Assim que voce entra na proxima sala consegue perceber que tem alguma coisa errada com o seu chao, como se ele estivesse conectado a algum mecanismo.\n\nA parte principal do mecanismo parece ser uma tabua conectada a parede, com tres bobinas giratorias e numeros de uma senha, assim como um cadeado.\n\nVoce se aproxima do desafio.\n\n");
    cena.tipo = 4;
    cena.cenaDeFalha = cena13();
    cena.cenaDeSucesso = cena14();
    return adicionarCena(cena);
}

Cena *cena13()
{
    Cena cena;
    cena.id = 15;
    strcpy(cena.descricao, "Ao colocar o ultimo numero, voce percebe tarde demais que colocou a senha errada novamente.\n\nO mecanismo na parede da um click e o chao se abre como um alcapao, fazendo com que voce caia ate atingir uma piscina de acido que corroe o seu corpo ate nao sobrar mais nada.\n\n");
    cena.tipo = 3;
    return adicionarCena(cena);
}

Cena *cena14()
{
    Cena cena;
    cena.id = 16;
    strcpy(cena.descricao, "Muito bem! O chao continua intacto e uma porta parece na parede como se sempre estivesse la.\n\nVoce entra e encontra uma escada espiral com outra porta no final, que lhe leva ao proximo desafio.\n\n");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena15();
    return adicionarCena(cena);
}

Cena *cena15()
{
    Cena cena;
    cena.id = 17;
    strcpy(cena.descricao, "Entrando na sala pequena voce imediatamente sente um cheiro quimico e nota que o ar esta repleto de um gas provavelmente venenoso, considerando como sua garganta esta inchando.\n\nNo canto esquerdo da sala se encontra uma pequena mesa com aparatos de alquimia, varias pocoes de multiplas cores e o que parece ser um bilhete. Rapidamente voce se aproxima:\n\n");
    cena.tipo = 5;
    cena.cenaDeSucesso = cena17();
    cena.cenaDeFalha = cena16();
    return adicionarCena(cena);
}

Cena *cena16()
{
    Cena cena;
    cena.id = 18;
    strcpy(cena.descricao, "\n\nVoce toma a pocao mas ela nao faz nenhum efeito.\n\nSua visao fica turva e sua respiracao ofegante, seus ultimos suspiros sao pura agonia antes de perder a consciencia.\n\nFim do jogo.\n");
    cena.tipo = 3;
    return adicionarCena(cena);
}

Cena *cena17()
{
    Cena cena;
    cena.id = 19;
    strcpy(cena.descricao, "\nAntidoto criado com sucesso!\n\nVoce bebe a pocao e imediatamente se sente melhor, ao mesmo tempo a proxima porta se abre e voce escuta:\n\n - Voce eh um heroi muito persistente... A maioria dos desafiantes anteriores ja teriam morrido. Mas veremos por quanto tempo a sua sorte continua.\n\n");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena18();
    return adicionarCena(cena);
}

Cena *cena18()
{
    Cena cena;
    cena.id = 20;
    strcpy(cena.descricao, "Voce abre a porta e ve uma placa que diz: Fim da demo. Voce sobreviveu ate aqui. Jogue novamente");
    cena.tipo = 3;
    return adicionarCena(cena);
}

#endif
