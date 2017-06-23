#ifndef AUSERWINDOW_H
#define AUSERWINDOW_H

#include <QWidget>
#include "User/floor.h"
#include "User/room.h"

#include <QDebug>
#include <QPainter>
#include <QPolygon>
#include <QPen>

namespace Ui {
class AUserWindow;
}

class AUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AUserWindow();
    virtual ~AUserWindow();

protected:
    enum E_USER{ EDITOR, CLIENT };
    E_USER userID;
    QWidget *thisWindow;

    //Room *room;

    Floor *activeFloor;         //this is the floor that will be rendered on screen
    virtual void OnFloorDropdown() = 0;
    virtual void OnUserSwitchButton() = 0;

    void paintEvent(QPaintEvent *e);


};

#endif // AUSERWINDOW_H
