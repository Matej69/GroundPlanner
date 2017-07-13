#include "room.h"

QImage Room::IMGInfo::edgePointIMG;
QImage Room::IMGInfo::centerPointIMG;
float Room::IMGInfo::imgSize = 20;
float Room::pointRadius = Room::IMGInfo::imgSize / 2;

int Room::TextboxInfo::h = 15;
int Room::TextboxInfo::w = 75;
int Room::TextboxInfo::xDist = 0;
int Room::TextboxInfo::yDist = 14;

Room::Room(QWidget *_window)
{    
    //for now init will be here but it should happen once and not in every constructor
    Room::IMGInfo::edgePointIMG.load(":/img/edgePoint.png");
    Room::IMGInfo::centerPointIMG.load(":/img/dragPoint.png");

    editBox = nullptr;

    centerPoint = QPoint(70,70);
    penWidth = 2;
    isActive = false;
}

Room::Room()
{
    qDebug() << "Default called";
}

Room::~Room()
{
    delete editBox;
}


void Room::AddPoint(QPoint &_point)
{
    points.push_back(_point);
    UpdateMiddlePointPos();
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



void Room::MoveRoomTo(QPoint &_p)
{
    QPoint moveBy = centerPoint - _p;
    //set center point pos
    centerPoint.setX(_p.x());
    centerPoint.setY(_p.y());
    //set edge points pos
    for(int i = 0; i < points.length(); ++i)
    {
        points[i].setX(points[i].x() - moveBy.x());
        points[i].setY(points[i].y() - moveBy.y());
    }
    //set textbox pos
    UpdateTextboxPos();
}



void Room::RenderRoom(QWidget *_window)
{    
    QPainter painter(_window);
    painter.setRenderHint(QPainter::Antialiasing);

    if(isActive)    //fill room with color only if it's active
    {
        QBrush fillBrush;
        fillBrush.setColor(Qt::darkCyan);
        fillBrush.setStyle(Qt::SolidPattern);
        painter.setBrush(fillBrush);
    }

    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(Qt::white);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);


    //fix for polygon weird bug
    QVector<QPoint> points2;
    for(int i = 0; i < points.length(); ++i)
        points2.push_back(QPoint(points[i].x(), points[i].y()));


    QPolygon polygon(points2);
    painter.drawPolygon(polygon);

    //draw edge points
    for(int i = 0; i < points.length(); ++i)
    {
        painter.drawImage(QRect(points[i].x() - IMGInfo::imgSize/2, points[i].y() - IMGInfo::imgSize/2, IMGInfo::imgSize, IMGInfo::imgSize), Room::IMGInfo::edgePointIMG);
    }
    //draw center point
    painter.drawImage(QRect(centerPoint.x() - IMGInfo::imgSize/2, centerPoint.y() - IMGInfo::imgSize/2, IMGInfo::imgSize, IMGInfo::imgSize), Room::IMGInfo::centerPointIMG);
}



void Room::UpdateMiddlePointPos()
{
    //calculate new center point
    QPoint point = Global::GetShapeCenter(points);
    centerPoint.setX(point.x());
    centerPoint.setY(point.y());
    //update textBox pos
    UpdateTextboxPos();

}

void Room::UpdateTextboxPos()
{
    if(editBox != nullptr)
    {
        editBox->setGeometry(QRect(centerPoint.x() - Room::TextboxInfo::xDist - Room::TextboxInfo::w / 2,
                                   centerPoint.y() + Room::TextboxInfo::yDist,
                                   Room::TextboxInfo::w,
                                   Room::TextboxInfo::h));
    }
}

void Room::SetTextboxVisiblity(bool _state)
{
    if(editBox != nullptr)
    {
        editBox->setVisible(_state);
        editBox->setEnabled(_state);
    }
}


