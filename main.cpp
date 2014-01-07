#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // show the window in the center of the screen
    QDesktopWidget wid;
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();
    MainWindow w;
    w.forConnections();
    w.makeConnections();
    int width = w.frameGeometry().width();
    int height = w.frameGeometry().height();
    w.setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
    w.show();

    return a.exec();
}
