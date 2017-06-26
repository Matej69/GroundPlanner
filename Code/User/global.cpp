#include "global.h"

Global::Global()
{

}


bool Global::IsPosInsidePointRadius(QPoint &_p1, QPoint &_p2, float _p2Radius)
{
    float distance = sqrt( pow(abs(_p1.x() - _p2.x()),2) + pow(abs(_p1.y() - _p2.y()),2) );
    if(distance < _p2Radius)
        return true;
    return false;
}

QPoint Global::GetMiddlePoint(QPoint &_p1, QPoint &_p2)
{
    return QPoint( (_p1.x() + _p2.x()) / 2, (_p1.y() + _p2.y()) / 2);
}

QPoint Global::GetShapeCenter(QVector<QPoint> &_vec)
{
    //find 4 edge axis values
    int xMin,xMax,yMin,yMax;
    for(int i = 0; i < _vec.length(); ++i)
    {
        QPoint &p = _vec[i];
        //initial values of every of 4 values
        if(i == 0)
        {
            xMin = xMax = p.x();
            yMin = yMax = p.y();
        }
        else
        {
            xMin = (p.x() < xMin) ? p.x() : xMin;
            xMax = (p.x() > xMax) ? p.x() : xMax;
            yMin = (p.y() < yMin) ? p.y() : yMin;
            yMax = (p.y() > yMax) ? p.y() : yMax;
        }
    }

    return QPoint( (xMax + xMin)/2, (yMax + yMin)/2 );
}
