//incluir arquivo na pasta Cenas
//Função auxiliar com 100 frases diferentes.
//Fonte: http://falandodetrova.com.br/08cemtrovaspopulares

const char *vetor[150] = {
  "A arvore do amor se planta no centro do coracao; so a pode derrubar o golpe da ingratidao.",
  "A cantar ganhei dinheiro, a cantar se me acabou. O dinheiro mal ganhado, agua deu, agua levou.",
  "A desgraca do pau verde e ter o seco encostado: chega o fogo, queima o seco, fica o verde sapecado...",
  "A dor por maior que seja, se comprime, se contrai. Eu nunca vi dor no mundo que nao coubesse num ai.",
  "Alegria dos meus olhos e ver a quem quero bem: quando nao vejo quem quero, nao quero ver mais ninguem.",
  "Alma no corpo nao tenho: minha existencia e fingida; sou como o tronco quebrado, que da sombra sem ter vida.",
  "Amar e saber amar sao dois pontos delicados: os que amam, sao sem conta: os que sabem, sao contados.",
  "Amar e nao ter ciumes, isso nao e querer bem; quem nao zela o bem que ama, muito pouco amor lhe tem.",
  "A menina que eu namoro e que me quer muito bem, tem um sorriso que encanta e vinte contos tambem.",
  "Amigo, nao volte nunca aos teus amores passados, os mortos, por mais queridos, devem ficar enterrados.",
  "Amor com amor se paga: nunca vi coisa tao justa; paga-me contigo mesmo saberas quanto te custa.",
  "A noite quando me deito eu rezo a Virgem Maria, para sonhar toda a noite com quem penso todo o dia.",
  "Aqui tens a minha mao, ajunta palma com palma domina o meu coracao, toma posse de minha alma.",
  "Aqui tens meu coracao e a chave para o abrir; nao tenho mais que te dar nem tu o que me pedir!",
  "As rosas e que sao belas, sao os espinhos que picam, mas sao as rosas que caem, sao os espinhos que ficam...",
  "Bateram, abri por do; era a desgraca que entrou. Fez-lhe pena ver-me so e nunca mais me deixou.",
  "Carvalho que da bogalho, porque nao das coisa boa? Cada um da o que tem, conforme a sua pessoa.",
  "Chamaste-me tua vida, eu tua alma quero ser: a vida acaba com a morte, a alma nao pode morrer.",
  "Com pena pego na pena, com pena quero escrever; caiu-me a pena no chao com pena de te nao ver.",
  "Coracao que a dois ama, e que depois quer agradar, nao ande enganando os outros, veja com quem quer ficar.",
  "Das lagrimas faco contas com que rezo as escuras; oh! morte que tanto tardas! oh! vida que tanto duras!",
  "Deixa ficar descontente contigo la quem quiser; tres coisas nunca se emprestam: arma, cavalo e mulher...",
  "Deus nao criou infelizes... Os infelizes se fazem... Mas quem pode interromper o destino que eles trazem?!",
  "Dizem que o pito alivia as magoas do coracao; eu pito, pito e repito e as magoas nunca se vao.",
  "E, si o sor ficasse preto, nunca mais que ninguem via. Mas teus olhos tem mais forca: eles sao preto e alumia...",
  "Eu amante e tu amante, qual de nos sera mais firme? Eu como o sol a buscar-te, tu como a sombra a fugir-me?",
  "Esta noite dormi fora, na porta do meu amor; deu vento na roseira me cobriu todo de flor.",
  "Eu amava-te, o menina, se nao fora um so senao: seres pia de agua benta onde todos poe a mao.",
  "Eu casei-me e cativei-me, ainda nao me arrependi; quanto mais vivo contigo, menos posso estar sem ti.",
  "Eu quero bem a desgraca que sempre me acompanhou; tenho odio a aventura, que bem cedo me deixou.",
  "Eu quero bem, mas nao digo a quem e que quero bem; quero que saiba que eu quero, mas que nao saibam a quem!",
  "Estudante, deixe os livros, e volte-se para mim; mais vale um dia de amores que dez anos de latim.",
  "Foste pedir-me a meu pai, sem saber o querer meu; em tudo meu pai governa, mas nisso governo eu.",
  "Fui no livro do destino minha sorte procurar, corri folhas encontrei: eu nasci para te amar.",
  "Ha uma especie de plantas que vingam sem ter raizes... Assim sao certos sorrisos nos labios dos infelizes.",
  "Inda que meu pai me mate, minha mae me tire a vida, minha palavra esta dada, minha alma esta prometida.",
  "Infeliz me considero em todos os meus intentos: quando penso achar venturas nao acho senao tormentos.",
  "Ja fui  alegre e contente, hoje nao sou mais ninguem. Ja fui consolo dos tristes, hoje sou triste tambem.",
  "Ja nao posso ser contente, tenho a esperanca perdida ando perdido entre a gente nem morro nem tenho vida.",
  "La vai uma ave voando com as penas que Deus lhe deu, contando pena por pena, mais penas padeco eu.",
  "Meu amor, vai pelo mundo: ir pelo mundo e um bem; o mundo tambem e regra para aqueles que a nao tem.",
  "Meu pai julga que me tem fechadinha na varanda. Coitadinho de meu pai que bem enganado anda...",
  "Minha mae, case-me cedo, enquanto sou rapariga, que o milho sachado tarde nao da palha, nem espiga.",
  "Menina dos olhos verdes, da-me agua pra beber; nao e sede, nao e nada, e vontade de te ver.",
  "Muito vence quem se vence muito diz quem diz tudo, porque ao discreto pertence a tempo fazer-se mudo.",
  "Nao me tentes com fortuna para contigo casar: eu prefiro mais que tenha coracao para me dar...",
  "Naquela noite saudosa quando de ti me apartei, cem passos nao eram dados quando sem alma fiquei.",
  "Ninguem deve, neste mundo, de alheias desgracas rir. Quando o sol troveja, o raio nao faz ponto onde cair...",
  "Ninguem descubra o seu peito por maior que seja a dor; quem o seu peito descobre e de si mesmo traidor.",
  "Ninguem se julgue feliz por ter tudo em bom estado, pois vem a tirana sorte, faz dum feliz desgracado.",
  "No coracao da mulher, por muito frio que faca, ha sempre calor bastante para aquecer a desgraca.",
  "No ventre da Virgem Mae encarnou divina graca; entrou e saiu por ela, como o sol pela vidraca.",
  "O alegria do mundo por onde e que tens andado? Tenho corrido mil terras, e nao te tenho encontrado...",
  "O anel que tu me deste era de vidro e quebrou; o amor que tu me tinhas era pouco e acabou.",
  "O coracao e os olhos sao dois amantes leais, quando o coracao tem penas logo os olhos dao sinais.",
  "O cipreste verde, triste, copia da minha figura, verde qual minha esperanca, triste qual minha ventura.",
  "Olhos pretos matadores, cara cheia de alegria, um beijo na tua boca me sustenta todo dia.",
  "O meu amor me disse ontem que eu andava coradinha; os anjos do ceu me levem se esta cor nao era minha!",
  "O morte, o tirana morte, contra ti tenho mil queixas quem has de levar, nao levas, quem deves deixar, nao deixas!",
  "O pouco que Deus nos deu cabe numa mao fechada; o pouco com Deus e muito, o muito sem Deus e nada.",
  "Os males que me circundam sao como as ondas do mar: atras de uma vem outras, sem nunca poder cessar.",
  "Os olhos de meu benzinho sao joias que nao se vendem, sao balas que me feriram, sao correntes que me prendem.",
  "Os teus olhos, pretos, pretos, sao como a noite cerrada... Mesmo pretos, como sao, sem eles, nao vejo nada.",
  "O teu pe decerto cabe num sapatinho chines, mas a vaidade nao cabe em toda a China, talvez!",
  "Passarinhos, meus amigos, eu tambem sou vosso irmao: vos tendes penas nas asas, eu tenho-as no coracao.",
  "Pobre louco apaixonado, ai de mim! Que nao mais via, que seu amor, pouco a pouco, esfriava dia a dia.",
  "Por te amar perdi a Deus, por teu amor me perdi, agora vejo-me so, sem Deus, sem amor, sem ti.",
  "Priva-me de que eu te veja isso, meu bem, pode ser; mas privar-me de que te ame, so Deus tem esse poder.",
  "Quando eu te vi, logo disse: lindos olhos para amar, linda boca para os beijos se a menina os quiser dar.",
  "Quando o sobreiro der baga e a cortica for ao fundo, so entao se hao de acabar as mas linguas deste mundo.",
  "Que cigarro tao cheiroso!... Me de uma fumacinha. Com a desculpa do cigarro sua mao pega na minha.",
  "Que disser que a vida acaba, digo-lhe eu que nunca amou; quem deixou ficar saudades nunca a vida abandonou.",
  "Quem inventou a partida nao sabia o que era amar; quem parte sem vida, quem fica, fica a chorar.",
  "Quem me dera ser a hera pela parede subir, para chegar a janela do teu quarto de dormir.",
  "Quem me dera ser as contas desse teu lindo colar, para dormir em teu seio e nunca mais acordar.",
  "Quem me dera ser a seda, depois da seda o cetim, para andar de mao em mao, as mocas pegando em mim!",
  "Quem nao nasceu pra sofrer desafiar pode os fados, que os proprios deuses respeitam os entes afortunados.",
  "Quem quiser ter vida longa fuja sempre que puder do medico, boticario, melao, pepino e mulher.",
  "Quem roubou o meu amor deve ser um meu amigo... Levou penas, deixou glorias, levou trabalhos consigo...",
  "Quem tem amores nao dorme, nem de noite, nem de dia; da tantas voltas na cama, como o peixe na agua fria.",
  "Quem tiver filhas no mundo nao fale das alfadadas; porque as filhas da desgraca tambem nasceram honradas.",
  "Quem tiver filhos pequenos por forca ha de cantar: quantas vezes as maes cantam com vontade de chorar.",
  "Rouxinol canta de noite, de manha a cotovia; todos cantam, so eu choro toda a noite e todo o dia!",
  "Venci! Cheguei a subir! Nada! Ninguem me ajudou! Mas comecei a cair, toda gente me puxou!...",
  "Vossos cabelos na testa e o que vos da tanta graca; parecem meadas de oiro aonde o sol se embaraca.",
  "Um suspiro de repente, um certo mudar de cor, sao infaliveis sinais de quem sofre o mal de amor.",
  "Ter amor e muito bom quando ha correspondencia; mas amar sem ser amado faz perder a paciencia.",
  "Todo homem que diz que sim depois de ter dito nao; primeiro fala o orgulho depois fala o coracao.",
  "Triste daquele a quem falta, na vida, que se evapora, uma crianca que salta, que canta, que ri e chora!",
  "Triste durmo, triste acordo, triste torno a amanhecer. Pra mim tudo e tristeza, serei triste ate morrer.",
  "Triste sou, triste me vejo sem a tua companhia; tao triste, que nem me lembro se alegre fui algum dia.",
  "Tudo o que e triste no mundo tomara que fosse meu, para ver se tudo junto era mais triste do que eu.",
  "Tu te queixas, eu me queixo... Qual de nos tem razao? Tu te queixas do meu zelo; eu, da tua ingratidao.",
  "Sao tres coisas neste mundo que um homem de gosto quer, uma casinha asseada, um pinho bom e mulher.",
  "Se esta rua fosse minha eu mandava ladrilhar, com pedrinhas de brilhante, para meu bem passar.",
  "Se eu pensara quem tu eras, quem tu avias de ser, nao dava meu coracao para tao cedo sofrer.",
  "Se mil coracoes tivesse com eles eu te amaria; mil vidas que Deus me desse em ti as empregaria.",
  "Se onde se mata um homem, por uma cruz e preceito, tu deves trazer, Maria, um cemiterio no peito.",
  "Se tu fosses pe de pau eu queria ser cipo: vivia em ti enroscado no teu corpo dando no.",
  "Sonhei contigo esta noite, mas oh! que sonho atrevido! Sonhei que estava abracado a  forma  do  teu  vestido!"
};

const char * banco_frases(int n)
{
  return vetor[n - 1];
}
