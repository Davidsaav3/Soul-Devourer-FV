#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Desarrolladores : public Estado{
    private:
        sf::Texture txt_desarrolladores, txt_atras;
        sf::Sprite desarrolladores, atras;
        sf::Font fuente;
        
    public:
        Desarrolladores(Run* juego); 
        virtual ~Desarrolladores();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool validacion();
};