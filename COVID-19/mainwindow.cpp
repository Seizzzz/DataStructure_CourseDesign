#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QString>
#include <fstream>

ofstream outfile("log.txt");

#include <iostream>
#include <vector>
#include <Windows.h>
#include "transport.h"
#include "city.h"
#include "tourist.h"
#include "route.h"
using namespace std;

vector<Tourist*> _Tourist_vector;
vector<City*> _City_vector;
vector<Transport*> _Transport_vector;
static int _time = 0;
static bool inited = false;

string digit_to_status(int n)
{
    switch (n)
    {
    case 0: return "UNKNOWN";
    case 1: return "WAITING";
    case 2: return "TRAVELLING";
    case 3: return "ARRIVED";
    case 4: return "FAILED";
    default: return "ERROR";
    }
}
string toRealTime(int t)
{
    if(t == INT_MAX) return "无限制";
    string res;
    res.append(to_string(t/24));
    res.append("天");
    res.append(to_string(t%24));
    res.append("小时");
    return res;
}
void update_all_tourist()
{
    for (auto& tor : _Tourist_vector)
    {
        if(tor->enabled) tor->update_status(_time);
    }
}
City* findInCityVector(QString cityname)
{
    for(auto city : _City_vector)
    {
        if(QString(city->name.c_str()) == cityname) return city;
    }
    return nullptr;
}
void MainWindow::updateUI(Ui::MainWindow* ui)
{
    ui->labelTime->setText(QString(toRealTime(++_time).c_str()));

    for(unsigned i=0;i<_Tourist_vector.size();i++){
        ui->tableWidgetTourist->setItem(i,0, new QTableWidgetItem(QString(_Tourist_vector[i]->nowat->name.c_str())));
        ui->tableWidgetTourist->setItem(i,1, new QTableWidgetItem(QString(_Tourist_vector[i]->start->name.c_str())));
        ui->tableWidgetTourist->setItem(i,2, new QTableWidgetItem(QString(_Tourist_vector[i]->destination->name.c_str())));
        ui->tableWidgetTourist->setItem(i,3, new QTableWidgetItem(digit_to_status(_Tourist_vector[i]->status).c_str()));
        ui->tableWidgetTourist->setItem(i,4, new QTableWidgetItem(QString(to_string(_Tourist_vector[i]->plan.risk).c_str())));
        ui->tableWidgetTourist->setItem(i,5, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->stlimit).c_str()));
        ui->tableWidgetTourist->setItem(i,6, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->limit).c_str()));
        if(!_Tourist_vector[i]->plan.mid_arrive_time.empty()) ui->tableWidgetTourist->setItem(i,8, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->plan.mid_arrive_time.back()).c_str()));
        QString plan;
        plan.append(_Tourist_vector[i]->nowat->name.c_str());
        for(auto i : _Tourist_vector[i]->plan.via){
            plan.append("->");
            plan.append(i->name.c_str());
        }
        ui->tableWidgetTourist->setItem(i,7, new QTableWidgetItem(plan));
        ui->widgetMap->drawTourist(_Tourist_vector[i], _time);
    }

    return;
}

void MainWindow::inputFromFile()
{
    //从city.txt文件添加城市
    ifstream cityStream("city.txt");
    string cityName;
    double cityRisk;
    int cityX, cityY;
    while(cityStream >> cityName >> cityRisk >> cityX >> cityY)
    {
        City* newCity = new City(cityName, _City_vector.size(), cityRisk);
        _City_vector.push_back(newCity);
        //更新选框
        ui->comboBoxTouristStart->addItem(newCity->name.c_str());
        ui->comboBoxTransportStart->addItem(newCity->name.c_str());
        ui->comboBoxTouristDes->addItem(newCity->name.c_str());
        ui->comboBoxTransportDes->addItem(newCity->name.c_str());
        //在树形图中创建条目
        ui->treeWidgetCity->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(newCity->name.c_str()))));
        //在地图上绘制城市
        newCity->pos = ui->widgetMap->drawCity(newCity->number, cityX, cityY);
        //输出至日志文件
        outfile << "======添加了城市======" << endl;
        outfile << "城市名: " << newCity->name << endl;
        outfile << "风险值: " << newCity->risk << endl;
        outfile << "====================" << endl;
    }

    //从transport.txt文件添加时刻表
    ifstream transportStream("transport.txt");
    string tranStart, tranDes;
    int tranKind, tranStartTime, tranCost;
    double tranRisk;
    while(transportStream >> tranKind >> tranStart >> tranDes >> tranStartTime >> tranRisk >> tranCost)
    {
        Transport* newTransport = new Transport(findInCityVector(QString(tranStart.c_str())), findInCityVector(QString(tranDes.c_str())), tranStartTime, tranRisk, tranCost);
        newTransport->transportKind = tranKind;
        _Transport_vector.push_back(newTransport);
        //向起始城市中添加路线
        findInCityVector(QString(tranStart.c_str()))->everyday_table.push_back(newTransport);
        //在树形图条目中补充内容
        ui->treeWidgetCity->findItems(QString(tranStart.c_str()),0).front()->addChild(new QTreeWidgetItem(QStringList() << newTransport->destination->name.c_str() << QString(to_string(newTransport->risk).c_str()) << QString(to_string(newTransport->start_time).c_str()) << QString(to_string(newTransport->time_cost).c_str())));
        //输出至日志文件
        outfile << "======添加了时刻表======" << endl;
        outfile << "始发站: " << newTransport->start->name << endl;
        outfile << "终点站: " << newTransport->destination->name << endl;
        outfile << "风险值: " << newTransport->risk << endl;
        outfile << "每日出发时间: " << newTransport->start_time << "时" << endl;
        outfile << "所需时长: " << newTransport->time_cost << "小时" << endl;
        outfile << "====================" << endl;
    }
    inited = true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1300, 600);
    timerUpdate = new QTimer(this);

    ui->tableWidgetTourist->setHorizontalHeaderLabels(QStringList() << "当前位置" << "起始地点" << "目的地点" << "状态" << "当前风险" << "最早出发时间" << "最晚到达时间" << "当前规划" << "预计到达时间");
    ui->treeWidgetCity->setHeaderLabels(QStringList() << "目的地" << "风险值" << "出发时间" << "时长");
    ui->comboBoxTransportKind->addItems(QStringList() << "汽车" << "火车" << "飞机");

    if(!inited) inputFromFile();

    connect(ui->pushButtonAddCity, &QPushButton::clicked, [=](){ //添加城市
        City* newCity = new City(ui->lineEditCityName->text().toStdString(), _City_vector.size(), ui->lineEditCityRisk->text().toDouble());
        _City_vector.push_back(newCity);
        //更新选框
        ui->comboBoxTouristStart->addItem(newCity->name.c_str());
        ui->comboBoxTransportStart->addItem(newCity->name.c_str());
        ui->comboBoxTouristDes->addItem(newCity->name.c_str());
        ui->comboBoxTransportDes->addItem(newCity->name.c_str());
        //在树形图中创建条目
        ui->treeWidgetCity->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(newCity->name.c_str()))));
        //在地图上绘制城市
        newCity->pos = ui->widgetMap->drawCity(newCity->number);
        //输出至日志文件
        outfile << "======添加了城市======" << endl;
        outfile << "城市名: " << newCity->name << endl;
        outfile << "风险值: " << newCity->risk << endl;
        outfile << "====================" << endl;
    });

    connect(ui->pushButtonAddTourist, &QPushButton::clicked, [=](){ //添加旅客
        Tourist* newTourist = new Tourist(findInCityVector(ui->comboBoxTouristStart->currentText()), findInCityVector(ui->comboBoxTouristDes->currentText()), ui->lineEditTouristLimit->text().toInt() + _time, _City_vector.size() - 1);
        newTourist->number = _Tourist_vector.size();
        newTourist->enabled = true;
        if(ui->checkBoxTouristNextDay->isChecked()) //第二天出发
        {
            newTourist->stlimit = (_time/24 + 1) * 24;
            newTourist->limit += 24;
        }
        else newTourist->stlimit = _time;
        if(!ui->checkBoxTouristTimeLimit->isChecked()) newTourist->limit = INT_MAX; //不限时
        _Tourist_vector.push_back(newTourist);
        //在表格中创建条目
        ui->tableWidgetTourist->setRowCount(ui->tableWidgetTourist->rowCount() + 1);
        for(unsigned i=0;i<_Tourist_vector.size();i++){
            ui->tableWidgetTourist->setItem(i,0, new QTableWidgetItem(QString(_Tourist_vector[i]->nowat->name.c_str())));
            ui->tableWidgetTourist->setItem(i,1, new QTableWidgetItem(QString(_Tourist_vector[i]->start->name.c_str())));
            ui->tableWidgetTourist->setItem(i,2, new QTableWidgetItem(QString(_Tourist_vector[i]->destination->name.c_str())));
            ui->tableWidgetTourist->setItem(i,3, new QTableWidgetItem(digit_to_status(_Tourist_vector[i]->status).c_str()));
            ui->tableWidgetTourist->setItem(i,5, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->stlimit).c_str()));
            ui->tableWidgetTourist->setItem(i,6, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->limit).c_str()));
        }
        //在地图上绘制旅客
        ui->widgetMap->drawTourist(newTourist, _time);
        //输出至日志文件
        outfile << "======添加了旅客======" << endl;
        outfile << "旅客序号: " << newTourist->number << endl;
        outfile << "起始地点: " << newTourist->start->name << endl;
        outfile << "目的地点: " << newTourist->destination->name << endl;
        outfile << "最晚到达时间: " << toRealTime(newTourist->limit) << endl;
        outfile << "====================" << endl;
    });

    connect(ui->pushButtonAddTransport, &QPushButton::clicked, [=](){ //添加时刻表
        Transport* newTransport = new Transport(findInCityVector(ui->comboBoxTransportStart->currentText()), findInCityVector(ui->comboBoxTransportDes->currentText()), ui->lineEditTransportStartTime->text().toInt(),ui->lineEditTransportRisk->text().toDouble(), ui->lineEditTransportTimecost->text().toUInt());
        if(ui->comboBoxTransportKind->currentText() == "汽车") newTransport->transportKind = 1;
        else if(ui->comboBoxTransportKind->currentText() == "火车") newTransport->transportKind = 2;
        else newTransport->transportKind = 3;
        _Transport_vector.push_back(newTransport);
        //向起始城市中添加路线
        findInCityVector(ui->comboBoxTransportStart->currentText())->everyday_table.push_back(newTransport);
        //在树形图条目中补充内容
        ui->treeWidgetCity->findItems(ui->comboBoxTransportStart->currentText(),0).front()->addChild(new QTreeWidgetItem(QStringList() << newTransport->destination->name.c_str() << QString(to_string(newTransport->risk).c_str()) << QString(to_string(newTransport->start_time).c_str()) << QString(to_string(newTransport->time_cost).c_str())));
        //输出至日志文件
        outfile << "======添加了时刻表======" << endl;
        outfile << "始发站: " << newTransport->start->name << endl;
        outfile << "终点站: " << newTransport->destination->name << endl;
        outfile << "风险值: " << newTransport->risk << endl;
        outfile << "每日出发时间: " << newTransport->start_time << "时" << endl;
        outfile << "所需时长: " << newTransport->time_cost << "小时" << endl;
        outfile << "====================" << endl;
    });

    connect(ui->checkBoxTime, &QCheckBox::stateChanged, [=](){ //运行复选框改变
       if(ui->checkBoxTime->isChecked()){
            ui->pushButtonAddCity->setEnabled(0);
            ui->pushButtonAddTourist->setEnabled(0);
            ui->pushButtonAddTransport->setEnabled(0);
            timerUpdate->start(1);
       }
       else{
           ui->pushButtonAddCity->setEnabled(1);
           ui->pushButtonAddTourist->setEnabled(1);
           ui->pushButtonAddTransport->setEnabled(1);
       }
    });

    connect(timerUpdate,&QTimer::timeout,[=](){ //计时器timeout更新
        if(ui->checkBoxTime->isChecked())
        {
            update_all_tourist();
            this->updateUI(ui);
        }
        timerUpdate->start(3000); //每3秒推进时间
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/resource/map.jpg");
    painter.drawPixmap(0,0,746,600,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

