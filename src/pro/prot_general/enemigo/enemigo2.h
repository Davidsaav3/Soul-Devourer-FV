#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "colision.h"
#include "../proyectil/proyectil.h"

class Enemigo2 {
    float velX;
    float velY;
    sf::Vector2f velocidad;

    sf::Sprite _sprite;
    sf::Sprite _sprite2;
    
    int vida;
    int danyo;
    sf::IntRect anime; 
    bool seguiratacandoizq;
    bool seguiratacandoder;
    bool visto;

    sf::Texture _texture;
    sf::Texture _texture2;
    int _timeRespawn;

    sf::Vector2i _newposition; // Declaramos el source ( SPrite sheet Crop)
    enum _Direction { Abajo, Izq, Der, Arriba}; 

    sf::Vector2f base;
    std::vector<Proyectil*> proyectiles;
    sf::RectangleShape colisionbalas;
    bool atDis ,colisionaProyectilPer;
    int posDireccionProyectil;
    int auxPosProyectil, auxPosEnemigo = 0;
    Proyectil *PrE;
    int posicionarrayenemigo;

    sf::SoundBuffer b1;

	sf::Sound alma;



    sf::Vector2f _newposition2;

    sf::Clock clock, animationTime,animationTime2;
    unsigned int seconds;
    unsigned int seconds2;
    sf::Clock enfri;

    sf::Time time;

    
    
    sf::RectangleShape  colisionIzq, colisionDer;
    sf::RectangleShape hitboxizq, hitboxder;
     bool colder, colizq;
     bool chocader, chocaizq;
    sf::SoundBuffer buffer;
    sf::Sound sonidoataque;
    bool muerto;
     bool muertoanimacion;

     bool proyectilcreado;

     bool animacionmuertejaja;
    

    float vel;


    sf::Clock animemuerte2;
    sf::Clock _Animeclock; // Enemigo reloj animacion
    sf::Time AnimeTime;// enemigo tiempo animacion
    sf::Time AnimeTime2;// enemigo tiempo animacion



    
    
    

public:
    
    Enemigo2();
    Enemigo2(int posix, int posiy);
    Enemigo2(int posix, int posiy,int hp, int dmg);
    ~Enemigo2();
    std::vector<Proyectil*>getProyectiles();
    void update();
    void moverse();
    void calculaposicion();
    void calcularposicionjugador();
    sf::FloatRect boundingboxe;
    void andarDer();
    void andarIzq();
    void destruirjugador();
    void compruebahitbox();
    int restavida(int posicion , int danio);

    int getVida();
    void render(sf::Time delta, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ);
    
    void animacionmuerte();

    void muevederecha();
    void mueveizquierda();

    int getDireccionProyectil();
    void destruirProyectil(int pos);
    bool pegaproyectilpersonaje();
    void quitarproyectildanyar();

    void mirar();
    bool getmuerto();

    void ataqueRango();
    
    void comprobarPersonaje();
    sf::RectangleShape gethitboxenemigo();
    bool buscarpresa(sf::Sprite);
    void posicion();
    sf::Sprite getSprite() const;
    //void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    //respawn?
    //sf::FloatRect getBounds() const override;
    sf::RectangleShape returnrectangle();
    sf::RectangleShape returnrectangle2();


};
