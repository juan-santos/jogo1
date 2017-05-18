#include "Jogo.h"
template <typename T>
std::string to_string(T value) {
  //create an output string stream
  std::ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}

/* construtor com as imagens */
Jogo::Jogo(void) {
  movement_step = 10;
  posx = 275;
  posy = 350;
  i = 0;

  this->objetoLancamento = -1;

  if (fundoJogo.loadFromFile("bin/Release/files/images/background.png"))
	this->background.setTexture(fundoJogo);

	//valor inicial do placar
	this->placar = 0;

	//se encontrar a fonte
	if (this->Font.loadFromFile("bin/Release/files/fonts/Arkhamreg.ttf")) {
		this->text_placar2.setFont(Font);
		this->text_placar2.setColor(sf::Color(255, 255, 255, 255));
		this->text_placar2.setCharacterSize(70);
		this->text_placar2.setPosition({602.f, 180.f });
	}

	this->nroVidas = 3;

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

void Jogo::desenharVida(sf::RenderWindow &App){
	int posix = 552;

	//desenho a quantidade de cora��es
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

    this->h = 78; /* o tamanho inicial é sempre o mesmo */

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
		objeto.setPosition(posx + 57.5, posy + h);
		h -= 64;

			/* desenha o objeto */
			App.draw(this->objeto);
    }

}

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

void Jogo::colisao(sf::RenderWindow &App){

    App.draw(this->lancamento);

    int posicaoY = this->lancamento.getPosition().y;
    int posicaoX = this->lancamento.getPosition().x;

    //se o objeto não chegou no mesmo y da bruxinha
    if(440 >= posicaoY){

        cout << "y obj" << posicaoY << " bruxa" << this->posy << endl;
        cout << "x obj" << posicaoX << " bruxa" << this->posx << endl;

        //vou avançando com o sprite e aumentando a velocidade
        posicaoY = posicaoY + 3;//(this->placar/10);

        this->lancamento.setPosition(posicaoX, posicaoY);
        //só exibo na tela se o item estiver em movimento
        App.draw(this->lancamento);

    } else{

        if(this->objetoLancamento != -1){

            //se a posição está correta
            if((this->posx > posicaoX) && ((this->posx+100) >= posicaoX)){
                this->placar+=50;
                this->pilha.Insere(this->objetoLancamento);
            } else{
                //se o jogador deixou o item cair
                this->nroVidas--;
            }

            //indico que pode haver um novo lancamento
            this->objetoLancamento = -1;

        }

        this->lancamento.setPosition(-800, -600);
    }

}

void Jogo::desenharPlacar(sf::RenderWindow &App){
	//atualiza o placar
	this->text_placar2.setString(to_string(placar));

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
	this->desenhaPilhaObjetos(App);

    this->colisao(App);

	//exibo na tela
	App.display();
}

int Jogo::Run(sf::RenderWindow &App) {

	sf::Event Event;
	bool Running = true;

	//toco uma m�sica de fundo do jogo
	sf::Music MusicaFundo;

	if (!MusicaFundo.openFromFile("bin/Release/files/musicas/fundo.ogg"))
	      std::cerr << "Error loading menu.ogg" << std::endl;

	MusicaFundo.setVolume(50); //defino um volume mais baixo que o normal para a m�sica n�o ser cansativa
	MusicaFundo.setLoop(true); //para a musica ficar sempre tocando
	MusicaFundo.play(); //tocar a musica do menu

	//enquanto estiver rodando
	while (Running) {

		//Verifico os eventos poss�veis
		while (App.pollEvent(Event)) {

            this->lancarObjeto(App);

            //perdeu o jogo
            if(this->nroVidas < 0){
                return 3;
            }

            //venceu
            if(this->placar == 300){
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

	//caso aconte�a algum erro e chegue neste ponto...
	return -1;
}
