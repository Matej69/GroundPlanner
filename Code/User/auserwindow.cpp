#include "auserwindow.h"
#include "ui_auserwindow.h"

AUserWindow::AUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AUserWindow)
{
    ui->setupUi(this);
}

AUserWindow::~AUserWindow()
{
    delete ui;
}
