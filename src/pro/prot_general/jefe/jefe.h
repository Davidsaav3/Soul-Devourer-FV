#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Jefe {
    private:
        float velX;
        float velY;
        sf::Vector2f vel;
        sf::Sprite spriteBoss;
        sf::Texture textura;
        sf::IntRect animacion;

        int limiteposy, limiteposx;
        int tiempoReaparicion;
        sf::Clock  clock, tiempoAnimacion, tiempoAnimacion2, circulo;
        unsigned int segundos;

        sf::Vector2f origenPos, nuevaPos, heroePos;
        sf::CircleShape escudo, proyect;
        sf::RectangleShape visionIzq, visionDer, visionArr, visionAba; //rango de visión
        sf::RectangleShape peligro; //las áreas de peligro
        bool visIzq, visDer, visArr, visAba; //comprobación de la visión

        sf::SoundBuffer buffer; //reproductor del sonido
        sf::Sound sonAtaque, voz, sonHerida, sonMuerte; //guarda el sonido
        bool activoizq, activoder; //por lo menos lo havisto una vez a la derecha o la izquierda
        int vida, ataque; //los puntos que varían según la acción
        float velocidad; //velocidad del personaje
        bool muerto; //para aplicar el estado Gana
        int fase; //el jefe va por fases, aquí se  indica la fase en la que está
        int tipoAtaque; //el jefe posee varios ataques. Guardamos el actual
    public:
        Jefe();
        Jefe(int posX, int posY);
        ~Jefe();
        void render(sf::Time tiempoJuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);

        sf::Sprite getSprite();
        
        sf::RectangleShape rectanguloIzq();
        sf::RectangleShape rectanguloDer();
        sf::RectangleShape rectanguloArr();
        sf::RectangleShape rectanguloAba();
        sf::RectangleShape hitbox();

        /*----ELEMENTOS SPRITE PARA ANIMACIÓN----*/
        void sprEstandar();
        void sprMoverIzquierda();
        void sprMoverDerecha();
        void sprMoverArriba();
        void sprMoverAbajo();
        void sprAtaca();
        void sprMuere();
        /*---------------------------------------*/
        void getPosHeroe();
        int devolverAtaque();
        void devolverFase();
        void activarEscudo(int i); //escudo activo con temporizador que varía en frecuencia según el valor pasado por parámetro 
        void ataqueJefe();
        void ataque1();
        void ataque2();
        void ataque3();
        void heridaJefe(int herida); //hieren al jefe, se aplica a la vida
        bool estaMuerto(); //para que se pueda aplicar en Estado
        void visto(); //comprueba si el jefe ha visto en el campo de visión al heroe
};
