#include "controles.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"

Controles::Controles(Run* juego) : Estado(juego) {
    std::cout << " [CONTROLES CREADO] "; 
    txt_controles.loadFromFile("resources/Menu/M0_3.png");
    controles.setTexture(txt_controles);
    txt_atras.loadFromFile("resources/Boton/atras.png");
    atras.setTexture(txt_atras);
    atras.setScale(0.7f, 0.7f);
    controles.setTextureRect(sf::IntRect(0,0,1280,720));
    atras.setPosition(490,600);

    txt_continuar.loadFromFile("resources/Boton/continuar.png");
    continuar.setTexture(txt_continuar);
    continuar.setPosition(650,600);
    continuar.setScale(0.7f,0.7f);
}

Controles::~Controles() {
    //Destructor
}


bool Controles::validacion() {
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

bool Controles::validacion2() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_atras= continuar.getGlobalBounds().width;
    int alto_atras= continuar.getGlobalBounds().height;
    int margen_izq= continuar.getGlobalBounds().left;
    int margen_sup= continuar.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_atras && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_atras) {
       ok= true;
    }

return ok;
}

////////// -- Input --/////////  
void Controles::input(sf::Event &evento){
    //std::cout << " [CONTROLES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed) { 
        if(evento.type == sf::Event::MouseButtonPressed){
            if (validacion()) {
                this->getRun()->cambiar("menu", 7);
            }
            if (validacion2()) {
                this->getRun()->cambiar("mapa", 7);
            }
        }
    }
}

///////////////////////// -- Update --/////////////////////////   
void Controles::update(sf::Event &evento) {
    //std::cout << " [CONTROLES UPDATE] "; 
    if(evento.type == sf::Event::MouseMoved){
        if (validacion()) {
            atras.setColor(sf::Color(175, 175, 175));
        }
        else{
            atras.setColor(sf::Color(255, 255, 255));             
        }
        if (validacion2()) {
            continuar.setColor(sf::Color(175, 175, 175));
        }
        else{
            continuar.setColor(sf::Color(255, 255, 255));             
        }
    }
}

//// -- Render --////   
void Controles::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [CONTROLES RENDER] "; 
    Motor::Instance()->ventana().draw(controles);
    Motor::Instance()->ventana().draw(atras);

    if (!fuente.loadFromFile("resources/Letra/arial.ttf")){
        std::cout << "Probelma fuente" <<std::endl;
	}
    sf::Text texto("Controles", fuente, 64);
	texto.setOrigin(texto.getLocalBounds().width/2, 0);
	texto.setPosition(640, 80);

    sf::Text texto_1("W: Subir escalera", fuente, 32);
	texto_1.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_1.setPosition(500, 180);

    sf::Text texto_2("S: Bajar escalera", fuente, 32);
	texto_2.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_2.setPosition(500, 250);

    sf::Text texto_3("D: Derecha", fuente, 32);
	texto_3.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_3.setPosition(500, 320);

    sf::Text texto_4("A: Izquierda", fuente, 32);
	texto_4.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_4.setPosition(500, 390);

    sf::Text texto_5("P: Pausa", fuente, 32);
	texto_5.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_5.setPosition(500, 460);

    //

    sf::Text texto_6("K: Ataque debil", fuente, 32);
	texto_6.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_6.setPosition(850, 320);

    sf::Text texto_7("L: Ataque fuerte", fuente, 32);
	texto_7.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_7.setPosition(850, 390);

    sf::Text texto_8("Q: Ataque a distancia", fuente, 32);
	texto_8.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_8.setPosition(850, 460);

    sf::Text texto_9("R: ataque ultimate", fuente, 32);
	texto_9.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_9.setPosition(850, 180);

    sf::Text texto_10("W+Direccion: subir rampa", fuente, 32);
	texto_10.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_10.setPosition(850, 250);

    
    Motor::Instance()->ventana().draw(texto);
    Motor::Instance()->ventana().draw(texto_1);
    Motor::Instance()->ventana().draw(texto_2);
    Motor::Instance()->ventana().draw(texto_3);
    Motor::Instance()->ventana().draw(texto_4);
    Motor::Instance()->ventana().draw(texto_5);

    Motor::Instance()->ventana().draw(texto_6);
    Motor::Instance()->ventana().draw(texto_7);
    Motor::Instance()->ventana().draw(texto_8);
    Motor::Instance()->ventana().draw(texto_9);
    Motor::Instance()->ventana().draw(texto_10);

    Motor::Instance()->ventana().draw(continuar);
}

