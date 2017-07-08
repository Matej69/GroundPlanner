#include "auserwindow.h"
#include "ui_auserwindow.h"



AUserWindow::AUserWindow()
{
}

AUserWindow::~AUserWindow()
{
}

void AUserWindow::paintEvent(QPaintEvent *e)
{
    if(activeFloor != nullptr)
        activeFloor->RenderFloor(thisWindow);
    thisWindow->update();
}

void AUserWindow::SetActiveFloor(Floor &_floor)
{
    //disable textFields of all rooms on old floor
    if(activeFloor != nullptr)
        for(int i = 0; i < activeFloor->rooms.length(); ++i)
        {
            Room& room = activeFloor->rooms[i];
            room.SetTextboxVisiblity(false);
        }
    //re-asigne pointer to another floor
    activeFloor = &_floor;
    //enable textFields of all rooms on new floor
    for(int i = 0; i < activeFloor->rooms.length(); ++i)
    {
        Room& room = activeFloor->rooms[i];
        room.SetTextboxVisiblity(true);
    }
}

