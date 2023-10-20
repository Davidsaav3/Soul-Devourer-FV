#include "pierde.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"
#include "../../nivel/nivel.h"


Pierde::Pierde(Run* juego) : Estado(juego) {
    //game= juego;
    std::cout << " [CONTROLES CREADO] "; 

    if(!T0.loadFromFile("resources/Menu/M0_2.png")){
        std::cout << "Probelma M0_2" <<std::endl;
    }
    P0.setTexture(T0);
    
   /*if(this->getRun()->getNivel()==0){
        if(!T0.loadFromFile("resources/Menu/M0_2.png")){
            std::cout << "Probelma M0_2" <<std::endl;
        }
        P0.setTexture(T0);
    }
    if(this->getRun()->getNivel()==1){
       if(!T0.loadFromFile("resources/Menu/M1_2.png")){
            std::cout << "Probelma M1_2" <<std::endl;
        }
        P1.setTexture(T0);
    }
    if(this->getRun()->getNivel()==1){
       if(!T0.loadFromFile("resources/Menu/M2_2.png")){
            std::cout << "Probelma M1_2" <<std::endl;
        }
        P2.setTexture(T0);
    }
    if(this->getRun()->getNivel()==3 || this->getRun()->getNivel()==4){
       if(!T0.loadFromFile("resources/Menu/M3_2.png")){
            std::cout << "Probelma M1_2" <<std::endl;
        }
        P3.setTexture(T0);
    }
    if(this->getRun()->getNivel()==5){
       if(!T0.loadFromFile("resources/Menu/M4_2.png")){
            std::cout << "Probelma M1_2" <<std::endl;
        }
        P5.setTexture(T0);
    }
    if(this->getRun()->getNivel()==6){
       if(!T0.loadFromFile("resources/Menu/M5_2.png")){
            std::cout << "Probelma M1_2" <<std::endl;
        }
        P6.setTexture(T0);
    }*/

    txt_salir.loadFromFile("resources/Boton/menu.png");
    salir.setTexture(txt_salir);
    
    txt_continuar.loadFromFile("resources/Boton/continuar.png");
    continuar.setTexture(txt_continuar);
    P0.setTextureRect(sf::IntRect(0,0,1280,720));
    continuar.setPosition(406,510);
    salir.setPosition(699,475);
    salir.setScale(0.7f,0.7f);
    continuar.setScale(0.7f,0.7f);

}

Pierde::~Pierde() {
    //Destructor
}


bool Pierde::validacion() {
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

bool Pierde::validacion2() {
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
void Pierde::input(sf::Event &evento){
   
    //std::cout << " [ESTADO] " << this->getRun()->getNivel() <<  std::endl;
    //std::cout << " [CONTROLES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed) { 
        if(evento.type == sf::Event::MouseButtonPressed){
            if (validacion()) {
                this->getRun()->cambiar("mapa",7);
            }
            if (validacion2()) {
                this->getRun()->cambiar("menu",7);
            }
        }
    }
}

///////////////////////// -- Update --/////////////////////////   
void Pierde::update(sf::Event &evento) {
    //std::cout << " [CONTROLES UPDATE] "; 


    if(evento.type == sf::Event::MouseMoved){
        if (validacion()) {
            continuar.setColor(sf::Color(175, 175, 175));
        }
        else{
            continuar.setColor(sf::Color(255, 255, 255));
        }

        if (validacion2()) {
            salir.setColor(sf::Color(175, 175, 175));       
        }
        else{
            salir.setColor(sf::Color(255, 255, 255));
        } 
    }
}

//// -- Render --////   
void Pierde::render(sf::Time tiempojuego, float tiempoo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [CONTROLES RENDER] "; 
    /*if(this->getRun()->getNivel()==0){
       P= P0;
    }
    if(this->getRun()->getNivel()==1){
       P=P1;
    }
    if(this->getRun()->getNivel()==2){
       P= P2;
    }
    if(this->getRun()->getNivel()==3 || this->getRun()->getNivel()==4){
        P= P3;
    }
    if(this->getRun()->getNivel()==5){
        P= P5;
    }
    if(this->getRun()->getNivel()==6){
       P= P6;
    }*/
    
    std::cout << " [ESTADO] " << this->getRun()->getNivel() <<  std::endl;
    Motor::Instance()->ventana().draw(P0);
    Motor::Instance()->ventana().draw(salir);
    Motor::Instance()->ventana().draw(continuar);

    if (!fuente.loadFromFile("resources/Letra/arial.ttf")){
        std::cout << "Probelma fuente" <<std::endl;
	}
    sf::Text texto("Has muerto :(", fuente, 64);
	texto.setOrigin(texto.getLocalBounds().width/2, 0);
	texto.setPosition(610, 180);
    
    Motor::Instance()->ventana().draw(texto);
}

