#include "proyectil.h"
#include  "../nivel/nivel.h"
#include "../motor/motor.h"



Proyectil::Proyectil(float x1,float y1)
{
    if(!_proyectexture.loadFromFile("resources/Sprites/proyectil.png"))
    {
                std::cout << "Error cargando el sprite";
    }

    _sprite.setTexture(_proyectexture);
    _sprite.setScale(1,1);

    x=x1;
    y=y1;

    speed = 9.0f;


    velX = 0; 
    velY = 0;

    tipodeproyect=1;

    _sprite.setPosition(x, y+100);
    direccion=0;

    


    colisIzq.setSize(sf::Vector2f(5.f, 20.f));
    colisDer.setSize(sf::Vector2f(5.f, 20.f));




}

Proyectil::Proyectil(float x1,float y1, int i)
{
    if(!_proyectexture.loadFromFile("resources/Sprites/hoces.png"))
    {
                std::cout << "Error cargando el sprite";
    }

    anime= sf::IntRect(0*48,0*64,48,64);

    _sprite.setTexture(_proyectexture);
    _sprite.setTextureRect(sf::IntRect(0*48, 0*64, 48, 64));
    _sprite.setScale(1.5,1.5);

    x=x1;
    y=y1;

    speed = 15.0f;

    tipodeproyect=2;

    velX = 0; 
    velY = 0;

    _sprite.setPosition(x, y+50);


    colisIzq.setSize(sf::Vector2f(5.f, 35.f));
    colisDer.setSize(sf::Vector2f(5.f, 35.f));




}


Proyectil::~Proyectil(){

}

void Proyectil::update(sf::Time tiempojuego, int _x1, int _y1)
{   

    if(tipodeproyect==2){
        
        if(animationTime.getElapsedTime().asSeconds()>0.03f)
        {
            
            if(anime.left >=624)
            {
                
                anime.left = 0;
                
                anime.top = 0;
                

            }else{
                
                anime.left +=48;
                anime.top = 0;
                

            }

            
            //_sprite.setOrigin(anime.width-10,0);
            //_sprite.setScale( -2.5, 2.5 );


            _sprite.setTextureRect(anime);
            animationTime.restart();
        

        }

    }
    else{

    }



    

    x = _x1;
    y = _y1;

    time = tiempojuego;

    if(direccion ==1)
    {
        _sprite.move(speed,0);

    }else if(direccion ==2)
    {
        if(tipodeproyect==2)
        {
        _sprite.setScale( -1.5, 1.5 );
        }

        _sprite.move(-speed ,0);
    }
        
    for(unsigned int i = 0; i <  Nivel::Instance()->getEnemigos2().size(); i++){
             colisionMapaProyectil(Nivel::Instance()->getEnemigos2()[i]->getDireccionProyectil());
             for(unsigned int j = 0 ; j < Nivel::Instance()->getEnemigos2()[i]->getProyectiles().size(); j++){
                 
                
                 //cout << "SE COMPRUEBA COL: " << col << endl;
                 if(col == 1 ){
                     cout << "Posicion proyectil: " << Nivel::Instance()->getEnemigos2()[i]->getProyectiles()[j]->_sprite.getPosition().x <<endl;

                     cout << "ayuda";
                     int aux2= Nivel::Instance()->getMapa()->getAux();
                     Nivel::Instance()->getEnemigos2()[i]->destruirProyectil(aux2);
                 }
             }
         }



}


int  Proyectil::colisionMapaProyectil(int posD)
{
    
     
 
         
        col = Nivel::Instance()->getMapa()->colisionproyectil2();
 
       

    return col;
}


void Proyectil::dirProyectil(int pos)
{
    direccion = pos;


}

sf::Sprite Proyectil::proyectilSprite(){
    return _sprite;

    
}

sf::RectangleShape Proyectil::gethitboxproyectil()
{
    return colisIzq;

}



float Proyectil::getspeed(){
    return speed;
}

void Proyectil::draw()
{
    //cout<<"lo que sea"<<endl;
    
    Motor::Instance()->dibuja(this->_sprite);
    //Motor::Instance()->dibujatrectangulo(colisDer);

    colisIzq.setPosition(_sprite.getPosition().x, _sprite.getPosition().y+10);
    colisDer.setPosition(_sprite.getPosition().x+36, _sprite.getPosition().y+10);
    

   
   


}

