#include "floor.h"


Floor::Floor()
{    
}

Floor::~Floor()
{
}

Floor::Floor(QString _name)
{
    nameID = _name;
}




void Floor::RenderFloor(QWidget *_window)
{
    for(int i = 0; i < rooms.length(); ++i)
        rooms[i].RenderRoom(_window);

}

void Floor::AddRoom(Room &_room, QWidget *_window, bool isTextboxVisible)
{
    rooms.push_back(_room);

    //Create edit box
    Room& newRoom = rooms[rooms.length()-1];
    //newRoom.editBox = new QLineEdit(_window);
    //QLineEdit *test = new QLineEdit(_window);
    //newRoom.editBox = test;

    /*
    _window->layout()->addWidget(newRoom.editBox);
    //set edit box visibility
    newRoom.SetTextboxVisiblity(isTextboxVisible);
    newRoom.UpdateTextboxPos();
    */
}

void Floor::DeleteRoom(Room &_room)
{
    for(int i = 0; i < rooms.length(); ++i)
        if(&rooms[i] == &_room)
        {
            //delete when called in room deconstructor couses error, Fix this later
            //delete rooms[i].editBox;
            rooms.remove(i);
            break;
        }
}

