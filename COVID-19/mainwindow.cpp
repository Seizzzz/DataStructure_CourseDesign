#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QString>

#include <iostream>
#include <vector>
#include <Windows.h>
#include "transport.h"
#include "city.h"
#include "tourist.h"
#include "route.h"
using namespace std;

const int UNKNOWN = 0;
const int WAITING = 1;
const int TRAVELLING = 2;
const int ARRIVED = 3;
const int FAILED = 4;

vector<Tourist*> _Tourist_vector;
vector<City*> _City_vector;
vector<Transport*> _Transport_vector;
static int _time = 0;

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
    string res;
    res.append(to_string(t/24));
    res.append("天");
    res.append(to_string(t%24));
    res.append("小时");
    return res;
}
void dbg_City()
{
    for (auto city : _City_vector)
    {
        //序号 名称 风险
        cout << city->number << ". " << city->name << " " << city->risk << endl;
    }
}
void dbg_Tourist()
{
    for (auto person : _Tourist_vector)
    {
        //序号 状态 剩余时间
        cout << person->number << ". " << digit_to_status(person->status) << " " << person->limit - _time << endl;
    }
}
void update_all_tourist()
{
    for (auto& tor : _Tourist_vector)
    {
        tor->update_status(_time);
        /*
        switch (tor->status)
        {
        case UNKNOWN: {
            tor->plan_route(_time);
            tor->update_status(_time);
            break;
        }
        case WAITING: {
            tor->update_status(_time);
            break;
        }
        case TRAVELLING: {
            tor->update_status(_time);
            break;
        }
        case ARRIVED: {
            tor->plan_route(_time);
            tor->update_status(_time);
            break;
        }
        }
        */
    }
}
void input()
{
    cout << "1. 添加旅客" << endl;
    cout << "2. 添加城市" << endl;
    cout << "3. 添加时刻表" << endl;
    cout << "4. 无操作" << endl;
    int opt; cin >> opt;
    switch (opt)
    {
    case 1: {
        cout << "输入旅客的出发点、目的地、时限" << endl;
        dbg_City();
        int st, des, limit;
        cin >> st >> des >> limit;
        Tourist* newTourist = new Tourist(_City_vector[st], _City_vector[des], limit + _time, _City_vector.size() - 1);
        newTourist->number = _Tourist_vector.size();
        _Tourist_vector.push_back(newTourist);
        break;
    }
    case 2: {
        cout << "输入城市名称、风险值" << endl;
        string name;
        double risk;
        cin >> name >> risk;
        City* newCity = new City(name, _City_vector.size(), risk);
        _City_vector.push_back(newCity);
        break;
    }
    case 3: {
        cout << "输入该次出发站、终点站、每日出发时间、风险值、所需时间" << endl;
        dbg_City();
        int st, des, st_time, cost;
        double risk;
        cin >> st >> des >> st_time >> risk >> cost;
        Transport* newTransport = new Transport(_City_vector[st], _City_vector[des], st_time, risk, cost);
        _Transport_vector.push_back(newTransport);
        _City_vector[st]->everyday_table.push_back(newTransport);
        break;
    }
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
        ui->tableWidgetTourist->setItem(i,4, new QTableWidgetItem(QString(to_string(_Tourist_vector[i]->risk).c_str())));
        ui->tableWidgetTourist->setItem(i,5, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->limit).c_str()));
        QString plan;
        plan.append(_Tourist_vector[i]->nowat->name.c_str());
        for(auto i : _Tourist_vector[i]->plan.via){
            plan.append("->");
            plan.append(i->name.c_str());
        }
        ui->tableWidgetTourist->setItem(i,6, new QTableWidgetItem(plan));
        ui->widgetMap->drawTourist(_Tourist_vector[i], _time);
    }

    return;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1300, 600);
    timerUpdate = new QTimer(this);

    ui->tableWidgetTourist->setHorizontalHeaderLabels(QStringList() << "当前位置" << "起始" << "目的" << "状态" << "当前风险" << "最晚时间" << "当前规划");
    ui->treeWidgetCity->setHeaderLabels(QStringList() << "目的地" << "风险值" << "出发时间" << "时长");
    ui->comboBoxTransportKind->addItems(QStringList() << "汽车" << "火车" << "飞机");

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
    });

    connect(ui->pushButtonAddTourist, &QPushButton::clicked, [=](){ //添加旅客
        Tourist* newTourist = new Tourist(findInCityVector(ui->comboBoxTouristStart->currentText()), findInCityVector(ui->comboBoxTouristDes->currentText()), ui->lineEditTouristLimit->text().toInt() + _time, _City_vector.size() - 1);
        newTourist->number = _Tourist_vector.size();
        if(ui->checkBoxTouristNextDay->isChecked()) newTourist->stlimit = (_time/24 + 1) * 24; //第二天出发
        if(!ui->checkBoxTouristTimeLimit->isChecked()) newTourist->limit = INT_MAX; //不限时
        _Tourist_vector.push_back(newTourist);
        //在表格中创建条目
        ui->tableWidgetTourist->setRowCount(ui->tableWidgetTourist->rowCount() + 1);
        for(unsigned i=0;i<_Tourist_vector.size();i++){
            ui->tableWidgetTourist->setItem(i,0, new QTableWidgetItem(QString(_Tourist_vector[i]->nowat->name.c_str())));
            ui->tableWidgetTourist->setItem(i,1, new QTableWidgetItem(QString(_Tourist_vector[i]->start->name.c_str())));
            ui->tableWidgetTourist->setItem(i,2, new QTableWidgetItem(QString(_Tourist_vector[i]->destination->name.c_str())));
            ui->tableWidgetTourist->setItem(i,3, new QTableWidgetItem(digit_to_status(_Tourist_vector[i]->status).c_str()));
            ui->tableWidgetTourist->setItem(i,5, new QTableWidgetItem(toRealTime(_Tourist_vector[i]->limit).c_str()));
        }
        //在地图上绘制旅客
        ui->widgetMap->drawTourist(newTourist, _time);
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
        timerUpdate->start(3000);
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

