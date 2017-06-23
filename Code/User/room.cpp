#include "room.h"

//QImage Room::IMGInfo::pointIMG(":/img/circle.png");
float Room::IMGInfo::imgSize = 26;
float Room::pointRadius = Room::IMGInfo::imgSize / 2;


Room::Room()
{
    //Room::IMGInfo::pointIMG.load(":/img/circle.png");
    penWidth = 4;
    isActive = false;
}

Room::~Room()
{
}

void Room::AddPoint(QPoint &_point)
{
    points.push_back(_point);
}

void Room::DeletePoint(QPoint &_point)
{
    for(int i = 0; i < points.length(); ++i)
        if(&points[i] == &_point)
        {
            points.remove(i);
            break;
        }
}

void Room::RenderRoom(QWidget *_window)
{

    QPainter painter(_window);
    painter.setRenderHint(QPainter::Antialiasing);

    if(isActive)    //fill room with color only if it's active
    {
        QBrush fillBrush;
        fillBrush.setColor(Qt::blue);
        fillBrush.setStyle(Qt::SolidPattern);
        painter.setBrush(fillBrush);
    }

    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(Qt::red);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);

    QPolygon polygon(points);
    painter.drawPolygon(polygon);


    for(int i = 0; i < points.length(); ++i)
    {
        //painter.drawImage(QRect(points[i].x() - IMGInfo::imgSize/2, points[i].y() - IMGInfo::imgSize/2, IMGInfo::imgSize, IMGInfo::imgSize), IMGInfo::pointIMG);
        painter.drawImage(QRect(points[i].x() - IMGInfo::imgSize/2, points[i].y() - IMGInfo::imgSize/2, IMGInfo::imgSize, IMGInfo::imgSize), QImage(":/img/circle.png"));
    }

}


