#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <QPoint>
#include <QImage>
#include <QPainter>
#include <QPolygon>
#include <QPen>
#include <QRect>
#include <QPainterPath>

#include <cmath>

#include "auserwindow.h"

using namespace std;

class Room
{
public:
    Room();
    ~Room();

    string nameID;
    QVector<QPoint> points;
    bool isActive;

    static float pointRadius;
    struct IMGInfo{
        static float imgSize;
        static QImage pointIMG;
    };


    void SetActive(bool _state);
    void AddPoint(QPoint &_point);
    void DeletePoint(QPoint &_point);

    void RenderRoom(QWidget *_window);


private:    
    int penWidth;

    void RenderPoint();







};

#endif // ROOM_H
