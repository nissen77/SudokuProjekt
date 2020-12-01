#include "mainwindow.h"

#include <QApplication>
#include <qfile.h>
#include <qtextstream.h>
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    // reading in the css files
    QFile styleFile(":/css/style.css");
    if(styleFile.open(QIODevice::ReadOnly))
       {
           QTextStream textStream(&styleFile);
           QString styleSheet = textStream.readAll();
           styleFile.close();
           a.setStyleSheet(styleSheet);
       }

    MainWindow w;
    w.show();
    return a.exec();
}
