#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include "QPoint"

#include "auserwindow.h"
#include "User/global.h"

namespace Ui {
class EditorWindow;
}

class EditorWindow : public AUserWindow
{
public:
    virtual void OnUserSwitchButton() override final;

    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);    
    ~EditorWindow();



private:
    Ui::EditorWindow *ui;
    virtual void OnFloorDropdown() override final;    

    QPoint *selectedPoint;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;


};

#endif // EDITORWINDOW_H
