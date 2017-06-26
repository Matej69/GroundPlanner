#ifndef AUSERWINDOW_H
#define AUSERWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "User/floor.h"
#include "User/room.h"

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

protected:
    enum E_USER{ EDITOR, CLIENT };
    E_USER userID;
    QWidget *thisWindow;

    Floor *activeFloor;         //this is the floor that will be rendered on screen
    //virtual void OnFloorDropdown();
    //virtual void OnUserSwitchButton();

    void paintEvent(QPaintEvent *e);


};

#endif // AUSERWINDOW_H
