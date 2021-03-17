#ifndef TORRE_DO_DRAGAO_H
#define TORRE_DO_DRAGAO_H

#include "../puzzles/sequenciaFibonacciPuzzle.h"
#include "cena.h"
#include <string.h>
const int MAX_CENAS = 13;
Cena CENAS[MAX_CENAS];

Cena jogoTorreDoDragão();
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

Cena jogoTorreDoDragão() {
    return introducao();
}

Cena introducao() {
    Cena cena;
    strcpy(cena.descricao, "Você é um herói renomado passando por uma vila praticamente destruída, os moradores contam que um dragão vive em um castelo no topo da montanha e recentemente vem atacando a vila.\n\nTodos ficam aliviados quando seus serviços são oferecidos, e assim você parte para o castelo - mas será que sobreviverá às inúmeras armadilhas do local e à força de um dragão?");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena1();
    CENAS[0] = cena;
    return CENAS[0];
}

Cena * cena1() {
    Cena cena;
    strcpy(cena.descricao, "Em uma terra muito distante, você é um herói renomado passando por uma vila praticamente em ruínas.\n\nSe aproximando, você encontra um morador e pergunta sobre o motivo de toda essa destruição, que conta: \n\n     - Ó grande herói! Um dragão anda atormentando nossa vila, roubando o gado e ateando fogo em nossas casas. Ele vive no castelo no topo daquela montanha... Por favor, nos ajude! Não vamos sobreviver muito mais tempo nesse estado. \n\nConcordando em os ajudar, você segue rumo ao castelo...");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena2();
    CENAS[1] = cena;
    return &CENAS[1];
}

Cena * cena2() {
    Cena cena;
    strcpy(cena.descricao, "Após um dia de viagem, você finalmente se encontra na porta do castelo. Mas antes de abrir suas grandes portas escuta uma voz muito antiga e poderosa, sem dúvida do próprio dragão: \n\n    - Hummm, o que temos aqui? Um herói? HAHAHAHA… Não pense que pode chegar aqui e lutar comigo, poucos possuem essa honra. Você terá que se provar merecedor, passando por todas minhas armadilhas antes de me alcançar. Vamos ver quanto tempo você dura...\n\nFalando isso as portas se abrem, como que por vontade própria, lhe chamando para os perigos adentro. Assim que você atravessa elas imediatamente se fecham novamente, lhe prendendo no castelo. Agora o único jeito de sair é derrotando o dragão ou morrendo no processo.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena3();
    CENAS[2] = cena;
    return &CENAS[2];
}

Cena * cena3() {
    Cena cena;
    strcpy(cena.descricao, "Após atravessar o hall de entrada, você entra em um quarto iluminado por velas e com inúmeros pergaminhos e livros espalhados pelo chão, existe uma porta de grades trancada na parede oposta da entrada.\n\nNo centro da sala se encontra uma mesa com um livro aberto e uma pena de escrever, você percebe que o livro é mágico pois as palavras parecem se escreverem e re-escrevem sozinhas.\n\nAo se aproximar as seguintes palavras aparecem em suas páginas: ");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena4();
    CENAS[3] = cena;
    return &CENAS[3];
}

// Rafaela eu separei a cena do puzzle pois não sei como vai ser o comportamento. Se implementar usando a interface de puzzle poderia ser na própria cena3() com o tipo de puzzle
Cena * cena4() {
    Cena cena;
    strcpy(cena.descricao, "Somente os que conhecem os padrões da lógica podem resolver meus desafios.\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(1, 3, 4, "Logo abaixo estão escritos os seguintes números junto com um indicatívo da pergunta do livro: \n\n");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena5();
    CENAS[4] = cena;
    return &CENAS[4];
}

Cena * cena5() {
    Cena cena;
    strcpy(cena.descricao, "O livro chacoalha levemente quando você termina de escrever. A página comeca a ficar mais preenchida de tinta a partir das bordas e no espaço central em branco a tinta se move.\n\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(2, 3, 5, "Após a tinta parar de se mover uma nova sequência aparece com mais uma pergunta: ");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena6();
    CENAS[5] = cena;
    return &CENAS[5];
}

Cena * cena6() {
    Cena cena;
strcpy(cena.descricao, "O livro treme com força, quase caindo de suas mãos. Você começa a sentir um calafrio e uma sensaçao de que não pode continuar falhando.\nA tinta preenche a página com símbolos de morte em diversas culturas e há poucos espaços em branco na página.\n");
    cena.tipo = 2;
    cena.puzzle = fibonacciPuzzle(6, 6, 5, "O livro forma novos números nos espaços em branco, e tu acredita que é a última vez que ele escreverá algo para você: ");
    cena.cenaDeSucesso = cena8();
    cena.cenaDeFalha = cena7();
    CENAS[6] = cena;
    return &CENAS[6];
}

Cena * cena7() {
    Cena cena;
    strcpy(cena.descricao, "Está claro que números não são o seu forte, a cada tentativa que faz você sente sua sanidade se esvaindo. O livro drenou sua personalidade e você não consegue mais pensar racionalmente.\n\nOs dias passam sem você conseguir sair da sala, até que as consequências da falta de água e comida finalmente te alcançam e você morre lentamente por desidratação, se tornando mais um dos esqueletos do castelo...\n\nFim de jogo.");
    cena.tipo = 3;
    CENAS[7] = cena;
    return &CENAS[7];
}

Cena * cena8() {
    Cena cena;
    strcpy(cena.descricao, "O livro volta a ficar completamente em branco e símbolos de positividade começam aparecer, em meio a eles tu reconhece um 'Parabéns' e 'Sucesso!'. \n\nNada mais acontece com o livro e após um longo minuto as grades prendendo a porta desaparecem e você escuta uma voz já conhecida:\n\nMuito bem, herói! Você passou meu primeiro enigma. Mas ainda há um grande caminho pela frente...\n\nVocê atravessa a sala e passa a porta para o próximo desafio.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena9();
    CENAS[8] = cena;
    return &CENAS[8];
}

Cena * cena9() {
    Cena cena;
    strcpy(cena.descricao, "Ao sair da sala do livro você percorre um corredor de pedra polida em paralelepípedos, com bastante limo nas partes mais baixas. Não há portas e depois andar por um longo tempo você chega em uma bifurcação, na verdade uma trifurcação.\n\nO caminho da esquerda te leva para um novo corredor parecido com o que tu vem percorrendo. O da direita leva para um corredor que tem uma leve descida. No centro tem uma porta de ferro\n\nEscolha um caminho:\n0 - Corredor da esquerda\n1 - Corredor que desce pela direita\n2 - Entrar pela porta no centro");
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
    strcpy(cena.descricao, "Tu anda pelo corredor por longas horas e ele não parece mudar. Tu se cansa e monta um acampamento precário. Ao acordar tu se alimenta com o que resta de suas proviões e continua andando. Por fim tu se cansa e começa a voltar mas o corredor não tem fim. Após andar e dormir mais duas vezes você percebe uma luz no fim do corredor e quando chega percebe que voltou a trifurcação. Você sabe que o dragão deve estar usando magia para te fazer se cansar.\n\nEscolha um caminho:\n0 - Corredor que desce pela direita\n1 - Entrar pela porta no centro");
    cena.tipo = 1;
    cena.escolhasPossiveis[0] = &CENAS[11];
    cena.escolhasPossiveis[1] = &CENAS[12];
    cena.maxEscolhas = 2;
    CENAS[10] = cena;
    return &CENAS[10];
}

Cena * cena11() {
    Cena cena;
    strcpy(cena.descricao, "Tu começa a andar pelo corredor, ele vai ficando mais inclinado conforme os minutos vão se passando até caminhar ficar perigoso. Quando tu resolve voltar escuta um barulho se aproximando. Logo tu percebe que era uma armadilha, possívelmente mortal. Um líquido desce pela corredor, aos montes preenchendo todo o espaço. Uma tromba de água te engole e te joga pelas parede, ela parece não acabar nunca e você sente cortes surgindo pelo seu corpo, o corredor tinha espinhos afiados em todas as parede. Depois de quase uma eternidade e quase se afogando tu é jogado em um lago, provavelmente o fosso do castelo. Tu pensa estar seguro quando vários peixes começam a te morder, em quantidades cada vei maiores e com mais verocidade. São piranhas. Em alguns momentos tu perde sua consciência e depois de alguns minutos somente seus ossos restam no fundo do fosso.");
    cena.tipo = 3;
    CENAS[11] = cena;
    return &CENAS[11];
}

Cena * cena12() {
    int tipo = 3;
    if (CENAS[12].tipo != tipo) {
        printf("Criando cena 12\n");
        Cena cena;
        strcpy(cena.descricao, "Tu abre a porta e vê uma placa que diz: Fim da demo. Você sobreviveu até aqui. Jogue novamente");
        cena.tipo = tipo;
        CENAS[12] = cena;
        return &CENAS[12];
    } else {
        printf("Reutilizando cena 12\n");
        return &CENAS[12];
    }
}

#endif
