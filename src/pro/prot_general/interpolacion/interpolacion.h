#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../estado/estado.h"
#include "../menu/menu.h"
#include "../mapa/mapa.h"
#include "../controles/controles.h"
#include "../desarrolladores/desarrolladores.h"
#include "../final/final.h"
#include "../pausa/pausa.h"
#include "../pierde/pierde.h"
#include "../gana/gana.h"

class Interpolacion{
    private:
        double ActX;
        double ActY;
        double PasX;
        double PasY;

        double ActX_jefe;
        double ActY_jefe;
        double PasX_jefe;
        double PasY_jefe;

        double ActX_enemigo1;
        double ActY_enemigo1;
        double PasX_enemigo1;
        double PasY_enemigo1;

        double ActX_enemigo2;
        double ActY_enemigo2;
        double PasX_enemigo2;
        double PasY_enemigo2;
    public:
        Interpolacion();
        ~Interpolacion();

        void setPos(int niv);
        double getActX();
        double getActY();
        double getPasX();
        double getPasY();

        void setActX(double x);
        void setActY(double y);

        //
        double getActX_jefe();
        double getActY_jefe();
        double getPasX_jefe();
        double getPasY_jefe();

        void setActX_jefe(double x);
        void setActY_jefe(double y);

        //
        double getActX_enemigo1();
        double getActY_enemigo1();
        double getPasX_enemigo1();
        double getPasY_enemigo1();

        void setActX_enemigo1(double x);
        void setActY_enemigo1(double y);

        //
        double getActX_enemigo2();
        double getActY_enemigo2();
        double getPasX_enemigo2();
        double getPasY_enemigo2();

        void setActX_enemigo2(double x);
        void setActY_enemigo2(double y);
};
