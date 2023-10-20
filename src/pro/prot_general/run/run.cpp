#include "run.h"
#include "../mapa/mapa.h"
#include "../menu/menu.h"
#include "../motor/motor.h"
#include "../estado/estado.h"
#include "../desarrolladores/desarrolladores.h"
#include "../controles/controles.h"
#include <iostream>
#include <algorithm>

#define RELOJ (1000/20)
#define mov 5
//https://www.sourcecodeexamples.net/2020/09/c-state-pattern-example.html

// Public //
Run::Run() {
    menu= new Menu(this);
    mapa= new Mapa(this);
    controles= new Controles(this);
    desarrolladores= new Desarrolladores(this);
    pausa= new Pausa(this);
    final= new Final(this);
    pierde= new Pierde(this);
    gana= new Gana(this);

    std::string estado= "menu";
    cambiar(estado, 0);
    this->previo = 0;
}

Run::~Run() {
    delete menu;
    delete mapa;
    delete controles;
    delete desarrolladores;
    delete pausa;
    delete final;
    delete pierde;
    delete gana;
}


/// Bucle Juego ////
void Run::runrun() {

    //crearPersonaje();
    //inicio();
    window.setFramerateLimit(60);
    while (Motor::Instance()->ventana().isOpen()) {


        // Update [20 x seg]
        sf::Event evento; //creo evento

        if(reloj_nuevo.getElapsedTime().asMilliseconds() > RELOJ){
            previo=  actual;
            tiempo = reloj_nuevo.restart().asMilliseconds();
            actual->update(evento); //clase Estado actualiza estado
            primera_vez= false; // ya no es la primera vez
        }

        // Si cierro ventana o toco esc   
        while (Motor::Instance()->ventana().pollEvent(evento)){
            
            actual->input(evento); //optiene el input actual
            if (evento.key.code == sf::Keyboard::Escape  || evento.type == sf::Event::Closed){
                Motor::Instance()->cerrar();
            }
             
        }
        float x= reloj_nuevo.getElapsedTime().asMilliseconds();
        float y= x/RELOJ;
        float percent= min(1.f, y);
        Motor::Instance()->clear();
        actual->render(tiempojuego,tiempo,percent,reloj_nuevo, RELOJ); // Bucle
        Motor::Instance()->display();        
    }
}


/*

// Interpolacion...
void render_interpolacion(sf::RenderWindow &window, State &lastState, State, &newState, float percentTick){
    window.clear(sf::Color(255,255,255));
    float personaje= lastState.personaje*(1-percenttick) + newState.personaje*percentTick;
    window.draw();
}
*/

float Run::min(float m1, float m2) {
    float dev= 0;
    if(m1<m2){
        dev= m1;
    }
    if(m2<m1){
        dev= m2;
    }
    return dev;
}
void Run::cambiar(std::string estado, int niv) {

    if(estado=="menu"){
        this->actual = menu;
        est= "menu";
    }
        if(estado=="mapa"){
        this->actual = mapa; 
        est= "mapa";
    }
        if(estado=="controles"){
        this->actual = controles;
        est= "controles";
    }
        if(estado=="desarrolladores"){
        this->actual = desarrolladores;
        est= "desarrolladores";
    }
        if(estado=="gana"){
        this->actual = gana;
        est= "gana";
    }
        if(estado=="pierde"){
        this->actual = pierde;
        est= "pierde";
    }
        if(estado=="pausa"){
        this->actual = pausa;
        est= "pausa";
    }
        if(estado=="final"){
        this->actual = final;
        est= "final";
    }
}


void Run::crearPersonaje() {
    sf::Texture per_tex;

    if (!per_tex.loadFromFile("resources/Sprites/personajes.png")) {
        std::cerr << "Error personajes.png";
        exit(0);
    }
    sf::Sprite per(per_tex);
    per.setOrigin(1280/2, 720/2);
    per.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    int x= 640; int y= 360;
    per.setPosition(x,y);
}

std::string Run::getEstado(){
    return this->est;
}

void Run::setNivel(int niv){
    this->nivel= niv;
}


int Run::getNivel(){
    return this->nivel;
}

void Run::inicio(){
  
}