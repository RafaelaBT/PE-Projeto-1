#ifndef TORRE_DO_DRAGAO_H
#define TORRE_DO_DRAGAO_H

#include "../puzzles/fibonacciPuzzle.h"
#include "../puzzles/jankenPuzzle.h"
#include "../puzzles/puzzlePocao.h"
#include "../puzzles/puzzle-senha.h"
#include "../puzzles/puzzle-sequencia.h"
#include "../puzzles/palavrasPuzzle.h"
#include "../puzzles/puzzleDomino.h"
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
Cena *cena19();
Cena *cena20();
Cena *cena21();
Cena *cena22();
//puzzle-sequencia -> cenas 23 a 27, ids 114 a 118
Cena *cena23();
Cena *cena24();
Cena *cena25();
Cena* cena26();
Cena *cena27();
Cena *imagemInicio();
Cena *fibonacci1();
Cena *fibonacci2();
Cena *fibonacci3();
Cena *fibonacci4();
Cena *fibonacci5();
Cena *fibonacci6();
Cena *fibonacci7();
Cena *fibonacci8();
Cena *fibonacci9();
Cena *fibonacci10();
Cena *fibonacci11();
Cena *fibonacci12();
Cena *fibonacci13();
Cena *fibonacciImagem();
Cena *ravenImage();
Cena *imagemPalavras();
Cena *imagemPocoes();
Cena *imagemDesmaio();
Cena *imagemSenha();
Cena *cenaSenha();
Cena *janken1();
Cena *janken2();
Cena *janken3();
Cena *janken4();

Cena jogoTorreDoDragao()
{
    int numDeCenas = 60;
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
    char cenaDescricao[] = "Apos atravessar o hall de entrada, você entra em um quarto iluminado por velas e com inumeros pergaminhos e livros espalhados pelo chao.\nNo centro da sala, se encontra uma mesa com um livro e uma pena de escrever.\n\nVoce escuta uma voz amargurada, mas parece que ela esta muito distante e vai se esvaindo com o passar do tempo.\n\n\t'A memoria é uma dadiva...\n\tProteja-a ou ela sera levada.\n\tO tempo nao espera nem o seu mais fiel amigo...'\n\nDe repente, o livro se abre, suas paginas sao reviradas freneticamente e param..., acompanhadas de um silencio profundo. So ha voce na sala.\n\nPalavras comecam a serem escritas no livro.";
    strcpy(cena.descricao, cenaDescricao);
    cena.tipo = 0;
    cena.cenaDeSucesso = imagemPalavras();
    return adicionarCena(cena);
}

Cena *imagemPalavras()
{
    Cena cena;
    cena.id = 66;
    cena.tipo = 7;
    strcpy(cena.descricao, "./C/images/palavras.txt");
    cena.cenaDeSucesso = cena4();
    return adicionarCena(cena);
}

Cena *cena4()
{
    Cena cena;
    cena.id = 6;
    char cenaDescricao[] = "Voce se sente atordoado, parece que algo esta testando sua sanidade.\nSe aproximando do livro, a principio, parece conseguir entender as palavras.\n\nDecore o máximo que puder! Mas sera que voce esta pronto? \n\nATENCAO: Ao tocar a pena, o tempo passara a correr.\n\n(NOTA: As frases adaptadas desse puzzle foram retiradas de 'CEM TROVAS POPULARES (anonimas)' da Colecao 'Trovadores Brasileiros' - Organizacao de Luiz Otavio e J. G. de Araujo Jorge.)";
    strcpy(cena.descricao, cenaDescricao);
    cena.tipo = 0;
    cena.cenaDeSucesso = cena5();
    return adicionarCena(cena);
}

Cena *cena5()
{
    Cena cena;
    cena.id = 7;
    strcpy(cena.descricao, "");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena6();
    return adicionarCena(cena);
}

Cena *cena6()
{
    Cena cena;
    cena.id = 8;
    strcpy(cena.descricao, "As palavras desaparecem. Voce se sente mais tonto e se apoia na mesa, olhando ao redor. Aquela pilha de livros estava ali antes? Voce nao tem mais certeza... nao, foco! Voce nao pode desistir, nao agora. Voce ainda tem muito o que percorrer.\nVoce tenta se recompor.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena7();
    return adicionarCena(cena);
}

Cena *cena7()
{
    Cena cena;
    cena.id = 9;
    strcpy(cena.descricao, "");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = cena8();
    return adicionarCena(cena);
}

Cena *cena8()
{
    Cena cena;
    cena.id = 88;
    strcpy(cena.descricao, "Voce se sente esgotado e sua visao vai se fechando, quase nao consegue segurar mais a pena. Coitado. Por que voce veio? Ou melhor, quando? Voce nao se lembra... mas sabe que precisa tentar mais uma vez, e a sua unica chance de sair daqui.\n\nCom toda a sua força restante, voce se aproxima novamente.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena22();
    return adicionarCena(cena);
}

Cena *imagemDesmaio()
{
    Cena cena;
    cena.id = 10;
    cena.tipo = 7;
    strcpy(cena.descricao, "./C/images/desmaio.txt");
    cena.cenaDeSucesso = cena9();
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
    cena.tipo = 0;
    strcpy(cena.descricao, "As paginas são reviradas de novo, mas ao contrario, e o livro se fecha. O silencio total reina novamente.\n\nBAM!\n\nAs grades enferrujadas caem e voce escuta uma voz ja conhecida:\n\n - Muito bem, heroi! Voce passou meu primeiro enigma. Mas ainda ha um grande caminho pela frente...\n\nVoce atravessa a sala e passa a porta para o proximo desafio.");
    cena.cenaDeSucesso = cena11();
    return adicionarCena(cena);
}

Cena *cena11()
{
    Cena cena;
    cena.id = 13;
    cena.tipo = 0;
    strcpy(cena.descricao, "Ao sair da sala do livro voce percorre um corredor de pedra polida em paralelepípedos, com bastante limo nas partes mais baixas. Por um longo tempo não há portas até que você chega em uma grande de metal com um ar sólido. Você a observa por um tempo e depois testa a maceneta. Ela gira e a porta abre. Tomando fôlego você passa para dentro da próxima sala.");
    cena.cenaDeSucesso = cena12();
    return adicionarCena(cena);
}

Cena *cena12()
{
    Cena cena;
    cena.id = 14;
    strcpy(cena.descricao, "Assim que voce entra na proxima sala consegue perceber que tem alguma coisa errada com o seu chao, como se ele estivesse conectado a algum mecanismo.\n\nA parte principal do mecanismo parece ser uma tabua conectada a parede, com tres bobinas giratorias e numeros de uma senha, assim como um cadeado.\n\nVoce se aproxima do desafio.\n\n");
    cena.tipo = 0;
    cena.cenaDeSucesso = imagemSenha();
    return adicionarCena(cena);
}

Cena *imagemSenha(){
  Cena cena;
  cena.id = 111;
  cena.tipo = 7;
  strcpy(cena.descricao, "./C/images/senha.txt");
  cena.cenaDeSucesso = cenaSenha();
  return adicionarCena(cena);
}

Cena *cenaSenha(){
  Cena cena;
  cena.id = 112;
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
    cena.cenaDeSucesso = imagemPocoes();
    return adicionarCena(cena);
}

Cena *imagemPocoes()
{
    Cena cena;
    cena.id = 91;
    cena.tipo = 7;
    strcpy(cena.descricao, "./C/images/pocoes.txt");
    cena.cenaDeSucesso = cena18();
    return adicionarCena(cena);
}

Cena *cena18()
{
    Cena cena;
    cena.id = 20;
    strcpy(cena.descricao, "Voce abre a porta e segue pelo corredor do castelo. Voce sobreviveu ate aqui. nada pode te deter certo?");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena19();
    return adicionarCena(cena);
}

Cena *cena19()
{
  Cena cena;
  cena.id = 21;
  strcpy(cena.descricao, "Voce se encontra andando por corredores interminaveis, que parecem se contorcer e mesclar uns aos outros. Ao pisar em uma das pedras do chao um alcapao escondido se abre fazendo com que voce caia em uma sala mal iluminada.");
  cena.tipo = 8;
  cena.cenaDeSucesso = cena21();
  cena.cenaDeFalha = cena20();
  return adicionarCena(cena);
}

Cena *cena20()
{
    Cena cena;
    cena.id = 22;
    strcpy(cena.descricao, "Voce olha o homem na sua frente colocando sua ultima peça no tabuleiro e murmurando “me desculpe” repetidas vezes antes de voce sentir uma dor aguda no pescoco e morrer.");
    cena.tipo = 3;
    return adicionarCena(cena);
}

Cena *cena21()
{
    Cena cena;
    cena.id = 23;
    strcpy(cena.descricao, "Colocando sua ultima peca no tabuleiro a cadeira solta seus pes e uma corda cai do buraco do alcapao. Com uma ultima olhada para o homem na sala voce promete o tirar do castelo e escala a corda de volta para o corredor.");
    cena.tipo = 0;
    cena.cenaDeSucesso = cena23();
    return adicionarCena(cena);
}

Cena *cena22()
{
    Cena cena;
    cena.id = 99;
    strcpy(cena.descricao, "");
    cena.tipo = 6;
    cena.cenaDeSucesso = cena10();
    cena.cenaDeFalha = imagemDesmaio();
    return adicionarCena(cena);
}

Cena *cena23(){
  Cena cena;
  cena.id = 114;
  strcpy(cena.descricao, "Após andar por mais um tempo, você encontra uma nova sala com uma música suave tocando, lhe hipnotizando a entrar... \n\nDentro dela você encontra uma caixinha de música dourada tocando a linda melodia, com uma pequena estátua de uma flor girando em seu interior. Ao lado da caixinha de música se encontra uma lira com um bilhete, que diz:\n\n\t\tPara por esta sala passar\n\t\ta melodia correta deve seguir.\n\t\tSe na tarefa fracassarr\n\t\teternamente a música irá prosseguir.\n\nAssim que encosta na lira você se sente em um transe e não consegue mais soltá-la, então a música para… Quando começar de novo é melhor seguir atentamente.");
  cena.tipo = 0;
  cena.cenaDeSucesso = cena24();
  return adicionarCena(cena);
}

Cena *cena24(){
  Cena cena;
  cena.id = 115;
  cena.tipo = 9;
  cena.cenaDeFalha = cena25();
  cena.cenaDeSucesso = cena26();
  return adicionarCena(cena);
}

Cena *cena25(){
  Cena cena;
  cena.id = 116;
  strcpy(cena.descricao, "Errando a última nota você pragueja a sua incapacidade musical e sente o transe ficando mais forte, você não consegue se mexer a não ser para tocar a lira. A música da caixinha continua, te forçando a tocar a lira para o resto dos seus dias.");
  cena.tipo = 3;
  return adicionarCena(cena);
}

Cena *cena26(){
  Cena cena;
  cena.id = 117;
  strcpy(cena.descricao, "Tocando a última nota você sente seu corpo saindo do transe, você está livre. Parece que aquelas aulas de lira na infância não foram inúteis afinal! Silenciosamente agradecendo à sua mãe você sai da sala o mais rápido possível para não cair no encanto da música novamente, seguindo assim o seu caminho pelo castelo.");
  cena.tipo = 0;
  cena.cenaDeSucesso = janken1();
  return adicionarCena(cena);
}

Cena *fibonacci1()
{
    Cena cena;
    cena.id = 40;
    cena.tipo = 0;
    strcpy(cena.descricao, "Vagando pelo castelo você entra por um corredor de pedra polida em formato de paralelepípedo. Parece que o negócio desse dragão está dando certo para ter uma ala de tanta qualidade. \n\nConforme os corredores passam eles vão ficando mais largos e você começa a ver mais tapeçariaa, decorações suntuosas nas paredes, armaduras completas em pose de continência, quadros, espadas e toda a sorte de items. \n\nDepois que o dragão estiver morto é capaz de você se tornar o novo senhor deste castelo, e será um senhor rico.");
    cena.cenaDeSucesso = fibonacci2();
    return adicionarCena(cena);
}

Cena *fibonacci2()
{
    Cena cena;
    cena.id = 41;
    cena.tipo = 0;
    strcpy(cena.descricao, "Você passa por algumas salas a procura do caminho para o oponente. Até que se depara com pessoas. \nServentes com uma coleira metalica ao redor do pescoço e dela pende uma corrent que não é longa mas é bem útil para alguém que quiser puxar e controlar o pobre coitado. \n\nEles se assustam com sua presença conforme te notam e começam a sair por portas laterais, entrar em quartos e bater a porta ou limpar o chão mais de perto, longe do alcance dos seus olhos.");
    cena.cenaDeSucesso = fibonacci3();
    return adicionarCena(cena);
}

Cena *fibonacci3()
{
    Cena cena;
    cena.id = 42;
    cena.tipo = 0;
    strcpy(cena.descricao, "Você se aproxima de um deles, um homem velho vestido com pouco mais que trapos. De perto você nota que a coleira de metal fez machucados ao redor da garganta. Ele deve ser escravo faz muito tempo. \n\nVocê pergunta se ele está bem e, após uma breve hesitação e um olhar para os lados checando se é com ele mesmo, o velho balança a cabeça freneticamente em aprovação. \nQuando você pergunta sobre o caminho ele aponta para uma direção e você percebe que, o caminho estava no fim do corredor. \n\nEstranho. Você se pergunta como você não havia percebido até agora? \n\nEra óbvio que estava ali. \n\nSempre esteve ali.");
    cena.cenaDeSucesso = fibonacci4();
    return adicionarCena(cena);
}

Cena *fibonacci4()
{
    Cena cena;
    cena.id = 43;
    cena.tipo = 0;
    strcpy(cena.descricao, "Tomando folêgo você ruma para a porta e a abre. Dentro, um corredor mais estreito e sem as suntuosidades de fora que deve ter uns 10 metros até uma porta dupla. \n\nO local não tem janelas apenas a luz que entra por onde chegou e que brilha da borda da porta iluminam o local. Olhando de novo você nota que a parede e o chão perto da porta dupla estão mais sujos que o redor, mas não dá para saber de quê.\n\nVocê dá alguns passos e escuta com pesar um 'click'. Teus reflexos não são rápidos o suficiente para voltar a tempo e a última coisa que você vê da porta por onde veio é o rosto do velho.\n\nEle não está surpreso ou apavorado, apenas complacente... Você raciocina e sabe que ele armou para você.");
    cena.cenaDeSucesso = fibonacci5();
    return adicionarCena(cena);
}

Cena *fibonacci5()
{
    Cena cena;
    cena.id = 44;
    cena.tipo = 0;
    strcpy(cena.descricao, "No instante seguinte a porta está fechada e começa a se mover na sua direção. \n\nSeus instintos heróicos sabem que não é o fim e deve ter uma saída, afinal o dragão disse que haveriam desafios e que só passando por eles você poderia o enfrentar. \n\nE mais importante ainda, se não achar uma saída vai ter que se acostumar com a vida em 2D.");
    cena.cenaDeSucesso = fibonacciImagem();
    return adicionarCena(cena);
}

Cena *fibonacciImagem()
{
    Cena cena;
    cena.id = 53;
    cena.tipo = 7;
    strcpy(cena.descricao, "./C/images/fibonacci.txt");
    cena.cenaDeSucesso = fibonacci6();
    return adicionarCena(cena);
}

Cena *fibonacci6()
{
    Cena cena;
    cena.id = 45;
    cena.tipo = 0;
    strcpy(cena.descricao, "Você olha para a porta e se aproxima dela rapidamente. Ela não tem fechadura dobradiça nem nada, se não fosse a borda brilhante poderia confundir com uma parede pintada de porta. \n\nOlhando mais de perto você percebe que ela tem uma espécie de quadro no meio e é adornada com alguns símbolos e runas que você sabe que são mágicas. \nAo tocar no quadro vários símbolos começam a se mover e deles se formam alguns números. \n\nVocê presume que deve desenhar algum número no quadro");
    cena.cenaDeSucesso = fibonacci7();
    return adicionarCena(cena);
}

Cena *fibonacci7()
{
    Cena cena;
    cena.id = 46;
    cena.tipo = 2;
    strcpy(cena.descricao, "O que você vê no quadro:\n");
    cena.puzzle = fibonacciPuzzle(4, 3, 12);
    cena.cenaDeFalha = fibonacci8();
    cena.cenaDeSucesso = fibonacci12();
    return adicionarCena(cena);
}

Cena *fibonacci8()
{
    Cena cena;
    cena.id = 47;
    cena.tipo = 2;
    strcpy(cena.descricao, "Os números tremem e somem mas a porta permanece sólida.\n\nVocê olha para trás e vê que a parede já andou um bom trecho, mais do que você gostaria. Após preciosos segundos novos símbolos aparecem no quadro e você se concentra no enigma:\n");
    cena.puzzle = fibonacciPuzzle(6, 4, 14);
    cena.cenaDeFalha = fibonacci9();
    cena.cenaDeSucesso = fibonacci12();
    return adicionarCena(cena);
}

Cena *fibonacci9()
{
    Cena cena;
    cena.id = 48;
    cena.tipo = 2;
    strcpy(cena.descricao, "Novamente os números tremem e somem e a porta parece ainda mais sólida, mas a verade é que você começa a sentir a parede encostando nas suas costas. \nVocê desesperadamente toca no quadro e ele mostra mais um conjunto de números, talvez pela última vez, queira você ou não. \n\nNão há tempo para esperar você olha para o conjunto e escreve a resposta da sua vida:\n");
    cena.puzzle = fibonacciPuzzle(10, 10, 21);
    cena.cenaDeFalha = fibonacci10();
    cena.cenaDeSucesso = fibonacci12();
    return adicionarCena(cena);
}

Cena *fibonacci10()
{
    Cena cena;
    cena.id = 49;
    cena.tipo = 0;
    strcpy(cena.descricao, "Você não tem tempo de olhar o que aconteceu pois começa a sentir uma dor absurda. Seus músculos queimam e seu corpo instintivamente tenta empurrar as parede em direções opostas, mas o mecanismo é tão sólido quanto a porta. \n\nLogo você escutra um 'crek' e sente a dor excruciante de ossos quebrarem. \nA parede segue, quebrando os ossos das costas, cranio e a esmagar músculos e gordura. \n\nLíquidos se espalham e um dos últimos pensamentos que te ocorre é que agora sabe de onde a sujeira perto da porta veio. \n\nTarde demais. \n\nVocê é esmagado impiedosamente pelo progresso do mecanismo e a imobilidade da porta.");
    cena.cenaDeSucesso = ravenImage();
    return adicionarCena(cena);
}

Cena *fibonacci11()
{
    Cena cena;
    cena.id = 50;
    cena.tipo = 3;
    strcpy(cena.descricao, "Depois de alguns minutos o mecanismo reverte e a porta por você onde entrou se abre. \nO velho, ainda com a cara complacente entra com um saco de estopa e um balde com água com um pano meio rasgado pendurado no ombro.\n\nEle calmamente recolhe seus restos e os joga no saco, uma parte de cada vez, como se pensando em outra coisa. Algo mais importante. Talvez no que fazer para o jantar. \n\nDepois, ele tira o pano do ombro e molha no balde, torcendo antes de começar a limpar seus fluídos.\nSangue, urina, e fezes misturadas vão sendo limpas e torcidas no balde.\n\nEle trabalha por vários minutos nauseantes e de limpeza displicente e então desiste, deixando um pouco da sujetira ainda presa nos cantos, livre para secar até que o próximo herói destemido e tolo venha enfrentar o dragão.\n\nEle sai pela porta e a fecha, deixando novamente o corredor em um silêncio fúnebre.\n\n\tFim de Jogo");
    return adicionarCena(cena);
}

Cena *ravenImage()
{
    Cena cena;
    cena.id = 54;
    cena.tipo = 7;
    strcpy(cena.descricao, "./C/images/raven.txt");
    cena.cenaDeSucesso = fibonacci11();
    return adicionarCena(cena);
}

Cena *fibonacci12()
{
    Cena cena;
    cena.id = 51;
    cena.tipo = 0;
    strcpy(cena.descricao, "Os deuses da matemática sorriem para você! A porta dupla brilha intensamente, te cegando e no instante seguinte não está mais lá. Você cai para frente já que estava se apoiando nela e momentos depois a parede chega tampando o caminho de volta.\n\nVocê suspira aliviado antes de lembrar do velho que te colocou naquela enrascada. Você lida com ele no caminho de volta.");
    cena.cenaDeSucesso = fibonacci13();
    return adicionarCena(cena);
}

Cena *fibonacci13()
{
    Cena cena;
    cena.id = 52;
    cena.tipo = 3;
    strcpy(cena.descricao, "Você sente o calor do sol tocar sua pele enquanto se levanta e percebe uma moeda dourada no chão aonde apoiou a mão, seguindo com os olhos percebe que não é só uma, são várias, e olhando ao redor percebe que não são várias são pilhas, montes.\nE não são só moedas, são cálices, espadas, baús, joias, pratarias e toda sorte de item valioso.\n\nVocê percebe a temperatura e lembra que o sol não é tão quente assim normalmente, olha rapidamente ao redor e não vê chamas acesas, nem locais por onde entratria calor externo.\n\nApós um momento de concentração você escuta um som, e depois com uma pontada de pânico surgindo no peito entende que aquela é uma respiração.\n\nPesada.\nGrave.\nMaligna.\n\nFinalmente você percebe que está no lugar mais perigoso desse castelo.");
    return adicionarCena(cena);
}


Cena *janken1()
{
    Cena cena;
    cena.id = 131;
    cena.tipo = 0;
    strcpy(cena.descricao, "Caminhando pelos corredores você se depara com uma luva em formato de mão flutuando. Você olha curioso mas deixa para lá. Conforme passa por ela a luva se move e te empurra de volta com força. \nSurpreso, você assume posição de batalha mas a luva não faz menção de atacar. Acima dela se desenham no ar palavras \n\n>> JANKEN MÁGICO << \n\nEscolha entre PEDRA, PAPEL ou TESOURA e dispute com a mão mágica. \nVença 5 partidas e poderá seguir. \nPerca 5 partidas e um fim terrível lhe aguarda. \n\nA mão se prepara e a disputa começa");
    cena.cenaDeSucesso = janken2();
    return adicionarCena(cena);
}

Cena *janken2()
{
    Cena cena;
    cena.id = 132;
    cena.tipo = 13;
    strcpy(cena.descricao, "Um placar mágico aparece. Registrando tudo sem demora.\n");
    cena.cenaDeFalha = janken3();
    cena.cenaDeSucesso = janken4();
    return adicionarCena(cena);
}

Cena *janken3()
{
    Cena cena;
    cena.id = 133;
    cena.tipo = 3;
    strcpy(cena.descricao, "A mão te soca até você virar uma massa de pele, osso e sangue. Você morreu.");
    return adicionarCena(cena);
}

Cena *janken4()
{
    Cena cena;
    cena.id = 134;
    cena.tipo = 3;
    strcpy(cena.descricao, "A luva lhe faz um aperto de mão e aparentemente foca em continência te liberando passagem. Você não entende bem e segue seu caminho acumulando mais essa vitória");
    return fibonacci1(cena);
}


#endif
