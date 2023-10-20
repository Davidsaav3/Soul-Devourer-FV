#include <stdlib.h>
#include "enemigo2.h"
#include "../motor/motor.h"
#include "../nivel/nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using namespace std;
#define KkVel 5


Enemigo2::Enemigo2()
{

    vida=5;
    danyo=1;
    

    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    
    if (!_texture.loadFromFile("resources/Sprites/tirador.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*80,0*80,80,80);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*80, 0*80, 80, 80));
     _sprite.setScale(2,2);
     _sprite.setPosition(20,50);

     colisionbalas.setSize(sf::Vector2f(30,50));


    //vision
    colisionIzq.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);
    colisionDer.setPosition(_sprite.getPosition().x+50,250 +_sprite.getGlobalBounds().width);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(180,30));
    colisionDer.setSize(sf::Vector2f(180,30));

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

Enemigo2::Enemigo2(int posix, int posiy)
{
    


    vida=5;
    danyo=1;
    posDireccionProyectil = 0;
    seguiratacandoizq=false;
    seguiratacandoder=false;
    visto=false;
    muerto=false;
    muertoanimacion=false;
    chocader=false;
    chocaizq=false;
    animacionmuertejaja=false;
    proyectilcreado=false;

    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());

    
    
    if (!_texture.loadFromFile("resources/Sprites/tirador.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*80,0*80,80,80);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*80, 0*80, 80, 80));
     _sprite.setScale(2.5,2.5);
     _sprite.setPosition(posix,posiy);


    base.x=_sprite.getPosition().x;
    base.y=_sprite.getPosition().y;


    _newposition2.x=_sprite.getPosition().x-100;
    _newposition2.y=_sprite.getPosition().y;


    //vision


    colisionbalas.setSize(sf::Vector2f(30,50));

    colisionIzq.setPosition(_sprite.getPosition().x-450, _sprite.getPosition().y-20);
    colisionDer.setPosition(_sprite.getPosition().x+395, _sprite.getPosition().y-20);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(600,30));
    colisionDer.setSize(sf::Vector2f(600,30));

    //hitbox

    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    hitboxder.setSize(sf::Vector2f(10,60));
    hitboxizq.setSize(sf::Vector2f(10,60));


    AnimeTime = sf::milliseconds(30);
    vel = 0.50f; // enemigo velocidad
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


Enemigo2::Enemigo2(int posix, int posiy, int hp, int dmg)
{
    


    vida=hp;
    danyo=dmg;
    posDireccionProyectil = 0;
    seguiratacandoizq=false;
    seguiratacandoder=false;
    visto=false;
    muerto=false;
    muertoanimacion=false;
    chocader=false;
    chocaizq=false;
    animacionmuertejaja=false;
    proyectilcreado=false;

    seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
    
    if (!_texture.loadFromFile("resources/Sprites/tiradorking.png")) 
    {
        std::cerr << "Error caragando enemigosssss";
        exit(0);
    }
    anime= sf::IntRect(0*80,0*80,80,80);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0*80, 0*80, 80, 80));
     _sprite.setScale(2.5,2.5);
     _sprite.setPosition(posix,posiy);


    base.x=_sprite.getPosition().x;
    base.y=_sprite.getPosition().y;


    _newposition2.x=_sprite.getPosition().x-100;
    _newposition2.y=_sprite.getPosition().y;


    //vision




    colisionbalas.setSize(sf::Vector2f(30,50));
    colisionIzq.setPosition(_sprite.getPosition().x-250, _sprite.getPosition().y-20);
    colisionDer.setPosition(_sprite.getPosition().x+195, _sprite.getPosition().y-20);

    //rectangle.setSize(sf::Vector2f(400, 10));
    colisionIzq.setSize(sf::Vector2f(600,30));
    colisionDer.setSize(sf::Vector2f(600,30));

    //hitbox

    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    hitboxder.setSize(sf::Vector2f(10,60));
    hitboxizq.setSize(sf::Vector2f(10,60));


    AnimeTime = sf::milliseconds(30);
    vel = 0.50f; // enemigo velocidad
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
    alma.setVolume(70);

    
    
    //_sprite.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    
    


}


Enemigo2::~Enemigo2(){

}

sf::RectangleShape Enemigo2::returnrectangle(){
    return colisionIzq;

}

sf::RectangleShape Enemigo2::returnrectangle2(){
    return colisionDer;

}





void Enemigo2::andarDer()
{



    
    if(Nivel::Instance()->getMapa()->colisionRectangulo(hitboxder) == false)
    {
        _newposition.y = Der;
        _sprite.move(vel,0);
        velX= vel;
        velY= 0;

        if(animationTime.getElapsedTime().asSeconds()>0.2f)
        {
            if(anime.left >=320)
            {
                anime.left = 0;
                anime.top = 80;


            }else{
                anime.left +=80;
                anime.top = 80;

            }

            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );

            _sprite.setTextureRect(anime);
            animationTime.restart();
        

        }

    }



}


void Enemigo2::andarIzq()
{



    
    if(Nivel::Instance()->getMapa()->colisionRectangulo(hitboxizq) == false)
    {
        _newposition.y = 5;
        _sprite.move(-vel,0);
        velX= -vel;
        velY= 0;

        if(animationTime.getElapsedTime().asSeconds()>0.2f)
        {
            
            if(anime.left >=320)
            {
                
                anime.left = 0;
                
                anime.top = 80;
                

            }else{
                
                anime.left +=80;
                anime.top = 80;
                

            }

            
            _sprite.setOrigin(anime.width-10,0);
            _sprite.setScale( -2.5, 2.5 );


            _sprite.setTextureRect(anime);
            animationTime.restart();
        

        }

    }



}



void Enemigo2::destruirjugador(){

    
    
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(colisionDer.getGlobalBounds()) || seguiratacandoder==true)
    {
       
        
        //const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        clock.getElapsedTime();

        if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
            if(anime.left >=400)
            {
                
                anime.left = 0;
                
                anime.top = 160;
                

            }else{
                
                anime.left +=80;
                anime.top = 160;
                

            }


            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }

        if(clock.getElapsedTime().asSeconds()>=3) 
        {
            
             
             clock.restart();
             
             
             seguiratacandoder=false;
             
            

        }
        




            



    }


    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(colisionIzq.getGlobalBounds()) || seguiratacandoizq==true)
    {
        
        //const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        clock.getElapsedTime();

        if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
           
            if(anime.left >=400)
            {
                
                anime.left = 0;
                
                anime.top = 160;
                

            }else{
                
                anime.left +=80;
                anime.top = 160;
                

            }


            _sprite.setOrigin(anime.width-10,0);
            _sprite.setScale( -2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }

        if(clock.getElapsedTime().asSeconds()>=3 ) 
        {
           
             clock.restart();
             
            
            seguiratacandoizq=false;
           

        }



    }


    
}




void Enemigo2::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {  
    
    /*float x= reloj_nuevo.getElapsedTime().asMilliseconds();
    float y= x/RELOJ;
    //std::cout << x << " :reloj_nuevo:" << endl;
    //std::cout << RELOJ << " :RELOJ:" << endl;
    std::cout << y << " :min:" << endl;
    float porcentaje= min(1.f, y);
    std::cout << porcentaje << " :porcentaje:" << endl;

    velocidad.x= Nivel::Instance()->getInterpolacion()->getPasX_enemigo2()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActX_enemigo2()*porcentaje;

    velocidad.y= Nivel::Instance()->getInterpolacion()->getPasY_enemigo2()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActY_enemigo2()*porcentaje;

    std::cout << Nivel::Instance()->getInterpolacion()->getActX_enemigo2() << " :x1:" << endl;
    std::cout << Nivel::Instance()->getInterpolacion()->getActY_enemigo2() << " :y1:" << endl;

    std::cout << velX << " :x2:" << endl;
    std::cout << velY << " :y2:" << endl;

    velocidad.x= velocidad.x+velX;
    velocidad.y= velocidad.y+velY;

    Nivel::Instance()->getInterpolacion()->setActX_enemigo2(velocidad.x);
    Nivel::Instance()->getInterpolacion()->setActY_enemigo2(velocidad.y);
    _sprite.setPosition(velocidad);*/
    
    //cout << "Tamaño proyectiles :"<< this->getProyectiles().size() << endl;   
     Motor::Instance()->dibuja(_sprite);
    //Motor::Instance()->dibujatrectangulo(colisionbalas); //campo vision
    //Motor::Instance()->dibujatrectangulo(colisionDer); //campo vision

    //vision

    colisionbalas.setPosition(_sprite.getPosition().x+40,_sprite.getPosition().y+90);  

    colisionIzq.setPosition(_sprite.getPosition().x-550, _sprite.getPosition().y+100);
    colisionDer.setPosition(_sprite.getPosition().x+130, _sprite.getPosition().y+100);

    //hitbox
    hitboxder.setPosition(_sprite.getPosition().x+100, _sprite.getPosition().y+60);
    hitboxizq.setPosition(_sprite.getPosition().x+20, _sprite.getPosition().y+60);

    if(muertoanimacion==true)
    {
        animacionmuerte();

        if(animemuerte2.getElapsedTime().asSeconds()>=2)
        {
            animemuerte2.restart();
            muerto=true;
            Nivel::Instance()->destruirenemigo(posicionarrayenemigo,1);

        }

    }
    else{

        
        
        destruirjugador();


        if(proyectilcreado==false)
        {
            ataqueRango();
        }
                


            
            

        

            for(size_t i = 0; i < proyectiles.size(); i++)
            {
                
                proyectiles[i]->draw();
            }

        
            for (size_t i = 0; i < proyectiles.size(); i++)
            {
                proyectiles[i]->update(tiempojuego, getSprite().getPosition().x, getSprite().getPosition().y);
                    time = tiempojuego;
            }

            this->pegaproyectilpersonaje();
            if(colisionaProyectilPer == true){

                    quitarproyectildanyar();
                    
            }
            

        

    

    if(chocader == true || chocaizq ==true || seguiratacandoizq == true || seguiratacandoder == true)
    {

         _sprite.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);


    }else{
        
        
     

    mirar();
    //jugador encontrado
        if(colder==true || colizq==true)
        {
            visto=true;







        }
        else //sehuir andando
        {
            
            if(visto==true)
            {
                _newposition2.x = base.x;
                
                if(_newposition2.x > _sprite.getPosition().x)
                {

                    
                    andarDer();
                    
                    if(_newposition2.x == _sprite.getPosition().x)
                    {

                        _newposition2.x=_sprite.getPosition().x-100;
                        visto=false;


                    }



                }else if(_newposition2.x <_sprite.getPosition().x)
                {
                    andarIzq();

                    if(_newposition2.x == _sprite.getPosition().x)
                    {
                        _newposition2.x=_sprite.getPosition().x+100;
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



int Enemigo2::getVida() 
{
        return this->vida;
}






void Enemigo2::mirar()
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

void Enemigo2::ataqueRango()
{
     
     const unsigned int seconds = static_cast<unsigned int>(enfri.getElapsedTime().asSeconds());
    
     bool comprobar = false;

       if(colder == true)
       {
                posDireccionProyectil = 1;
                comprobar = true;
                        
        }else if(colizq ==true)
        {
                posDireccionProyectil = 2;
                 comprobar = true;
        }


            if(comprobar == true)
            {
                if(seconds>=3){

                    
                                                        
                        cout << "disparo proyectil" <<endl;
                        int posX = getSprite().getPosition().x;
                        int posY = getSprite().getPosition().y;
                        PrE = new Proyectil(posX,posY);
                        proyectiles.push_back(PrE);
                        PrE->dirProyectil(posDireccionProyectil);
                        enfri.restart();
                        proyectilcreado=true;
                        
                }
            }

}

sf::Sprite Enemigo2::getSprite() const {
        return _sprite;
}


std::vector<Proyectil*> Enemigo2::getProyectiles(){
        return proyectiles;
}

int Enemigo2::getDireccionProyectil(){
    return posDireccionProyectil;
}

void Enemigo2::destruirProyectil(int pos){
    


    cout << "destruyo proyectil";
        
    proyectiles.erase(proyectiles.begin() + pos);
    proyectilcreado=false;
}

bool Enemigo2::pegaproyectilpersonaje()
{
    colisionaProyectilPer = false;
        
        if(this->getProyectiles().size() > 0){
                    for(unsigned int j = 0; j <this->getProyectiles().size();j++){
                            if(this->getProyectiles()[j]->proyectilSprite().getGlobalBounds().intersects(Nivel::Instance()->getPersonaje()->gethitboxpersonaje().getGlobalBounds()))
                            {
                                    colisionaProyectilPer = true;
                                    auxPosProyectil = j;
                                       
                                        
                                }
                        }
                }
        return colisionaProyectilPer;


}

void Enemigo2::quitarproyectildanyar(){

    destruirProyectil(auxPosProyectil);


    Nivel::Instance()->getPersonaje()->setVidaPersonaje(danyo);

        
}



void Enemigo2::compruebahitbox(){
    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->colisionIzq.getGlobalBounds()))
    {
        seguiratacandoizq=true;
        chocaizq= true;

    }
    else
    {
        
        chocaizq=false;

    }

    if(Nivel::Instance()->getPersonaje()->boundingbox.intersects(this->colisionDer.getGlobalBounds()))
    {
        seguiratacandoder=true;
        chocader= true;

    }
    else
    {
        chocader=false;

    }

}

void Enemigo2::calculaposicion()
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



void Enemigo2::calcularposicionjugador()
{
    _newposition2 = Nivel::Instance()->getPersonaje()->getSprite().getPosition();
    

}




int Enemigo2::restavida(int posicion, int danio)
{

    this->vida -= danio;

    if (this->vida <= 0)
    {
        alma.play();
        
       this->vida=0;
       this->muertoanimacion=true;
        posicionarrayenemigo=posicion;
        
        
        
        animemuerte2.restart();

            
        //cout << "denrtro de funcion" << muerto;
        //Nivel::Instance()->destruirenemigo(posicion,0);
           

        


    }

    return this->vida;


}

void Enemigo2::animacionmuerte()
{

    if(animacionmuertejaja==false){
        anime.left=0;
        anime.top=320;
        animacionmuertejaja=true;
    }
        if(animationTime.getElapsedTime().asSeconds() > 0.1f) 
        {
           
            if(anime.left >=1520)
            {
                
                anime.left = 0;
                
                anime.top = 320;
                

            }else{
                
                anime.left +=80;
                anime.top = 320;
                

            }


            _sprite.setOrigin(anime.width-55,0);
            _sprite.setScale( 2.5, 2.5 );
            

            _sprite.setTextureRect(anime);
            animationTime.restart();



        }

}

bool Enemigo2::getmuerto(){
    return muerto;
}

sf::RectangleShape Enemigo2::gethitboxenemigo()
{
    return colisionbalas;

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