#ifndef FONTWIDGET_H
#define FONTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QPixmap>
#include <QString>

class FontWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FontWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QMap<QString, QPixmap> pixmapMap;

};

#endif // FONTWIDGET_H
