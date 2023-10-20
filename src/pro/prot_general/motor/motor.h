#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Motor{
    
    private:
        Motor();
        ~Motor();
        sf::View vista;

    public:
        sf::RenderWindow *window;
        static Motor *motor;

        static Motor* Instance();
        sf::RenderWindow& ventana();

        void display();
        void clear();
        void cerrar();
        void dibujarPersonaje(sf::Sprite &sprite);

        void dibuja(sf::Sprite &tile);
        void dibujatexto(sf::Text &text);
        void dibujatrectangulo(sf::RectangleShape &rect);
        void dibujatcirculo(sf::CircleShape &circ);
        void dibujarVista(sf::View view);
        void dibujar(sf::CircleShape *circle);

        void resetVista(sf::View camPersonaje);
        sf::View& getVista();
  
};