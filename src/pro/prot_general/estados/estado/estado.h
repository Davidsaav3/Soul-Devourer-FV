#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
//#include <Sprite.hpp>

class Run;
class Estado{
    private:
        Run* run;
        
    public:
        Estado(Run* juego);
        virtual ~Estado();

        Run* getRun();

        virtual void input(sf::Event &evento) = 0; 
        virtual void update(sf::Event &evento) = 0;
        virtual void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) = 0;
};

