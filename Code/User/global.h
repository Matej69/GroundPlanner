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
    static QPoint GetMiddlePoint(QPoint &_p1, QPoint &_p2);
    static QPoint GetShapeCenter(QVector<QPoint> &_vec);
};

#endif // GLOBAL_H
