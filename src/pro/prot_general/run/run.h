#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../estado/estado.h"
#include "../menu/menu.h"
#include "../mapa/mapa.h"
#include "../controles/controles.h"
#include "../desarrolladores/desarrolladores.h"
#include "../final/final.h"
#include "../pausa/pausa.h"
#include "../pierde/pierde.h"
#include "../gana/gana.h"

class Run{
    private:
        Menu *menu;
        Mapa *mapa;
        Controles *controles;
        Desarrolladores *desarrolladores;
        Pausa *pausa;
        Final *final;
        Pierde *pierde;
        Gana *gana;

        sf::RenderWindow window;
        sf::Clock reloj;
        sf::Clock reloj_nuevo;

        Estado* actual;
        Estado* previo;
        std::string est;
        float tiempo;
        sf::Time tiempojuego;
        bool primera_vez;
        int nivel;

    public:
        Run();
        virtual ~Run();

        void runrun();
        void cambiar(std::string estado, int nivel);
        std::string getEstado();
        void crearPersonaje();
        int getNivel();
        void setNivel(int niv);
        void inicio();
        static float min(float m1, float m2);

};
