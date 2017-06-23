#ifndef AUSERWINDOW_H
#define AUSERWINDOW_H

#include <QWidget>

namespace Ui {
class AUserWindow;
}

class AUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AUserWindow(QWidget *parent = 0);
    ~AUserWindow();

private:
    Ui::AUserWindow *ui;
};

#endif // AUSERWINDOW_H
