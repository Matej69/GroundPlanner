#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>

#include "auserwindow.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public AUserWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();
    virtual void OnCloseWindow() override;   //Clears resources (pointers to addresses)

private slots:
    void on_switchWindow_clicked();
    void on_dropBox_floors_activated(const QString& _name);

private:
    Ui::ClientWindow *ui;
    void RefreshDropdownContent();
};

#endif // CLIENTWINDOW_H
