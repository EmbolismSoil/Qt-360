#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QStateMachine>
#include <QState>
#include <QSignalTransition>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
   setWindowFlags(Qt::FramelessWindowHint);
    setAutoFillBackground(true);

    InitUi();
    InitConnect();
    InitAnimation();
}

MainWindow::~MainWindow()
{

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
    setStyleSheet("MainWindow{background-image:url(:/background/background_mainwnd.jpg) ;}");
    Tray = new QSystemTrayIcon(this);
    Tray->setIcon(QIcon(":/background/360logo.png"));
    Tray->setToolTip("a trayicon example");//设置提示语
    Tray->show();

    topWdiget = new TopBaseWidget;
    layout = new QVBoxLayout;
    layout->addWidget(topWdiget,0);
    layout->addStretch(1);
    layout->setSpacing(0);
    layout->setMargin(0);

    center = new CenterWidget;
    center->setLayout(layout);
    layout->setSpacing(0);
    layout->setMargin(0);
    center->setLayout(layout);
    setCentralWidget(center);    

    this->setFixedSize(900, 600);
    QDesktopWidget *deskdop = QApplication::desktop();
    QRect rect = deskdop->screenGeometry();
    move(rect.width() / 4, rect.height() / 4);
    setWindowIcon(QIcon(":/background/360logo.ico"));
    WindowGeometry = geometry();
}

void MainWindow::InitConnect()
{
    closeAnimation = new QPropertyAnimation(this, "windowOpacity");
    connect(closeAnimation, SIGNAL(finished()), this, SLOT(close()));
    connect(topWdiget->getTitleBar()->getCloseBtn(), SIGNAL(clicked()), this, SLOT(unFix()));

}

void MainWindow::InitAnimation()
{
    QStateMachine *closeMachine = new QStateMachine;

    QState *start = new QState(closeMachine);
    QState *end = new QState(closeMachine);

    start->assignProperty(this, "windowOpacity", 1);
    end->assignProperty(this, "windowOpacity", 0);

    closeMachine->setInitialState(start);
     QSignalTransition *tran = start->addTransition(topWdiget->getTitleBar()->getCloseBtn(),
                                                    SIGNAL(clicked()),  end);

     closeAnimation->setDuration(800);
     tran->addAnimation(closeAnimation);

     QStateMachine *moveMachine = new QStateMachine;
     QState *moveStart = new QState(moveMachine);
     QState *moveEnd  = new QState(moveMachine);
      moveStart->assignProperty(this, "geometry", geometry());
      moveEnd->assignProperty(this, "geometry", QRectF(geometry().x() / 8, geometry().y() / 8,
                                                           geometry().width() / 8, geometry().height() / 8));

      moveMachine->setInitialState(moveStart);
      QSignalTransition *moveTran = moveStart->addTransition(topWdiget->getTitleBar()->getCloseBtn(),
                                                             SIGNAL(clicked()),moveEnd);
     QPropertyAnimation *moveAnimation = new QPropertyAnimation(this, "geometry");
     moveAnimation->setDuration(800);
     moveTran->addAnimation(moveAnimation);

     closeMachine->start();
     moveMachine->start();
}
