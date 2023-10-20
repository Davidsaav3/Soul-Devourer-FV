#include "motor.h"
#include <SFML/Graphics.hpp>

Motor::Motor() {
    std::cout << " [motor] "; 
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Soul Devourer");

    vista.reset(sf::FloatRect(640,360,1280,720));

}

Motor::~Motor() {
    delete window;
    delete motor;
}

////////////////////////
Motor* Motor::motor = 0;

Motor* Motor::Instance(){
    if(motor == 0) {
        motor = new Motor;
    }
    return motor;
}

///////////////////////////////////
sf::RenderWindow& Motor::ventana() {
    return *window;
}

void Motor::display(){
    window->display();
}

void Motor::clear(){
    window->clear();
}

void Motor::cerrar(){
    window->close();
}

// Dibujar ///////////////////////////////
void Motor::dibuja(sf::Sprite &tile){
    window->draw(tile);
}

void Motor::dibujatrectangulo(sf::RectangleShape &tile){
    window->draw(tile);
}

void Motor::dibujatcirculo(sf::CircleShape &tile){
    window->draw(tile);
}

void Motor::dibujarVista(sf::View view){
    window->setView(view);
}

void Motor::dibujar(sf::CircleShape *circle){
    //std::cout << " [impresion] "; 
    window->draw(*circle);
}

void Motor::dibujatexto(sf::Text &text){
    window->draw(text);
}

void Motor::resetVista(sf::View camPersonaje){
    vista.reset(sf::FloatRect(650,900,1280,720));
}

sf::View& Motor::getVista(){
    return vista;
}

