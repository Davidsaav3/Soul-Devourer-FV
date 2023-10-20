#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "../map/map.h"
#include "../interpolacion/interpolacion.h"
#include "../personaje/personaje.h"
#include "../enemigo/enemigo.h"
#include "../enemigo/enemigo2.h"
#include "../jefe/jefe.h"
#include "../jefe/jefeNPC.h"
#include "../runa/runa.h"
#include <SFML/Audio.hpp>
#define NIVEL_H

class Nivel {
    
    private:
        sf::SoundBuffer buffer;
        sf::SoundBuffer b1;
        sf::SoundBuffer b2;
        sf::SoundBuffer b3;
        sf::SoundBuffer b4;
        sf::SoundBuffer b5;

	    sf::Sound musica_n0;
        sf::Sound musica_n1;
        sf::Sound musica_n2;
        sf::Sound musica_n3;
        sf::Sound musica_n4;
        sf::Sound musica_final;
        Interpolacion *interpolacion;
        Map *N, *N0, *N1, *N2, *N3, *N6, *N4, *N5;
        double nivel;
        Jefe* jefe;
        JefeNPC* jefeNpc;
        std::vector<Enemigo*> enemigos;   
        std::vector<Enemigo2*> enemigos2;
        sf::IntRect anime; 
        sf::IntRect anime2; 
        Runa* runafisica;
        static Nivel* niv;
        Personaje* per;
        bool ok;
        int est;
        bool final;
        sf::Sound s1;
        bool x;
        int totalenemigos;
        sf::Clock animationtime;
        sf::Clock animationtime2;
        sf::Clock animationtime3;

        sf::Text enemigosrestantes;
        sf::Font fuente;

        bool runapillada;
        bool enemigosdestruidos;
        bool enemigosdestruidos2;
        int contadoralmas;
        sf::Texture txt_fondo,txt_0,txt_1,txt_2,txt_3,txt_4,txt_5,txt_6,txt_cora_i, txt_cora_d,txt_puerta,txt_ulti0,txt_ulti1,txt_ulti2,txt_ulti3,txt_ulti4,txt_ulti5,txt_ulti6,txt_ulti7,txt_ulti8,txt_ulti9,txt_ulticargada,txt_enulti,txt_ojos2,txt_efecto,txt_ojos,txt_guadanya0,txt_guadanya1,txt_guadanya2,txt_guadanya3,txt_guadanya4,txt_guadanya5;
        sf::Sprite fondo, cora_1, cora_2,cora_3,cora_4,cora_5, cora_6, cora_7,cora_8,cora_9,cora_10, puerta,ulti0,ulti1,ulti2,ulti3,ulti4,ulti5,ulti6,ulti7,ulti8,ulti9,ulticargada,enulti,efecto,ojos,ojos2,guadanya0,guadanya1,guadanya2,guadanya3,guadanya4,guadanya5;

        sf::Time auxi;
        //salto y colisiones
        sf::RectangleShape body;
        clock_t reloj;

    public:    
        static Nivel* Instance();
        Nivel(); 
        ~Nivel(); 

        void inicializar();
        void input(sf::Event &evento); 
        void update(sf::Event &evento);
        void render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);
        Personaje* getPersonaje();
        void creaEnemigos();
        void destruyenemigostemporal();
        void destruirenemigo(int pos, int tipo);
        void cojerRuna();
        void borrarRuna();
        void destruirruantemporal();
        void deleteJefe();
        void deleteJefeNpc();
        

        void checkhitboxBOSS();
        void gastaralmas();
        void checkhitboxes();
        void checkhitboxestiradores();

        std::vector<Enemigo2*> getEnemigos2();
        std::vector<Enemigo*> getEnemigos();
//cosas salto y colisiones
        sf::Vector2f size;
        sf::Vector2f position;
        Collision GetCollision(){return Collision(body);}

        Map* getMapa();
        Interpolacion* getInterpolacion();
        int getNivel();
        int getEstado();
        void sumaunamuerte();
        int returnalmastotal();
        void setEstado(int n);
        bool getFinal();
        void setFinal();
        void crearunas();
        int getNum();
        bool getRunapillada();
        void reAparece();
        Jefe* getJefe();
        JefeNPC* getJefeNPC();


};