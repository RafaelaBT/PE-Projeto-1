#ifndef TORRE_DO_DRAGAO_H
#define TORRE_DO_DRAGAO_H

#include "../puzzles/sequenciaFibonacciPuzzle.h"
#include "../puzzles/puzzlePocao.h"
#include "cena.h"
#include <string.h>
const int MAX_CENAS = 13;
Cena CENAS[MAX_CENAS];

Cena jogoTorreDoDragao();
Cena introducao();
Cena * cena1();
Cena * cena2();
Cena * cena3();
Cena * cena4();
Cena * cena5();
Cena * cena6();
Cena * cena7();
Cena * cena8();
Cena * cena9();
Cena * cena10();
Cena * cena11();
Cena * cena12();

Cena jogoTorreDoDragao() {
    return introducao();
}

Cena introducao() {
    Cena cena;
    strcpy(cena.descricao, "Voce eh um heroi renomado passando por uma vila praticamente destruida, os moradores contam que um dragao vive em um castelo no topo da montanha e recentemente vem atacando a vila.\n\nTodos ficam aliviados quando seus serviços sao oferecidos, e assim você parte para o castelo - mas será que sobreviverá as inumeras armadilhas do local e a força de um dragao?");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena1();
    CENAS[0] = cena;
    return CENAS[0];
}

Cena * cena1() {
    Cena cena;
    strcpy(cena.descricao, "Em uma terra muito distante, voce eh um heroi renomado passando por uma vila praticamente em ruinas.\n\nSe aproximando, voce encontra um morador e pergunta sobre o motivo de toda essa destruicao, que conta: \n\n     - Oh grande heroi! Um dragao anda atormentando nossa vila, roubando o gado e ateando fogo em nossas casas. Ele vive no castelo no topo daquela montanha... Por favor, nos ajude! Nao vamos sobreviver muito mais tempo nesse estado. \n\nConcordando em os ajudar, voce segue rumo ao castelo...");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena2();
    CENAS[1] = cena;
    return &CENAS[1];
}

Cena * cena2() {
    Cena cena;
    strcpy(cena.descricao, "Apos um dia de viagem, voce finalmente se encontra na porta do castelo. Mas antes de abrir suas grandes portas escuta uma voz muito antiga e poderosa, sem duvida do proprio dragao: \n\n    - Hummm, o que temos aqui? Um heroi? HAHAHAHA… Nao pense que pode chegar aqui e lutar comigo, poucos possuem essa honra. Voce tera que se provar merecedor, passando por todas minhas armadilhas antes de me alcancar. Vamos ver quanto tempo voce dura...\n\nFalando isso as portas se abrem, como que por vontade propria, lhe chamando para os perigos adentro. Assim que você atravessa elas imediatamente se fecham novamente, lhe prendendo no castelo. Agora o unico jeito de sair eh derrotando o dragao ou morrendo no processo.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena3();
    CENAS[2] = cena;
    return &CENAS[2];
}

Cena * cena3() {
    Cena cena;
    strcpy(cena.descricao, "Apos atravessar o hall de entrada, voce entra em um quarto iluminado por velas e com inumeros pergaminhos e livros espalhados pelo chao, existe uma porta de grades trancada na parede oposta da entrada.\n\nNo centro da sala se encontra uma mesa com um livro aberto e uma pena de escrever, voce percebe que o livro eh magico pois as palavras parecem se escreverem e re-escreverem sozinhas.\n\nAo se aproximar as seguintes palavras aparecem em suas paginas: \n\n");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena4();
    CENAS[3] = cena;
    return &CENAS[3];
}

// Rafaela eu separei a cena do puzzle pois não sei como vai ser o comportamento. Se implementar usando a interface de puzzle poderia ser na própria cena3() com o tipo de puzzle
Cena * cena4() {
    Cena cena;
    strcpy(cena.descricao, "Somente os que conhecem os padroes da logica podem resolver meus desafios.\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(1, 3, 4, "Logo abaixo estao escritos os seguintes numeros junto com um indicativo da pergunta do livro: \n\n");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena5();
    CENAS[4] = cena;
    return &CENAS[4];
}

Cena * cena5() {
    Cena cena;
    strcpy(cena.descricao, "O livro chacoalha levemente quando voce termina de escrever. A pagina comeca a ficar mais preenchida de tinta a partir das bordas e no espaço central em branco a tinta se move.\n\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(2, 3, 5, "Apos a tinta parar de se mover uma nova sequencia aparece com mais uma pergunta: ");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena6();
    CENAS[5] = cena;
    return &CENAS[5];
}

Cena * cena6() {
    Cena cena;
    strcpy(cena.descricao, "O livro treme com forca, quase caindo de suas maos. Voce comeca a sentir um calafrio e uma sensacao de que nao pode continuar falhando.\nA tinta preenche a pagina com simbolos de morte em diversas culturas e ha poucos espacos em branco na pagina.\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(6, 6, 5, "O livro forma novos numeros nos espacos em branco, e voce acredita que eh a ultima vez que ele escrevera algo para voce: ");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena7();
    CENAS[6] = cena;
    return &CENAS[6];
}

Cena * cena7() {
    Cena cena;
    strcpy(cena.descricao, "Esta claro que numeros nao sao o seu forte, a cada tentativa que faz voce sente sua sanidade se esvaindo. O livro drenou sua personalidade e voce nao consegue mais pensar racionalmente.\n\nOs dias passam sem voce conseguir sair da sala, ate que as consequencias da falta de agua e comida finalmente te alcancam e voce morre lentamente por desidratacao, se tornando mais um dos esqueletos do castelo...\n\nFim de jogo.");
    cena.tipo = 3;
    CENAS[7] = cena;
    return &CENAS[7];
}

Cena * cena8() {
    Cena cena;
    strcpy(cena.descricao, "O livro volta a ficar completamente em branco e simbolos de positividade começam aparecer, em meio a eles voce reconhece um 'Parabens' e 'Sucesso!'. \n\nNada mais acontece com o livro e apos um longo minuto as grades prendendo a porta desaparecem e voce escuta uma voz ja conhecida:\n\n - Muito bem, heroi! Você passou meu primeiro enigma. Mas ainda ha um grande caminho pela frente...\n\nVoce atravessa a sala e passa a porta para o proximo desafio.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena9();
    CENAS[8] = cena;
    return &CENAS[8];
}

Cena * cena9() {
    Cena cena;
    strcpy(cena.descricao, "Ao sair da sala do livro voce percorre um corredor de pedra polida em paralelepipedos, com bastante limo nas partes mais baixas. Nao ha portas e depois de andar por um longo tempo voce chega em uma bifurcacao, na verdade uma trifurcacao.\n\nO caminho da esquerda te leva para um novo corredor parecido com o que voce vem percorrendo. O da direita leva para um corredor com uma leve descida. No centro tem uma porta de ferro.\n\nEscolha um caminho:\n0 - Corredor da esquerda\n1 - Corredor que desce pela direita\n2 - Entrar pela porta no centro");
    cena.tipo = 1;
    cena.escolhasPossiveis[0] = cena10();
    cena.escolhasPossiveis[1] = cena11();
    cena.escolhasPossiveis[2] = cena12();
    cena.maxEscolhas = 3;
    CENAS[9] = cena;
    return &CENAS[9];
}

Cena * cena10() {
    Cena cena;
    strcpy(cena.descricao, "Voce anda pelo corredor por longas horas e ele nao parece mudar. Voce se cansa e monta um acampamento precario. Ao acordar, se alimenta com o que resta de suas provioes e continua andando. Por fim voce se cansa e comeca a voltar, mas o corredor nao tem fim.\n\nApos andar e dormir mais duas vezes voce percebe uma luz no fim do corredor e quando chega percebe que voltou a trifurcacao. Voce sabe que o dragao deve estar usando magia para lhe cansar.\n\nEscolha um caminho:\n0 - Corredor que desce pela direita\n1 - Entrar pela porta no centro");
    cena.tipo = 1;
    cena.escolhasPossiveis[0] = &CENAS[11];
    cena.escolhasPossiveis[1] = &CENAS[12];
    cena.maxEscolhas = 2;
    CENAS[10] = cena;
    return &CENAS[10];
}

Cena * cena11() {
    Cena cena;
    strcpy(cena.descricao, "Voce comeca a andar pelo corredor, ele vai ficando mais inclinado conforme os minutos vao se passando ate caminhar ficar perigoso. Quando voce resolve voltar escuta um barulho se aproximando. Logo voce percebe que era uma armadilha, possivelmente mortal. Um liquido desce pelo corredor aos montes, preenchendo todo o espaço. Uma tromba de agua te engole e te joga pela parede, ela parece nao acabar nunca e voce sente cortes surgindo pelo seu corpo, o corredor tinha espinhos afiados em todas as parede. Depois de quase uma eternidade e quase se afogando voce eh jogado em um lago, provavelmente o fosso do castelo.\n\nVoce pensa estar seguro quando varios peixes comecam a lhe morder, em quantidades cada vez maiores e com mais verocidade. Sao piranhas.\n\nEm alguns momentos voce perde sua consciencia e depois de alguns minutos somente seus ossos restam no fundo do fosso.");
    cena.tipo = 3;
    CENAS[11] = cena;
    return &CENAS[11];
}

Cena * cena12() {
    int tipo = 3;
    if (CENAS[12].tipo != tipo) {
        printf("Criando cena 12\n");
        Cena cena;
        strcpy(cena.descricao, "Voce abre a porta e ve uma placa que diz: Fim da demo. Voce sobreviveu ate aqui. Jogue novamente");
        cena.tipo = tipo;
        CENAS[12] = cena;
        return &CENAS[12];
    } else {
        printf("Reutilizando cena 12\n");
        return &CENAS[12];
    }
}

#endif
