#include "mainwindow.h"
#include "startdialog.h"
#include "middledialog.h"
#include "losedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(240,0);
    w.hide();
    return a.exec();
}
