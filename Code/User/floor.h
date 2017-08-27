#ifndef FLOOR_H
#define FLOOR_H

#include "User/room.h"

class Floor
{
public:
    Floor(QString _name);
    Floor();
    ~Floor();

    QVector<Room> rooms;
    QString nameID;

    void RenderFloor(QWidget *_window);
    void AddRoom(Room &_room, QWidget *_window, bool isTextboxVisible);
    void DeleteRoom(Room &_room);
    void SetAllTextBoxVisiblity(bool _visibility);





};

#endif // FLOOR_H
