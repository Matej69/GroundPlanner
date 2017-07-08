#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLineEdit>

#include "QPoint"
#include "auserwindow.h"
#include "User/global.h"
#include "User/jsonconnection.h"

namespace Ui {
class EditorWindow;
}

class EditorWindow : public AUserWindow
{
public:
    virtual void OnUserSwitchButton();

    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);    
    ~EditorWindow();

    bool arePointsSticky;
    Room *activeRoom;

    void RefreshDropdownContent();


private slots:
    void on_roomAdd_clicked();
    void on_pointAdd_clicked();
    void on_floorAdd_clicked();

    void on_roomDelete_clicked();
    void on_pointDelete_clicked();
    void on_floorDelete_clicked();

    void on_dropBox_floors_activated(const QString& _name);

private:
    Ui::EditorWindow *ui;

    QPoint *activePoint;
    Room *movableRoom;
    bool canDeletePoint;
    bool canDeleteRoom;

    virtual void OnFloorDropdown();

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

    void SetActiveRoom(Room& _room);   //set new room to be active one, set previous to not be active


};

#endif // EDITORWINDOW_H
