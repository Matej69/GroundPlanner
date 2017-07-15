#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    thisWindow = this;
    this->setWindowTitle("Client");
    this->setMouseTracking(true);

    activeFloor = nullptr;
    activeRoom = nullptr;

    //read all floors from JSON(must be here because thisWindow is still undefined if ReadAll is called in base class)
    JSONConnection con;
    con.ReadAll(floors, thisWindow);

    if(floors.length() > 0)
        SetActiveFloor(floors[0]);
    RefreshDropdownContent();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::OnCloseWindow()
{
    qDebug() << "Client Clearing taken resources";
}





void ClientWindow::RefreshDropdownContent()
{
    ui->dropBox_floors->clear();
    for(int i = 0; i < floors.length(); ++i)
        ui->dropBox_floors->addItem(floors[i].nameID);
}


void ClientWindow::on_switchWindow_clicked()
{
    AUserWindow::SwitchToWindow(E_USER::EDITOR, this);
}

void ClientWindow::on_dropBox_floors_activated(const QString& _name)
{
    for(int i = 0; i < floors.length(); ++i)
        if(floors[i].nameID == _name)
            SetActiveFloor(floors[i]);
}
