#include "mainwindow.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QStateMachine>
#include <QState>
#include <QSignalTransition>
#include <QEasingCurve>
#include <QApplication>
#include <stdlib.h>

MainWindow *MainWindow::instance = NULL;
pthread_once_t MainWindow::initOnce = 0;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    center(new CenterWidget),
    closeOpacityAnimation (new QPropertyAnimation(this, "windowOpacity")),
    closemoveAnimation(new QPropertyAnimation(this, "geometry")),
    Tray(new QSystemTrayIcon(this))
{

   atexit(&MainWindow::deleteSth);
   setWindowFlags(Qt::FramelessWindowHint);
    setAutoFillBackground(true);
    
    InitUi();
    InitConnect();
    InitAnimation();

    //atexit(&MainWindow::deleteSth);
}

MainWindow::~MainWindow()
{
    delete center;
    delete  closeOpacityAnimation;
     delete closemoveAnimation;
     delete Tray;

    delete closeMachine;
    //delete start;
    //delete end;
    //delete tran ;
    delete moveMachine ;
    //delete moveStart;
    //delete moveEnd  ;
    //delete moveTran;
}

void MainWindow::unFix()
{
    setMaximumSize(65535, 65535);
    setMinimumSize(0, 0);
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
         windowPos = this->pos();
         mousePos = event->globalPos();
         isMousePress = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        isMousePress = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isMousePress == true){
        move(windowPos + (event->globalPos() - mousePos));
    }
}


void MainWindow::InitUi()
{
    setObjectName("Window");
    //setStyleSheet("MainWindow{background-image:url(:/background/background_mainwnd.jpg) ;}");

    setWindowTitle(tr("360安全卫士"));
    setWindowIcon(QIcon(":/background/360logo.png"));

    Tray->setIcon(QIcon(":/background/360logo.png"));
    Tray->setToolTip("a trayicon example");//设置提示语
    Tray->show();

    setCentralWidget(&(*center));

    this->setFixedSize(900, 600);
    QDesktopWidget *deskdop = QApplication::desktop();
    QRect rect = deskdop->screenGeometry();
    move(rect.width() / 4, rect.height() / 4);
    setWindowIcon(QIcon(":/background/360logo.ico"));
    WindowGeometry = geometry();
}


void MainWindow::InitConnect()
{
    closeOpacityAnimation->setDuration(1300);
    closemoveAnimation->setDuration(1300);
    closeOpacityAnimation->setEasingCurve(QEasingCurve::OutQuad);
    closemoveAnimation->setEasingCurve(QEasingCurve::OutQuad);

    connect(&(*closeOpacityAnimation), SIGNAL(finished()), this, SLOT(close()));
    connect(&(*center), SIGNAL(closeBtnClicked()), this, SLOT(unFix()));

}

void MainWindow::InitAnimation()
{
    closeMachine = new QStateMachine;

    start = new QState(closeMachine);
    end = new QState(closeMachine);

    start->assignProperty(this, "windowOpacity", 1);
    end->assignProperty(this, "windowOpacity", 0);

    closeMachine->setInitialState(start);
     tran = start->addTransition(&(*center), SIGNAL(closeBtnClicked()),  end);

     tran->addAnimation(&(*closeOpacityAnimation));

     moveMachine = new QStateMachine;
     moveStart = new QState(moveMachine);
     moveEnd  = new QState(moveMachine);
      moveStart->assignProperty(this, "geometry", geometry());
      moveEnd->assignProperty(this, "geometry", QRectF(geometry().x() / 8, geometry().y() / 8,
                                                           geometry().width() / 8, geometry().height() / 8));

      moveMachine->setInitialState(moveStart);
      moveTran = moveStart->addTransition(&(*center),
                                                             SIGNAL(closeBtnClicked()),moveEnd);
     moveTran->addAnimation(&(*closemoveAnimation));

     closeMachine->start();
     moveMachine->start();
}
