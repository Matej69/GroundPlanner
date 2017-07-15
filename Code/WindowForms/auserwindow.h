#ifndef AUSERWINDOW_H
#define AUSERWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "User/floor.h"
#include "User/room.h"
#include "User/jsonconnection.h"

#include <QDebug>
#include <QPainter>
#include <QPolygon>
#include <QPen>
#include <QtGui>

namespace Ui {
class AUserWindow;
}

class AUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AUserWindow();
    virtual ~AUserWindow();
    virtual void OnCloseWindow();   //Clears resources (pointers to addresses)


protected:
    enum E_USER{ EDITOR, CLIENT };
    E_USER userID;
    QWidget *thisWindow;

    Floor *activeFloor;         //the floor that will be rendered on screen
    Room *activeRoom;
    QVector<Floor> floors;       //all floors that are available
    //virtual void OnFloorDropdown();
    //virtual void OnUserSwitchButton();

    void paintEvent(QPaintEvent *e);
    void SetActiveFloor(Floor& _floor);   

    static void SwitchToWindow(E_USER _userType, AUserWindow* _win);
};

#endif // AUSERWINDOW_H
