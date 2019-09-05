#include "geom.h"

Geom::Geom(){

}

double Geom::dist(double ax, double ay, double bx, double by){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
