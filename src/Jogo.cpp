#include "Jogo.h"
#include "Pilha.h"
/* construtor com as imagens */
Jogo::Jogo(void) {
	  movement_step = 10;
	  posx = 380;
	  posy = 590;
	  i = 0;

	//this->jogador.setFillColor(sf::Color(255, 255, 255, 255));
	this->jogador.setColor(sf::Color(255, 255, 255, 255));
	//this->jogador.setSize({ 10.f, 10.f });
	this->jogador.setScale({ 10.f, 10.f });

	if (fundoJogo.loadFromFile("bin/Release/files/images/background.png"))
		this->background.setTexture(fundoJogo);

  	//valor inicial do placar
	this->placar = 0;

  	//se encontrar a fonte
	if (this->Font.loadFromFile("bin/Release/files/fonts/Arkhamreg.ttf")) {
		this->text_placar1.setFont(Font);
		this->text_placar1.setColor(sf::Color(255, 255, 255, 255));
		this->text_placar1.setCharacterSize(20);
		this->text_placar1.setPosition({705.f, 100.f });
		this->text_placar1.setString("*Pontos*");

		this->text_placar2.setFont(Font);
		this->text_placar2.setColor(sf::Color(255, 255, 255, 255));
		this->text_placar2.setCharacterSize(20);
		this->text_placar2.setPosition({705.f, 150.f });
	}

	this->nroVidas = 3;

	if (this->imagem_vidas.loadFromFile("bin/Release/files/images/coracao.png"))
    		this->vidas.setTexture(this->imagem_vidas);

  	/* estou tentando usar isso pra bruxinha aparecer na tela mas não está funcionando... */
	if (this->imagem_jogador.loadFromFile("bin/Release/files/images/player01.png")) {
		this->jogador.setTexture(this->imagem_jogador);
		this->jogador.setPosition(0, 0);
	}

	this->imagem_objeto[0].loadFromFile("bin/Release/files/images/ball.jpg");
	this->imagem_objeto[1].loadFromFile("bin/Release/files/images/skull.jpg");
	this->imagem_objeto[2].loadFromFile("bin/Release/files/images/caulderon.jpg");
	this->imagem_objeto[3].loadFromFile("bin/Release/files/images/poison.jpg");

}

void Jogo::desenharVida(sf::RenderWindow &App){
    int posx = 552;

    //desenho a quantidade de cora��es
    for(int i = 0; i < this->nroVidas; i++){
        this->vidas.setPosition(posx, 350);
        App.draw(this->vidas);
        posx += 50;
    }

}

/* função desenha pilha */
void Jogo::desenhaPilhaObjetos(sf::RenderWindow &App){

		/* pilha auxiliar para desenhar os objetos */
		Pilha<int> paux;
		int aux;

    this->h = 351; /* o tamanho inicial é sempre o mesmo */

		/* o personagem é desenhado primeiro */
		this->jogador.setTexture(this->imagem_jogador);
		this->jogador.setPosition(0, 0);
    App.draw(this->jogador);

		/*
			declarei a Pilha<int> pilha; em Jogo.h, que vai armazenar a pilha de objetos da personagem
			todos os elementos de pilha são mandados para paux
		*/
		while (!this->pilha.EstaVazia()) {
			pilha.Retira(aux);
			paux.Insere(aux);
		}

		/* agora que paux possui pilha invertida, reinserimos os valores em pilha na ordem correta e aproveitamos para desenhar o objeto! */
		while (!paux.EstaVazia()) {
			paux.Retira(aux);
			/* inserimos o elemento de volta na stack */
			pilha.Insere(aux);
			/*
				Em Jogo.h declarei um array de textures: Sf::Texture imagem_objetos[4] onde carregei no construtor a imagem de
				cada um dos objetos, poderia ter feito um spritesheet em que cada posição é um objeto mas como não
				criamos uma classe objeto e sim definimos cada um por um inteiro tipo achei que esse inteiro poderia ser equivalente
				ao index do array de texturas... por isso uso aux da pilha como index do array
			*/
			objeto.setTexture(imagem_objeto[aux]);
			/*
				o valor 57.5 centraliza o objeto no meio da bruxa, mas como a pilha é desenhada com um objeto sobre o outro a altura deve
				ser variável, por isso declarei h em jogo.h para ir alterando a altura a cada objeto, a altura inicial é o height da tela (600)
				menos a distancia ate a prancha da bruxa menos o tamanho dos objetos, portanto h é inicialmente 351, e vou subindo mais pixels a cada
				objeto (por mais que o tamanho do objeto seja de 94 px, 84 deixa os objetos um "sobrepondo" um pouco o outro como se fosse uma pilha real)
			*/
			objeto.setPosition(posx + 57.5, posy + h);
			h += 94;

			/* desenha o objeto */
			App.draw(this->objeto);
		}

}


void Jogo::desenharPlacar(sf::RenderWindow &App){
    //atualiza o placar
	this->text_placar2.setString(std::to_string(placar));

	//desenho os textos
	App.draw(this->text_placar1);
	App.draw(this->text_placar2);
}

void Jogo::desenharPainel(sf::RenderWindow &App){
    this->desenharPlacar(App);
    this->desenharVida(App);
}

void Jogo::desenharTela(sf::RenderWindow &App){
    //limpo os elementos da tela
    App.clear(sf::Color(0, 0, 0, 0));

    //desenho o fundo
    App.draw(this->background);
		App.draw(this->jogador);

    //desenhar o placar
    this->desenharPainel(App);

    //desenho o personagem
		//this->jogador.setTextureRect(sf::IntRect(0, 200, 250, 233));
    App.draw(this->jogador);

    this->desenhaPilhaObjetos(App);

    //exibo na tela
    App.display();
}

int Jogo::Run(sf::RenderWindow &App) {

	sf::Event Event;
	bool Running = true;

  //toco uma m�sica de fundo do jogo
  sf::Music MusicaFundo;

	if (!MusicaFundo.openFromFile("bin/Release/files/musicas/fundo.ogg")){
        std::cerr << "Error loading menu.ogg" << std::endl;
    }

  MusicaFundo.setVolume(50); //defino um volume mais baixo que o normal para a m�sica n�o ser cansativa
  MusicaFundo.setLoop(true); //para a musica ficar sempre tocando
  MusicaFundo.play(); //tocar a musica do menu

    //enquanto estiver rodando
	while (Running) {

		//Verifico os eventos poss�veis
		while (App.pollEvent(Event)) {

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
					case sf::Event::MouseMoved:
						if ((Event.mouseMove.x - 50) >= 0 && (Event.mouseMove.x + 50) < 800)
							this->posx = Event.mouseMove.x - 125;
					default:
					break;

				}
			}
		}

		//Updating
		if (posx > 675) {
			posx = 675;
		}

		if (posx < -125){
			posx = -125;
		}

		this->jogador.setPosition({posx, posy});
		this->desenharTela(App);
	}

	//caso aconte�a algum erro e chegue neste ponto...
	return -1;
}
