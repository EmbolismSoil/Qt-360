#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <closebutton.h>
#include <titlebar.h>
#include <QPropertyAnimation>
#include <QSystemTrayIcon>
#include <centerwidget.h>
#include <basewidget.h>
#include <tr1/memory>
#include <iostream>
#include <pthread.h>

class QStateMachine;
class QState;
class QSignalTransition;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static MainWindow* getInstance()
    {
        pthread_once(&MainWindow::initOnce, &MainWindow::newInstance);
        return instance;
    }

    static void  deleteSth(void)
    {
          std::cout << "in MainWindow::deleteSth();" << std::endl;
             //if (instance != NULL)
                //delete instance;
    }


private:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    static MainWindow* instance;
    static pthread_once_t initOnce;
    static void newInstance(void)
    {
          instance = new MainWindow;
    }

public slots:
    void unFix();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    CenterWidget* center;

    void InitUi();
    void InitConnect();
    void InitAnimation();

    bool isMousePress;
    QPoint windowPos;
    QPoint mousePos;

    QPropertyAnimation*  closeOpacityAnimation;
    QPropertyAnimation* closemoveAnimation;
    QSystemTrayIcon* Tray;
    QRect WindowGeometry;

    QStateMachine *closeMachine;
    QState *start;
    QState *end;
    QSignalTransition *tran ;
    QStateMachine *moveMachine ;
    QState *moveStart;
    QState *moveEnd  ;
    QSignalTransition *moveTran;
    Q_DISABLE_COPY(MainWindow)
};


#endif // MAINWINDOW_H
