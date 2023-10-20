#include "gana.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"


Gana::Gana(Run* juego) : Estado(juego) {
    std::cout << " [CONTROLES CREADO] "; 
    txt_gana.loadFromFile("resources/Menu/gana.png");
    gana.setTexture(txt_gana);
    txt_salir.loadFromFile("resources/Boton/continuar.png");
    salir.setTexture(txt_salir);
    gana.setTextureRect(sf::IntRect(0,0,1280,720));
    salir.setPosition(590,650);
}

Gana::~Gana() {
    //Destructor
}


bool Gana::validacion() {
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
void Gana::input(sf::Event &evento){
    std::cout << " [HEY] "<<std::endl;

    //std::cout << " [CONTROLES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed) { 
        if(evento.type == sf::Event::MouseButtonPressed){
            if (validacion()) {
                this->getRun()->cambiar("mapa",7);
            }
        }
    }
}

///////////////////////// -- Update --/////////////////////////   
void Gana::update(sf::Event &evento) {
    //std::cout << " [CONTROLES UPDATE] "; 
    if(evento.type == sf::Event::MouseMoved){
        if (validacion()) {
            salir.setColor(sf::Color(175, 175, 175));
        }
        else{
            salir.setColor(sf::Color(255, 255, 255));             
        }
    }
}

//// -- Render --////   
void Gana::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [CONTROLES RENDER] "; 
    Motor::Instance()->ventana().draw(gana);
    Motor::Instance()->ventana().draw(salir);
}

