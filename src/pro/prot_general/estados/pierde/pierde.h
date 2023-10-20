#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Pierde : public Estado{
    private:
        sf::Texture T0,T1,T2,T3,T4,T5,T6, txt_salir, txt_continuar;
        sf::Sprite P,P0,P1,P2,P3,P4,P5,P6, salir,continuar; 
        sf::Font fuente;

    public:
        Pierde(Run* juego); 
        virtual ~Pierde();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool validacion();
        bool validacion2();
};