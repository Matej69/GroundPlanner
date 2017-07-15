#include <QApplication>
#include "WindowForms/editorwindow.h"
#include "WindowForms/clientwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWindow w;
    w.show();

    return a.exec();
}
