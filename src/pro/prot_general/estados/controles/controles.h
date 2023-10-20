#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Controles : public Estado{
    private:
        sf::Texture txt_controles, txt_atras, txt_continuar;
        sf::Sprite controles, atras, continuar; 
        sf::Font fuente;

    public:
        Controles(Run* juego); 
        virtual ~Controles();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);
        bool validacion2();
        bool validacion();
};