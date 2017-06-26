#include "WindowForms/editorwindow.h"
#include "ui_editorwindow.h"


EditorWindow::EditorWindow(QWidget *parent) :
    ui(new Ui::EditorWindow)
{    
    ui->setupUi(this);
    thisWindow = this;
    this->setWindowTitle("Editor");
    this->setMouseTracking(true);



    activePoint = nullptr;
    activeRoom = nullptr;
    activeFloor = nullptr;
    arePointsSticky = true;
    canDeletePoint = false;
    canDeleteRoom = false;

    //for testing
    activeFloor = new Floor();
    Room room = Room();     room.AddPoint(QPoint(240,40)); room.AddPoint(QPoint(200,40)); room.AddPoint(QPoint(240,200)); room.nameID = "ROOM1";
    Room room1 = Room();    room1.AddPoint(QPoint(160,80)); room1.AddPoint(QPoint(450,40)); room1.AddPoint(QPoint(210,150));           room1.isActive = true;
    activeFloor->AddRoom(room);
    activeFloor->AddRoom(room1);

    activeRoom = &activeFloor->rooms[1];

}

EditorWindow::~EditorWindow()
{
    delete ui;
}


void EditorWindow::OnFloorDropdown()
{

}

void EditorWindow::OnUserSwitchButton()
{
}

void EditorWindow::SetActiveRoom(Room& _room)
{
    //previous room will be inactive
    if(activeRoom != nullptr)
        activeRoom->isActive = false;
    //new current room will become active
    activeRoom = &_room;
    activeRoom->isActive = true;
}



void EditorWindow::mousePressEvent(QMouseEvent *e)
{
    //selectedPoint will be pointing to room point if mouse is over it
    for(int i = activeFloor->rooms.length() - 1; i >= 0; --i)
    {
        Room& curRoom = activeFloor->rooms[i];
        //if center point was clicked
        if(Global::IsPosInsidePointRadius(QPoint(e->x(),e->y()), curRoom.centerPoint, Room::pointRadius))
        {
            SetActiveRoom(curRoom);
            return;
        }

        //if one of room edge points was clicked
        for(int j = activeFloor->rooms[i].points.length() - 1; j >= 0 ; --j)
        {
            QPoint& curPoint = activeFloor->rooms[i].points[j];
            Room& curRoom = activeFloor->rooms[i];
            if(Global::IsPosInsidePointRadius(QPoint(e->x(),e->y()), curPoint, Room::pointRadius))
            {                
                //if point can be deleted on click delete it, else just point at it
                if(canDeletePoint)
                    curRoom.DeletePoint(curPoint);
                else
                {
                    activePoint = &curPoint;
                    SetActiveRoom(curRoom);
                }
                return;
            }
        }    
    }
}

void EditorWindow::mouseReleaseEvent(QMouseEvent *e)
{
    //if stickyPoint is true, take selectedPoint and stick it to point it is touching
    if(arePointsSticky && activePoint != nullptr)
    {
        for(int i = 0; i < activeFloor->rooms.length(); ++i)
            for(int j = 0; j < activeFloor->rooms[i].points.length(); ++j)
            {
                QPoint& curPoint = activeFloor->rooms[i].points[j];
                if(Global::IsPosInsidePointRadius(*activePoint, curPoint, Room::pointRadius * 2))
                {
                    activePoint->setX(curPoint.x());
                    activePoint->setY(curPoint.y());
                }
            }
    }

    //selectedPoint will not be pointing at any point
    activePoint = nullptr;

}

void EditorWindow::mouseMoveEvent(QMouseEvent *e)
{    
    //move selected point to mouse pos
    if(activePoint != nullptr)
    {
        activePoint->setX(e->x());
        activePoint->setY(e->y());
    }
    //update  middle point of selected room
    if(activeRoom != nullptr)
        activeRoom->UpdateMiddlePointPos();

}




void EditorWindow::on_roomAdd_clicked()
{
    if(activeFloor != nullptr && activeFloor != nullptr)
    {
        int dist = 100;
        Room room;
        room.AddPoint(QPoint(width()/2 - dist, height()/2 - dist));
        room.AddPoint(QPoint(width()/2 + dist, height()/2 - dist));
        room.AddPoint(QPoint(width()/2 + dist, height()/2 + dist));
        room.AddPoint(QPoint(width()/2 - dist, height()/2 + dist));
        activeFloor->AddRoom(room);
        //active room will be newly added room
        SetActiveRoom(activeFloor->rooms[activeFloor->rooms.length()-1]);
    }

}

void EditorWindow::on_pointAdd_clicked()
{
    if(activeRoom != nullptr && activeRoom->points.length() > 0)
    {
        int numOfPoints = activeRoom->points.length();
        activeRoom->AddPoint(Global::GetMiddlePoint(activeRoom->points[0], activeRoom->points[numOfPoints - 1]));
        activePoint = nullptr;
    }

}

void EditorWindow::on_floorAdd_clicked()
{

}





void EditorWindow::on_roomDelete_clicked()
{
    if(activeRoom != nullptr)
        for(int i = 0; i < activeFloor->rooms.length(); ++i)
            if(&activeFloor->rooms[i] == &(*activeRoom))
            {
                activeFloor->DeleteRoom(*activeRoom);
                activeRoom = nullptr;
                break;
            }
}

void EditorWindow::on_pointDelete_clicked()
{
    canDeletePoint = !canDeletePoint;
}

void EditorWindow::on_floorDelete_clicked()
{

}
