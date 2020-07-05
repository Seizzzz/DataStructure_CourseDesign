#ifndef MYMAP_H
#define MYMAP_H

#include <QWidget>
#include <QLabel>
#include "tourist.h"
#include "city.h"
#include "route.h"

class myMap : public QWidget
{
    Q_OBJECT
public:
    explicit myMap(QWidget *parent = nullptr);

    QLabel* labelPin;
    void mousePressEvent(QMouseEvent *event);
    QPoint drawCity(int num);
    QPoint drawCity(int num, int x, int y);
    void drawTourist(Tourist* tor, int time);
    vector<QLabel*> posTourist;
    vector<QLabel*> posCity;

signals:

};

#endif // MYMAP_H
