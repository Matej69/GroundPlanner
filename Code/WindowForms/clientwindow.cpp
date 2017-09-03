#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    thisWindow = this;
    this->setWindowTitle("Client");
    this->setMouseTracking(true);
    setAttribute(Qt::WA_QuitOnClose);

    activeFloor = nullptr;
    activeRoom = nullptr;

    //read all floors from JSON(must be here because thisWindow is still undefined if ReadAll is called in base class)
    JSONConnection con;
    con.ReadAll(floors, thisWindow);

    qDebug() << "WORKZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

    //floor that will initialy be displayed
    if(floors.length() > 0)
    {
        SetActiveFloor(floors[0]);
        RefreshDropdownContent();
        RefreshRoomsDropdownContent();
        foreach (Room room, activeFloor->rooms) {
            room.editBox->setReadOnly(true);
        }
    }
}

ClientWindow::~ClientWindow()
{
    qDebug() << "CLIENT DECONSTRUCTOR CALLED";
    delete ui;
}

void ClientWindow::CloseWindow()
{
    //Delete taken resources -> destructor of floor/room are taking of memory release
    floors.clear();
    //Close window
    qDebug() << "CLIENT CLOSED";
    close();
}





void ClientWindow::RefreshDropdownContent()
{
    ui->dropBox_floors->clear();
    for(int i = 0; i < floors.length(); ++i)
        ui->dropBox_floors->addItem(floors[i].nameID);
}

void ClientWindow::RefreshRoomsDropdownContent()
{
    ui->dropBox_rooms->clear();
    for(int i = 0; i < activeFloor->rooms.length(); ++i)
        ui->dropBox_rooms->addItem(activeFloor->rooms[i].GetName());
}


void ClientWindow::on_switchWindow_clicked()
{
    AUserWindow::SwitchToWindow(E_USER::EDITOR, this);
}

void ClientWindow::on_dropBox_floors_activated(const QString& _name)
{
    for(int i = 0; i < floors.length(); ++i)
        if(floors[i].nameID == _name)
        {            
            SetActiveFloor(floors[i]);
            RefreshRoomsDropdownContent();
            foreach (Room room, activeFloor->rooms) {
                room.editBox->setReadOnly(true);
            }
        }
}

void ClientWindow::on_dropBox_rooms_activated(const QString& _name)
{
    for(int i = 0; i < activeFloor->rooms.length(); ++i)
        if(activeFloor->rooms[i].GetName() == _name)
            SetActiveRoom(activeFloor->rooms[i]);
}
