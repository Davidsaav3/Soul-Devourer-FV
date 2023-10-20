#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "../colisiones/Collision.h"
#include "../proyectil/proyectil.h"
#define PERSONAJE_H

class Personaje {

    
    
    private:
        sf::CircleShape* circulo= NULL;
        float velX;
        float velY;
        sf::Vector2f velocidad;

        sf::Texture * per_tex = NULL;
        sf::Sprite * per = NULL;
        sf::RectangleShape arriba, abajo, izquierda, derecha;
        sf::RectangleShape colisionbalas, colisionsuelo;
        sf::SoundBuffer a1,a2,a3,a4,a5;
        sf::Sound ultisonido,sonidogolpe,sonidogolpefuerte,sonidosalto,sonidohit;
        int cont40;
        bool colS, colA, colW, colD;
        bool abrir;
        bool colisiona;
        bool colisiona2;
        bool animacioataque1;
        bool animacioataque2;
        bool animaciondistancia;
        bool quietoataquecargado;
        bool colisionasuelo;
        int llave;
        int puerta;
        int x,y;
        bool puerta_num;
        bool puerta_num_2;
        int vida;
        int danio;
        bool col;
        bool escalera;
        bool rampaIzquierda;
        bool rampaDerecha;
        int posicionenemigoenarray;
        int posicionenemigoenarray2;
        bool colisionaProyectilMap;
        bool ultiactivada;

        int auxPosProyectil;
        int auxPosProyectil2;
        bool colisionaProyectilEn;
        bool colisionaProyectilEn2;
        bool vuelvoasaltar;
        bool cayendo;
        bool saltocoldown;
        bool ensalto;
        bool volveranmmovrse;
        bool atopeconlaulti;
        bool porsalto;
        bool entroencaida;
        bool unavez;
        int municionguadanyas;
        bool vuelvoataque1;

        int posDireccionProyectil;
        std::vector<Proyectil*> proyectiles;  
        Proyectil *PrE; 

        sf::Clock enfri, enfri2;
        sf::IntRect anime; 
        sf::Clock _Animeclock; 
        sf::Time AnimeTime;
        sf::Time AnimeTime2;
        sf::Clock clock, animationTime,animationTime2,clocksalto,estadoulti,tiempodeulti,tiempocaer,ataquecargadotiempo,ataquedistanciatiempo,enfriataque1;
        sf::Time time;
        sf::Clock relojsalto;

	    //sf::Sound ultisonido;
        //salto
        
        float alturaSalto;

        int frameactual;
        enum animacion {
            iddle,
            ataque1,
            ataque2,
            moverse,
            dash,
            salto,
            ulti,
            caer,
            lanzar,
            subir
        };

        animacion animacionactual;

    public:    
        Personaje(); 
        ~Personaje(); 
        bool compruebaintenemigo(sf::FloatRect laquemepasan);
        void input();
        int getdanio();
        void update(sf::Event &evento);
        void render(sf::Time delta, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);
        void sumavida(int hpmas);
        sf::RectangleShape gethitboxpersonaje();
        sf::FloatRect boundingbox,boundingbox2;
        void posicion(int n);
        bool getPuerta();
        bool devolvervariableulti();
        bool getPuerta2();
        void getposicion();
        bool getPuertecita();
        void setVidaPersonaje(int danio);
        void setPuerta();
        void setPuerta2();
        int getVida();
        void spawn(int niv);
        sf::Sprite getSprite();
        int getPos();
        void iteraranim();
        
        void setVida(int vid);   

        void ataqueRang();
        bool pegaproyectilmapa();
        bool pegaproyectilenemigo();
        bool pegaproyectilenemigo2();
        std::vector<Proyectil*> getProyectiles();
        void destruirProyectil(int pos);
        void quitarproyectildanyar();
        void quitarproyectildanyar2();
        void quitarproyectilpormapa();
        float min(float m1, float m2);
        void updateGravedad();
        void interpolarAlturas();
        void bufarpersonaje();
        void devolverstats();
        int devolvermnunicion();
        void sumarmunicion();
};