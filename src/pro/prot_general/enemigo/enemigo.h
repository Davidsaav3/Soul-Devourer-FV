#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "colision.h"

class Enemigo {
    float velX;
    float velY;
    sf::Vector2f velocidad;

    sf::Sprite _sprite;
    int vida;
    int danyo;
    sf::IntRect anime; 
    bool seguiratacandoizq;
    bool seguiratacandoder;
    bool visto;
    int posicionarrayenemigo;
    sf::RectangleShape colisionbalas;
    bool comienzanimacion;
    bool pego;

    sf::SoundBuffer b1;

	sf::Sound alma;


    sf::Texture _texture;
    int _timeRespawn;

    sf::Vector2i _newposition; // Declaramos el source ( SPrite sheet Crop)
    enum _Direction { Abajo, Izq, Der, Arriba}; 

    sf::Vector2f base;

    sf::Vector2f _newposition2;
    //sf::Color rojo();

    sf::Clock clock, animationTime,animationTime2;
    unsigned int seconds;
    unsigned int seconds2;

    bool muertoanimacion;
    
    sf::RectangleShape  colisionIzq, colisionDer;
    sf::RectangleShape hitboxizq, hitboxder;
     bool colder, colizq;
     bool chocader, chocaizq;
    sf::SoundBuffer buffer;
    sf::Sound sonidoataque;
    bool muerto;

    float vel;
    bool reinicioreloj;



    sf::Clock animemuerte;
    sf::Clock _Animeclock; // Enemigo reloj animacion
    sf::Time AnimeTime;// enemigo tiempo animacion
    sf::Time AnimeTime2;// enemigo tiempo animacion



    
    
    

public:
    
    Enemigo();
    Enemigo(int posix, int posiy);
    Enemigo(int posix, int posiy, int hp, int dmg);
    ~Enemigo();
    void update();
    void moverse();
    bool getmuerto();
    void calculaposicion();
    void calcularposicionjugador();
    void andarDer();
    void andarIzq();
    void destruirjugador();
    void compruebahitbox();
    int restavida(int posicion , int danio);
    sf::FloatRect boundingboxe;
    sf::RectangleShape gethitboxenemigo();

    int getVida();
    void render(sf::Clock reloj_nuevo, float RELOJ);

    void animacionmuerte();
    void muevederecha();
    void mueveizquierda();

    void mirar();
    
    void comprobarPersonaje();
    bool buscarpresa(sf::Sprite);
    void matarenemigo();
    void posicion();
    void aux();
    sf::Sprite getsprite();
    //void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    //respawn?
    //sf::FloatRect getBounds() const override;
    sf::RectangleShape returnrectangle();
    sf::RectangleShape returnrectangle2();


};
