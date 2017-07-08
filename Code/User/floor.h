#ifndef FLOOR_H
#define FLOOR_H

#include "User/room.h"

class Floor
{
public:
    Floor();
    ~Floor();

    QVector<Room> rooms;
    QString nameID;

    void RenderFloor(QWidget *_window);
    void AddRoom(Room &_room, QWidget *_window);
    void DeleteRoom(Room &_room);





};

#endif // FLOOR_H
