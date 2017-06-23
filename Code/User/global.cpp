#include "global.h"

Global::Global()
{

}


bool Global::IsPosInsidePointRadius(QPoint &_p1, QPoint &_p2, float _p2Radius)
{
    float distance = sqrt( pow((_p1.x() - _p2.x()),2) + pow((_p1.y() - _p2.y()),2) );
    if(distance < _p2Radius)
        return true;
    return false;
}
