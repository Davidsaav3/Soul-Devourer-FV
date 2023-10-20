#include <SFML/Graphics.hpp>
#include <iostream>
#include "personaje.h"
#include "../nivel/nivel.h"
#include "../motor/motor.h"
#include <string>
#include<math.h>

Personaje::~Personaje(){
    delete circulo;
    delete per_tex;
    delete per;
    delete PrE;
    for (Proyectil* i : proyectiles) {
        delete i;
    }   
}

Personaje::Personaje(){
    //std::cout << " [UPDATE] "; 
    per_tex = new sf::Texture();

    if (!per_tex->loadFromFile("resources/Sprites/guerrera.png")) {
        std::cerr << "Error personajes.png";
        exit(0);
    }

    cont40= 0;
    abrir= true;
    vida=10;
    danio=2;
    velX= 0.0f;
    velY= 0.0f;

    circulo= new sf::CircleShape(40.f);
    circulo->setOrigin(circulo->getGlobalBounds().width/2, circulo->getGlobalBounds().height/2);
    circulo->setFillColor(sf::Color::Red);
    circulo->setPosition(400,655);

    anime= sf::IntRect(0*69,0*44,69,44);
    per = new sf::Sprite(*per_tex);
    per->setOrigin(22, 33);
    //per->setOrigin(0,0);
    per->setTextureRect(sf::IntRect(0 * 66, 0 * 44, 66, 44));
    per->setScale(2,3);

    boundingbox = per->getGlobalBounds();
    frameactual = 0;
    animacionactual = animacion::iddle;
    posDireccionProyectil = 1;

    colisionbalas.setSize(sf::Vector2f(30,40));
    colisionsuelo.setSize(sf::Vector2f(30,20));
    animacioataque1=false;
    animacioataque2=false;
    animaciondistancia=false;

    colisionaProyectilEn = false;
    colisionaProyectilEn2 = false;

    x = 250; y = 650;
    per->setPosition(x,y);

    AnimeTime = sf::milliseconds(30);
    AnimeTime2 = sf::milliseconds(35); 
    
    col= false;

    colW= false;
    colW= false;
    colD= false;
    colS= false;  
    puerta_num= false;
    puerta_num_2=false;
    vuelvoasaltar=true;
    saltocoldown=false;
    cayendo=false;
    ensalto=false;
    volveranmmovrse=true;
    ultiactivada=false;
    atopeconlaulti=false;
    porsalto=false;
    entroencaida=false;
    quietoataquecargado=false;
    vuelvoataque1=true;
    unavez=false;

    if (!a1.loadFromFile("resources/Sonido/sonidoulti.wav")){
        std::cout << "Probelma sonidoulti" <<std::endl;
	}
	ultisonido.setBuffer(a1);
    ultisonido.setVolume(80);

    if (!a2.loadFromFile("resources/Sonido/sonidogolpe.wav")){
        std::cout << "Probelma sonidoulti" <<std::endl;
	}
	sonidogolpe.setBuffer(a2);
    sonidogolpe.setVolume(80);
    
    if (!a3.loadFromFile("resources/Sonido/sonidoataquefuerte.wav")){
        std::cout << "Probelma sonidoulti" <<std::endl;
	}
    
    sonidogolpefuerte.setBuffer(a3);
    sonidogolpefuerte.setVolume(80);

    if (!a4.loadFromFile("resources/Sonido/salto.wav")){
        std::cout << "Probelma sonidoulti" <<std::endl;
	}

	sonidosalto.setBuffer(a4);
    sonidosalto.setVolume(5);

    if (!a5.loadFromFile("resources/Sonido/hit.wav")){
        std::cout << "Probelma sonidoulti" <<std::endl;
	}

	sonidohit.setBuffer(a5);
    sonidohit.setVolume(80);

    municionguadanyas=5;

    
}

void Personaje::input() { 

    if(cayendo==true){
        animacionactual=animacion::caer;
    }



    if(volveranmmovrse==true && quietoataquecargado==false)
    {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            
            const unsigned int seconds2 = static_cast<unsigned int>(enfri2.getElapsedTime().asSeconds());
            if(seconds2>=1){
                colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());

                rampaDerecha= Nivel::Instance()->getMapa()->rampaDerecha(per, Nivel::Instance()->getNivel());
                animacionactual = animacion::dash;
                if(posDireccionProyectil==1){
                    per->setScale(2,3);
                }
                else{
                    per->setScale(-2,3);
                }
                

                if(colisiona==false ||per->getPosition().x > 1200) {
                    colisiona= false; 
                    //per->setTextureRect(sf::IntRect(0 * 64, 2 * 44, 66, 44));
                    //per->setScale(1, 1);
                    //per->move(0.0f,0);
                    velX= 0.0f;
                    colD= true;
                    //std::cout << "para " ;
                }
                else{
                    //per->setTextureRect(sf::IntRect(0 * 64, 2 * 44, 66, 44));
                    //per->setScale(1, 1);
                    if(posDireccionProyectil==1){
                        //per->move(100.0f,0);
                        velX= 20;
                    }
                    else{
                        //per->move(-100.0f,0);
                        velX= -10;
                    }
                     
                    colW=false;
                    colS=false;
                    colD=false; 
                }       
                if(rampaDerecha) {
                //per->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
                    //per->setScale(1, 1);
                    //per->move(30.0f,0); 
                    //per->move(0, -30.0f);
                    velX= 30.0f;
                    velY= -30.0f;
                    colW=false;
                    colS=false;
                    colD=false; 
                }
            enfri2.restart();
            }
                 
        }

    ///////////////////////////////////////////////
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A))){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            //per->move(0, -3.0f); 
            //per->move(3.0f,0); 
            //velX= 15.0f;
            //velY= -15.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ 
            //per->move(0, 3.0f); 
            //per->move(3.0f,0); 
            //velX= 15.0f;
            //velY= 15.0f;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ 
            //per->move(0, 3.0f); 
            //per->move(-3.0f, 0);
            //velX= -15.0f;
            //velY= 15.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ 
            //per->move(0, -3.0f); 
            //per->move(-3.0f, 0);
            //velX= -15.0f;
            //velY= -15.0f;
        }

        

    }
    else{

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());

            colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());
            
            escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());
            
            //std::cout << escalera << "-xd-" << endl ;

            /*if((colisiona && colS==false && colA==false && colD==false) || per->getPosition().y < 40) {
                colisiona= false; 
                per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                //per->move(0, -0.0f); 
                velY= -0.0f;
                velX= 0.0f;//
                colW= true;
            }
            else {
                per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                //per->move(0, -30.0f); 
                velY= -30.0f;
                velX= 0.0f;
                colS=false;
                colA=false;
                colD=false; 
            } */
            if(escalera==1) {
                animacionactual= animacion::subir;
                cayendo=false;
                //per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                //per->move(0, -6.0f); 
                velY= -30.0f;
                velX= 0.0f;//
                colS=false;
                colA=false;
                colD=false; 
                

            }               
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

            }
            else{
                velX= 0.0f;
                velY= 0.0f; 
            }  
        }

        escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && escalera==0) {
            velX= 0.0f;
            velY= 0.0f;
            colW=false;
            colS=false;
            colD=false; 
        }
        

        ///////////////////////////////////////////////
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());

            colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());

            escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());

            rampaDerecha= Nivel::Instance()->getMapa()->rampaDerecha(per, Nivel::Instance()->getNivel());
            rampaIzquierda= Nivel::Instance()->getMapa()
            ->rampaIzquierda(per, Nivel::Instance()->getNivel());

            if(Nivel::Instance()->getNum()!=4){
                /*if((colisiona && colW==false && colA==false && colD==false) || per->getPosition().y > 4800)  {
                    colisiona= false; 
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 0.0f); 
                    velY= 0.0f;
                    velX= 0.0f;//
                    colS= true;
                }
                else {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f);
                    velY= 30.0f; 
                    velX= 0.0f;//
                    colW=false;
                    colA=false;
                    colD=false; 
                }*/
                if(escalera) {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    animacionactual= animacion::subir;
                    cayendo=false;
                    //per->move(0, 6.0f);
                    velY= 30.0f; 
                    velX= 0.0f;//
                    colW=false;
                    colA=false;
                    colD=false; 
                }
                if(rampaIzquierda) {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f); 
                    //per->move(6.0f,0); 
                    velY= 30.0f; 
                    velX= 30.0f; 
                    colW=false;
                    colA=false;
                    colD=false; 
                }
                if(rampaDerecha) {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f);
                    //per->move(-6.0f,0); 
                    velY= 30.0f; 
                    velX= -30.0f; 
                    colW=false;
                    colA=false;
                    colD=false; 
                }
            }
            else{
                if((colisiona && (colW==false && colA==false && colD==false)) || per->getPosition().y > 2300)  {
                    colisiona= false; 
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 0.0f); 
                    velY= 0.0f; 
                    colS= true;
                }
                else {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f); 
                    velY= 30.0f; 
                    colW=false;
                    colA=false;
                    colD=false; 
                }
                if(rampaIzquierda) {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f); 
                    //per->move(6.0f,0); 
                    velX= 30.0f; 
                    velY= 30.0f; 
                    colW=false;
                    colA=false;
                    colD=false; 
                }
                if(rampaDerecha) {
                    per->setTextureRect(sf::IntRect(0 * 64, 0 * 64, 66, 44));
                    //per->move(0, 6.0f);
                    //per->move(-6.0f,0); 
                    velX= -30.0f; 
                    velY= 30.0f; 
                    colW=false;
                    colA=false;
                    colD=false; 
                } 
            }
            colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && escalera==1 && colisiona) {
                animacionactual= animacion::subir;
                cayendo=false;
                velX= 0.0f;
                velY= 0.0f;
                colW=false;
                colS=false;
                colD=false; 
            }
                         
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

            }
            else{
                velX= 0.0f;
                velY= 0.0f; 
            }
        }

        ///////////////////////////////////////////////
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            posDireccionProyectil = 2;

            colisionbalas.setPosition(getSprite().getPosition().x-30,getSprite().getPosition().y-50);  
            colisionsuelo.setPosition(getSprite().getPosition().x-30,getSprite().getPosition().y+15);  

            colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());
            //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());

            rampaDerecha= Nivel::Instance()->getMapa()->rampaDerecha(per, Nivel::Instance()->getNivel());
            rampaIzquierda= Nivel::Instance()->getMapa()->rampaIzquierda(per, Nivel::Instance()->getNivel());

            animacionactual = animacion::moverse;
            per->setScale(-2,3);

            if((colisiona && (colS==false && colW==false && colD==false)) || per->getPosition().x < 40) 
            {
                colisiona= false; 
                //per->setTextureRect(sf::IntRect(0 * 69, 2 * 44, 66, 44));   
                //per->setScale(-2, 2);
                //per->move(-0.0f, 0); 
                velX= -0.0f; 
                velY= 0.0f;//
                colA= true;
            }
            else {  
                //per->setTextureRect(sf::IntRect(0 * 69, 2 * 44, 66, 44));
                //per->setScale(-2, 2);
                //per->move(-6.0f, 0);

                if(cayendo==true){
                    
                    anime.left = 0;
                    anime.top = 44;
                    animacionactual= animacion::caer;
                    velX=0;
                    colW=false;
                    colS=false;
                    colD=false; 

                }
                else{
                    
                    velX= -8.0f;
                    velY= 0.0f;// 
                    colW=false;
                    colS=false;
                    colD=false; 

                }





                

            }
            if(rampaIzquierda) {
                //per->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
                //per->setScale(-1, 1);
                //per->move(-6.0f, 0); 
                //per->move(0, -6.0f); 
                velX= -30.0f; 
                velY= -30.0f; 
                colW=false;
                colS=false;
                colD=false; 
            } 
               
                          
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

            }
            else{
                velX= 0.0f;
                velY= 0.0f; 
            }   
        }

        ///////////////////////////////////////////////
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            posDireccionProyectil = 1;

            colisiona= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->getNivel());
            

            rampaDerecha= Nivel::Instance()->getMapa()->rampaDerecha(per, Nivel::Instance()->getNivel());
            animacionactual = animacion::moverse;
            per->setScale(2,3);
            
            if((colisiona && (colW==false && colA==false && colS==false)) ||per->getPosition().x > 1250) {
                std::cout << per->getPosition().x << " :COLISIONA:" << endl;
                colisiona= false; 
                //per->setTextureRect(sf::IntRect(0 * 64, 2 * 44, 66, 44));
                //per->setScale(1, 1);
                //per->move(0.0f,0);
                velX= 0.0f;
                velY= 0.0f;//
                colD= true;
                //std::cout << "para " ;
            }
            else{
                //per->setTextureRect(sf::IntRect(0 * 64, 2 * 44, 66, 44));
                //per->setScale(1, 1);
                //per->move(6.0f,0); 

                if(cayendo==true){

                    anime.left = 0;
                    anime.top = 44;
                    
                    animacionactual= animacion::caer;
                    velX=0.0f;

                    colW=false;
                    colS=false;
                    colD=false; 
                }
                else{
                    
                    velX= 8.0f;
                    velY= 0.0f;//
                    colW=false;
                    colS=false;
                    colD=false; 

                    
                }



                

            }       
            if(rampaDerecha) {
            //per->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
                //per->setScale(1, 1);
                //per->move(6.0f,0); 
                //per->move(0, -6.0f); 
                velX= 30.0f;
                velY= -30.0f;
                colW=false;
                colS=false;
                colD=false; 
            }     
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

            }
            else{
                velX= 0.0f;
                velY= 0.0f; 
            }   
        }
    }
    ///////////////////////////////////////////////
    //&& Nivel::Instance()->getNivel()==1 para limitar ataques en niveles
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K) && vuelvoataque1==true) 
    {
        enfriataque1.restart();
        vuelvoataque1=false;
        anime.left = 0;
        anime.top = 132;
        animacionactual = animacion::ataque1;
        animacioataque1=true;
        
        /*animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
            if(anime.left ==330)
            {
                
                anime.left = 0;
                
                anime.top = 132;
                

            }else{
                
                anime.left +=66;
                anime.top = 132;
                

            }


            //per->setOrigin(anime.width-55,0);
            //per->setScale( 2.5, 2.5 );
            

            per->setTextureRect(anime);
            animationTime.restart();



        }   */          
    }

    if(Nivel::Instance()->returnalmastotal()==10)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            ultisonido.play();
            
            tiempodeulti.restart();
            atopeconlaulti=true;

            anime.left = 0;
            anime.top = 220;

        animacionactual = animacion::ulti;
        velX=0.0f;
        velY=0.0;

        Nivel::Instance()->gastaralmas();
        
        }

    }


    //colisiona= true;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && colisionasuelo==true)
    {
        sonidosalto.play();
        //porsalto=true;
        //ensalto=true;
        clocksalto.restart();
        //saltocoldown=true; 

            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            //relojsalto.restart();
            //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());
            
            //escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());


            //if(vuelvoasaltar==true)
            //{

            //tiemposalto.restart();
            animacionactual = animacion::salto;

            //relojsalto.getElapsedTime();
            
                if(relojsalto.getElapsedTime().asSeconds()>2.0f ){
                    /*if((colisiona && colS==false && colA==false && colD==false) || per->getPosition().y < 40) {
                        colisiona= false; 
                        per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -0.0f); 
                        velY= -0.0f;
                        velX= 0.0f;//
                        colW= true;
                    }*/
                    
                        per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -30.0f); 

                    
                relojsalto.restart();
                }




                    

                    velY= -30.0f;
                    velX= 20.0f;
                    colS=false;
                    colA=false;
                    colD=false;
                    //vuelvoasaltar=false;

            //}




        }
        //colisiona= true;
        //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)  && colisionasuelo==true){

            sonidosalto.play();

            porsalto=true;
            ensalto=true;
            clocksalto.restart();

            //saltocoldown=true;
            //cout << "ENTRO EN A";
            
             //tiemposalto.restart();           
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            //relojsalto.restart();
            //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());
            
            //escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());

            //if(vuelvoasaltar==true)
            
                animacionactual = animacion::salto;
                //tiemposalto.restart();

                //relojsalto.getElapsedTime();
                if(relojsalto.getElapsedTime().asSeconds()>2.0f){
                    /*if((colisiona && colS==false && colA==false && colD==false) || per->getPosition().y < 40) {
                        colisiona= false; 
                        per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -0.0f); 
                        velY= -0.0f;
                        velX= 0.0f;//
                        colW= true;
                    }*/
                    
                        //per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -30.0f); 

                    
                relojsalto.restart();
                }


                   

                velY= -30.0f;
                velX= -20.0f;
                colS=false;
                colA=false;
                colD=false;
  
                    //vuelvoasaltar=false;

            



                           
        }
        //colisiona= true
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && colisionasuelo==true){

            //sonidosalto.play();

            //porsalto=true;
            //ensalto=true;
            clocksalto.restart();
            //saltocoldown=true;
            //llave= Nivel::Instance()->getMapa()->colision(per, Nivel::Instance()->llave());
            //relojsalto.restart();
            //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());
            
            //escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());
            
            
            
            //if(vuelvoasaltar==true)
            //{
                 //tiemposalto.restart();
                animacionactual = animacion::caer;
                //tiemposalto.restart();


                //relojsalto.getElapsedTime();
                if(relojsalto.getElapsedTime().asSeconds()>2.0f){
                    /*if((colisiona && colS==false && colA==false && colD==false) || per->getPosition().y < 40) {
                        colisiona= false; 
                        per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -0.0f); 
                        velY= -0.0f;
                        velX= 0.0f;//
                        colW= true;
                    }*/
                    
                        per->setTextureRect(sf::IntRect(0 * 69, 3 * 44, 66, 44));
                        //per->move(0, -30.0f); 

                    
                relojsalto.restart();
                }



                   

                    velY= -30.0f;
                    velX= 0.0f;
                    colS=false;
                    colA=false;
                    colD=false;
                    //vuelvoasaltar=false;

        }
        else{

           

        }

    if(Nivel::Instance()->getNivel()>=2){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && colisionasuelo==true){
            anime.left = 0;
            anime.top = 572;
            this->danio=4;
            animacioataque2=true;
            quietoataquecargado=true;
            velX=0.0f;
            animacionactual = animacion::ataque2;
            ataquecargadotiempo.restart();
        }
        else{
            this->danio=2;
        }

    }


        if(Nivel::Instance()->getNivel()>=3)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && municionguadanyas>0)
            {


            anime.left =138;
            anime.top = 88; 
            animaciondistancia=true;
            animacionactual= animacion::lanzar;
            
            ataqueRang();
            ataquedistanciatiempo.restart();
            }


        }




    puerta= Nivel::Instance()->getMapa()->next(per, Nivel::Instance()->getNivel());
    boundingbox = colisionbalas.getGlobalBounds();
    boundingbox2 = colisionsuelo.getGlobalBounds();

/*  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    }
    else{
        velY= 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    }
    else{
        velY= 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    }
    else{
        velX= 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    }
    else{
        velX= 0;
    }   */

    }
}

/*void Personaje::OnCollision(sf::Vector2f direction){
if(direction.x<0.0f){
    //izq
    velocity.x=0.0f;
}
else if(direction.x>0.0f)
{
    //der
    velocity.x=0.0f;
}
if(direction.y>0.0f)
{
    //abajo
    velocity.y=0.0f;
    canJump=true;
}
else if(direction.y>0.0f){
    //arriba
    velocity.y=0.0f;
}
}
*/
////////////
////////////
void Personaje::update(sf::Event &evento){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        switch (abrir){
            case true:
                abrir= false;
            break;
            case false:
                abrir= true;
            break;
        }
    }


    this->input();
    colisionbalas.setPosition(getSprite().getPosition().x,getSprite().getPosition().y-50);
    colisionsuelo.setPosition(getSprite().getPosition().x,getSprite().getPosition().y+15);

    if(entroencaida==true){
        if(tiempocaer.getElapsedTime().asSeconds()>=1){
            cayendo=true;
            entroencaida=false;
        }
    }

    if(volveranmmovrse==false){
        if(estadoulti.getElapsedTime().asSeconds()>=2)
        {
            volveranmmovrse=true;
            bufarpersonaje();

        }
    }

    if(quietoataquecargado==true)
    {
        if(ataquecargadotiempo.getElapsedTime().asSeconds()>=1){
            quietoataquecargado=false;
        }


    }

    if(vuelvoataque1==false){
        if(enfriataque1.getElapsedTime().asSeconds()>=1){
            vuelvoataque1=true;
        }
    }

    if(atopeconlaulti==true)
    {
        if(tiempodeulti.getElapsedTime().asSeconds()>=20)
        {
            atopeconlaulti=false;
            
            devolverstats();



        }

    }
    colisionasuelo= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());

    updateGravedad();



    /*if(colisionasuelo==true){

        cayendo=false;

    }*/


    //cout << "CAYENDO:" <<cayendo <<endl;

    
    
    if(Nivel::Instance()->getMapa()->lava(per, Nivel::Instance()->getNivel())){
        vida= 0;
    }

    //colisionbalas.setOrigin(getSprite().getGlobalBounds().width/2,getSprite().getGlobalBounds().height/2);

    puerta= Nivel::Instance()->getMapa()->next(per, Nivel::Instance()->getNivel());
    //std::cout << puerta; 
    if(abrir==true){
        if( (puerta==1 && (Nivel::Instance()->getNivel()==1 || Nivel::Instance()->getNivel()==2 || Nivel::Instance()->getNivel()==3 || Nivel::Instance()->getNivel()==5 || Nivel::Instance()->getNivel()==4 /*|| Nivel::Instance()->getNivel()==6*/) && Nivel::Instance()->getRunapillada()) || (puerta==1 && (Nivel::Instance()->getNivel()==0)) ){
            puerta_num= true;
        }  
    }
    else{
       if( (puerta==1 && (Nivel::Instance()->getNivel()==1 || Nivel::Instance()->getNivel()==2 || Nivel::Instance()->getNivel()==3 || Nivel::Instance()->getNivel()==5 || Nivel::Instance()->getNivel()==4 /*|| Nivel::Instance()->getNivel()==6*/)/* && Nivel::Instance()->getRunapillada()*/) || (puerta==1 && (Nivel::Instance()->getNivel()==0)) ){
            puerta_num= true;
        } 
    }  

    if(puerta==1 && Nivel::Instance()->getNivel()==6 && Nivel::Instance()->getJefe()->estaMuerto()==true){
        puerta_num= true;
    }

    if(puerta==2 && (Nivel::Instance()->getNivel()==3)){
        puerta_num_2= true;
    }
}

bool Personaje::getPuerta(){
    return this->puerta_num;
}

void Personaje::setPuerta(){
    this->puerta_num= false;
}

bool Personaje::getPuerta2(){
    return this->puerta_num_2;
}

void Personaje::setPuerta2(){
    this->puerta_num_2= false;
}

void Personaje::setVida(int vid){
    this->vida= vid;
}

void Personaje::render(sf::Time delta, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {  
    
    
    float x= reloj_nuevo.getElapsedTime().asMilliseconds();
    float y= x/RELOJ;
    //std::cout << x << " :reloj_nuevo:" << endl;
    //std::cout << RELOJ << " :RELOJ:" << endl;
   // std::cout << y << " :min:" << endl;
    float porcentaje= min(1.f, y);
    //std::cout << porcentaje << " :porcentaje:" << endl;

    velocidad.x= Nivel::Instance()->getInterpolacion()->getPasX()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActX()*porcentaje;

    velocidad.y= Nivel::Instance()->getInterpolacion()->getPasY()*(1-porcentaje)+Nivel::Instance()->getInterpolacion()->getActY()*porcentaje;

    //std::cout << Nivel::Instance()->getInterpolacion()->getActX() << " :x1:" << endl;
    //std::cout << Nivel::Instance()->getInterpolacion()->getActY() << " :y1:" << endl;

    //std::cout << velX << " :x2:" << endl;
    //std::cout << velY << " :y2:" << endl;

    velocidad.x= velocidad.x+velX;
    velocidad.y= velocidad.y+velY;

    Nivel::Instance()->getInterpolacion()->setActX(velocidad.x);
    Nivel::Instance()->getInterpolacion()->setActY(velocidad.y);
    per->setPosition(velocidad);


    for(size_t i = 0; i < proyectiles.size(); i++)
        {
            proyectiles[i]->draw();
        }
        for (size_t i = 0; i < proyectiles.size(); i++)
        {
			proyectiles[i]->update(delta, getSprite().getPosition().x, getSprite().getPosition().y);
                time = delta;
        }
    pegaproyectilenemigo();
    pegaproyectilenemigo2();
    pegaproyectilmapa();
    if(colisionaProyectilEn == true){
                quitarproyectildanyar();
    }
    else if(colisionaProyectilEn2 == true){
                quitarproyectildanyar2();
    }
    else if(colisionaProyectilMap==true){
        quitarproyectilpormapa();
    }

     
    //Motor::Instance()->dibujatrectangulo(colisionsuelo);
    //Motor::Instance()->dibujatrectangulo(colisionbalas);
    //input();
    if(circulo!=NULL){
        getposicion();
        Motor::Instance()->dibuja(*per);
    }
}

int Personaje::getVida(){
    return vida;
}

void Personaje::setVidaPersonaje(int danio){
    this->vida -=danio;
    sonidohit.play();
    if(this->vida <=0){
        this->vida=0;
        

    }
}

void Personaje::spawn(int niv){
    //Nivel::Instance()->reAparece();
    if(niv==0){    
        x = 250; y = 600;
        per->setPosition(x,y);

    }
    if(niv==1){
        per->setPosition(200,4630);
    }
    if(niv==2){
        per->setPosition(280,4550);
    }
    if(niv==3){
        per->setPosition(700,4500);
    }
    if(niv==4){

        per->setPosition(350,2230);
    }
    if(niv==5){
        per->setPosition(1100,4535);
    }
    if(niv==6){
        per->setPosition(200,500);
    }
}

sf::Sprite Personaje::getSprite() {  
    return *per;
}

int Personaje::getPos() {
    return per->getPosition().y;
}

void Personaje::getposicion(){
    //std::cout << per->getPosition().x << "," << per->getPosition().y << endl ;
}

void Personaje::iteraranim(){
    
    switch (animacionactual)
    {
    case animacion::iddle:
        anime.left = 0;
        anime.top = 0;
        //frameactual = 0;
        break;

    case animacion::ataque1:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.1f && animacioataque1==true) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                //animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 132;
                animacioataque1=false;

            }else{
                //frameactual++;
                anime.left +=69;
                anime.top = 132;

            }
            per->setTextureRect(anime);
            animationTime.restart();
        }
        break;
    case animacion::ataque2:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.2f && animacioataque2==true) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                //animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 0;

                animacioataque2=false;
                
            }else{
                frameactual++;
                anime.left +=69;
                anime.top = 572;

            }
            per->setTextureRect(anime);
            animationTime.restart();
        }
        break;

    case animacion::ulti:



        estadoulti.restart();
        volveranmmovrse=false;

        animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.6f) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 0;
                
            }else{
                frameactual++;
                anime.left +=69;
                anime.top = 220;

            }
            per->setTextureRect(anime);
            animationTime.restart();
        }


    break;


    case animacion::moverse:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.1f) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 44;
                
            }else{

                frameactual++;
                anime.left +=69;
                anime.top = 44;

            }
            per->setTextureRect(anime);
            
            animationTime.restart();
        }
        break;
    case animacion::dash:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.1f) 
        {
            if(frameactual == 5)
            {   
                //if(frameactual==5)
                animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 0;
                
            }else{

                frameactual++;
                anime.left +=69;
                anime.top = 616;

            }
            per->setTextureRect(anime);
            
            animationTime.restart();
        }
        break;
        case animacion::salto:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.1f) 
        {
            if(frameactual == 5)
            {   
                //if(frameactual==5)
                animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 44;
                
            }else{

                frameactual++;
                anime.left +=69;
                anime.top = 352;

            }
            per->setTextureRect(anime);
            
            animationTime.restart();
        }
        break;
        case animacion::caer:
    animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.1f) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                //animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 396;
                
            }else{

                frameactual++;
                anime.left +=69;
                anime.top = 396;

            }
            per->setTextureRect(anime);
            
            animationTime.restart();
        }
        break;

        case animacion::lanzar:


        animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.2f && animaciondistancia==true) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                //animacionactual = animacion::iddle;
                
                anime.left = 0;
                anime.top = 0;

                animaciondistancia=false;
                
            }else{
                //frameactual++;
                anime.left +=69;
                anime.top = 88;

            }
            per->setTextureRect(anime);
            animationTime.restart();
        }
        break;

        case animacion::subir:

        animationTime.getElapsedTime();
        if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
            if(anime.left >= 345)
            {   
                //if(frameactual==5)
                //animacionactual = animacion::iddle;
                
                anime.left = 69;
                anime.top = 0;

                //animaciondistancia=false;
                
            }else{
                //frameactual++;
                anime.left +=69;
                anime.top = 660;

            }
            per->setTextureRect(anime);
            animationTime.restart();
        }
        break;



        
    default:
        break;
    }
}


bool Personaje::compruebaintenemigo(sf::FloatRect laquemepasan){

    //comrpuebo tiempp de ataque
    const unsigned int seconds = static_cast<unsigned int>(enfri.getElapsedTime().asSeconds());

    if(animacionactual == animacion::ataque1 && animacioataque1==true){
        if(boundingbox.intersects(laquemepasan) && seconds>=1){
            sonidogolpe.play();
            enfri.restart();
        return true;
        }
    }

    else if(animacionactual == animacion::ataque2 && animacioataque2==true){
        if(boundingbox.intersects(laquemepasan) && seconds>=2){
            sonidogolpefuerte.play();
            enfri.restart();
        return true;
        }
    }
    
    return false;
    

}

void Personaje::sumavida(int hpmas){

    if(this->getVida()>=10)
    {
        this->vida=10;

    }else{
        this->vida += hpmas;

    }
    


}




sf::RectangleShape Personaje::gethitboxpersonaje()
{
    return colisionbalas;

}

int Personaje::getdanio(){
    return danio;
}

void Personaje::ataqueRang()
{
     
     const unsigned int seconds = static_cast<unsigned int>(enfri.getElapsedTime().asSeconds());

                if(seconds>=1){                              
                        cout << "disparo bala" <<endl;
                        int posX = getSprite().getPosition().x;
                        int posY = getSprite().getPosition().y;
                        PrE = new Proyectil(posX,posY-125, 1);
                        proyectiles.push_back(PrE);
                        PrE->dirProyectil(posDireccionProyectil);
                        enfri.restart();
                }
            

}

bool Personaje::pegaproyectilenemigo()
{
    colisionaProyectilEn = false;
        
        if(this->getProyectiles().size() > 0){
                    for(unsigned int j = 0; j <this->getProyectiles().size();j++){
                        for(unsigned int i = 0; i<Nivel::Instance()->getEnemigos().size(); i++){
                           if(this->getProyectiles()[j]->proyectilSprite().getGlobalBounds().intersects(Nivel::Instance()->getEnemigos()[i]->gethitboxenemigo().getGlobalBounds()))
                            {
                                    colisionaProyectilEn = true;
                                    auxPosProyectil = j; 
                                    posicionenemigoenarray = i;        
                            } 
                        }
                            
                    }
                }
        return colisionaProyectilEn;
}


bool Personaje::pegaproyectilmapa()
{
    colisionaProyectilMap = false;
        
        if(this->getProyectiles().size() > 0){
                    for(unsigned int j = 0; j <this->getProyectiles().size();j++){
                        
                           if(this->getProyectiles()[j]->proyectilSprite().getPosition().x>1200 || this->getProyectiles()[j]->proyectilSprite().getPosition().x<0)
                            {
                                    colisionaProyectilMap = true;
                                    auxPosProyectil = j; 
                                    //posicionenemigoenarray = i;        
                             
                        }
                            
                    }
                }
        return colisionaProyectilMap;
}

bool Personaje::pegaproyectilenemigo2()
{
    colisionaProyectilEn2 = false;
        
        if(this->getProyectiles().size() > 0){
                    for(unsigned int j = 0; j <this->getProyectiles().size();j++){
                        for(unsigned int i = 0; i<Nivel::Instance()->getEnemigos2().size(); i++){
                           if(this->getProyectiles()[j]->proyectilSprite().getGlobalBounds().intersects(Nivel::Instance()->getEnemigos2()[i]->gethitboxenemigo().getGlobalBounds()))
                            {
                                    colisionaProyectilEn2 = true;
                                    auxPosProyectil2 = j; 
                                    posicionenemigoenarray2 = i;        
                            } 
                        }
                            
                    }
                }
        return colisionaProyectilEn;
}

std::vector<Proyectil*> Personaje::getProyectiles(){
        return proyectiles;
}

void Personaje::destruirProyectil(int pos){
        
    proyectiles.erase(proyectiles.begin() + pos);
}

void Personaje::quitarproyectilpormapa()
{
    if(this->municionguadanyas <=0)
    {
        this->municionguadanyas=0;
        

    }else{
            municionguadanyas--;
    }
    cout << "culpa del mapa" << endl;
    destruirProyectil(auxPosProyectil);

}



void Personaje::quitarproyectildanyar(){

        if(this->municionguadanyas <=0)
        {
        this->municionguadanyas=0;
        

        }else{
            municionguadanyas--;
        }

    destruirProyectil(auxPosProyectil);

    Nivel::Instance()->getEnemigos()[posicionenemigoenarray]->restavida(posicionenemigoenarray, danio);
        
}

void Personaje::quitarproyectildanyar2(){

        if(this->municionguadanyas <=0)
        {
        this->municionguadanyas=0;
        

        }else{
            municionguadanyas--;
        }

    destruirProyectil(auxPosProyectil2);

    Nivel::Instance()->getEnemigos2()[posicionenemigoenarray2]->restavida(posicionenemigoenarray2, danio);
        
}

float Personaje::min(float m1, float m2) {
    float dev= 0;
    if(m1<m2){
        dev= m1;
    }
    if(m2<m1){
        dev= m2;
    }
    return dev;
}

void Personaje::updateGravedad(){


    //cout << "ENSALTO:" <<  entroencaida << endl;

    //colisiona= Nivel::Instance()->getMapa()->colisiongravedad(per, Nivel::Instance()->getNivel());

    //escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());
    if(colisionasuelo == false && sf::Keyboard::isKeyPressed(sf::Keyboard::W)== false){

        if(unavez==false){
            tiempocaer.restart();
            unavez=true;

        }


        entroencaida=true;
        
        velY= 7.0f;

        
        


        
        //cayendo=true;
        //velX= 0.0f;
    }
    escalera= Nivel::Instance()->getMapa()->escalera(per, Nivel::Instance()->getNivel());
    if(colisionasuelo==true || escalera==1){
        cayendo=false;
        unavez=false;
    }
    else{

    }


}

void Personaje::interpolarAlturas(){
    
}

void Personaje::bufarpersonaje()
{
    ultiactivada=true;
    this->danio=10;
    this->vida=10;
    
    

}

void Personaje::devolverstats()
{
    ultiactivada=false;
    this->danio=2;

}


bool Personaje::devolvervariableulti(){
    return this->ultiactivada;
}

int Personaje::devolvermnunicion(){
    return this->municionguadanyas;
}

bool Personaje::getPuertecita(){
    return this->abrir;
}

void Personaje::sumarmunicion(){
    
    if(this->municionguadanyas >=5)
    {
        this->municionguadanyas=5;
        

    }else{
            municionguadanyas+=2;
    }

    
}

/*bool Enemigo2::pegaproyectilpersonaje()
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


}*/




/* 
if(animationTime.getElapsedTime().asSeconds() > 0.2f) 
        {
            if(anime.left ==704)
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



        }*/

        /*if(j1->boundingBox.intersects(e1->boundingBox)){
            std::cout <<"colisiona maquina" << "\n";
            //y procedo a restarle la vida al enemigo
            e1->restarvida(50);
            std::cout <<e1->vida << "\n";
          }*/