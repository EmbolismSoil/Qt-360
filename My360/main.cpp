#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <tr1/memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    std::tr1::shared_ptr<MainWindow> w(new MainWindow);
    w->show();

    return a.exec();
}
