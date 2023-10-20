#include "desarrolladores.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"


Desarrolladores::Desarrolladores(Run* juego) : Estado(juego) {
    std::cout << " [DESARROLLADORES CREADO] "; 
    txt_desarrolladores.loadFromFile("resources/Menu/M0_3.png");
    desarrolladores.setTexture(txt_desarrolladores);
    txt_atras.loadFromFile("resources/Boton/atras.png");
    atras.setTexture(txt_atras);
    desarrolladores.setTextureRect(sf::IntRect(0,0,1280,720));
    atras.setScale(0.7f, 0.7f);
    atras.setPosition(590,620);
}

Desarrolladores::~Desarrolladores() {
    //Destructor
}


bool Desarrolladores::validacion() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_atras= atras.getGlobalBounds().width;
    int alto_atras= atras.getGlobalBounds().height;
    int margen_izq= atras.getGlobalBounds().left;
    int margen_sup= atras.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_atras && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_atras) {
       ok= true;
    }

return ok;
}

////////// -- Input --/////////  
void Desarrolladores::input(sf::Event &evento){
    //std::cout << " [DESARROLLADORES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed){
        if (validacion()) {
            this->getRun()->cambiar("menu", 7);
        }
    }
}

///////////////////////// -- Update --/////////////////////////   
void Desarrolladores::update(sf::Event &evento) {
    //std::cout << " [DESARROLLADORES UPDATE] "; 
    if(evento.type == sf::Event::MouseMoved){
        if (validacion()) {
            atras.setColor(sf::Color(175, 175, 175));
        }
        else{
            atras.setColor(sf::Color(255, 255, 255));             
        }
    }
}

//////// -- Render --/////// //  
void Desarrolladores::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [DESARROLLADORES RENDER] "; 
    Motor::Instance()->ventana().draw(desarrolladores);
    Motor::Instance()->ventana().draw(atras);

    if (!fuente.loadFromFile("resources/Letra/arial.ttf")){
        std::cout << "Probelma fuente" <<std::endl;
	}
    sf::Text texto("Desarrolladores", fuente, 64);
	texto.setOrigin(texto.getLocalBounds().width/2, 0);
	texto.setPosition(650, 80);

    sf::Text texto_1("Isabel Box Cerda", fuente, 32);
	texto_1.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_1.setPosition(720, 180);

    sf::Text texto_2("Alexandru Carlos Sular Feier", fuente, 32);
	texto_2.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_2.setPosition(640, 250);

    sf::Text texto_3("David Saavedra Pastor", fuente, 32);
	texto_3.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_3.setPosition(675, 320);

    sf::Text texto_4("Javier Botella Rico", fuente, 32);
	texto_4.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_4.setPosition(699, 390);

    sf::Text texto_5("Alejandro Martinez Gonzalves", fuente, 32);
	texto_5.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_5.setPosition(640, 460);

    Motor::Instance()->ventana().draw(texto);
    Motor::Instance()->ventana().draw(texto_1);
    Motor::Instance()->ventana().draw(texto_2);
    Motor::Instance()->ventana().draw(texto_3);
    Motor::Instance()->ventana().draw(texto_4);
    Motor::Instance()->ventana().draw(texto_5);

}

