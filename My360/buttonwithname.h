#ifndef BUTTONWITHNAME_H
#define BUTTONWITHNAME_H

#include <QWidget>
#include <closebutton.h>
#include <QLabel>
#include <QVBoxLayout>

class ButtonWithName : public QWidget
{
    Q_OBJECT
public:
    ButtonWithName( QString FileName, int xnum  = 1,  QWidget *parent = 0, int ynum = 1, QString name = 0);
    ButtonWithName(QVector<QString> &list, QWidget *parent = 0, QString name = 0);
    void setSpacing(int space){ layout->setSpacing(space); }
    void setFontSize(int size){  font->setPointSize(size); nameLabel->setFont(*font);}

signals:

public slots:

protected:

private:
    QLabel *nameLabel;
    Button *Btn;
    QFont *font;
    QVBoxLayout *layout;
    QPalette *palette;
};

#endif // BUTTONWITHNAME_H
