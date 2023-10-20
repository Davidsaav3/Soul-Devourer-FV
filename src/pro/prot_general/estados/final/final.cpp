#include "final.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"


Final::Final(Run* juego) : Estado(juego) {
    std::cout << " [CONTROLES CREADO] "; 
    txt_final.loadFromFile("resources/Menu/M0_2.png");
    final.setTexture(txt_final);
    txt_salir.loadFromFile("resources/Boton/menu.png");
    salir.setTexture(txt_salir);
    final.setTextureRect(sf::IntRect(0,0,1280,720));
    salir.setPosition(590,650);

    salir.setTexture(txt_salir);
    salir.setPosition(550,520);
    salir.setScale(0.7f,0.7f);
}

Final::~Final() {
    //Destructor
}


bool Final::validacion() {
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
void Final::input(sf::Event &evento){
    //std::cout << " [CONTROLES INPUT] "; 
    if(evento.type == sf::Event::MouseButtonPressed) { 
        if(evento.type == sf::Event::MouseButtonPressed){
            if (validacion()) {
                this->getRun()->cambiar("menu",7);
            }
        }
    }
}

///////////////////////// -- Update --/////////////////////////   
void Final::update(sf::Event &evento) {
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
void Final::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [CONTROLES RENDER] "; 
    Motor::Instance()->ventana().draw(final);
    Motor::Instance()->ventana().draw(salir);

    if (!fuente.loadFromFile("resources/Letra/arial.ttf")){
        std::cout << "Probelma fuente" <<std::endl;
	}
    sf::Text texto("! Has ganado !", fuente, 64);
	texto.setOrigin(texto.getLocalBounds().width/2, 0);
	texto.setPosition(610, 180);
    
    sf::Text texto_2("Muchas gracias x jugar", fuente, 44);
	texto_2.setOrigin(texto.getLocalBounds().width/2, 0);
	texto_2.setPosition(597, 280);
    
    Motor::Instance()->ventana().draw(texto);
    Motor::Instance()->ventana().draw(texto_2);
}        


