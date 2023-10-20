#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mapa.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"
#include "../../nivel/nivel.h"

 
/////////////////////////////////////////
Mapa::Mapa(Run* juego) : Estado(juego) {
    Nivel::Instance();
    Nivel::Instance()->inicializar();
}

Mapa::~Mapa() {
    //Destructor
    delete N0;
    delete N1;
    delete N2;
    delete N3;
    delete N4;
    delete N5;
    
    for (Enemigo* i : enemigos) {
        delete i;
    }
}

//////////// -- Input --////////// --> Derivan a Nivel
void Mapa::input(sf::Event &evento){
    //std::cout << " [MAPA INPUT] ";
    
 if (evento.key.code == sf::Keyboard::P) {
        std::string estado= "pausa";

        Motor::Instance()->getVista().setCenter(640,360);
        Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
        
        this->getRun()->cambiar(estado,7);
    }

    Nivel::Instance()->input(evento);
}

///////////////////////// -- Update --/////////////////////////// 
void Mapa::update(sf::Event &evento) {
    //std::cout << " [MAPA UPDATE] "<< Nivel::Instance()->getEstado(); 
    
    //this->getRun()->setNivel(Nivel::Instance()->getNivel());

    
    if(Nivel::Instance()->getEstado()==3){
        std::string estado= "final";
        this->getRun()->cambiar(estado,7);
    }     
    if(Nivel::Instance()->getEstado()==2){
        std::string estado= "pierde";
        this->getRun()->cambiar(estado,7);
        int e= 0; Nivel::Instance()->setEstado(e);
        
    }    
    if(Nivel::Instance()->getEstado()==1){
        std::string estado= "final";
        this->getRun()->cambiar(estado,7);
    }
    
    if(evento.type){}
    Nivel::Instance()->update(evento);

    if(Nivel::Instance()->getFinal()){
        Nivel::Instance()->setFinal();
        std::string estado= "final";
        this->getRun()->cambiar(estado,7);
    }

}

/// -- Render --////  
void Mapa::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {
    //std::cout << " [MAPA RENDER] "; 
    Nivel::Instance()->render(tiempojuego,tiempo, percent, reloj_nuevo, RELOJ);
}

