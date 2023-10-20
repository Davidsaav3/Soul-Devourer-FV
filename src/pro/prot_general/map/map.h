#pragma once
#include "../motor/motor.h"
#include "../estado/estado.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <time.h>
#include <string>
#include <iostream>
#include "../tinyxml/tinyxml.h"
#include "../tinyxml/tinystr.h"

using std::cout;
using std::endl;



class Map{
    private:
        int cont_xd;
        //XmlTextReader* m1_tmx, m1_tsx;
        int ancho;
        int alto;
        int ancho_tile;
        sf::FloatRect boundingbox;
        int alto_tile;
        int num_capas; 
        int aux = 0;
        bool colProyect;
        int colP = 0;
        int *** bloque;     
        bool col= false;
        sf::Sprite ****sprite_bloque;

        std::string gid;
        std::string num;
        TiXmlDocument txt_tmx;
        TiXmlElement *mapa; 
        TiXmlElement *tile;
        TiXmlElement *data; 

        sf::Texture txt_png; 
        sf::Texture textura_bloque; 
        sf::Sprite *sprite; 
        clock_t temp;
        clock_t ant;

        sf::Texture txt_fondo,txt_0,txt_1,txt_2,txt_3,txt_4,txt_5,txt_6;
        sf::Sprite fondo;
        bool agua;
        bool fuego;


    public:

        Map(int nivel,clock_t reloj); 
        ~Map();

        void inicializarMapa();
        void cargarMapa();
        void dibujarMapa(double N,int capa);
        bool colision(sf::Sprite *personaje, int nivel);
        bool colisiongravedad(sf::Sprite *personaje, int nivel);
        bool colisionRectangulo(sf::RectangleShape rectangulo);
        int next(sf::Sprite *personaje, int nivel);
        void setAux(int pos);
        int colisionproyectil();
        int colisionproyectil2();
        bool escalera(sf::Sprite *personaje, int nivel);
        bool rampaDerecha(sf::Sprite *personaje, int nivel);
        bool rampaIzquierda(sf::Sprite *personaje, int nivel);
        int llave(sf::Sprite *personaje, int nivel);
        bool lava(sf::Sprite *personaje, int nivel);
        int getAux();

};