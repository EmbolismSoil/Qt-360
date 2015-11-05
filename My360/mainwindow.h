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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void unFix();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    TopBaseWidget *topWdiget;
    QVBoxLayout *layout;
    CenterWidget *center;

    void InitUi();
    void InitConnect();
    void InitAnimation();

    bool isMousePress;
    QPoint windowPos;
    QPoint mousePos;

    QPropertyAnimation *closeOpacityAnimation;
    QPropertyAnimation *closemoveAnimation;
    QSystemTrayIcon *Tray;
    QRect WindowGeometry;
};

#endif // MAINWINDOW_H
