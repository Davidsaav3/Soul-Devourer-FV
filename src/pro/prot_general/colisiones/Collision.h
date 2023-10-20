#include <SFML/Graphics.hpp>
#include <ctime>

class Collision
{
    public:
        Collision(sf::RectangleShape& body);
        ~Collision();
        void Move(float dx, float dy) {body.move(dx,dy);}
        
        bool CheckCollision(Collision& other,sf::Vector2f& direction,float push);
        
        sf::Vector2f GetPosition () {return body.getPosition();}
        sf::Vector2f GetHalfSize () {return body.getSize()/2.0f;}


        private:
        sf::RectangleShape& body;
};
//quitar esto no sirve