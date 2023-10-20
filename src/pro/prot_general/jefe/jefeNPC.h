#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class JefeNPC {
    private:
        sf::Sprite spriteBossNPC;
        sf::Texture textura;
        sf::IntRect animacion;

        sf::Clock clock, tiempoAnimacion;
        unsigned int segundos;

        bool meVoy; //cuando el sprite lo vayamos a quitar, activando la animación de desaparición
        bool aviso; //para moverse detrás del personaje
    public:
        JefeNPC();
        JefeNPC(int posX, int posY);
        ~JefeNPC();
        void render(sf::Time tiempoJuego, float tiempo, float percent);
        /*----ELEMENTOS SPRITE PARA ANIMACIÓN----*/
        void sprEstandar();
        void sprAdios();
        /*---------------------------------------*/
        void setAviso(bool avis); //recibe aviso de que la conversación incial acaba
        void cambioPos(); //el npc se coloca detrás del personaje
        sf::Sprite getSprite();
};