#include <stdlib.h>
#include "enemigo.h"
#include "../motor/motor.h"
#include "../nivel/nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using namespace std;
#define KkVel 5


Enemigo::Enemigo()
{

    vida=10;
    danyo=30;
    

    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    
    if (!_texture.loadFromFile("resources/Sprites/esqueleto.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*64,0*64,64,64);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*64, 0*64, 64, 64));
     _sprite.setScale(2,2);
     _sprite.setPosition(20,50);

    boundingboxe = _sprite.getGlobalBounds();

    //vision
    colisionIzq.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);
    colisionDer.setPosition(_sprite.getPosition().x+50,250 +_sprite.getGlobalBounds().width);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(180,50));
    colisionDer.setSize(sf::Vector2f(180,50));

    //hitbox

    hitboxder.setPosition(_sprite.getPosition().x+10,_sprite.getPosition().y);
    hitboxizq.setPosition(_sprite.getPosition().x-10,_sprite.getPosition().y);

    hitboxder.setSize(sf::Vector2f(10,10));
    hitboxizq.setSize(sf::Vector2f(10,10));


    AnimeTime = sf::milliseconds(30);
    vel = 0.50f; // enemigo velocidad
    AnimeTime2 = sf::milliseconds(35); 
    /*
    buffer.loadFromFile("resources/ataque.wav");
    sonidoataque.setBuffer(buffer);
    */
    colder=false;
    colizq=false;


 

    
    
    //_sprite.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    
    


}

Enemigo::Enemigo(int posix, int posiy)
{
    


    vida=6;
    danyo=1;
    seguiratacandoizq=false;
    seguiratacandoder=false;
    visto=false;
    muerto=false;
    muertoanimacion=false;
    chocader=false;
    chocaizq=false;
    reinicioreloj=false;
    comienzanimacion=false;
    
    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    
    if (!_texture.loadFromFile("resources/Sprites/esqueleto.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*64,0*64,64,64);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*64, 3*64, 64, 64));
     _sprite.setScale(2.5,2.5);
     _sprite.setPosition(posix,posiy);

    colisionbalas.setSize(sf::Vector2f(30,50));


    base.x=_sprite.getPosition().x;
    base.y=_sprite.getPosition().y;


    _newposition2.x=_sprite.getPosition().x-200;
    _newposition2.y=_sprite.getPosition().y;


    //vision



    colisionIzq.setPosition(_sprite.getPosition().x-105, _sprite.getPosition().y+60);
    colisionDer.setPosition(_sprite.getPosition().x+105, _sprite.getPosition().y+60);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(200,50));
    colisionDer.setSize(sf::Vector2f(200,50));

    //hitbox

    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    hitboxder.setSize(sf::Vector2f(20,60));
    hitboxizq.setSize(sf::Vector2f(20,60));


    AnimeTime = sf::milliseconds(30);
    vel = 1; // enemigo velocidad
    AnimeTime2 = sf::milliseconds(35); 
    /*
    buffer.loadFromFile("resources/ataque.wav");
    sonidoataque.setBuffer(buffer);
    */
    colder=false;
    colizq=false;


	if (!b1.loadFromFile("resources/Sonido/sonidoalma.wav")){
        std::cout << "Probelma sonidoalma" <<std::endl;
	}
	alma.setBuffer(b1);
    alma.setVolume(80);


    

    
    
    //_sprite.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    
    


}

Enemigo::Enemigo(int posix, int posiy, int hp, int dmg)
{
    


    vida=hp;
    danyo=dmg;
    seguiratacandoizq=false;
    seguiratacandoder=false;
    visto=false;
    muerto=false;
    muertoanimacion=false;
    chocader=false;
    chocaizq=false;
    reinicioreloj=false;
    comienzanimacion=false;
    
    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    
    if (!_texture.loadFromFile("resources/Sprites/esqueletoking.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*64,0*64,64,64);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*64, 3*64, 64, 64));
     _sprite.setScale(2.5,2.5);
     _sprite.setPosition(posix,posiy);


    base.x=_sprite.getPosition().x;
    base.y=_sprite.getPosition().y;


    _newposition2.x=_sprite.getPosition().x-200;
    _newposition2.y=_sprite.getPosition().y;


    //vision

    colisionbalas.setSize(sf::Vector2f(30,50));


    colisionIzq.setPosition(_sprite.getPosition().x-105, _sprite.getPosition().y+60);
    colisionDer.setPosition(_sprite.getPosition().x+105, _sprite.getPosition().y+60);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(200,50));
    colisionDer.setSize(sf::Vector2f(200,50));

    //hitbox

    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    hitboxder.setSize(sf::Vector2f(20,60));
    hitboxizq.setSize(sf::Vector2f(20,60));


    AnimeTime = sf::milliseconds(30);
    vel = 0.50f; // enemigo velocidad
    AnimeTime2 = sf::milliseconds(35); 
    /*
    buffer.loadFromFile("resources/ataque.wav");
    sonidoataque.setBuffer(buffer);
    */
    colder=false;
    colizq=false;

    if(!b1.loadFromFile("resources/Sonido/sonidoalma.wav")){
        std::cout << "Probelma sonidoalma" <<std::endl;
	}
	alma.setBuffer(b1);
    alma.setVolume(80);


    
    
    //_sprite.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    
    


}


Enemigo::~Enemigo(){

}

sf::RectangleShape Enemigo::returnrectangle(){
    return colisionIzq;

}

sf::RectangleShape Enemigo::returnrectangle2(){
    return colisionDer;

}

void Enemigo::andarDer()
{



    
    if(Nivel::Instance()->getMapa()->colisionRectangulo(hitboxder) == false)
    {
        _newposition.y = Der;
        velX= vel;
        velY= 0;
        _sprite.move(vel,0);


        if(animationTime.getElapsedTime().asSeconds()>0.2f)
        {
            if(anime.left >=704)
            {
                anime.left = 0;
                anime.top = 128;


            }else{
                anime.left +=64;
                anime.top = 128;

            }

            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );

            _sprite.setTextureRect(anime);
            animationTime.restart();
        

        }

    }



}


void Enemigo::andarIzq()
{



    
    if(Nivel::Instance()->getMapa()->colisionRectangulo(hitboxizq) == false)
    {
        _newposition.y = 5;
        _sprite.move(-vel,0);
        velX= -vel;
        velY= 0;

        if(animationTime.getElapsedTime().asSeconds()>0.2f)
        {
            
            if(anime.left >=704)
            {
                
                anime.left = 0;
                
                anime.top = 128;
                

            }else{
                
                anime.left +=64;
                anime.top = 128;
                

            }

            
            _sprite.setOrigin(anime.width-10,0);
            _sprite.setScale( -2.5, 2.5 );


            _sprite.setTextureRect(anime);
            animationTime.restart();
        

        }

    }



}



void Enemigo::destruirjugador(){

    
    
    if(chocader==true || seguiratacandoder==true)
    {
        chocaizq=false;
        seguiratacandoizq=false;
       
        
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        

        if(animationTime.getElapsedTime().asSeconds() > 0.3f) 
        {
            if(anime.left >=384)
            {
                
                anime.left = 0;
                
                anime.top = 0;
                

            }else{
                
                anime.left +=64;
                anime.top = 0;
                

            }


            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }



        if(reinicioreloj==true && seconds>=3) 
        {
            
            clock.restart();
            reinicioreloj=false;

               
                if(chocader==true)
                Nivel::Instance()->getPersonaje()->setVidaPersonaje(danyo);

                

               


                


            
             anime.left=0;
             seguiratacandoder=false;
             
            

        }

        




            



    }


    else if(chocaizq==true || seguiratacandoizq==true)
    {
        chocader=false;
        seguiratacandoder=false;
        
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        

        if(animationTime.getElapsedTime().asSeconds() > 0.3f) 
        {
           
            if(anime.left >=384)
            {
                
                anime.left = 0;
                
                anime.top = 0;
                

            }else{
                
                anime.left +=64;
                anime.top = 0;
                

            }


            _sprite.setOrigin(anime.width-10,0);
            _sprite.setScale( -2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }



        if(reinicioreloj==true && seconds>=3) 
        {
           
            clock.restart();
            reinicioreloj=false;

                if(chocaizq==true)
                Nivel::Instance()->getPersonaje()->setVidaPersonaje(danyo);

                

                

            

            anime.left=0;
            seguiratacandoizq=false;
           

        }




    }


    
}

void Enemigo::animacionmuerte()
{
    if(comienzanimacion==false){
        anime.left=0;
        anime.top=64;
        comienzanimacion=true;
    }


        
        
        if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
           
            if(anime.left >=768)
            {
                
                anime.left = 0;
                
                anime.top = 64;
                

            }else{
                
                anime.left +=64;
                anime.top = 64;
                

            }


            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }



}

void Enemigo::render(sf::Clock reloj_nuevo, float RELOJ) {  
    
    /*float x= reloj_nuevo.getElapsedTime().asMilliseconds();
    float y= x/RELOJ;
    //std::cout << x << " :reloj_nuevo:" << endl;
    //std::cout << RELOJ << " :RELOJ:" << endl;
    std::cout << y << " :min:" << endl;
    float porcentaje= min(1.f, y);
    std::cout << porcentaje << " :porcentaje:" << endl;

    velocidad.x= Nivel::Instance()->getInterpolacion()->getPasX_enemigo1()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActX_enemigo1()*porcentaje;

    velocidad.y= Nivel::Instance()->getInterpolacion()->getPasY_enemigo1()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActY_enemigo1()*porcentaje;

    std::cout << Nivel::Instance()->getInterpolacion()->getActX_enemigo1() << " :x1:" << endl;
    std::cout << Nivel::Instance()->getInterpolacion()->getActY_enemigo1() << " :y1:" << endl;

    std::cout << velX << " :x2:" << endl;
    std::cout << velY << " :y2:" << endl;

    velocidad.x= velocidad.x+velX;
    velocidad.y= velocidad.y+velY;

    Nivel::Instance()->getInterpolacion()->setActX_enemigo1(velocidad.x);
    Nivel::Instance()->getInterpolacion()->setActY_enemigo1(velocidad.y);
    _sprite.setPosition(velocidad);*/

    /*
            if(chocader==true){
                cout << "true derecha";
            }else{
                cout << "false derecha";
            }    
                
            if(chocaizq==true){
                cout << "true izq";
            }else{
                cout << "false izq";
            }
    */
        
        Motor::Instance()->dibuja(_sprite);

       //Motor::Instance()->dibujatrectangulo(colisionbalas); //campo vision
       //Motor::Instance()->dibujatrectangulo(hitboxizq); //campo vision
        
    
    colisionbalas.setPosition(getsprite().getPosition().x+40,getsprite().getPosition().y+50);  
    //vision
    colisionIzq.setPosition(_sprite.getPosition().x-150, _sprite.getPosition().y+60);
    colisionDer.setPosition(_sprite.getPosition().x+95, _sprite.getPosition().y+60);

    //hitbox
    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    
    
    if(muertoanimacion==true)
    {
        animacionmuerte();

        if(animemuerte.getElapsedTime().asSeconds()>=2)
        {
            animemuerte.restart();
            muerto=true;
            Nivel::Instance()->destruirenemigo(posicionarrayenemigo,0);

        }

    }
    else
    {
            
        compruebahitbox();
        destruirjugador();

       

    

    if(chocader == true || chocaizq ==true || seguiratacandoizq == true || seguiratacandoder == true)
    {
        

        

         _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);


    }else{

            seguiratacandoizq=false;
            seguiratacandoder=false;
        
        
     

    mirar();
    //jugador encontrado
        if(colder==true || colizq==true)
        {
            visto=true;
            calcularposicionjugador();
            if(colder==true)
            {
                vel=2;
                andarDer();
                calcularposicionjugador();

            }else if(colizq==true){
                vel=2;
                andarIzq();
                calcularposicionjugador();
                
            }






        }
        else //sehuir andando
        {
            //cout << "1" << endl;

            vel=1;
            if(visto==true)
            {
                                

                
                _newposition2.x = base.x;
                
                if(_newposition2.x > _sprite.getPosition().x)
                {

                    
                    andarDer();
                    
                    if(_newposition2.x == _sprite.getPosition().x)
                    {

                        _newposition2.x=_sprite.getPosition().x-200;
                        visto=false;


                    }



                }else if(_newposition2.x <_sprite.getPosition().x)
                {
                    andarIzq();

                    if(_newposition2.x == _sprite.getPosition().x)
                    {
                        _newposition2.x=_sprite.getPosition().x+200;
                        visto=false;
                    }


                }

                else{

                }                  




            }
            else
            {


                if(_newposition2.x > _sprite.getPosition().x)
                {
                    
                    andarDer();
                    
                    if(_newposition2.x == _sprite.getPosition().x)
                    {


                        _newposition2.x=_sprite.getPosition().x-200;
                    }



                }else if(_newposition2.x <_sprite.getPosition().x)
                {
                    andarIzq();

                    if(_newposition2.x == _sprite.getPosition().x)
                    {
                        _newposition2.x=_sprite.getPosition().x+200;
                    }


                }

                else{

                }                




            }



            



        }

    }

    }




    



}



int Enemigo::getVida() 
{
        return this->vida;
}


int Enemigo::restavida(int posicion, int danio)
{
    

    this->vida -= danio;

    

    if (this->vida <= 0)
    {
        alma.play();
        
        
       this->vida=0;
       this->muertoanimacion=true;
        posicionarrayenemigo=posicion;
        
        
        
        animemuerte.restart();

            
        //cout << "denrtro de funcion" << muerto;
        //Nivel::Instance()->destruirenemigo(posicion,0);
           

        


    }

    return this->vida;


}

sf::RectangleShape Enemigo::gethitboxenemigo()
{
    return colisionbalas;

}





void Enemigo::mirar()
{
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->colisionIzq.getGlobalBounds()))
    {
        colizq= true;

    }
    else
    {
        colizq=false;

    }

    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->colisionDer.getGlobalBounds()))
    {
        colder= true;

    }
    else
    {
        colder=false;

    }
    



}


void Enemigo::aux(){
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->hitboxizq.getGlobalBounds()))
    {



    }else if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->hitboxder.getGlobalBounds()))
    {
        _Animeclock.restart();
    }



}

void Enemigo::compruebahitbox(){
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->hitboxizq.getGlobalBounds()))
    {
        if(reinicioreloj==false){
            clock.restart();
            reinicioreloj=true;
        }

        
            

        

        
        seguiratacandoizq=true;
        chocaizq= true;

    }
    else
    {
        
        chocaizq=false;
        

    }

    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->hitboxder.getGlobalBounds()))
    {

        if(reinicioreloj==false){
            clock.restart();
            reinicioreloj=true;
        }

        
        
        seguiratacandoder=true;
        chocader= true;

    }
    else
    {
        chocader=false;

    }
    boundingboxe = _sprite.getGlobalBounds();
}

void Enemigo::calculaposicion()
{


        if(_sprite.getPosition().x   < _newposition2.x)
        {
            _newposition2.x=_sprite.getPosition().x+300;


        }
        
        if(_sprite.getPosition().x   > _newposition2.x)
        {
            
            _newposition2.x =_sprite.getPosition().x-300;

        }


    
    

}



void Enemigo::calcularposicionjugador()
{
    _newposition2 = Nivel::Instance()->getPersonaje()->getSprite().getPosition();
    

}

bool Enemigo::getmuerto(){
    return muerto;
}


sf::Sprite Enemigo::getsprite(){
    return _sprite;
}



/*bool Enemigo::buscarpresa(sf::Sprite jugador)
{
    const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    const unsigned int seconds2 = static_cast<unsigned int>(animationTime.getElapsedTime().asSeconds());
    
   
    bool seguirmviendo=true;
    

    if(jugador.getGlobalBounds().intersects(colisionIzq.getGlobalBounds()))
    {
        

        if(_sprite.getGlobalBounds().intersects(jugador.getGlobalBounds()))
        {
            
            
            
            seguirmviendo=false;

            

                _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);

            

                
            
               
                if(seconds >= 1)
                {

                 sonidoataque.play();

                _texture.loadFromFile("resources/monstruo3.png");
                _sprite.setTexture(_texture);

                                 
                _texture.loadFromFile("resources/monstruo4.png");
                _sprite.setTexture(_texture);



                }


    

                if(seconds >= 3){
                _texture.loadFromFile("resources/monstruo.png");
                _sprite.setTexture(_texture);

                    clock.restart();
                }

            


                

                
            


        }


        

        
        
        
        
        
        if(seguirmviendo==true)
        {

            if(sonidoataque.getStatus()==sf::Music::Status::Playing)
            sonidoataque.stop();

                

            _texture.loadFromFile("resources/monstruo.png");
            _sprite.setTexture(_texture);

            _sprite.move(-4,0);
            colisionIzq.move(-4,0);
            colisionDer.move(-4,0);

                    
                if(std::abs((jugador.getPosition().x-10) - _sprite.getPosition().x) <= 4){
                    _sprite.setPosition(jugador.getPosition().x  ,_sprite.getPosition().y);
                    colisionIzq.setPosition(_sprite.getPosition().x-20 ,_sprite.getPosition().y);
                    colisionDer.setPosition(_sprite.getPosition().x-20 ,_sprite.getPosition().y);
        
                
                }   

        }
        


        return true;


    }

    else if(jugador.getGlobalBounds().intersects(colisionDer.getGlobalBounds()))
    {
        if(_sprite.getGlobalBounds().intersects(jugador.getGlobalBounds()))
        {
                _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);

            

                
            
               
                if(seconds >= 1)
                {

                 sonidoataque.play();

                _texture.loadFromFile("resources/monstruo5.png");
                _sprite.setTexture(_texture);

                                 
                _texture.loadFromFile("resources/monstruo6.png");
                _sprite.setTexture(_texture);



                }


    

                if(seconds >= 3){
                _texture.loadFromFile("resources/monstruo2.png");
                _sprite.setTexture(_texture);

                    clock.restart();
                }


            

        }
        else
        {


                if(sonidoataque.getStatus()==sf::Music::Status::Playing)
                sonidoataque.stop();

                
                _texture.loadFromFile("resources/monstruo2.png");
            _sprite.setTexture(_texture);

            _sprite.move(4,0);
            colisionIzq.move(4,0);
            colisionDer.move(4,0);

                    
            if(std::abs((jugador.getPosition().x+10) - _sprite.getPosition().x) <= 4){
                _sprite.setPosition(jugador.getPosition().x  ,_sprite.getPosition().y);
                colisionIzq.setPosition(_sprite.getPosition().x+20 ,_sprite.getPosition().y);
                colisionDer.setPosition(_sprite.getPosition().x+20 ,_sprite.getPosition().y);
    
            
            }  

            
 

        }
        


        return true;


    }

    else
    {

        return false;
    }



    
}*/

/*
void Enemigo::update(){


            if(sonidoataque.getStatus()==sf::Music::Status::Playing)
            sonidoataque.stop();
    
        
        _timeRespawn--;

        if(_timeRespawn<0){
            _timeRespawn = 60 * 5;
            _newPosition = { std::rand() %400 + _sprite.getGlobalBounds().width,0};
        }

        if(_newPosition.x > _sprite.getPosition().x){
            _texture.loadFromFile("resources/monstruo2.png");
            _sprite.setTexture(_texture);

            _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

            _sprite.move(5,0);
            colisionIzq.move(5,0);
            colisionDer.move(5,0);
            //rectangle.move(5,0);
            
            
            
        }


        if(_newPosition.x < _sprite.getPosition().x){
            _texture.loadFromFile("resources/monstruo.png");
            _sprite.setTexture(_texture);

            _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

            _sprite.move(-5,0);
            //rectangle.move(-5,0);
            colisionIzq.move(-5,0);
            colisionDer.move(-5,0);
            
            
        }

        if(std::abs(_newPosition.x - _sprite.getPosition().x) <= 5){
            _sprite.setPosition(_newPosition.x ,_sprite.getPosition().y);
             //rectangle.setPosition(_sprite.getPosition().x/2,250 +_sprite.getGlobalBounds().width);
            colisionIzq.setPosition(_newPosition.x-195,_sprite.getPosition().y);
            colisionDer.setPosition(_newPosition.x+50,_sprite.getPosition().y);
            
        } 


    
   



    


}
/*
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);

}

sf::Sprite Enemigo::getsprite(){
    return _sprite;
}

void Enemigo::posicion()
{
    _sprite.setPosition(100 + _sprite.getGlobalBounds().width,250 +_sprite.getGlobalBounds().height);
    //rectangle.setPosition(_sprite.getPosition().x/2,250 +_sprite.getGlobalBounds().width);
    colisionIzq.setPosition(_sprite.getPosition().x-195,250 +_sprite.getGlobalBounds().width);
    colisionDer.setPosition(_sprite.getPosition().x+50,250 +_sprite.getGlobalBounds().width);



}

sf::FloatRect Enemigo::getBounds() const
{
    return _sprite.getGlobalBounds();
}*/