#include "colision.h"

bool Colision::isColision(Colision& obj) const {
    return getBounds().intersects(obj.getBounds());
}