#include "menu.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"


Menu::Menu(Run* juego) : Estado(juego) {
    std::cout << " [Menu] "; 

	if (!buffer.loadFromFile("resources/Sonido/hover.wav")){
        std::cout << "Probelma" <<std::endl;
	}
	s1.setBuffer(buffer);

	if (!buffer.loadFromFile("resources/Sonido/sel.wav")){
        std::cout << "Probelma" <<std::endl;
	}
	s2.setBuffer(buffer);

    s1.setVolume(50);
    s2.setVolume(50);

    txt_menu.loadFromFile("resources/Mapa/0/M0.png");
    spr_menu.setTexture(txt_menu);

    txt_soul.loadFromFile("resources/Boton/soul.png");
    spr_soul.setTexture(txt_soul);

    txt_comenzar.loadFromFile("resources/Boton/comenzar.png");
    spr_comenzar.setTexture(txt_comenzar);
    txt_controles.loadFromFile("resources/Boton/controles.png");
    spr_controles.setTexture(txt_controles);
    txt_desarrolladores.loadFromFile("resources/Boton/desarrolladores.png");
    spr_desarrolladores.setTexture(txt_desarrolladores);

    spr_comenzar.setOrigin(150,22);
    spr_controles.setOrigin(150,22);
    spr_desarrolladores.setOrigin(190,22);

    spr_menu.setTextureRect(sf::IntRect(0,0,1280,720));
    spr_controles.setPosition(250,597);
    spr_comenzar.setPosition(650,460);

    spr_controles.setScale(0.6f,0.6f);
    spr_soul.setScale(1.2f,1.2f);
    spr_comenzar.setScale(1.2f,1.2f);
    spr_desarrolladores.setScale(.6f,.6f);

    spr_desarrolladores.setPosition(990,600);
    spr_soul.setPosition(350,90);

}

Menu::~Menu() {
    //Destructor
}

bool Menu::comenzar() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_comenzar= spr_comenzar.getGlobalBounds().width;
    int alto_comenzar= spr_comenzar.getGlobalBounds().height;
    int margen_izq= spr_comenzar.getGlobalBounds().left;
    int margen_sup= spr_comenzar.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_comenzar && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_comenzar) {
       ok= true;
    }

return ok;
}

bool Menu::controles() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_controles= spr_controles.getGlobalBounds().width;
    int alto_controles= spr_controles.getGlobalBounds().height;
    int margen_izq= spr_controles.getGlobalBounds().left;
    int margen_sup= spr_controles.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_controles && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_controles) {
       ok= true;
    }

return ok;
}

bool Menu::desarrolladores() {
    bool ok= false;
    int ancho_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).x;
    int alto_ventana= sf::Mouse::getPosition(Motor::Instance()->ventana()).y;
    int ancho_des= spr_desarrolladores.getGlobalBounds().width;
    int alto_des= spr_desarrolladores.getGlobalBounds().height;
    int margen_izq= spr_desarrolladores.getGlobalBounds().left;
    int margen_sup= spr_desarrolladores.getGlobalBounds().top;

    if (ancho_ventana>margen_izq && ancho_ventana<margen_izq+ancho_des && 
        alto_ventana>margen_sup && alto_ventana<margen_sup+alto_des) {
       ok= true;
    }

return ok;
}

void Menu::input(sf::Event &evento){
    //std::cout << " [MENU INPUT] " << std::endl;
    if(evento.type == sf::Event::MouseButtonPressed) { 

        if (comenzar()) {
            if(n!=1){
                s2.play();
            }     
            n=1;
            std::cout << " [comenzar] " << std::endl;
            //comenzar.setColor(sf::Color(250, 20, 20));
            this->getRun()->cambiar("mapa", 7);
        }

        if (controles()) {
           if(n!=2){
                s2.play();
            }     
            n=2;
            std::cout << " [controles] " << std::endl;
            //controles.setColor(sf::Color(250, 20, 20));
            this->getRun()->cambiar("controles",7);              
        }

        if (desarrolladores()) {
            if(n!=3){
                s2.play();
            }     
            n=3;
            std::cout << " [desarrolladores] " << std::endl;
            //desarrolladores.setColor(sf::Color(250, 20, 20));
            this->getRun()->cambiar("desarrolladores",7);
        }

    }
    
}

void Menu::update(sf::Event &evento) { 
    //std::cout << " [MENU UPDATE] " << std::endl;
    
    if(evento.type == sf::Event::MouseMoved){

        if (comenzar()) {
            if(num!=1){
                s1.play();
            }
            num=1;
            std::cout << " [comenzar 2] " << std::endl;
            spr_comenzar.setColor(sf::Color(175, 175, 175));
            spr_comenzar.setScale(1.3, 1.3);              
        }
        else{   
            spr_desarrolladores.setColor(sf::Color(255, 255, 255));
            spr_controles.setColor(sf::Color(255, 255, 255));  spr_comenzar.setScale(1.2, 1.2);  
        }

        if (controles()) {
            if(num!=2){
                s1.play();
            }     
            num=2;
            std::cout << " [controles 2] " << std::endl;
            spr_controles.setColor(sf::Color(175, 175, 175));
            spr_controles.setScale(0.7, 0.7);               
        }
        else {
            spr_desarrolladores.setColor(sf::Color(255, 255, 255));
            spr_comenzar.setColor(sf::Color(255, 255, 255));
            spr_controles.setScale(0.6, 0.6);               
        }

        if (desarrolladores()) {
            if(num!=3){
                s1.play();
            }      
            num=3;
            //std::cout << " [desarrolladores 2] " << std::endl;
            spr_desarrolladores.setColor(sf::Color(175, 175, 175));
            spr_desarrolladores.setScale(0.7, 0.7);                    
        }
        else{
            spr_comenzar.setColor(sf::Color(255, 255, 255));
            spr_controles.setColor(sf::Color(255, 255, 255));
            spr_desarrolladores.setScale(0.6, 0.6);               
        }       
    } 
}

void Menu::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [MENU RENDER] " << std::endl;
    Motor::Instance()->ventana().draw(spr_menu);

    Motor::Instance()->ventana().draw(spr_soul);
    Motor::Instance()->ventana().draw(spr_comenzar);
    Motor::Instance()->ventana().draw(spr_controles);
    Motor::Instance()->ventana().draw(spr_desarrolladores);
}

