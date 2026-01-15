#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"powernode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawBasicMicroScada();

    QLCDNumber* parentVoltageA = qobject_cast<QLCDNumber*>(ui->trafo1V);
    QLCDNumber* parentPowerA = qobject_cast<QLCDNumber*>(ui->trafo1P);
    parentLineA = new PowerNode(parentVoltageA, parentPowerA, this);

    QLCDNumber* parentVoltageB = qobject_cast<QLCDNumber*>(ui->trafo2V);
    QLCDNumber* parentPowerB = qobject_cast<QLCDNumber*>(ui->trafo2P);
    parentLineB = new PowerNode(parentVoltageB, parentPowerB, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::drawBasicMicroScada(){
    QString scadaDiagramSource = ":/symbols/resources/IEC_60617/IEC_60617_ScadaDiagramMain.svg";

    QWidget* parentContainer = qobject_cast<QWidget*>(ui->scadaWidget);

    QSvgWidget* svg = new QSvgWidget(scadaDiagramSource, parentContainer);
    svg->setGeometry(0, 0, parentContainer->width(), parentContainer->height());

    QTimer* stepTimer100ms = new QTimer(this);
    connect(stepTimer100ms, &QTimer::timeout, this, &MainWindow::simulationStep);
    stepTimer100ms->start(2000);

}

void MainWindow::simulationStep(){
    parentLineA->setNodeVoltage(QRandomGenerator::global()->bounded(210, 240));
    parentLineA->setNodeTotalPower(QRandomGenerator::global()->bounded(600, 1300));

    parentLineB->setNodeVoltage(QRandomGenerator::global()->bounded(210, 240));
    parentLineB->setNodeTotalPower(QRandomGenerator::global()->bounded(600, 1300));

}

void MainWindow::assignPowerNodes(QList<PowerNode*>& nodeList, QLCDNumber* first, QLCDNumber* second){

}

