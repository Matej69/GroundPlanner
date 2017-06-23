#ifndef GLOBAL_H
#define GLOBAL_H

#include <QPoint>
#include <cmath>
#include <QDebug>
using namespace std;

class Global
{
public:
    Global();
    static bool IsPosInsidePointRadius(QPoint &_p1, QPoint &_p2, float _p2Radius);
};

#endif // GLOBAL_H
