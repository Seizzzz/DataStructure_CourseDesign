#include "mymap.h"
#include "route.h"
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>

const int UNKNOWN = 0;
const int WAITING = 1;
const int TRAVELLING = 2;
const int ARRIVED = 3;
const int FAILED = 4;
const int MAX_CITY = 20;
const int MAX_TOURIST = 20;

QPoint myMap::drawCity(int num)
{
    posCity[num]->setVisible(true);
    posCity[num]->move(labelPin->pos().x()+labelPin->width()/2-posCity[num]->width()/2,labelPin->pos().y()+labelPin->height()/2-posCity[num]->height()/2);

    return labelPin->pos();
}

void myMap::drawTourist(class Tourist* tor, int time)
{
    if(tor->nowat->name == tor->destination->name){ //已到达则不再绘制
        posTourist[tor->number]->setVisible(false);
        return;
    }

    if(tor->status == TRAVELLING){
        if(tor->plan.transportKind == 1) posTourist[tor->number]->setPixmap(QPixmap(":/resource/car.png"));
        else if(tor->plan.transportKind == 2) posTourist[tor->number]->setPixmap(QPixmap(":/resource/train.png"));
        else posTourist[tor->number]->setPixmap(QPixmap(":/resource/plane.png"));
        double div = ((double)time - (double)tor->plan.start_time) / (double)tor->plan.time_cost;
        double x = tor->nowat->pos.x() + (tor->plan.via[0]->pos.x() - tor->nowat->pos.x())*div,
               y = tor->nowat->pos.y() + (tor->plan.via[0]->pos.y() - tor->nowat->pos.y())*div;
        posTourist[tor->number]->move(x,y);
    }
    else
    {
        posTourist[tor->number]->move(tor->nowat->pos); //未知或等待
        posTourist[tor->number]->setPixmap(QPixmap(":/resource/tourist.png"));
    }
    posTourist[tor->number]->setVisible(true);
}

void myMap::mousePressEvent(QMouseEvent *event)
{
    this->labelPin->move(event->x()-labelPin->width()/2,event->y()-labelPin->height()/2);
}

myMap::myMap(QWidget *parent) : QWidget(parent)
{
    //绘制大头针
    this->labelPin = new QLabel(this);
    labelPin->setPixmap(QPixmap(":/resource/pin.png"));

    //绘制城市
    for(int i=0;i<MAX_CITY;i++)
    {
        QLabel* newLabel = new QLabel(this);
        newLabel->setVisible(false);
        newLabel->setPixmap(QPixmap(":/resource/city.png"));
        posCity.push_back(newLabel);
    }

    //绘制旅客
    for(int i=0;i<MAX_TOURIST;i++)
    {
        QLabel* newLabel = new QLabel(this);
        newLabel->setVisible(false);
        newLabel->setPixmap(QPixmap(":/resource/tourist.png"));
        posTourist.push_back(newLabel);
    }
}
