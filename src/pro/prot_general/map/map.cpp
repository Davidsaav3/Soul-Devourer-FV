#include "map.h"
#include "../motor/motor.h"
#include "../estado/estado.h"
#include "../nivel/nivel.h"
#include "../personaje/personaje.h"
#include <SFML/Graphics.hpp>

/*
#using	<System.xml.dll>
using namespace System::Xml;
*/


Map::Map(int nivel,clock_t reloj) {
    std::cout << " [MAPA CREADO] Nivel:" << nivel <<std::endl;
    cont_xd= 10;
    ancho = 0;
    alto = 0;
    ancho_tile = 0;
    alto_tile = 0;
    num_capas = 0;
    temp= reloj;
    agua= true;
    fuego= true;

    if(!txt_png.loadFromFile("resources/Mapa/M.png")){
        std::cout << "Probelma obtencion png" <<std::endl;
    }

    if(nivel==0){
        if(!txt_tmx.LoadFile("resources/Mapa/0/M0.tmx")){
            std::cout << "Probelma obtencion tmx 0" <<std::endl;
        }
    }
    if(nivel==1){
        if(!txt_tmx.LoadFile("resources/Mapa/1/M1.tmx")){
            std::cout << "Probelma obtencion tmx 1" <<std::endl;
        }
    }
    if(nivel==2){
        if(!txt_tmx.LoadFile("resources/Mapa/2/M2.tmx")){
            std::cout << "Probelma obtencion tmx 2" <<std::endl;
        }
    }
    if(nivel==3){
        if(!txt_tmx.LoadFile("resources/Mapa/3/M3.tmx")){
            std::cout << "Probelma obtencion tmx 3.1" <<std::endl;
        }
    }
    if(nivel==4){
        if(!txt_tmx.LoadFile("resources/Mapa/3.1/M3.1.tmx")){
            std::cout << "Probelma obtencion tmx 3.1" <<std::endl;
        }
    }
    if(nivel==5){
        if(!txt_tmx.LoadFile("resources/Mapa/4/M4.tmx")){
            std::cout << "Probelma obtencion tmx 4" <<std::endl;
        }
    }
    if(nivel==6){
        if(!txt_tmx.LoadFile("resources/Mapa/5/M5.tmx")){
            std::cout << "Probelma obtencion tmx 5" <<std::endl;
        }
    }

    //crearMapa()
    inicializarMapa();
    cargarMapa();
}

Map::~Map() {
}
    /*delete bloque;
    delete sprite_bloque;
    delete mapa; 
    delete tile;
    delete data; 
    delete sprite;*/

    /*Destructor
    ****sprite_bloque.erase(std::remove(****sprite_bloque.begin(), ****sprite_bloque.end()), ****sprite_bloque.end()); 
    std::remove(****sprite_bloque);
    *mapa->RemoveChild(*mapa); 
    *tile->RemoveChild(*tile);
    *data->RemoveChild(*data); 
    delete *sprite; */



// CARGAMOS MAPA /////////////
void Map::inicializarMapa() {

    mapa= txt_tmx.FirstChildElement("map");

    //Dimension mapa //Dimension tile
    mapa->QueryIntAttribute("width",&ancho);
    mapa->QueryIntAttribute("height",&alto);
    mapa->QueryIntAttribute("tilewidth",&ancho_tile);
    mapa->QueryIntAttribute("tileheight",&alto_tile);

    //Imprimo cositas
    std::cout << "ancho:"  << ancho <<std::endl;
    std::cout << "alto:"  << alto <<std::endl;
    std::cout << "ancho_tile:"  << ancho_tile <<std::endl;
    std::cout << "alto_tile:"  << alto_tile <<std::endl;

   // Declaro variables para recorrer 
    int tiles_columna = txt_png.getSize().y / alto_tile;
    int tiles_fila = txt_png.getSize().x / ancho_tile;
    std::cout << "tiles_columna:" << tiles_columna <<std::endl;
    std::cout << "tiles_fila:" << tiles_fila <<std::endl;

    //inicializo vector de tiles en png 
    TiXmlElement *capa= mapa->FirstChildElement("layer");
    bloque = new int **[num_capas];
    sprite_bloque = new sf::Sprite***[num_capas];
    sprite= new sf::Sprite[tiles_fila*tiles_columna];
    num= capa->Attribute("id");
    num_capas= std::stoi(num); 
    std::cout << "C:" << num_capas <<std::endl;
    
    // obtener tiles de png
    int n = 0; 
    for(int y = 0; y< tiles_columna; y++){
        for(int x = 0; x < tiles_fila; x++){

            // cargamos los sprites uno a uno
            sprite[n].setTexture(txt_png);
            // cargamos cuadrados de sprite
            sprite[n].setTextureRect(sf::IntRect(x*ancho_tile, y*alto_tile, ancho_tile, alto_tile ));
            n++;   

        }
    }


    // inicializamos bloque y sprite_bloque
    for(int z = 0 ; z < num_capas; z++){ // capas
        bloque[z] = new int*[alto]; 
        sprite_bloque[z] = new sf::Sprite**[alto];

        for(int y = 0; y < alto; y++){ //alto
            bloque[z][y] = new int[ancho]; 
            sprite_bloque[z][y] = new sf::Sprite*[ancho];

            for(int x = 0; x <ancho; x++){ //ancho
                sprite_bloque[z][y][x] = new sf::Sprite; 
                // necesita un puntero por cada dismension de direccionado
            }
        }
    }


    // dentro de bloque meto los numeros
    for(int z= 0; capa ; z++){
        data= capa->FirstChildElement("data");
        tile= data->FirstChildElement("tile"); //obtenemos tile

        for(int n= 0; tile ; n++){
            for(int y = 0; y < alto; y++){
                for(int x = 0; x < ancho; x++){ //recorremos
                    tile->Attribute("gid", &bloque[z][y][x]); //se le pasa espacio de memoria
                    //gid= tile->Attribute("gid");
                    //bloque[z][y][x]=  std::stoi(gid);
                    tile= tile->NextSiblingElement("tile");
                }
            }
        }
        // Siguiente capa
        capa= capa->NextSiblingElement("layer"); //avamzamos a la siguiente capa
    }
}
    

// DIBUJAMOS MAPA//
void Map::cargarMapa(){
    sf::IntRect rec;

    // Insertamos tiles 
    for(int z = 0; z< num_capas; z++){
        
        for(int y = 0; y <alto ; y++){
            for(int x = 0; x <ancho; x++){ //recorremos array 3d

                if(bloque[z][y][x]>0 && bloque[z][y][x]<ancho*alto){
                    // obtenemos rect a partir de el bloque correspondiente
                    if(bloque[z][y][x]==44 || bloque[z][y][x]==8){
                                  
                        if(bloque[z][y][x]==44/* &&this->temp-ant==1000*/){ 
                            if(agua==false){
                                //std::cout << "----------------------------------" << cont_xd <<std::endl;
                                rec= sprite[bloque[z][y][x]-1].getTextureRect();
                            }
                            if(agua==true){
                                //std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << cont_xd <<std::endl;
                                rec= sprite[143].getTextureRect();
                            }
                        }                
                        if(bloque[z][y][x]==8/* && this->temp-ant==1000*/){ 
                        
                            if(agua==false){
                                rec= sprite[bloque[z][y][x]-1].getTextureRect();
                            }
                            else{ 
                                rec= sprite[155].getTextureRect();
                            }
                        }   
                    }
                    else{
                        rec= sprite[bloque[z][y][x]-1].getTextureRect();//156
                    }
                    // generamos el sprite a partir de la imagen png y su rect
                    sprite_bloque[z][y][x] = new sf::Sprite(txt_png,rec);
                    // colocamos la posicion de impresion
                    sprite_bloque[z][y][x]->setPosition(x*80, y*75);
                }
            }
        }
    }
if(cont_xd==10){
    if(agua==true){
        agua= false;
    }
    else{
        agua= true;
    }
cont_xd= 0;
} 
cont_xd= cont_xd+1;

}

//

void Map::dibujarMapa(double N, int capa){
    cargarMapa();
    
    // bucle que imprime
        for(int y=0; y < alto; y++){
            for(int x=0;x < ancho; x++){
                //std::cout << "-->" << sprite_bloque[capa][y][x];

                if(sprite_bloque[capa][y][x]!=NULL){
                    // simplemente dibuja (enviamos datos)
                    if(bloque[capa][y][x]!=133 && bloque[capa][y][x]!=145){          
                        Motor::Instance()->dibuja(*sprite_bloque[capa][y][x]);  
                     
                    }
                }   
            }
        } 

    ant= this->temp;  
}


bool Map::colision(sf::Sprite *personaje, int nivel){
    boundingbox=Nivel::Instance()->getPersonaje()->boundingbox;
    col= false;
    int num= 0;
    if(nivel==4 || nivel==5){
        num= 1;
    }

    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(boundingbox.intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]!=20 && bloque[num][y][x]!=32){
                        col= true;
                    }
                }   
            }
        }
    }

    // CUIDADO AQUI COLISION MALA PRUEBA ALEXSU
    //col= false;
    // CUIDADO AQUI COLISION MALA PRUEBA ALEXSU
     
    return col;
}

bool Map::colisiongravedad(sf::Sprite *personaje, int nivel)
{
    boundingbox=Nivel::Instance()->getPersonaje()->boundingbox2;
    col= false;
    int num= 0;

    float puntox=0;
    float puntoy=0;

    if(nivel==4 || nivel==5){
        num= 1;
    }

    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){

                puntox=sprite_bloque[num][y][x]->getPosition().x;
                puntoy=sprite_bloque[num][y][x]->getPosition().y;
                
                /*
                if(boundingbox.contains(puntox,puntoy)){
                    if(bloque[num][y][x]!=20 && bloque[num][y][x]!=32){
                        col= true;
                    }
                }*/

                
                if(boundingbox.intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]!=20 && bloque[num][y][x]!=32){
                        col= true;
                    }
                }
            }
        }
    }

    // CUIDADO AQUI COLISION MALA PRUEBA ALEXSU
    //col= false;
     // CUIDADO AQUI COLISION MALA PRUEBA ALEXSU
     
    return col;


}


int Map::next(sf::Sprite *personaje, int nivel){
    boundingbox=Nivel::Instance()->getPersonaje()->boundingbox;
    int col= 0;
    int num= 2;
    if(nivel==4 || nivel==5){
        num= 0;
    }

    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[2][y][x]!= NULL){
                        
                if(boundingbox.intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==46 || bloque[num][y][x]==58){
                        col= 1;
                    }
                    if(bloque[num][y][x]==70 || bloque[num][y][x]==82){
                        col= 2;
                    }
                }       
            }
        }
    }
    return col;
}


bool Map::colisionRectangulo(sf::RectangleShape rectangulo)
{
        for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[2][y][x]!= NULL){
                        
                if(rectangulo.getGlobalBounds().intersects(sprite_bloque[2][y][x]->getGlobalBounds())){
                    //std::cout << "intersects" ;
                    col= true;
                }
                else{
                    col= false;
                }       
            }
        }
    }
    return col;



}


int Map::colisionproyectil(){
    int nivel = Nivel::Instance()->getNivel();
    
    int numero=0;

    if(nivel==4 || nivel==5)
    {
        numero=1;
    }

    
            for(int y = 0; y< alto;y++){
                for(int x = 0; x< ancho; x++){
                    if(sprite_bloque[numero][y][x]!= NULL){
                        
                            for(unsigned int j = 0 ; j < Nivel::Instance()->getEnemigos2().size(); j++){
                                for(unsigned int i = 0; i <Nivel::Instance()->getEnemigos2()[j]->getProyectiles().size();i++){
                                   if(Nivel::Instance()->getEnemigos2()[j]->getProyectiles()[i]->gethitboxproyectil().getGlobalBounds().intersects(sprite_bloque[numero][y][x]->getGlobalBounds()) || Nivel::Instance()->getEnemigos2()[j]->getProyectiles()[i]->proyectilSprite().getPosition().x<0){
                                       cout << "se borra proyectilizquierda";
                                        //cout << "colsiona" <<endl;
                                        colProyect =  true;  
                                        setAux(i);
                                        return colP = 1;
                                        
                                    
                                    }
                                    
                                    else{
                                        colP = 0;
                                        colProyect = false;
                                    }
                               }     
                            }
                                     
                    }
                }
            }
    return colP;


}


int Map::colisionproyectil2(){
    int nivel = Nivel::Instance()->getNivel();

    //cout << "compruebo derecha" <<endl;
    
    int numero=0;

    if(nivel==4 || nivel==5)
    {
        numero=1;

    }

    
            for(int y = 0; y< alto;y++){
                for(int x = 0; x< ancho; x++){
                    if(sprite_bloque[numero][y][x]!= NULL){
                        
                            for(unsigned int j = 0 ; j < Nivel::Instance()->getEnemigos2().size(); j++){
                                for(unsigned int i = 0; i <Nivel::Instance()->getEnemigos2()[j]->getProyectiles().size();i++){
                                   if(Nivel::Instance()->getEnemigos2()[j]->getProyectiles()[i]->gethitboxproyectil().getGlobalBounds().intersects(sprite_bloque[numero][y][x]->getGlobalBounds()) || Nivel::Instance()->getEnemigos2()[j]->getProyectiles()[i]->proyectilSprite().getPosition().x>1200 || Nivel::Instance()->getEnemigos2()[j]->getProyectiles()[i]->proyectilSprite().getPosition().x < 0){
                                       if(bloque[numero][y][x]!=20 && bloque[numero][y][x]!=32){
                                        
                                        
                                        //cout << "colsiona" <<endl;
                                        colProyect =  true;  
                                        setAux(i);
                                        return colP = 1;

                                       }

                                        
                                    
                                    }
                                    
                                    else{
                                        colP = 0;
                                        colProyect = false;
                                    }
                               }     
                            }
                                     
                    }
                }
            }
    return colP;


}

int Map::getAux(){
    return aux;
}

void Map::setAux(int pos){
    aux = pos;
}


bool Map::escalera(sf::Sprite *personaje, int nivel){
    col= false;
    int num= 0;
    if(nivel==4 || nivel==5){
        num= 1;
    }

    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(personaje->getGlobalBounds().intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==20 || bloque[num][y][x]==32){
                        col= true;
                    }
                }   
            }
        }
    }
    return col;
}


bool Map::rampaDerecha(sf::Sprite *personaje, int nivel){
    col= false;
    int num= 0;
    if(nivel==4 || nivel==5){
        num= 1;
    }
    //30 43 64 76 106
    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(personaje->getGlobalBounds().intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==30 || bloque[num][y][x]==43  || bloque[num][y][x]==64  || bloque[num][y][x]==76 || bloque[num][y][x]==106){
                        col= true;
                    }
                }   
            }
        }
    }
    return col;
}

int Map::llave(sf::Sprite *personaje, int nivel){
    int col= 0;
    int num= 0;
    
    //55 67 92 99
    //Amarillo Naranja Azul Verde
    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(personaje->getGlobalBounds().intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==55){
                        col= 1;
                    }
                    if(bloque[num][y][x]==67){
                        col= 2;
                    }
                    if(bloque[num][y][x]==92){
                        col= 3;
                    }
                    if(bloque[num][y][x]==99){
                        col= 4;
                    }
                }   
            }
        }
    }
    return col;
}


bool Map::rampaIzquierda(sf::Sprite *personaje, int nivel){
    col= false;
    int num= 0;
    if(nivel==4 || nivel==5){
        num= 1;
    }
    //6 9 11 31 40 96 
    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(personaje->getGlobalBounds().intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==6 || bloque[num][y][x]==9  || bloque[num][y][x]==11  || bloque[num][y][x]==31  || bloque[num][y][x]==40 || bloque[num][y][x]==96){                          col= true;
                    }
                }   
            }
        }
    }
    return col;
}

bool Map::lava(sf::Sprite *personaje, int nivel){
    bool col= false;
    int num= 2;

    for(int y = 0; y< alto;y++){
        for(int x = 0; x< ancho; x++){
            if(sprite_bloque[num][y][x]!= NULL){
                        
                if(personaje->getGlobalBounds().intersects(sprite_bloque[num][y][x]->getGlobalBounds())){
                    if(bloque[num][y][x]==139){          
                     col= true;
                    }
                }   
            }
        }
    }
    return col;
}


/*map=txt_tmx.FirstChildElement("map");
m1_png.loadFromFile("resources/Mapa/M1.png");

try{
    XmlTextReader* m1_tmx = new XmlTextReader ("resources/Mapa/M1.tmx");
    XmlTextReader* m1_tsx = new XmlTextReader ("resources/Mapa/M1.tsx");
    while (xmlreader->Read()){

    }
}
catch (Exception* ex){
}
__  finally {

}*/

