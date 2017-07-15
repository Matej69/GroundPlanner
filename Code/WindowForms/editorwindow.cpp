#include "WindowForms/editorwindow.h"
#include "ui_editorwindow.h"




EditorWindow::EditorWindow(QWidget *parent) :
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    thisWindow = this;
    this->setWindowTitle("Editor");
    this->setMouseTracking(true);

    //remove later if not needed
    floors = QVector<Floor>();

    activePoint = nullptr;
    movableRoom = nullptr;

    arePointsSticky = true;
    canDeletePoint = false;
    canDeleteRoom = false;

    //read all floors from JSON(must be here because thisWindow is still undefined if ReadAll is called in base class)
    JSONConnection con;
    con.ReadAll(floors, thisWindow);



    if(floors.length() > 0)
        SetActiveFloor(floors[0]);
    RefreshDropdownContent();

}

EditorWindow::~EditorWindow()
{
    delete ui;
}
void EditorWindow::OnCloseWindow()
{
    qDebug() << "Editor Clearing taken resources";

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
    {
        activeRoom->isActive = false;
    }
    //new current room will become active
    activeRoom = &_room;
    activeRoom->isActive = true;
}



void EditorWindow::mousePressEvent(QMouseEvent *e)
{
    if(activeFloor == nullptr)
        return;

    //selectedPoint will be pointing to room point if mouse is over it
    for(int i = activeFloor->rooms.length() - 1; i >= 0; --i)
    {
        Room& curRoom = activeFloor->rooms[i];
        //if center point was clicked
        if(Global::IsPosInsidePointRadius(QPoint(e->x(),e->y()), curRoom.centerPoint, Room::pointRadius))
        {
            movableRoom = &curRoom;
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
    //remove pointer to room that follows mouse on movement
    movableRoom = nullptr;

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
    {
        activeRoom->UpdateMiddlePointPos();
    }
    //If movableRoom is pointing at room, move that room as mouse moves
    if(movableRoom != nullptr && activeRoom != nullptr)
    {
        activeRoom->MoveRoomTo(QPoint(e->x(),e->y()));
    }



}


//*************************************************************************************************
//WHEN NEW ROOM IS ADDED PROGRAM WILL BREAK BECAUSEOF TEXTFIELD OF X ROOM THAT IS PROBABLY NULL
//*************************************************************************************************
void EditorWindow::on_roomAdd_clicked()
{
    if(activeFloor != nullptr)
    {
        int dist = 100;
        Room room(thisWindow);
        //room.SetTextboxVisiblity(true);
        room.AddPoint(QPoint(width()/2 - dist, height()/2 - dist));
        room.AddPoint(QPoint(width()/2 + dist, height()/2 - dist));
        room.AddPoint(QPoint(width()/2 + dist, height()/2 + dist));
        room.AddPoint(QPoint(width()/2 - dist, height()/2 + dist));
       //only here we are manualy changing activity bacouse once we add new room, activeRoom pointer will be pointing to old address
        if(activeRoom != nullptr)
            activeRoom->isActive = false;

        activeFloor->AddRoom(room,thisWindow, true);

       //new room will also have visible textbox
        //activeFloor->rooms[activeFloor->rooms.length()-1].SetTextboxVisiblity(true);
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
    bool isConfirmed;
    QString floorName = QInputDialog::getText(thisWindow,
                                              "Floor creation",
                                              "Floor name:",
                                              QLineEdit::Normal,
                                              "",
                                              &isConfirmed);
    if(isConfirmed)
    {
        floors.push_back(Floor(floorName));
        //SetActiveFloor(floors[floors.length()-1]);
        RefreshDropdownContent();
    }
}





void EditorWindow::on_roomDelete_clicked()
{
    if(activeRoom != nullptr)
        for(int i = 0; i < activeFloor->rooms.length(); ++i)
            if(&activeFloor->rooms[i] == &(*activeRoom))
            {
                //delete activeRoom->editBox;
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
    //remove current floor from vector
    if(activeFloor != nullptr)
        for(int i = floors.length()-1; i >= 0; --i)
            if(&floors[i] == &*activeFloor)
            {
                floors.removeAt(i);
                activeFloor = nullptr;
                activeRoom = nullptr;
                activePoint = nullptr;
            }
    RefreshDropdownContent();
}



void EditorWindow::on_saveAll_clicked()
{
    JSONConnection con;
    con.WriteAll(floors);
}


//ON ITEM CLICKED
void EditorWindow::on_dropBox_floors_activated(const QString& _name)
{    
    for(int i = 0; i < floors.length(); ++i)
        if(floors[i].nameID == _name)
            SetActiveFloor(floors[i]);
}







void EditorWindow::RefreshDropdownContent()
{
    ui->dropBox_floors->clear();
    for(int i = 0; i < floors.length(); ++i)
        ui->dropBox_floors->addItem(floors[i].nameID);
}

void EditorWindow::on_switchWindow_clicked()
{
    SwitchToWindow(AUserWindow::E_USER::CLIENT, this);
}
