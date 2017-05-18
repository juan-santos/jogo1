#include "Jogo.h"

#define NUMERO_VIDAS 3
#define ALTURA_INICIAL 78
#define NUMERO_ACERTOS_VITORIA 6
#define SCORE_ACERTO 50
#define LARGURA_ITEM 115
#define ALTURA_BRUXA 64

template <typename T>
std::string to_string(T value) {
  std::ostringstream os ;

  os << value ;

  return os.str() ;
}

/* construtor com as imagens */
Jogo::Jogo(void) {
    this->movement_step = 10;
    this->posx = 275;
    this->posy = 350;
    this->i = 0;

    //não há imagem para o sprite de lançamento
    this->objetoLancamento = -1;

    //se achar a imagem de fundo
    if (this->fundoJogo.loadFromFile("bin/Release/files/images/background.png")){
        this->background.setTexture(fundoJogo);
    }


    //valor inicial do placar
    this->placar = 0;

    //se encontrar a fonte
    if (this->Font.loadFromFile("bin/Release/files/fonts/Arkhamreg.ttf")) {
        this->text_placar2.setFont(Font);
        this->text_placar2.setColor(sf::Color(255, 255, 255, 255));
        this->text_placar2.setCharacterSize(70);
        this->text_placar2.setPosition({602.f, 180.f });
    }

    //número inicial de vidas
	this->nroVidas = NUMERO_VIDAS;

	if (this->imagem_vidas.loadFromFile("bin/Release/files/images/coracao.png"))
    		this->vidas.setTexture(this->imagem_vidas);

	this->imagem_jogador[0].loadFromFile("bin/Release/files/images/player01.png");
	this->imagem_jogador[1].loadFromFile("bin/Release/files/images/player02.png");
	this->imagem_jogador[2].loadFromFile("bin/Release/files/images/player03.png");
	this->imagem_jogador[3].loadFromFile("bin/Release/files/images/player04.png");
	this->imagem_jogador[4].loadFromFile("bin/Release/files/images/player05.png");

	this->imagem_objeto[0].loadFromFile("bin/Release/files/images/ball.png");
	this->imagem_objeto[1].loadFromFile("bin/Release/files/images/skull.png");
	this->imagem_objeto[2].loadFromFile("bin/Release/files/images/caulderon.png");
	this->imagem_objeto[3].loadFromFile("bin/Release/files/images/poison.png");

}

/*Realiza o desenho dos corações da vida*/
void Jogo::desenharVida(sf::RenderWindow &App){
	int posix = 552;

	//desenho a quantidade de coraçoes
	for(int i = 0; i < this->nroVidas; i++){
	    this->vidas.setPosition(posix, 350);
	    App.draw(this->vidas);
	    posix += 50;
	}
}

/* função desenha pilha */
void Jogo::desenhaPilhaObjetos(sf::RenderWindow &App){

	/* pilha auxiliar para desenhar os objetos */
	Pilha<int> paux;
	int aux;

    this->h = ALTURA_INICIAL; /* o tamanho inicial é sempre o mesmo */

	/* o personagem é desenhado primeiro */
	this->jogador.setTexture(this->imagem_jogador[i++ % 4]);
	this->jogador.setPosition(posx, posy);
    App.draw(this->jogador);

	while (!this->pilha.EstaVazia()) {
		pilha.Retira(aux);
		paux.Insere(aux);
	}

	/* agora que paux possui pilha invertida, reinserimos os valores em pilha na ordem correta e aproveitamos para desenhar o objeto! */
	while (!paux.EstaVazia()) {
		paux.Retira(aux);
		/* inserimos o elemento de volta na stack */
		pilha.Insere(aux);
		objeto.setTexture(imagem_objeto[aux]);
		objeto.setPosition(posx + float(LARGURA_ITEM/2), posy + this->h);
		this->h -= 64;

        /* desenha o objeto */
        App.draw(this->objeto);
    }

}

/*Função que faz o objeto "cair*/
void Jogo::lancarObjeto(sf::RenderWindow &App){

    //começo a jogar um próximo objeto
    if(this->objetoLancamento == -1){
        //escolho um objeto aleatório
        this->objetoLancamento = rand()%4;
        this->lancamento.setTexture(this->imagem_objeto[this->objetoLancamento]);
        //escolho uma posicao aleatória em X de 0 até 500
        this->lancamento.setPosition(rand()%500, 0);
    }
}

/*Função que verifica se a bruxinha acertou o objeto*/
void Jogo::colisao(sf::RenderWindow &App){

    //obtenho a posição x e y do lançamento
    int posicaoY = this->lancamento.getPosition().y;
    int posicaoX = this->lancamento.getPosition().x;

    //se o objeto não chegou no mesmo y da bruxinha
    if(posicaoY <= 435){
        //vou avançando com o sprite e aumentando a velocidade
        posicaoY = posicaoY + 1 + int(this->placar/30);

        this->lancamento.setPosition(posicaoX, posicaoY);
        //só exibo na tela se o item estiver em movimento
        App.draw(this->lancamento);

    } else{

        //houver algum desenho dentro do lançamento
        if(this->objetoLancamento != -1){

            //se a posição está correta
            if(fabs(this->posx + (LARGURA_ITEM/2) - posicaoX) < LARGURA_ITEM){
                this->placar+= SCORE_ACERTO;
                this->pilha.Insere(this->objetoLancamento);
            } else{
                //se o jogador deixou o item cair
                this->nroVidas--;
            }

            //indico que pode haver um novo lancamento
            this->objetoLancamento = -1;

        }
        //escondo o o lançamento até que a nova localização seja colocada
        this->lancamento.setPosition(-800, -600);
    }

}

/*Desenha o placar*/
void Jogo::desenharPlacar(sf::RenderWindow &App){
	//atualiza o placar
	this->text_placar2.setString(to_string(placar));

	//desenho os textos
	App.draw(this->text_placar1);
	App.draw(this->text_placar2);
}

/*Desenha o painel do jogo*/
void Jogo::desenharPainel(sf::RenderWindow &App){
//desenho todos os componentesdo painel
  this->desenharPlacar(App);
  this->desenharVida(App);
}

/*Função que chama todas as funções gráficas da tela*/
void Jogo::desenharTela(sf::RenderWindow &App){
	//limpo os elementos da tela
	App.clear(sf::Color(0, 0, 0, 0));

	//desenho o fundo
	App.draw(this->background);
	App.draw(this->jogador);

	//desenhar o placar
	this->desenharPainel(App);
	//desenhar a pilha de objetos
	this->desenhaPilhaObjetos(App);
	//realizar a colisão entre personagem e objeto
    this->colisao(App);

	//exibo na tela
	App.display();
}

int Jogo::Run(sf::RenderWindow &App) {

	sf::Event Event;
	bool Running = true;

	//toco uma música de fundo do jogo
	sf::Music MusicaFundo;

	if (!MusicaFundo.openFromFile("bin/Release/files/musicas/fundo.ogg"))
	      std::cerr << "Error loading menu.ogg" << std::endl;

	MusicaFundo.setVolume(50); //defino um volume mais baixo que o normal para a música não ser cansativa
	MusicaFundo.setLoop(true); //para a musica ficar sempre tocando
	MusicaFundo.play(); //tocar a musica do menu

	//enquanto estiver rodando
	while (Running) {

        this->lancarObjeto(App);

		//Verifico os eventos possíveis
		while (App.pollEvent(Event)) {

            //perdeu o jogo
            if(this->nroVidas < 0){
                return 3;
            }

            //venceu
            if(this->placar == NUMERO_ACERTOS_VITORIA*SCORE_ACERTO){
                return 2;
            }

			// caso feche a janela
			if (Event.type == sf::Event::Closed)
				return -1;

			// caso utilize o teclado
			if (Event.type == sf::Event::KeyPressed) {

				switch (Event.key.code) {

                    case sf::Keyboard::Escape:
                        return EXIT_SUCCESS;
                        break;
                    case sf::Keyboard::Left:
						if (posx > -125)
                            this->posx -= movement_step;
                        break;
                    case sf::Keyboard::Right:
						if (posx < 675)
                            this->posx += movement_step;
                        break;
					default:
                        break;

				}

			} else if (Event.type == sf::Event::MouseMoved) {
				if ((Event.mouseMove.x - 50) >= 0 && (Event.mouseMove.x + 50) < 800)
					this->posx = Event.mouseMove.x - 125;
			}
		}

		this->jogador.setPosition({this->posx, this->posy});
		this->desenharTela(App);
	}

	//caso aconteça algum erro e chegue neste ponto...
	return -1;
}
