#pragma once
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../map/map.h"
#include "../../enemigo/enemigo.h"


class Mapa : public Estado{
    private:
 
        Map *N0, *N1, *N2, *N3, *N4, *N5;
        int N;
        std::vector<Enemigo*> enemigos;   

    public:
        Mapa(Run* juego); 
        virtual ~Mapa();

        void input(sf::Event &evento); 
        void update(sf::Event &evento);
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);
        void generaenemigo();

        void siguienteNivel(int nivel);
        Map* getMapa();
        int numNivel();
        int nivel();
};