#include "floor.h"

Floor::Floor()
{    
}

Floor::~Floor()
{
}

void Floor::RenderFloor(QWidget *_window)
{
    for(int i = 0; i < rooms.length(); ++i)
        rooms[i].RenderRoom(_window);

}

void Floor::AddRoom(Room &_room)
{
    rooms.push_back(_room);
}

void Floor::DeleteRoom(Room &_room)
{
    for(int i = 0; i < rooms.length(); ++i)
        if(&rooms[i] == &_room)
        {
            rooms.remove(i);
            break;
        }
}

