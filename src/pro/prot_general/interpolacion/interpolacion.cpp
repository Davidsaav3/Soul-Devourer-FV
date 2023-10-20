#include "interpolacion.h"
#include "../mapa/mapa.h"
#include "../menu/menu.h"
#include "../motor/motor.h"
#include "../estado/estado.h"
#include "../desarrolladores/desarrolladores.h"
#include "../controles/controles.h"
#include <iostream>
#include <algorithm>

Interpolacion::Interpolacion() {
    ActX= 250;
    ActY= 650;
    PasX= 250;
    PasY= 650;

    ActX_jefe= 750;
    ActY_jefe= 200;
    PasX_jefe= 750;
    PasY_jefe= 200;

    ActX_enemigo1= 750;
    ActY_enemigo1= 200;
    PasX_enemigo1= 750;
    PasY_enemigo1= 200;

    ActX_enemigo2= 750;
    ActY_enemigo2= 200;
    PasX_enemigo2= 750;
    PasY_enemigo2= 200;
}

void Interpolacion::setPos(int niv){
    if(niv==0){    
        ActX= 250;
        ActY= 650;
        PasX= 250;
        PasY= 650;
    }
    if(niv==1){
        //per->setPosition(200,4630);
        ActX= 200;
        ActY= 4630;
        PasX= 200;
        PasY= 4630;
    }
    if(niv==2){
        //per->setPosition(280,4550);
        ActX= 280;
        ActY= 4540;
        PasX= 280;
        PasY= 4540;
    }
    if(niv==3){
        //per->setPosition(460,4635);
        ActX= 460;
        ActY= 4635;
        PasX= 460;
        PasY= 4635;
    }
    if(niv==4){
        //per->setPosition(350,2230);
        ActX= 350;
        ActY= 2220;
        PasX= 350;
        PasY= 2220;
    }
    if(niv==5){
        //per->setPosition(1100,4535);
        ActX= 1100;
        ActY= 4535;
        PasX= 1100;
        PasY= 4535;
    }
    if(niv==6){
        //per->setPosition(200,500);
        ActX= 200;
        ActY= 500;
        PasX= 200;
        PasY= 500;
    }
}

Interpolacion::~Interpolacion() {
}

// GET
double Interpolacion::getActX(){
    return ActX;
}
double Interpolacion::getActY(){
    return ActY;
}
double Interpolacion::getPasX(){
    return PasX;
}
double Interpolacion::getPasY(){
    return PasY;
}

// SET
void Interpolacion::setActX(double x){
    this->PasX= ActX; 
    this->ActX= x; 
}
void Interpolacion::setActY(double y){
    this->PasY= ActY; 
    this->ActY= y;
}


///////////////////////

// GET
double Interpolacion::getActX_jefe(){
    return ActX_jefe;
}
double Interpolacion::getActY_jefe(){
    return ActY_jefe;
}
double Interpolacion::getPasX_jefe(){
    return PasX_jefe;
}
double Interpolacion::getPasY_jefe(){
    return PasY_jefe;
}

// SET
void Interpolacion::setActX_jefe(double x){
    this->PasX_jefe= ActX_jefe; 
    this->ActX_jefe= x; 
}
void Interpolacion::setActY_jefe(double y){
    this->PasY_jefe= ActY_jefe; 
    this->ActY_jefe= y;
}


///////////////////////

// GET
double Interpolacion::getActX_enemigo1(){
    return ActX_enemigo1;
}
double Interpolacion::getActY_enemigo1(){
    return ActY_enemigo1;
}
double Interpolacion::getPasX_enemigo1(){
    return PasX_enemigo1;
}
double Interpolacion::getPasY_enemigo1(){
    return PasY_enemigo1;
}

// SET
void Interpolacion::setActX_enemigo1(double x){
    this->PasX_enemigo1= ActX_enemigo1; 
    this->ActX_enemigo1= x; 
}
void Interpolacion::setActY_enemigo1(double y){
    this->PasY_enemigo1= ActY_enemigo1; 
    this->ActY_enemigo1= y;
}


///////////////////////

// GET
double Interpolacion::getActX_enemigo2(){
    return ActX_enemigo2;
}
double Interpolacion::getActY_enemigo2(){
    return ActY_enemigo2;
}
double Interpolacion::getPasX_enemigo2(){
    return PasX_enemigo2;
}
double Interpolacion::getPasY_enemigo2(){
    return PasY_enemigo2;
}

// SET
void Interpolacion::setActX_enemigo2(double x){
    this->PasX_enemigo2= ActX_enemigo2; 
    this->ActX_enemigo2= x; 
}
void Interpolacion::setActY_enemigo2(double y){
    this->PasY_enemigo2= ActY_enemigo2; 
    this->ActY_enemigo2= y;
}