#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Gana : public Estado{
    private:
        sf::Texture txt_gana, txt_salir;
        sf::Sprite gana, salir; 
        
    public:
        Gana(Run* juego); 
        virtual ~Gana();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool validacion();
};