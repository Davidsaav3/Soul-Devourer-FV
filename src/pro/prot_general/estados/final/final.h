#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Final : public Estado{
    private:
        sf::Texture txt_final, txt_salir;
        sf::Sprite final, salir; 
        sf::Font fuente;
        
    public:
        Final(Run* juego); 
        virtual ~Final();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool validacion();
};