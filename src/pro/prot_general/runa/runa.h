#pragma once

#include <SFML/Graphics.hpp>


class Runa{
  
    private:
     
      bool deleted;
      sf::Texture texVida;
      sf::RectangleShape colisionjugador;
      sf::Sprite _sprite;
      sf::Vector2i _Source; // Declaramos el source ( SPrite sheet Crop)
      enum _Direction { Down, Left, Right, Up}; 

    public:  

        Runa();
        Runa(int posx, int posy);

        ~Runa();

       void update(sf::Time delta, float tiempo);
       void render();
       void colisionPersonaje();
       //enemigo(sf::Texture&);
       sf::Sprite getSprite() ;

       void borrarRuna();
      
       void dibujarRuna();

       

};

