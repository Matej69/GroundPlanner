#ifndef FLOOR_H
#define FLOOR_H

#include "User/room.h"

class Floor
{
public:
    Floor();
    ~Floor();

    QVector<Room> rooms;

    void RenderFloor(QWidget *_window);
    void AddRoom(Room &_room);
    void DeleteRoom(Room &_room);




private:
    string nameID;



};

#endif // FLOOR_H
