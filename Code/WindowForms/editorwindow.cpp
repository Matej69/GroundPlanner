#include "editorwindow.h"
#include "ui_editorwindow.h"


EditorWindow::EditorWindow(QWidget *parent) :
    ui(new Ui::EditorWindow)
{    
    ui->setupUi(this);
    thisWindow = this;

    this->setMouseTracking(true);


    selectedPoint = nullptr;

    //for testing
    activeFloor = new Floor();
    Room* room = new Room();    room->AddPoint(QPoint(40,40)); room->AddPoint(QPoint(200,40)); room->AddPoint(QPoint(40,200));
    Room* a = new Room();       a->AddPoint(QPoint(80,80)); a->AddPoint(QPoint(250,40)); a->AddPoint(QPoint(10,150));           a->isActive = true;
    activeFloor->AddRoom(*room);
    activeFloor->AddRoom(*a);
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

void EditorWindow::mousePressEvent(QMouseEvent *e)
{
    //selectedPoint will be pointing to room point if mouse is over it
    for(int i = 0; i < activeFloor->rooms.length(); ++i)
        for(int j = 0; j < activeFloor->rooms[i].points.length(); ++j)
        {
            QPoint& curPoint = activeFloor->rooms[i].points[j];
            if(Global::IsPosInsidePointRadius(QPoint(e->x(),e->y()), curPoint, Room::pointRadius))
            {
                selectedPoint = &curPoint;
                break;
            }
        }

}

void EditorWindow::mouseReleaseEvent(QMouseEvent *e)
{
    selectedPoint = nullptr;
}

void EditorWindow::mouseMoveEvent(QMouseEvent *e)
{
    //move selected point to mouse pos
    if(selectedPoint != nullptr)
    {
        selectedPoint->setX(e->x());
        selectedPoint->setY(e->y());
    }
}
