#include "runa.h"
#include "../nivel/nivel.h"
#include "../motor/motor.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using std::cout;
using std::endl;

Runa::Runa(){

        deleted = false;

    /*SPRITE JUGADOR*/
        if(!texVida.loadFromFile("resources/Sprites/runa.png")) {
                std::cout << "Error cargando el sprite";
        }
        _sprite.setTexture(texVida);
        _sprite.setTextureRect(sf::IntRect(0*32, 0*32, 32, 32));
        _sprite.setScale(1.5,1.5);
        _sprite.setPosition(385,40);
}

Runa::Runa(int posx, int posy){

        deleted = false;

    /*SPRITE JUGADOR*/
        if(Nivel::Instance()->getNivel()==1)
        {
                if(!texVida.loadFromFile("resources/Sprites/runa.png")) 
                {
                        std::cout << "Error cargando el sprite";
                }

        }

        if(Nivel::Instance()->getNivel()==2)
        {
                 if(!texVida.loadFromFile("resources/Sprites/runa2.png")) 
                {
                        std::cout << "Error cargando el sprite";
                }
                

        }

        if(Nivel::Instance()->getNivel()==3)
        {
                 if(!texVida.loadFromFile("resources/Sprites/runa3.png")) 
                {
                        std::cout << "Error cargando el sprite";
                }
                

        }

        if(Nivel::Instance()->getNivel()==4)
        {
                 if(!texVida.loadFromFile("resources/Sprites/runa4.png")) 
                {
                        std::cout << "Error cargando el sprite";
                }
                

        }

        if(Nivel::Instance()->getNivel()==5)
        {
                 if(!texVida.loadFromFile("resources/Sprites/runa5.png")) 
                {
                        std::cout << "Error cargando el sprite";
                }
                

        }

        _sprite.setTexture(texVida);
        
        _sprite.setScale(1,1);
        _sprite.setPosition(posx,posy);

        colisionjugador.setSize(sf::Vector2f(30,50));
        colisionjugador.setPosition(getSprite().getPosition().x,getSprite().getPosition().y);
}

Runa::~Runa(){

}

void Runa::update(sf::Time delta, float tiempo){
        
}

void Runa::render() {   

    

/*if(deleted == false || this != NULL) {
        motor2D::Instance()->dibujarPersonaje(this->_sprite);
        colisionPersonaje();
    }
}*/
}
void Runa::colisionPersonaje() {
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->colisionjugador.getGlobalBounds())) {

            
            Nivel::Instance()->borrarRuna();
            //mundo::Instance()->borrarPasti();
        
    }
}

sf::Sprite Runa::getSprite()  {
        return _sprite;
}
void Runa::borrarRuna(){
    deleted = true;
    Nivel::Instance()->borrarRuna();
    
}

void Runa::dibujarRuna(){
    //Motor::Instance()->dibujatrectangulo(this->colisionjugador);
    Motor::Instance()->dibuja(this->_sprite);
}

