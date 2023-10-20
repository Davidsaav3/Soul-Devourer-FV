#include "nivel.h"
#include "../../motor/motor.h"
#include "../estado/estado.h"
#include "../../run/run.h"
#include "../personaje/personaje.h"

 
/////////////////////////////////////////
Nivel* Nivel::niv = 0;
Nivel* Nivel::Instance(){
    if(niv == 0) {
        niv = new Nivel;
    }
return niv;
}

Nivel::Nivel() {

}

void Nivel::inicializar() {
    reloj= clock();

    interpolacion= new Interpolacion();
    x= true;
    std::cout << " [MAPAS] ";
    N0 = new Map(0,reloj); 
    N1 = new Map(1,reloj); 
    N2 = new Map(2,reloj);
    N3 = new Map(3,reloj);
    N4 = new Map(4,reloj); //Extra
    N5 = new Map(5,reloj); //Nivel 4
    N6 = new Map(6,reloj); //Final

    N= N0;
    nivel= 0;
    ok= true;
    
    per = new Personaje();
    jefe = new Jefe(860,180);
    jefeNpc = new JefeNPC();

    runapillada=false;
    enemigosdestruidos=false;
    enemigosdestruidos2=false;
    contadoralmas=10;
    totalenemigos=0;
    anime= sf::IntRect(0*48,0*64,48,64);
    anime2= sf::IntRect(0*100,0*100,100,100);
    
    est= 0;
    final= false;
    txt_puerta.loadFromFile("resources/Mapa/puerta.png");
    
    puerta.setTexture(txt_puerta);

    txt_ulti0.loadFromFile("resources/Sprites/ulti1.png");
    txt_ulti1.loadFromFile("resources/Sprites/ulti2.png");
    txt_ulti2.loadFromFile("resources/Sprites/ulti3.png");
    txt_ulti3.loadFromFile("resources/Sprites/ulti4.png");
    txt_ulti4.loadFromFile("resources/Sprites/ulti5.png");
    txt_ulti5.loadFromFile("resources/Sprites/ulti6.png");
    txt_ulti6.loadFromFile("resources/Sprites/ulti7.png");
    txt_ulti7.loadFromFile("resources/Sprites/ulti8.png");
    txt_ulti8.loadFromFile("resources/Sprites/ulticasisi.png");
    txt_ulti9.loadFromFile("resources/Sprites/ulticasi.png");
    txt_enulti.loadFromFile("resources/Sprites/enulti.png");
    txt_ulticargada.loadFromFile("resources/Sprites/ulti.png");
    txt_efecto.loadFromFile("resources/Sprites/efecto4864.png");
    txt_ojos.loadFromFile("resources/Sprites/fuego100100.png");
    txt_ojos2.loadFromFile("resources/Sprites/fuego100100.png");

    txt_guadanya0.loadFromFile("resources/Sprites/guadanyas0.png");
    txt_guadanya1.loadFromFile("resources/Sprites/guadanyas1.png");
    txt_guadanya2.loadFromFile("resources/Sprites/guadanyas2.png");
    txt_guadanya3.loadFromFile("resources/Sprites/guadanyas3.png");
    txt_guadanya4.loadFromFile("resources/Sprites/guadanyas4.png");
    txt_guadanya5.loadFromFile("resources/Sprites/guadanyas5.png");

    if(!fuente.loadFromFile("resources/Fuentes/fuentenemigos.ttf"))
    {
        exit(0);

    }

    enemigosrestantes.setFont(fuente);
    enemigosrestantes.setCharacterSize(24);
    enemigosrestantes.setColor(sf::Color::Red);
    enemigosrestantes.setStyle(sf::Text::Bold);

    guadanya0.setTexture(txt_guadanya0);
    guadanya0.setScale(0.15f,0.15f);

    guadanya1.setTexture(txt_guadanya1);
    guadanya1.setScale(0.15f,0.15f);

    guadanya2.setTexture(txt_guadanya2);
    guadanya2.setScale(0.15f,0.15f);

    guadanya3.setTexture(txt_guadanya3);
    guadanya3.setScale(0.15f,0.15f);

    guadanya4.setTexture(txt_guadanya4);
    guadanya4.setScale(0.15f,0.15f);

    guadanya5.setTexture(txt_guadanya5);
    guadanya5.setScale(0.15f,0.15f);

    ulti0.setTexture(txt_ulti0);
    ulti0.setScale(0.25f,0.25f);

    ulti1.setTexture(txt_ulti1);
    ulti1.setScale(0.25f,0.25f);


    ulti2.setTexture(txt_ulti2);
    ulti2.setScale(0.25f,0.25f);


    ulti3.setTexture(txt_ulti3);
    ulti3.setScale(0.25f,0.25f);


    ulti4.setTexture(txt_ulti4);
    ulti4.setScale(0.25f,0.25f);

        
    ulti5.setTexture(txt_ulti5);
    ulti5.setScale(0.25f,0.25f);

    ulti6.setTexture(txt_ulti6);
    ulti6.setScale(0.25f,0.25f);


    ulti7.setTexture(txt_ulti7);
    ulti7.setScale(0.25f,0.25f);

    ulti8.setTexture(txt_ulti8);
    ulti8.setScale(0.25f,0.25f);

    ulti9.setTexture(txt_ulti9);
    ulti9.setScale(0.25f,0.25f);

    ulticargada.setTexture(txt_ulticargada);
    ulticargada.setScale(0.25f,0.25f);


    enulti.setTexture(txt_enulti);
    enulti.setScale(0.25f,0.25f);

    



    efecto.setTexture(txt_efecto);
    efecto.setTextureRect(sf::IntRect(0*48, 0*64, 48, 64));
    efecto.setScale(1.25f,1.25f);

    ojos.setTexture(txt_ojos);
    ojos.setTextureRect(sf::IntRect(0*100, 0*100, 100, 100));
    ojos.setScale(1.0f,1.0f);

    ojos2.setTexture(txt_ojos2);
    ojos2.setTextureRect(sf::IntRect(0*100, 0*100, 100, 100));
    ojos2.setScale(1.0f,1.0f);
    



    txt_cora_i.loadFromFile("resources/Sprites/cora.png");
    txt_cora_d.loadFromFile("resources/Sprites/cora_2.png");
    cora_1.setTexture(txt_cora_i);
    cora_1.setScale(0.5f,0.5f);
    cora_2.setTexture(txt_cora_i);
    cora_2.setScale(0.5f,0.5f);
    cora_3.setTexture(txt_cora_i);
    cora_3.setScale(0.5f,0.5f);
    cora_4.setTexture(txt_cora_i);
    cora_4.setScale(0.5f,0.5f);
    cora_5.setTexture(txt_cora_i);
    cora_5.setScale(0.5f,0.5f);

    cora_6.setTexture(txt_cora_d);
    cora_6.setScale(0.5f,0.5f);
    cora_7.setTexture(txt_cora_d);
    cora_7.setScale(0.5f,0.5f);
    cora_8.setTexture(txt_cora_d);
    cora_8.setScale(0.5f,0.5f);
    cora_9.setTexture(txt_cora_d);
    cora_9.setScale(0.5f,0.5f);
    cora_10.setTexture(txt_cora_d);
    cora_10.setScale(0.5f,0.5f);


	if (!b1.loadFromFile("resources/Sonido/m5.wav")){
        std::cout << "Probelma m1" <<std::endl;
	}
	musica_n1.setBuffer(b1);
    musica_n1.setVolume(50);

	if (!b2.loadFromFile("resources/Sonido/m1.wav")){
        std::cout << "Probelma m2" <<std::endl;
	}
	musica_n2.setBuffer(b2);
    musica_n2.setVolume(50);

	if (!b3.loadFromFile("resources/Sonido/m3.wav")){
        std::cout << "Probelma m3" <<std::endl;
	}
	musica_n3.setBuffer(b3);
    musica_n3.setVolume(50);

	if (!b4.loadFromFile("resources/Sonido/m4.wav")){
        std::cout << "Probelma m4" <<std::endl;
	}
	musica_n4.setBuffer(b4);
    musica_final.setVolume(50);

	if (!b5.loadFromFile("resources/Sonido/m2.wav")){
        std::cout << "Probelma musica final" <<std::endl;
	}
	musica_final.setBuffer(b5);
    musica_final.setVolume(50);

}

Nivel::~Nivel() {
    //Destructor
    delete interpolacion;
    delete N;
    delete N0;
    delete N1;
    delete N2;
    delete N3;
    delete N6;
    delete N4;
    delete N5;
    delete jefe;
    delete jefeNpc;
    delete runafisica;
    delete niv;
    delete per;

    for (Enemigo* i : enemigos) {
        delete i;
    }
    for (Enemigo2* i : enemigos2) {
        delete i;
    }
}

//////////// -- Input --////////// --> Derivan a Nivel

//////////// -- Input --////////// --> Derivan a Nivel
void Nivel::input(sf::Event &evento){
    //std::cout << " [MAPA INPUT] "; 
    per->input();
    if(evento.type){}
}

///////////////////////// -- Update --/////////////////////////// 
void Nivel::update(sf::Event &evento) {
   

   //cout <<"ALMAS:"<<contadoralmas << endl;

    //std::cout << " [MAPA UPDATE] "; 
    if(evento.type){}
    //std::cout << " [UPDATE] ";
    
    per->update(evento);
    //std::cout << " X "; 
        if(nivel==0 && x==true){
            musica_n1.play();
            musica_n1.setLoop(true);
            x= false;
        }

        if(nivel==0 && per->getPuerta()){
            std::cout <<"nivel 1"<<std::endl; N=N1; nivel=1; ok= false;
            per->setPuerta(); per->spawn(1); creaEnemigos();
            crearunas();
            interpolacion->setPos(1);

        }
        if(nivel==1 && per->getPuerta() && ok){
            std::cout <<"nivel 2"<<std::endl; N=N2; nivel=2; ok= false;
            per->setPuerta();
            
            /*
            if(enemigosdestruidos==false && enemigosdestruidos2==false)
            {
                destruyenemigostemporal(); 
            } */

            per->spawn(2);

            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();
            }
            creaEnemigos();
            crearunas();
            interpolacion->setPos(2);
            musica_n1.stop();
            musica_n2.play();
            musica_n2.setLoop(true);
            
        }
        if(nivel==2 && per->getPuerta() && ok){
            std::cout <<"nivel 3"<<std::endl; N=N3; nivel=3; ok= false;
            per->setPuerta(); per->spawn(3);

            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();

            }
            creaEnemigos();
            crearunas();
            interpolacion->setPos(3);
            musica_n2.stop();
            musica_n3.play();
            musica_n3.setLoop(true);
        }
        if(nivel==3 && per->getPuerta2() && ok){
            std::cout <<"nivel 3.1"<<std::endl; N=N4; nivel=4; ok= false;
            per->setPuerta2(); per->spawn(4);

            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();
            }
            creaEnemigos();
            crearunas();
            interpolacion->setPos(4);
            musica_n2.stop();
            musica_n3.play();
            musica_n3.setLoop(true);
        }
        if(nivel==3 && per->getPuerta() && ok){
            std::cout <<"nivel 4"<<std::endl; N=N5; nivel=5; ok= false;
            per->setPuerta(); per->spawn(5);
            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();

            }
            creaEnemigos();
            interpolacion->setPos(5);
            musica_n3.stop();
            musica_n4.play();
            musica_n4.setLoop(true);
        }
        
        if(nivel==4 && per->getPuerta() && ok){
            std::cout <<"nivel 4"<<std::endl; N=N5; nivel=5; ok= false;
            per->setPuerta(); per->spawn(5);
            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();
            }
            creaEnemigos();
            interpolacion->setPos(5);
            musica_n3.stop();
            musica_n4.play();
            musica_n4.setLoop(true);
        }
        if(nivel==5 && per->getPuerta() && ok){
            std::cout <<"nivel Final"<<std::endl; N=N6; nivel=6; ok= false;
            per->setPuerta(); per->spawn(6);
            //destruyenemigostemporal();
            destruyenemigostemporal();
            if(runafisica!=NULL)
            {
                destruirruantemporal();
            }
            interpolacion->setPos(6);
            musica_n4.stop();
            musica_final.play();
            musica_final.setLoop(true);
        }
        if(nivel==6 && per->getPuerta() && ok){
            std::cout <<"nivel 0"<<std::endl; ok= false;
            per->setPuerta(); final= true; N=N0; nivel=0;
            per->spawn(0);
            per->setVida(10);
            interpolacion->setPos(0);
            musica_final.stop();
            musica_n0.play();
            musica_final.setLoop(true);
        }
        ok= true;

    /*if (evento.key.code == sf::Keyboard::V) {
        est= 0;
    }
    if (evento.key.code == sf::Keyboard::B) {
        est= 1;
    }
    if (evento.key.code == sf::Keyboard::N) {
        std::cout <<"VIDAAAA 1"<<std::endl;
        Motor::Instance()->getVista().setCenter(640,360);
        Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
        est= 2;
        per->spawn(nivel);
    }   */
    if (per->getVida()<=0) {
        //std::cout <<"VIDAAAA 2"<<std::endl;
        Motor::Instance()->getVista().setCenter(640,360);
        Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
        per->setVida(10);
        est= 2;
        per->spawn(nivel);
        interpolacion->setPos(nivel);
        reAparece();
    }
    
}

/// -- Render --////  
void Nivel::render(sf::Time tiempojuego, float tiempo, float percent, sf::Clock reloj_nuevo, float RELOJ) {

    //est= 0;
    if(nivel==0 || nivel==1 || nivel==2 || nivel==3 || nivel==4 || nivel==5 || nivel==6){
       

        //std::cout << "  RENDER] "; 
        if(nivel==0){
            txt_fondo.loadFromFile("resources/Mapa/0/M0.png");
            
            //cout << "vida:"<< per->getVida() <<endl;
        }
        if(nivel==1){
            txt_fondo.loadFromFile("resources/Mapa/1/M1.png");
            //cout << "vida:"<< per->getVida() <<endl;

            puerta.setPosition(1040,187);
        }
        if(nivel==2){
            txt_fondo.loadFromFile("resources/Mapa/2/M2.png");
            //cout << "vida:"<< per->getVida() <<endl;
            puerta.setPosition(956,186);
        }
        if(nivel==3){
            txt_fondo.loadFromFile("resources/Mapa/3/M3.png");
            //cout << "vida:"<< per->getVida() <<endl;
            puerta.setPosition(1037,187);
        }
        if(nivel==4){
            txt_fondo.loadFromFile("resources/Mapa/3.1/M3.1.png");
            //cout << "vida:"<< per->getVida() <<endl;
            puerta.setPosition(160,183);
        }
        if(nivel==5){
            txt_fondo.loadFromFile("resources/Mapa/4/M4.png");
            puerta.setPosition(1120,407);
        }
        if(nivel==6){
            txt_fondo.loadFromFile("resources/Mapa/5/M5.png");
            puerta.setPosition(560,412);
        }
            //cout << "heyyyy:" << txt_fondo.getSize().x << endl;

        if(nivel==1 || nivel==2 || nivel==3 || nivel==4 || nivel==5 ){
            fondo.setTexture(txt_fondo);
            fondo.setTextureRect(sf::IntRect(0,0,1280,720));
            fondo.setPosition( Motor::Instance()->getVista().getCenter().x-640,  Motor::Instance()->getVista().getCenter().y -360);
            Motor::Instance()->ventana().draw(fondo);
            
            //enemigosrestantes.setPosition(0,0);

            totalenemigos=enemigos.size()+enemigos2.size();
            std::ostringstream os;
            os << totalenemigos;
            
            enemigosrestantes.setString("Enemigos restantes:"+os.str());
            //cout  << os.str();
            Motor::Instance()->ventana().draw(enemigosrestantes);



        }
        if(nivel==0 || nivel==6){
            std::cout <<"nivel----->"<< nivel <<std::endl; 
            fondo.setTexture(txt_fondo);
            fondo.setTextureRect(sf::IntRect(0,0,1280,720));
            fondo.setPosition( Motor::Instance()->getVista().getCenter().x-640,  Motor::Instance()->getVista().getCenter().y -360);
            Motor::Instance()->ventana().draw(fondo);


            //cout << "TOTAL DE ENEMIGOS"<<totalenemigos;

            //Motor::Instance()->ventana().draw(fondo);
        }

        if(nivel==0 || nivel==1 || nivel==2 || nivel==3 || nivel==6){
            N->dibujarMapa(nivel,0);
            N->dibujarMapa(nivel,1);
            per->render(tiempojuego, tiempo, percent, reloj_nuevo, RELOJ);

            jefeNpc->render(tiempojuego,tiempo, percent);
            N->dibujarMapa(nivel,2);
        }
        else{
            N->dibujarMapa(nivel,0);
            N->dibujarMapa(nivel,1);
            N->dibujarMapa(nivel,2);
            per->render(tiempojuego, tiempo, percent, reloj_nuevo, RELOJ);
            jefeNpc->render(tiempojuego,tiempo, percent);
        }

        if(nivel==5 || nivel==4 || nivel==1 || nivel==2 || nivel==3 /*|| nivel==6*/){
            if(runapillada==false){
                Motor::Instance()->ventana().draw(puerta);
            }
        }

        if(nivel==1)
        {
            if(enemigos.size()==0 && enemigos2.size()==0 && runapillada==false)
            {
                cout << "me dibujo" <<endl;
                runafisica->colisionPersonaje();

                if(runafisica!= NULL)
                runafisica->dibujarRuna();

            }


            for(unsigned int i = 0; i < enemigos.size(); i++) {
                if(enemigos[i]->getmuerto()==false) 
                {         
                    enemigos[i]->render(reloj_nuevo, RELOJ);
                }
                
            }

            for(unsigned int i = 0; i < enemigos2.size(); i++) 
            {
                if(enemigos2[i]->getmuerto()==false) 
                {         
                    enemigos2[i]->render(tiempojuego,tiempo, percent, reloj_nuevo, RELOJ);
                }
            }

        }else if(nivel == 2)       
        {

            if(enemigos.size()==0 && enemigos2.size()==0 && runapillada==false)
            {
                cout << "me dibujo" <<endl;
                runafisica->colisionPersonaje();

                if(runafisica!= NULL)
                runafisica->dibujarRuna();

            }

            for(unsigned int i = 0; i < enemigos.size(); i++) 
            {
                if(enemigos[i]->getmuerto()==false) 
                {         
                    enemigos[i]->render(reloj_nuevo, RELOJ);
                }
            }

            for(unsigned int i = 0; i < enemigos2.size(); i++) 
            {
                if(enemigos2[i]->getmuerto()==false) 
                {         
                    enemigos2[i]->render(tiempojuego,tiempo, percent,reloj_nuevo, RELOJ);
                }
            }

        }else if(nivel==3)
        {

            if(enemigos.size()==0 && enemigos2.size()==0 && runapillada==false)
            {
                cout << "me dibujo" <<endl;
                runafisica->colisionPersonaje();
                if(runafisica!= NULL)
                runafisica->dibujarRuna();
            }

            for(unsigned int i = 0; i < enemigos.size(); i++) 
            {
                if(enemigos[i]->getmuerto()==false) 
                {         
                    enemigos[i]->render(reloj_nuevo, RELOJ);
                }
            }

            for(unsigned int i = 0; i < enemigos2.size(); i++) 
            {
                if(enemigos2[i]->getmuerto()==false) 
                {         
                    enemigos2[i]->render(tiempojuego,tiempo,  percent, reloj_nuevo, RELOJ);
                }
            }

        }else if(nivel==4)
        {

            if(enemigos.size()==0 && enemigos2.size()==0 && runapillada==false)
            {
                cout << "me dibujo" <<endl;
                runafisica->colisionPersonaje();

                if(runafisica!= NULL)
                runafisica->dibujarRuna();

            }
            
            for(unsigned int i = 0; i < enemigos.size(); i++) 
            {
                if(enemigos[i]->getmuerto()==false) 
                {         
                    enemigos[i]->render(reloj_nuevo, RELOJ);
                }
            }

            for(unsigned int i = 0; i < enemigos2.size(); i++) 
            {
                if(enemigos2[i]->getmuerto()==false) 
                {         
                    enemigos2[i]->render(tiempojuego,tiempo,  percent, reloj_nuevo, RELOJ);
                }
            }

        }else if(nivel==5)
        {

            if(enemigos.size()==0 && enemigos2.size()==0 && runapillada==false)
            {
                cout << "me dibujo" <<endl;
                runafisica->colisionPersonaje();

                if(runafisica!= NULL)
                runafisica->dibujarRuna();
                





            }
            
            for(unsigned int i = 0; i < enemigos.size(); i++) 
            {
                if(enemigos[i]->getmuerto()==false) 
                {         
                    enemigos[i]->render(reloj_nuevo, RELOJ);
                }

            }

            for(unsigned int i = 0; i < enemigos2.size(); i++) 
            {
                if(enemigos2[i]->getmuerto()==false) 
                {         
                    enemigos2[i]->render(tiempojuego,tiempo,  percent,  reloj_nuevo,  RELOJ);
                }

            }

            


        }else if(nivel==6){
            jefe->render(tiempojuego,tiempo, percent, reloj_nuevo, RELOJ);
        }


        if((est!=2) && (nivel==1 || nivel==2 || nivel==3 || nivel==4  || nivel==5)){

            if((nivel==4 && per->getPos()>2040) || per->getPos()>4440 || per->getPos()<360){
                if(per->getPos()<360){
                    Motor::Instance()->getVista().setCenter(640, 360); 
                    Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
                }
                if((nivel==1 || nivel==2 || nivel==3 || nivel==5) && (per->getPos()>4440)){
                    Motor::Instance()->getVista().setCenter(640, 4440); Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
                }
                if(nivel==4 && per->getPos()>2040){
                    Motor::Instance()->getVista().setCenter(640, 2040); Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
                }
                
            }
            else{
                if(nivel!=0 && nivel!=6){
                    Motor::Instance()->getVista().setCenter(640, Nivel::Instance()->getPersonaje()->getSprite().getPosition().y); 
                    Motor::Instance()->dibujarVista(Motor::Instance()->getVista());
                }
            }
        }
        if(nivel==6 || nivel==0){
            Motor::Instance()->getVista().setCenter(640, 360); 
            Motor::Instance()->dibujarVista(Motor::Instance()->getVista());

            cora_1.setPosition(10,685);
            cora_2.setPosition(40,685);
            cora_3.setPosition(70,685);
            cora_4.setPosition(100,685);
            cora_5.setPosition(130,685);

            cora_6.setPosition(22,685);
            cora_7.setPosition(52,685);
            cora_8.setPosition(82,685);
            cora_9.setPosition(112,685);
            cora_10.setPosition(142,685);

            if(per->devolvermnunicion()==5)
            {
                guadanya5.setPosition(260,670);

            }else if(per->devolvermnunicion()==4){
                guadanya4.setPosition(260,670);
            }else if(per->devolvermnunicion()==3){
                guadanya3.setPosition(260,670);
            }else if(per->devolvermnunicion()==2){
                guadanya2.setPosition(260,670);
            }else if(per->devolvermnunicion()==1){
                guadanya1.setPosition(260,670);
            }else if(per->devolvermnunicion()==0){
                guadanya0.setPosition(260,670);
            }

            if(per->devolvervariableulti()==true)
            {
                enulti.setPosition(200,670);
                ojos.setPosition(160,615);
                ojos2.setPosition(195,615);
                

            }
            else
            {

                if(contadoralmas==0){
                    ulti0.setPosition(200,670);

                }else if(contadoralmas==1){
                    ulti1.setPosition(200,670);
                }else if(contadoralmas==2){
                    ulti2.setPosition(200,670);
                }else if(contadoralmas==3){
                    ulti3.setPosition(200,670);
                }else if(contadoralmas==4){
                    ulti4.setPosition(200,670);
                }
                else if(contadoralmas==5){
                    ulti5.setPosition(200,670);
                }
                else if(contadoralmas==6){
                    ulti6.setPosition(200,670);
                }
                else if(contadoralmas==7){
                    ulti7.setPosition(200,670);
                }else if(contadoralmas==8){
                    ulti8.setPosition(200,670);
                }else if(contadoralmas==9){
                    ulti9.setPosition(200,670);
                }
                else if(contadoralmas==10){
                    ulticargada.setPosition(200,670);
                     efecto.setPosition(200,655);
                   
                }

            }


        }
         if(nivel==1 || nivel==2 || nivel==3 || nivel==4 || nivel==5 ){
            cora_6.setPosition(Motor::Instance()->getVista().getCenter().x-620,  Motor::Instance()->getVista().getCenter().y +315);
            cora_7.setPosition(Motor::Instance()->getVista().getCenter().x-590,  Motor::Instance()->getVista().getCenter().y +315);
            cora_8.setPosition(Motor::Instance()->getVista().getCenter().x-560,  Motor::Instance()->getVista().getCenter().y +315);
            cora_9.setPosition(Motor::Instance()->getVista().getCenter().x-530,  Motor::Instance()->getVista().getCenter().y +315);
            cora_10.setPosition(Motor::Instance()->getVista().getCenter().x-500,  Motor::Instance()->getVista().getCenter().y +315);

            cora_1.setPosition(Motor::Instance()->getVista().getCenter().x-632,  Motor::Instance()->getVista().getCenter().y +315);
            cora_2.setPosition(Motor::Instance()->getVista().getCenter().x-602,  Motor::Instance()->getVista().getCenter().y +315);
            cora_3.setPosition(Motor::Instance()->getVista().getCenter().x-572,  Motor::Instance()->getVista().getCenter().y +315);
            cora_4.setPosition(Motor::Instance()->getVista().getCenter().x-542,  Motor::Instance()->getVista().getCenter().y +315);
            cora_5.setPosition(Motor::Instance()->getVista().getCenter().x-512,  Motor::Instance()->getVista().getCenter().y +315); 


            enemigosrestantes.setPosition(Motor::Instance()->getVista().getCenter().x+375,  Motor::Instance()->getVista().getCenter().y -350); 


            if(per->devolvermnunicion()==5){
                guadanya5.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }else if(per->devolvermnunicion()==4){
                guadanya4.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }else if(per->devolvermnunicion()==3){
                guadanya3.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }else if(per->devolvermnunicion()==2){
                guadanya2.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }else if(per->devolvermnunicion()==1){
                guadanya1.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }else if(per->devolvermnunicion()==0){
                guadanya0.setPosition(Motor::Instance()->getVista().getCenter().x-400,  Motor::Instance()->getVista().getCenter().y +295);
            }

            

            if(per->devolvervariableulti()==true)
            {
                enulti.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                ojos.setPosition(Motor::Instance()->getVista().getCenter().x-490,  Motor::Instance()->getVista().getCenter().y +240);
                ojos2.setPosition(Motor::Instance()->getVista().getCenter().x-455,  Motor::Instance()->getVista().getCenter().y +240);

            }
            else
            {

                if(contadoralmas==0)
                {
                    ulti0.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);

                }else if(contadoralmas==1){
                    ulti1.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }else if(contadoralmas==2){
                    ulti2.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }else if(contadoralmas==3){
                    ulti3.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }else if(contadoralmas==4){
                    ulti4.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }
                else if(contadoralmas==5){
                    ulti5.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }
                else if(contadoralmas==6){
                    ulti6.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }
                else if(contadoralmas==7){
                    ulti7.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }else if(contadoralmas==8){
                    ulti8.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }else if(contadoralmas==9){
                    ulti9.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                }
                else if(contadoralmas==10){
                    ulticargada.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +295);
                    efecto.setPosition(Motor::Instance()->getVista().getCenter().x-450,  Motor::Instance()->getVista().getCenter().y +285);
                   
                }
                
            }
            



        }

        if(per->devolvermnunicion()==5){
            Motor::Instance()->ventana().draw(guadanya5);
        }else if(per->devolvermnunicion()==4){
            Motor::Instance()->ventana().draw(guadanya4);
        }else if(per->devolvermnunicion()==3){
            Motor::Instance()->ventana().draw(guadanya3);
        }else if(per->devolvermnunicion()==2){
            Motor::Instance()->ventana().draw(guadanya2);
        }else if(per->devolvermnunicion()==1){
            Motor::Instance()->ventana().draw(guadanya1);
        }else if(per->devolvermnunicion()==0){
            Motor::Instance()->ventana().draw(guadanya0);
        }


            if(per->devolvervariableulti()==true)
            {
                Motor::Instance()->ventana().draw(enulti);


                    if(animationtime2.getElapsedTime().asSeconds() > 0.2f) 
                    {
                        if(anime2.left >=700)
                        {
                            
                            anime2.left = 0;
                            
                            anime2.top += 100;
                            

                        }else{
                            
                            anime2.left +=100;
                            anime2.top = 0;
                            

                        }

                        

                        ojos.setTextureRect(anime2);
                        ojos2.setTextureRect(anime2);
                        animationtime2.restart();



                    }
                Motor::Instance()->ventana().draw(ojos);
                Motor::Instance()->ventana().draw(ojos2);

            }
            else
            {

                if(contadoralmas==0){
                Motor::Instance()->ventana().draw(ulti0);

                }else if(contadoralmas==1){
                    Motor::Instance()->ventana().draw(ulti1);
                }else if(contadoralmas==2){
                    Motor::Instance()->ventana().draw(ulti2);
                }else if(contadoralmas==3){
                    Motor::Instance()->ventana().draw(ulti3);
                }else if(contadoralmas==4){
                    Motor::Instance()->ventana().draw(ulti4);
                }
                else if(contadoralmas==5){
                    Motor::Instance()->ventana().draw(ulti5);
                }
                else if(contadoralmas==6){
                    Motor::Instance()->ventana().draw(ulti6);
                }
                else if(contadoralmas==7){
                Motor::Instance()->ventana().draw(ulti7);
                }else if(contadoralmas==8){
                    Motor::Instance()->ventana().draw(ulti8);
                }else if(contadoralmas==9){
                    Motor::Instance()->ventana().draw(ulti9);
                }
                else if(contadoralmas==10){
                    Motor::Instance()->ventana().draw(ulticargada);

                    if(animationtime.getElapsedTime().asSeconds() > 0.2f) 
                    {
                        if(anime.left >=720)
                        {
                            
                            anime.left = 0;
                            
                            anime.top = 0;
                            

                        }else{
                            
                            anime.left +=48;
                            anime.top = 0;
                            

                        }

                        

                        efecto.setTextureRect(anime);
                        animationtime.restart();



                    }                    


                    Motor::Instance()->ventana().draw(efecto);
                }

            }
        
        if(nivel==1 || nivel==2 || nivel==3 || nivel==4 || nivel==5 ){

            totalenemigos=enemigos.size()+enemigos2.size();
            std::ostringstream os;
            os << totalenemigos;
            
            enemigosrestantes.setString("Enemigos restantes:"+os.str());
            //cout  << os.str();
            Motor::Instance()->ventana().draw(enemigosrestantes);

        }

            sf::String s= "";
            if(per->getPuertecita()==true){
                s= "Hacks desactivados";
            }
            else{
                s= "Hacks activados";
            }
            sf::Text texto(s, fuente, 22);
	        texto.setOrigin(texto.getLocalBounds().width/2, 0);
	        texto.setPosition(Motor::Instance()->getVista().getCenter().x-250,  Motor::Instance()->getVista().getCenter().y +315);
            Motor::Instance()->ventana().draw(texto);


            if(per->getVida()==1){
                Motor::Instance()->ventana().draw(cora_1);
                s1.play();
            }
            if(per->getVida()==2){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                s1.play();
            }
            if(per->getVida()==3){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2); 
                s1.play();
            }
            if(per->getVida()==4){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7); 
                s1.play();
            }
            if(per->getVida()==5){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3); 
                s1.play();
           }
            if(per->getVida()==6){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3);
                Motor::Instance()->ventana().draw(cora_8); 
                s1.play();
           }
            if(per->getVida()==7){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3);
                Motor::Instance()->ventana().draw(cora_8);
                Motor::Instance()->ventana().draw(cora_4); 
                s1.play();
           }
            if(per->getVida()==8){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3);
                Motor::Instance()->ventana().draw(cora_8);
                Motor::Instance()->ventana().draw(cora_4);
                Motor::Instance()->ventana().draw(cora_9); 
                s1.play();
           }
            if(per->getVida()==9){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3);
                Motor::Instance()->ventana().draw(cora_8);
                Motor::Instance()->ventana().draw(cora_4);
                Motor::Instance()->ventana().draw(cora_9);
                Motor::Instance()->ventana().draw(cora_5);
                s1.play();
            }
            if(per->getVida()==10){
                Motor::Instance()->ventana().draw(cora_1);
                Motor::Instance()->ventana().draw(cora_6);
                Motor::Instance()->ventana().draw(cora_2);
                Motor::Instance()->ventana().draw(cora_7);
                Motor::Instance()->ventana().draw(cora_3);
                Motor::Instance()->ventana().draw(cora_8);
                Motor::Instance()->ventana().draw(cora_4);
                Motor::Instance()->ventana().draw(cora_9);
                Motor::Instance()->ventana().draw(cora_5);
                Motor::Instance()->ventana().draw(cora_10);
                s1.play();
            }

    }
   
    checkhitboxBOSS();
    checkhitboxes();
    checkhitboxestiradores();
    per->iteraranim();
}


///////////////////////////////////////////

Map* Nivel::getMapa(){
    return this->N;
}

Interpolacion* Nivel::getInterpolacion(){
    return this->interpolacion;
}

int Nivel::getNivel(){
    return this->nivel;
}

int Nivel::getEstado(){
    return est;
}

void Nivel::setEstado(int n){
    this->est= n;
}

Personaje* Nivel::getPersonaje() {
    return this->per;
}

bool Nivel::getFinal() {
    return this->final;
}

bool Nivel::getRunapillada() {
    return this->runapillada;
}

void Nivel::setFinal(){
    this->final= false;
}

void  Nivel::destruirenemigo(int posicion, int tipo)
{
    if(contadoralmas==10){
        contadoralmas=10;
    }else{
            contadoralmas+=1;

    }

    per->sumarmunicion();



    if(tipo==0)
    {
        Enemigo *malo =NULL;
        malo = enemigos[posicion];
        enemigos.erase(enemigos.begin() + posicion);
        delete malo;
        malo = NULL;
        
        per->sumavida(1);

        cout << "vida personaje:" << per->getVida() << endl;

        cout << " Alma absorbida" << endl;
        

    }else if(tipo==1)
    {
        Enemigo2 *malo2 =NULL;
        malo2 = enemigos2[posicion];
        enemigos2.erase(enemigos2.begin() + posicion);
        delete malo2;
        malo2 = NULL;

        per->sumavida(1);

        cout << "vida personaje:" << per->getVida() << endl;
        

        cout << " Alma tirador absorbida" << endl;


    }
    else{

    }


}

void Nivel::gastaralmas(){
    contadoralmas=0;
}



void Nivel::destruyenemigostemporal(){


    enemigos.clear();
    enemigos2.clear();
   
    
    
    /*

    for (unsigned int i=0;i<enemigos.size();i++)
    {
        
        
        Enemigo *malo =NULL;
        malo = enemigos[i];
        
        enemigos.erase(enemigos.begin() + i);
        
        delete malo;
        malo = NULL;
        if(i==enemigos.size()-1){
            enemigosdestruidos=true;
        }


    }


    cout << "despues de bucle:" << enemigos.size() <<endl;

    for(unsigned int j=0;j<enemigos2.size();j++){
        Enemigo2 *malo2 =NULL;
        malo2 = enemigos2[j];
        enemigos2.erase(enemigos2.begin() + j);
        delete malo2;
        malo2 = NULL;

        if(j==enemigos2.size()-1){
            enemigosdestruidos2=true;
        }

    }*/

}

void Nivel::destruirruantemporal()
{
        delete this->runafisica;
        this->runafisica = NULL;
        
        if(runafisica == NULL)
        {
                cout << "Runa borrada del temporal" <<endl;
        }
    

}

void Nivel::deleteJefe(){
    delete jefe;
}

void Nivel::deleteJefeNpc(){
    delete jefeNpc;
}

void Nivel::creaEnemigos()
{
    
    if(this->nivel== 1)
    {

        Enemigo *ene1 = new Enemigo(600,4540);
        enemigos.push_back(ene1);
        Enemigo *ene2 = new Enemigo(1000,4005);
        enemigos.push_back(ene2);
        Enemigo *ene3 = new Enemigo(236,3035);
        enemigos.push_back(ene3);

        Enemigo *ene4 = new Enemigo(950,2210);
        enemigos.push_back(ene4);



        Enemigo *ene6 = new Enemigo(860,645);
        enemigos.push_back(ene6);

        Enemigo *ene7 = new Enemigo(600,345);
        enemigos.push_back(ene7);

        Enemigo2 *ene8 = new Enemigo2(950,3585);
        enemigos2.push_back(ene8);





    }else if(this->nivel==2)
    {
        Enemigo *ene10 = new Enemigo(550,4460);
        enemigos.push_back(ene10);

        Enemigo *ene11 = new Enemigo(1100,3490);
        enemigos.push_back(ene11);

        Enemigo *ene12 = new Enemigo(550,3110);
        enemigos.push_back(ene12);

        Enemigo2 *ene13 = new Enemigo2(550,3830);
        enemigos2.push_back(ene13);


        Enemigo2 *ene14 = new Enemigo2(782,2780);
        enemigos2.push_back(ene14);

        Enemigo2 *ene15 = new Enemigo2(782,2400);
        enemigos2.push_back(ene15);

        Enemigo *ene16 = new Enemigo(580,189);
        enemigos.push_back(ene16);


    }else if(nivel==3){

        Enemigo *ene17 = new Enemigo(423,4540,10,2);
        enemigos.push_back(ene17);

        Enemigo2 *ene18 = new Enemigo2(600,2780);
        enemigos2.push_back(ene18);

        Enemigo2 *ene19 = new Enemigo2(600,2560);
        enemigos2.push_back(ene19);

        Enemigo *ene20 = new Enemigo(780,1690,10,2);
        enemigos.push_back(ene20);

        Enemigo *ene21 = new Enemigo(990,1163);
        enemigos.push_back(ene21);

        Enemigo2 *ene22 = new Enemigo2(446,900,10,2);
        enemigos2.push_back(ene22);



        Enemigo *ene23 = new Enemigo(300,719);
        enemigos.push_back(ene23);


    }
    else if(nivel==4){

        Enemigo *ene24 = new Enemigo(500,2140);
        enemigos.push_back(ene24);

        Enemigo *ene25 = new Enemigo(1000,2140,10,2);
        enemigos.push_back(ene25);


        Enemigo2 *ene26 = new Enemigo2(1040,1890,10,2);
        enemigos2.push_back(ene26);

        Enemigo *ene27 = new Enemigo(1000,708);
        enemigos.push_back(ene27);

        Enemigo *ene28 = new Enemigo(150,560,10,2);
        enemigos.push_back(ene28);

        Enemigo *ene29 = new Enemigo(1130,414,10,2);
        enemigos.push_back(ene29);
        
    }else if(nivel==5)
    {
        Enemigo *ene30 = new Enemigo(600,4315,10,2);
        enemigos.push_back(ene30);

        Enemigo *ene31 = new Enemigo(900,4387,10,2);
        enemigos.push_back(ene31);

        Enemigo2 *ene32 = new Enemigo2(400,3390,10,2);
        enemigos2.push_back(ene32);

        Enemigo2 *ene33 = new Enemigo2(600,3830,10,2);
        enemigos2.push_back(ene33);


        Enemigo *ene34 = new Enemigo(900,2666,10,2);
        enemigos.push_back(ene34);

        Enemigo *ene344 = new Enemigo(412,2666,10,2);
        enemigos.push_back(ene344);


        Enemigo *ene35 = new Enemigo(200,1550,10,2);
        enemigos.push_back(ene35);


        Enemigo2 *ene36 = new Enemigo2(1032,1500,10,2);
        enemigos2.push_back(ene36);



    }


}

void Nivel::checkhitboxBOSS(){
    if(per->compruebaintenemigo(jefe->hitbox().getGlobalBounds())){
        jefe->heridaJefe(per->getdanio());
    }
}

void Nivel::checkhitboxes(){
    for(unsigned int i = 0; i<enemigos.size(); i++){
        if(per->compruebaintenemigo(enemigos[i]->boundingboxe) && enemigos[i]->getVida()>0){
            enemigos[i]->restavida(i,getPersonaje()->getdanio());
        }
    }  
}

void Nivel::checkhitboxestiradores(){
    for(unsigned int i = 0; i<enemigos2.size(); i++){
        if(per->compruebaintenemigo(enemigos2[i]->getSprite().getGlobalBounds())){
            enemigos2[i]->restavida(i,getPersonaje()->getdanio());
        }
    }  
}

std::vector<Enemigo2*> Nivel::getEnemigos2(){
    return this->enemigos2;
}

std::vector<Enemigo*> Nivel::getEnemigos(){
    return this->enemigos;
}



int Nivel::getNum(){
    return nivel;
}

void Nivel::cojerRuna()
{

        runapillada=true;



}


void Nivel::crearunas(){

    runapillada=false;

    if(this->nivel==1)
    {
        cout << "runa1creada";
        runafisica = new Runa(602,100);

    }
    else if(this->nivel==2){

        cout << "runa2creada";

        runafisica = new Runa(190,230);

    }
    else if(this->nivel==3){

        cout << "runa3creada";

        runafisica = new Runa(500,460);

    }
    else if(this->nivel==4){

        cout << "runa4creada";

        runafisica = new Runa(1202,240);

    }

}

void Nivel::borrarRuna(){
    
       
        delete this->runafisica;
        this->runafisica = NULL;
        
        if(runafisica == NULL){
                cout << "Runa borrada" <<endl;
        }

        runapillada=true;
}

void Nivel::reAparece(){
    destruyenemigostemporal();
    if(this->runafisica!=NULL){
        destruirruantemporal();
    }
    creaEnemigos();
    crearunas();
}

Jefe* Nivel::getJefe(){
    return this->jefe;
}

JefeNPC* Nivel::getJefeNPC(){
    return this->jefeNpc;
}

int Nivel::returnalmastotal(){
    return this->contadoralmas;
}


