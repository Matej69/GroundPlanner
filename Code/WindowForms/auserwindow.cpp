#include "auserwindow.h"
#include "ui_auserwindow.h"

#include "WindowForms/clientwindow.h"
#include "WindowForms/editorwindow.h"


AUserWindow::AUserWindow()
{
    activeFloor = nullptr;
    activeRoom = nullptr;
}

AUserWindow::~AUserWindow()
{
    qDebug() << "BASE DECONSTRUCTOR CALLED";
}
void AUserWindow::CloseWindow()
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
        activeFloor->SetAllTextBoxVisiblity(false);    
    //re-asigne pointer to another floor
    activeFloor = &_floor;
    //enable textFields of all rooms on new floor
    activeFloor->SetAllTextBoxVisiblity(true);
}

void AUserWindow::SetActiveRoom(Room &_room)
{
    //previous room will be inactive
    if(activeRoom != nullptr)
    {
        activeRoom->isActive = false;
    }
    //new current room will become active
    activeRoom = &_room;
    activeRoom->isActive = true;
}





void AUserWindow::SwitchToWindow(E_USER _userType, AUserWindow* _win)
{
    //delete previous(DESTRUCTOR MUST BE CALLED)
    if(_win != nullptr)
    {
        _win->CloseWindow();
        //_win->OnCloseWindow();  //deletes resources
        //_win->close();          //closes window
    }
    //create new Window
    AUserWindow *newWindow;
    if(_userType == E_USER::CLIENT)
        newWindow = new ClientWindow();
    else
        newWindow = new EditorWindow();
    newWindow->show();
}

