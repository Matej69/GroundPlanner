#include "auserwindow.h"
#include "ui_auserwindow.h"



AUserWindow::AUserWindow()
{
}

AUserWindow::~AUserWindow()
{
}

void AUserWindow::paintEvent(QPaintEvent *e)
{
    activeFloor->RenderFloor(thisWindow);
    update();
}

