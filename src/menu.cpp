#include "menu.h"


//construtor da tela menu
Menu::Menu() {
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int Menu::Run(sf::RenderWindow &App) {

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
	string path = "";

	if (!Texture.loadFromFile("bin/Release/files/images/menu.png")){
		std::cerr << "Error loading menu.png" << std::endl;
		return (-1);
	}

	Sprite.setTexture(Texture);
	Sprite.setColor(sf::Color(255, 255, 255, alpha));

    if (!Font.loadFromFile("bin/Release/files/fonts/Arkhamreg.ttf")){

		std::cerr << "Error loading Arkhamreg.ttf" << std::endl;
		return (-1);
	}

    sf::Music musica;
    if (!musica.openFromFile("bin/Release/files/musicas/menu.ogg")){
        std::cerr << "Error loading menu.ogg" << std::endl;
        return -1; // error
    }

    musica.setLoop(true); //para a musica ficar sempre tocando
    musica.play(); //tocar a musica do menu

    //escolho tamanho e fontes dos textos do menu
	Menu1.setFont(Font);
	Menu1.setCharacterSize(60);
	Menu1.setString("Jogar");
	Menu1.setPosition({320.f, 200.f });

    Menu3.setFont(Font);
	Menu3.setCharacterSize(60);
	Menu3.setString("Continuar");
	Menu3.setPosition({250.f, 200.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(60);
	Menu2.setString("Sair");
	Menu2.setPosition({320.f,350.f });

	if (playing) {
		alpha = alpha_max;
	}

	while (Running) {

		//Verifying events
		while (App.pollEvent(Event)) {

			// Window closed
			if (Event.type == sf::Event::Closed) {
				return (-1);
			}

			//Key pressed
			if (Event.type == sf::Event::KeyPressed) {

				switch (Event.key.code) {
                    case sf::Keyboard::Up:
                        menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu = 1;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0) {
                            //Let's get play !
                            playing = true;
                            return (1);
                        }
                        else {
                            //Let's get work...
                            return (-1);
                        }
                        break;
                    default:
                        break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max) {
			alpha++;
		}

		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0) {
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
		}
		else {
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(Sprite);

		if (alpha == alpha_max) {
			if (playing) {
				App.draw(Menu3);
			}
			else {
				App.draw(Menu1);
			}
			App.draw(Menu2);
		}
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
