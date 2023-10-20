#include "pausa.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"


Pausa::Pausa(Run* juego) : Estado(juego) {
    std::cout << " [CONTROLES CREADO] "; 
    txt_pausa.loadFromFile("resources/Menu/M0_2.png");
    pausa.setTexture(txt_pausa);

    txt_continuar.loadFromFile("resources/Boton/continuar.png");
    continuar.setTexture(txt_continuar);

    txt_salir.loadFromFile("resources/Boton/salir.png");
    controles.setTexture(txt_salir);

    txt_controles.loadFromFile("resources/Boton/controles.png");
    controles.setTexture(txt_controles);

    controles.setPosition(426,490);
    salir.setTexture(txt_salir);
    pausa.setTextureRect(sf::IntRect(0,0,1280,720));
    continuar.setPosition(426,540);
    salir.setPosition(699,520);
    salir.setScale(0.7f,0.7f);
    continuar.setScale(0.7f,0.7f);
    controles.setScale(0.7f,0.7f);
}

Pausa::~Pausa() {
    //Destructor
}


bool Pausa::validacion_continuar() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_continuar= continuar.getGlobalBounds().width;
    int alto_continuar= continuar.getGlobalBounds().height;
    int margen_izq= continuar.getGlobalBounds().left;
    int margen_sup= continuar.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_continuar && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_continuar) {
       ok= true;
    }

return ok;
}

bool Pausa::validacion_controles() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_continuar= controles.getGlobalBounds().width;
    int alto_continuar= controles.getGlobalBounds().height;
    int margen_izq= controles.getGlobalBounds().left;
    int margen_sup= controles.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_continuar && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_continuar) {
       ok= true;
    }

return ok;
}

bool Pausa::validacion_salir() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_salir= salir.getGlobalBounds().width;
    int alto_salir= salir.getGlobalBounds().height;
    int margen_izq= salir.getGlobalBounds().left;
    int margen_sup= salir.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_salir && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_salir) {
       ok= true;
    }

return ok;
}


////////// -- Input --/////////  
void Pausa::input(sf::Event &evento){
    //std::cout << " [CONTROLES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed) { 
        if (validacion_continuar()) {
            this->getRun()->cambiar("mapa",7);
        }
        if (validacion_salir()) {
            this->getRun()->cambiar("menu",7);
        }
        if (validacion_controles()) {
            this->getRun()->cambiar("controles",7);
        }
        
    }
}

///////////////////////// -- Update --/////////////////////////   
void Pausa::update(sf::Event &evento) {
    //std::cout << " [CONTROLES UPDATE] "; 
    if(evento.type == sf::Event::MouseMoved){
        if (validacion_continuar()) {
            continuar.setColor(sf::Color(175, 175, 175));
        }
        else{
            continuar.setColor(sf::Color(255, 255, 255));   
        }
        if (validacion_salir()) {
            salir.setColor(sf::Color(175, 175, 175));
        }
        else{
            salir.setColor(sf::Color(255, 255, 255));         
        }
        if (validacion_controles()) {
            controles.setColor(sf::Color(175, 175, 175));
        }
        else{
            controles.setColor(sf::Color(255, 255, 255));        
        }
    }
}

//// -- Render --////   
void Pausa::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [CONTROLES RENDER] "; 
    Motor::Instance()->ventana().draw(pausa);
    Motor::Instance()->ventana().draw(continuar);
    Motor::Instance()->ventana().draw(salir);
    Motor::Instance()->ventana().draw(controles);
    
    if (!fuente.loadFromFile("resources/Letra/arial.ttf")){
        std::cout << "Probelma fuente" <<std::endl;
	}
    sf::Text texto("Pausa", fuente, 64);
	texto.setOrigin(texto.getLocalBounds().width/2, 0);
	texto.setPosition(620, 180);
    
    Motor::Instance()->ventana().draw(texto);
}

