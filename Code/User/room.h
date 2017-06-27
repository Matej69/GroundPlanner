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
#include <QLineEdit>
#include <QLayout>

#include <cmath>

#include "auserwindow.h"
#include "global.h"

using namespace std;

class Room
{
public:
    Room(QWidget *_window);
    Room();
    ~Room();

    QString nameID;
    QLineEdit* editBox;
    QVector<QPoint> points;
    QPoint centerPoint;
    bool isActive;

    static float pointRadius;
    struct IMGInfo{
        static float imgSize;
        static QImage edgePointIMG;
        static QImage centerPointIMG;
    };

    struct TextboxInfo{
        static int w,h,xDist,yDist;
    };

    void UpdateTextboxPos();


    void SetActive(bool _state);
    void AddPoint(QPoint &_point);
    void DeletePoint(QPoint &_point);

    void MoveRoomTo(QPoint &_p);

    void RenderRoom(QWidget *_window);
    void UpdateMiddlePointPos();


private:    
    int penWidth;

    void RenderPoint();







};

#endif // ROOM_H
