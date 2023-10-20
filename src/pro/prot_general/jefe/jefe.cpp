#include <stdlib.h>
#include "jefe.h"
#include "../motor/motor.h"
#include "../nivel/nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
#define KkVel 5

Jefe:: Jefe(){}
Jefe::Jefe(int posX, int posY){
    limiteposx = 0;
    limiteposy = 0;
    activoizq = false;
    activoder = false;
    vida=30;
    ataque=2;
    fase=1;
    tipoAtaque=0;
    muerto=false;
    heroePos.x = -1;
    heroePos.y = -1;

    segundos = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());

    if (!textura.loadFromFile("resources/jefe/jefe.png")){
        std::cerr << "Error en el sprite del jefe";
        exit(0);
    }else{
        //Cada sprite es de 100x100. completar una fila entera -> 7x100
        animacion = sf::IntRect(0,0,100,100);
        spriteBoss.setTexture(textura);
        spriteBoss.setTextureRect(sf::IntRect(0, 0, 100, 100));
        spriteBoss.setScale(3,2.5);
        spriteBoss.setPosition(posX,posY);
    }

    origenPos.x = spriteBoss.getPosition().x;
    origenPos.y = spriteBoss.getPosition().y;

    nuevaPos.x = spriteBoss.getPosition().x-200;
    nuevaPos.y = spriteBoss.getPosition().y;

    //PROYECTIL
    proyect.setPosition(spriteBoss.getPosition().x, spriteBoss.getPosition().y);

    proyect.setRadius(20);
    proyect.setFillColor(sf::Color::Cyan);

    //CAMPO DE VISIÓN
    visionIzq.setPosition(spriteBoss.getPosition().x-500, spriteBoss.getPosition().y+80);
    visionDer.setPosition(spriteBoss.getPosition().x+200, spriteBoss.getPosition().y+80);
    visionArr.setPosition(spriteBoss.getPosition().x-150, spriteBoss.getPosition().y-30);
    visionAba.setPosition(spriteBoss.getPosition().x-350, spriteBoss.getPosition().y+190);

    visionIzq.setSize(sf::Vector2f(600,100));
    visionDer.setSize(sf::Vector2f(600,100));
    visionArr.setSize(sf::Vector2f(600,100));
    visionAba.setSize(sf::Vector2f(1000,400));

    //color
    visionIzq.setFillColor(sf::Color::Blue);
    visionDer.setFillColor(sf::Color::Blue);
    visionArr.setFillColor(sf::Color::Blue);
    visionAba.setFillColor(sf::Color::Blue);


    //COLISIONES DE ZONA DE PELIGRO (donde el ataque danya al personaje)
    peligro.setPosition(spriteBoss.getPosition().x+100, spriteBoss.getPosition().y+80);

    peligro.setSize(sf::Vector2f(100,80));

    //color
    peligro.setFillColor(sf::Color::Green);

    velocidad = 0.50f;

    visAba=false;
    visArr=false;
    visDer=false;
    visIzq=false;
}

Jefe::~Jefe(){}

void Jefe::render(sf::Time tiempoJuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ){
    float x= reloj_nuevo.getElapsedTime().asMilliseconds();
    float y= x/RELOJ;
    //std::cout << x << " :reloj_nuevo:" << endl;
    //std::cout << RELOJ << " :RELOJ:" << endl;
    std::cout << y << " :min:" << endl;
    float porcentaje= min(1.f, y);
    std::cout << porcentaje << " :porcentaje:" << endl;

    vel.x= Nivel::Instance()->getInterpolacion()->getPasX_jefe()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActX_jefe()*porcentaje;

    vel.y= Nivel::Instance()->getInterpolacion()->getPasY_jefe()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActY_jefe()*porcentaje;

    std::cout << Nivel::Instance()->getInterpolacion()->getActX_jefe() << " :x1:" << endl;
    std::cout << Nivel::Instance()->getInterpolacion()->getActY_jefe() << " :y1:" << endl;

    std::cout << velX << " :x2:" << endl;
    std::cout << velY << " :y2:" << endl;

    vel.x= vel.x+velX;
    vel.y= vel.y+velY;

    Nivel::Instance()->getInterpolacion()->setActX_jefe(vel.x);
    Nivel::Instance()->getInterpolacion()->setActY_jefe(vel.y);
    
    if(estaMuerto()==false){
        Motor::Instance()->dibuja(spriteBoss);
    }
    //spriteBoss.setPosition(vel);

    //CAMPO DE VISIÓN
    visionIzq.setPosition(spriteBoss.getPosition().x-820, spriteBoss.getPosition().y+80);
    visionDer.setPosition(spriteBoss.getPosition().x-80, spriteBoss.getPosition().y+80);
    visionArr.setPosition(spriteBoss.getPosition().x-430, spriteBoss.getPosition().y-30);
    visionAba.setPosition(spriteBoss.getPosition().x-630, spriteBoss.getPosition().y+190);

    visionIzq.setSize(sf::Vector2f(600,100));
    visionDer.setSize(sf::Vector2f(600,100));
    visionArr.setSize(sf::Vector2f(600,100));
    visionAba.setSize(sf::Vector2f(1000,400));

    //COLISIONES DE ZONA DE PELIGRO
    peligro.setPosition(spriteBoss.getPosition().x-240, spriteBoss.getPosition().y+20);

    peligro.setSize(sf::Vector2f(190,170));
/*    
    Motor::Instance()->dibujatrectangulo(peligro);
    Motor::Instance()->dibujatrectangulo(visionDer);
    Motor::Instance()->dibujatrectangulo(visionIzq);
    Motor::Instance()->dibujatrectangulo(visionArr);
    Motor::Instance()->dibujatrectangulo(visionAba);
*/
    if(muerto){
        sprMuere();
        //Nivel::Instance()->deleteJefe();
    }else{
        if(!visIzq && !visDer && !visArr && !visAba){
            sprEstandar();
        }
        visto();
        sprMoverIzquierda();
        sprMoverDerecha();
        sprMoverAbajo();
        sprMoverArriba();
        sprMuere();
        cout << "vide del jefe: " << vida << endl;
    }
}
sf::RectangleShape Jefe::rectanguloIzq(){
    return visionIzq;
}
sf::RectangleShape Jefe::rectanguloDer(){
    return visionDer;
}
sf::RectangleShape Jefe::rectanguloArr(){
    return visionArr;
}
sf::RectangleShape Jefe::rectanguloAba(){
    return visionAba;
}

sf::Sprite Jefe::getSprite(){
    return spriteBoss;
}


int Jefe::devolverAtaque(){
    return ataque;
}

void Jefe::devolverFase(){
    if(vida<=30 && vida>20){
        fase=1;
    }else{
        if(vida<=20 && vida>10){
            fase=2;
        }else{
            fase=3;
        }
    }
}

void Jefe::ataqueJefe(){
    devolverFase();
    if(!muerto){
        if(fase==1){
            ataque=1;

        }else{
            if(fase==2){
                ataque=1;

            }else{
                ataque=2;
            }
        }
    }
}

sf::RectangleShape Jefe::hitbox(){
    return peligro;
}

void Jefe::heridaJefe(int herida){
    if(Nivel::Instance()->getPersonaje()->gethitboxpersonaje().getGlobalBounds().intersects(this->peligro.getGlobalBounds())){
        if(vida>0){
            vida -= herida;
            if(vida<0){
                vida=0;
                muerto=true;
            }
            devolverFase();
        }else{
            muerto=true;
        }
    }
}

bool Jefe::estaMuerto(){
    if(vida==0){
        muerto=true;
    }
    return muerto;
}

void Jefe::visto(){
    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->visionArr.getGlobalBounds())){
        visArr=true;
        visAba=false;
    }else{
        visArr=false;
    }
    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->visionAba.getGlobalBounds())){
        visAba=true;
        visArr=false;
    }else{
        visAba=false;
    }
    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->visionIzq.getGlobalBounds())){
        visIzq=true;
        visDer=false;
    }else{
        visIzq=false;
    }
    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->visionDer.getGlobalBounds())){
        visDer=true;
        visIzq=false;
    }else{
        visDer=false;
    }
    //cuando estando abajo intersecta con derecha también...
    if(visAba && visDer){
        visAba = false;
    }
    //cuando estando abajo intersecta con izquierda también...
    if(visAba && visIzq){
        visAba = false;
    }
    //cuando estando arriba intersecta con derecha también...
    if(visArr && visDer){
        visArr = false;
    }
    //cuando estando arriba intersecta con izquierda también...
    if(visArr && visIzq){
        visArr = false;
    }
    if(visIzq || visDer || visArr || visAba){
        ataqueJefe();
    }
}

void Jefe::activarEscudo(int i){

}

void Jefe::ataque1(){
    if(fase==1){
        proyect.setFillColor(sf::Color::Cyan);
        if(limiteposx ==0 || limiteposy ==0){
            limiteposx =100;
            limiteposy =300;
        }
            proyect.setPosition(limiteposx, limiteposy);
            Motor::Instance()->dibujatcirculo(proyect);
            if(heroePos.x != -1 && heroePos.y != -1 && tiempoAnimacion2.getElapsedTime().asSeconds()>0.1f){
                circulo.getElapsedTime();

                if(proyect.getRadius() <= 40){
                    proyect.setRadius(proyect.getRadius()+5);
                }else{
                    proyect.setRadius(20);
                }

                tiempoAnimacion2.restart();
                if(circulo.getElapsedTime().asSeconds()>=0.8) {
                    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->proyect.getGlobalBounds())){
                        devolverFase();
                        Nivel::Instance()->getPersonaje()->setVidaPersonaje(ataque);
                    }
                    circulo.restart();
                    limiteposx= 100 + rand()%1000;
                    limiteposy=400 + rand()%100;
                } 
            }
    }
}
void Jefe::ataque2(){
    if(fase==2){
        proyect.setFillColor(sf::Color::Yellow);
        if(limiteposx ==0 || limiteposy ==0){
            limiteposx =100;
            limiteposy =300;
        }
            proyect.setPosition(limiteposx, limiteposy);
            Motor::Instance()->dibujatcirculo(proyect);
            if(heroePos.x != -1 && heroePos.y != -1 && tiempoAnimacion2.getElapsedTime().asSeconds()>0.1f){
                circulo.getElapsedTime();

                if(proyect.getRadius() <= 50){
                    proyect.setRadius(proyect.getRadius()+5);
                }else{
                    proyect.setRadius(20);
                }

                tiempoAnimacion2.restart();
                if(circulo.getElapsedTime().asSeconds()>=0.5) {
                    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->proyect.getGlobalBounds())){
                        devolverFase();
                        Nivel::Instance()->getPersonaje()->setVidaPersonaje(ataque);
                    }
                    circulo.restart();
                    limiteposx= 100 + rand()%1000;
                    limiteposy=400 + rand()%100;
                } 
            }
        
    }
}
void Jefe::ataque3(){
    if(fase==3){
        proyect.setFillColor(sf::Color::Red);
        if(limiteposx ==0 || limiteposy ==0){
            limiteposx =100;
            limiteposy =300;
        }

            proyect.setPosition(limiteposx, limiteposy);
            Motor::Instance()->dibujatcirculo(proyect);
            if(heroePos.x != -1 && heroePos.y != -1 && tiempoAnimacion2.getElapsedTime().asSeconds()>0.1f){
                circulo.getElapsedTime();

                if(proyect.getRadius() <= 60){
                    proyect.setRadius(proyect.getRadius()+5);
                }else{
                    proyect.setRadius(20);
                }

                tiempoAnimacion2.restart();
                if(circulo.getElapsedTime().asSeconds()>=0.3) {
                    if(Nivel::Instance()->getPersonaje()->getSprite().getGlobalBounds().intersects(this->proyect.getGlobalBounds())){
                        devolverFase();
                        Nivel::Instance()->getPersonaje()->setVidaPersonaje(ataque);
                    }
                    circulo.restart();
                    limiteposx= 100 + rand()%1000;
                    limiteposy=400 + rand()%100;
                } 
            }
        
    }
}

/*--------------- SPRITES SEGÚN EL MOVIMIENTO ------------------*/

void Jefe::sprEstandar(){
    ataqueJefe();
    ataque1();
    ataque2();
    ataque3();
    if(!Nivel::Instance()->getPersonaje()->boundingbox.intersects(peligro.getGlobalBounds())){
        cout << "Boss en posición estandar" << endl;

        clock.getElapsedTime();

        if(animacion.left >=700){ 
            animacion.left = 0;
            animacion.top = 0;
        }else{
            animacion.left +=100;
            animacion.top = 0;
        }

        spriteBoss.setOrigin(animacion.width,0);
        spriteBoss.setScale(3,2.5);
            
        spriteBoss.setTextureRect(animacion);
        tiempoAnimacion.restart();
    }
    if(clock.getElapsedTime().asSeconds()>=6) {
        clock.restart();
    }
}

void Jefe::sprMoverIzquierda(){
    cout << "fase: " << fase <<endl;
    if(visIzq){
        activoizq=true;
        velY= 0.0f;
        velX= -velocidad;
        getPosHeroe();
        if((spriteBoss.getPosition().x - heroePos.x) > 400){
            spriteBoss.move(velX,velY);
        }
        ataqueJefe();
        ataque1();
        ataque2();
        ataque3();
        std::cout << spriteBoss.getPosition().x << endl;
        if(Nivel::Instance()->getMapa()->colisionRectangulo(peligro) == false && tiempoAnimacion.getElapsedTime().asSeconds()>0.2f){
            cout << "Boss en posición izquierda" << endl;

            clock.getElapsedTime();

            if(animacion.left >=700){ 
                animacion.left = 0;
                animacion.top = 1;
            }else{
                animacion.left +=100;
                animacion.top = 1;
            }

            spriteBoss.setOrigin(animacion.width,0);
            spriteBoss.setScale(3,2.5);
                
            spriteBoss.setTextureRect(animacion);
            tiempoAnimacion.restart();
        }
        if(clock.getElapsedTime().asSeconds()>=6) {
            clock.restart();
        }   
    }
}
void Jefe::sprMoverDerecha(){
    if(visDer){
        activoder=true;
        velY= 0.0f;
        velX= velocidad;
        getPosHeroe();
        if((heroePos.x - spriteBoss.getPosition().x) > 100){
            //spriteBoss.setColor(sf::Color::Blue);
            spriteBoss.move(velX,velY);
        }
        ataqueJefe();
        ataque1();
        ataque2();
        ataque3();
        if(Nivel::Instance()->getMapa()->colisionRectangulo(peligro) == false && tiempoAnimacion.getElapsedTime().asSeconds()>0.2f){
            cout << "Boss en posición derecha" << endl;

            clock.getElapsedTime();

            if(animacion.left >=700){ 
                animacion.left = 0;
                animacion.top = 2;
            }else{
                animacion.left +=100;
                animacion.top = 2;
            }

            spriteBoss.setOrigin(animacion.width,0);
            spriteBoss.setScale(3,2.5);
                
            spriteBoss.setTextureRect(animacion);
            tiempoAnimacion.restart();
        }
        if(clock.getElapsedTime().asSeconds()>=6) {
            clock.restart();
        }
    }

}
void Jefe::sprMoverArriba(){
    if(visArr){
        velX= 0.0f;
        velY= -velocidad;
        spriteBoss.move(velX,velY);
        ataqueJefe();
        ataque1();
        ataque2();
        ataque3();
        if(Nivel::Instance()->getMapa()->colisionRectangulo(peligro) == false && tiempoAnimacion.getElapsedTime().asSeconds()>0.2f){
            cout << "Boss en posición arriba" << endl;

            clock.getElapsedTime();

            if(animacion.left >=700){ 
                animacion.left = 0;
                animacion.top = 3;
            }else{
                animacion.left +=100;
                animacion.top = 3;
            }

            spriteBoss.setOrigin(animacion.width,0);
            spriteBoss.setScale(3,2.5);
                
            spriteBoss.setTextureRect(animacion);
            tiempoAnimacion.restart();
        }
        if(clock.getElapsedTime().asSeconds()>=6) {
            clock.restart();
        }
    }
}
void Jefe::sprMoverAbajo(){
    if(visAba){
        velX= 0.0f;
        velY= velocidad;
        spriteBoss.move(velX,velY);
        if(activoder || activoizq){
            ataqueJefe();
            ataque1();
            ataque2();
            ataque3();
        }
        if(Nivel::Instance()->getMapa()->colisionRectangulo(peligro) == false && tiempoAnimacion.getElapsedTime().asSeconds()>0.2f){
            cout << "Boss en posición abajo" << endl;
        
            clock.getElapsedTime();

            if(animacion.left >=700){ 
                animacion.left = 0;
                animacion.top = 4;
            }else{
                animacion.left +=100;
                animacion.top = 4;
            }

            spriteBoss.setOrigin(animacion.width,0);
            spriteBoss.setScale(3,2.5);
                
            spriteBoss.setTextureRect(animacion);
            tiempoAnimacion.restart();
        }
        if(clock.getElapsedTime().asSeconds()>=6) {
            clock.restart();
        }
    }
}
void Jefe::sprAtaca(){

}
void Jefe::sprMuere(){
    if(muerto || vida<=0){
        cout << "Boss en posición muerte" << endl;

        clock.getElapsedTime();

        if(animacion.left >=700){ 
            animacion.left = 0;
            animacion.top = 5;
        }else{
            animacion.left +=100;
            animacion.top = 5;
        }

        spriteBoss.setOrigin(animacion.width,0);
        spriteBoss.setScale(3,2.5);
            
        spriteBoss.setTextureRect(animacion);
        tiempoAnimacion.restart();
    }
    if(clock.getElapsedTime().asSeconds()>=6) {
        clock.restart();
    }
}

void Jefe::getPosHeroe(){
    heroePos = Nivel::Instance()->getPersonaje()->getSprite().getPosition();
}