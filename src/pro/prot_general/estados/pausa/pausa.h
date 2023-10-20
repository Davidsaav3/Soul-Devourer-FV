#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"


class Pausa : public Estado{
    private:
        sf::Texture txt_pausa, txt_continuar,txt_controles, txt_salir;
        sf::Sprite pausa, continuar, salir, controles; 
        sf::Font fuente;

    public:
        Pausa(Run* juego); 
        virtual ~Pausa();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool validacion_continuar();
        bool validacion_salir();
        bool validacion_controles();
};