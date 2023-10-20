#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include <SFML/Audio.hpp>

class Menu : public Estado{
    private:
        sf::Texture txt_menu, txt_comenzar, txt_controles, txt_desarrolladores, txt_soul;
        sf::Sprite spr_menu, spr_comenzar, spr_controles, spr_soul, spr_desarrolladores;
        int num, n;	
        sf::SoundBuffer buffer;
	    sf::Sound s2;
        sf::Sound s1;

    public:
        Menu(Run* juego); 
        virtual ~Menu();

        void input(sf::Event &evento); 
        void update(sf::Event &evento); 
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        bool comenzar();
        bool desarrolladores();
        bool controles();
};