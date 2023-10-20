#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
#include <iostream>



class Proyectil{

    private:
        float speed;
        float x,y;
        float velX,velY;

        sf::Sprite _sprite;
        sf::Texture _proyectexture;
        sf::Time time;
        sf::RectangleShape colisArriba, colisAbajo, colisIzq, colisDer;
        sf::IntRect anime; 

        sf::Clock clock, animationTime;
        

        float xP,yP;

        int direccion;

        int tipodeproyect;

        bool colArriba, colAbajo, colIzq, colDer;

        int col,col2;

        int textura;
    
    public:

        Proyectil( float x1,float y1);
        Proyectil(float x1,float y1, int i);
        virtual ~Proyectil();

        void update(sf::Time tiempojuego, int _xX, int _yY);

        sf::RectangleShape gethitboxproyectil();
        void draw();
        
        void colision();
        bool getHay();
        void dirProyectil(int pos);
        sf::Sprite proyectilSprite();
        float getspeed();
        int colisionMapaProyectil(int posDireccionBala);
        

       
};


#endif 