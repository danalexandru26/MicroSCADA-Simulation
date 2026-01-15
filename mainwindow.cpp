#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"powernode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawBasicMicroScada();

}

void MainWindow::drawBasicMicroScada(){
    QString scadaDiagramSource = ":/symbols/resources/IEC_60617/IEC_60617_ScadaDiagramMain.svg";

    QWidget* parentContainer = qobject_cast<QWidget*>(ui->scadaWidget);

    QSvgWidget* svg = new QSvgWidget(scadaDiagramSource, parentContainer);
    svg->setGeometry(0, 0, parentContainer->width(), parentContainer->height());

    QTimer* stepTimer100ms = new QTimer(this);
    connect(stepTimer100ms, &QTimer::timeout, this, &MainWindow::simulationStep);
    stepTimer100ms->start(100);

}

void MainWindow::simulationStep(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
