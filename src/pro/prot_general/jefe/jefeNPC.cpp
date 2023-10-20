#include <stdlib.h>
#include "jefeNPC.h"
#include "../motor/motor.h"
#include "../nivel/nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
#define KkVel 5

JefeNPC:: JefeNPC()
{



    if (!textura.loadFromFile("resources/Sprites/espiritu.png")){
        std::cerr << "Error en el sprite del espiritu";
        exit(0);
    }
        //Cada sprite es de 100x100. completar una fila entera -> 7x100

        animacion = sf::IntRect(0*100,0*100,100,100);
        spriteBossNPC.setTexture(textura);

        
        spriteBossNPC.setTextureRect(sf::IntRect(0*100,0*100,100,100));
        spriteBossNPC.setScale(1,1);
        
        spriteBossNPC.setPosition(750,500);

        meVoy=false;

        segundos = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        aviso = false;


}

JefeNPC::JefeNPC(int posX, int posY){


    if (!textura.loadFromFile("resources/Sprites/espiritu.png")){
        std::cerr << "Error en el sprite del espiritu";
        exit(0);
    }
        //Cada sprite es de 100x100. completar una fila entera -> 7x100

        animacion = sf::IntRect(0*100,0*100,100,100);
        spriteBossNPC.setTexture(textura);

        
        spriteBossNPC.setTextureRect(animacion);
        spriteBossNPC.setScale(1,0.7);

        if(Nivel::Instance()->getNivel()==0)
        spriteBossNPC.setPosition(posX,posY);

    segundos = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    aviso = false;
    
}

JefeNPC::~JefeNPC(){}

void JefeNPC::render(sf::Time tiempoJuego, float tiempo, float percent){
    
    //cout << spriteBossNPC;
    

    if(meVoy)
    {
        sprAdios();
        Nivel::Instance()->deleteJefeNpc();
        
    }else{
        sprEstandar();
    }

    if(Nivel::Instance()->getNivel()>0 && Nivel::Instance()->getNivel()!=6){
        spriteBossNPC.setScale(0.3,0.3);
        spriteBossNPC.setPosition(Nivel::Instance()->getPersonaje()->gethitboxpersonaje().getPosition().x-20,Nivel::Instance()->getPersonaje()->gethitboxpersonaje().getPosition().y);

    }

    Motor::Instance()->dibuja(spriteBossNPC);
}

sf::Sprite JefeNPC::getSprite(){
    return spriteBossNPC;
}

void JefeNPC::sprEstandar(){

    
    if(!meVoy){
        //cout << "BossNPC en posición estandar" << endl;


        //if(tiempoAnimacion.getElapsedTime().asSeconds() > 0.1f) 
        //{
           
            if(animacion.left >=700){ 
                animacion.left = 0;
            }else{
                animacion.left +=100;  
            }
            if(animacion.top >= 600){
                animacion.top = 0;
            }else{
                animacion.top +=100;
            }


            spriteBossNPC.setOrigin(animacion.width,0);
            spriteBossNPC.setScale(1,0.7);
            

            spriteBossNPC.setTextureRect(animacion);
            //tiempoAnimacion.restart();



        //}

     /*   clock.getElapsedTime();

        if(animacion.left >=700){ 
            animacion.left = 0;
        }else{
            animacion.left +=100;  
        }
        if(animacion.top >= 600){
            animacion.top = 0;
        }else{
            animacion.top +=100;
        }

        spriteBossNPC.setOrigin(animacion.width,0);
        spriteBossNPC.setScale(1,0.7);
            
        spriteBossNPC.setTextureRect(animacion);
        tiempoAnimacion.restart();
    }
    if(clock.getElapsedTime().asSeconds()>=6) {
        clock.restart();
    */
    }
}

void JefeNPC::sprAdios(){

}

void JefeNPC::setAviso(bool avis){
    if(avis){
        aviso = avis;
    }
}

void JefeNPC::cambioPos(){
    if(aviso){
        
    }
}