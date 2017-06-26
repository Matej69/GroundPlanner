#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <QDebug>
#include <QPoint>
#include <QImage>
#include <QPainter>
#include <QPolygon>
#include <QPen>
#include <QRect>
#include <QPainterPath>

#include <cmath>

#include "auserwindow.h"
#include "global.h"

using namespace std;

class Room
{
public:
    Room();
    ~Room();

    QString nameID;
    QVector<QPoint> points;
    QPoint centerPoint;
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
    void UpdateMiddlePointPos();


private:    
    int penWidth;

    void RenderPoint();







};

#endif // ROOM_H
