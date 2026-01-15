#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TransformerLayouts();
    WireLayout();
    circuitBreakerLayout();
}

void MainWindow::TransformerLayouts(){

    QGridLayout* layoutTrafo1 = qobject_cast<QGridLayout*>(ui->trafoLayout1->layout());
    QGridLayout* layoutTrafo2 = qobject_cast<QGridLayout*>(ui->trafoLayout2->layout());

    const QString trafoResource =  ":/symbols/resources/IEC_60617/IEC_60617_Transformer.svg";

    QSvgWidget* svg1 = new QSvgWidget(trafoResource);
    QSvgWidget* svg2= new QSvgWidget(trafoResource);

    layoutTrafo1->addWidget(svg1);
    layoutTrafo2->addWidget(svg2);
}

void MainWindow::WireLayout(){
    const QString wireSource = ":/symbols/resources/IEC_60617/IEC_60617_ConnectionLine.svg";

    QHBoxLayout* layoutWire1 = qobject_cast<QHBoxLayout*>(ui->hWire1->layout());

    QSvgWidget* wireSvg = new QSvgWidget(wireSource);

    layoutWire1->addWidget(wireSvg);
}

void MainWindow::circuitBreakerLayout(){
    const QString switchSource = ":/symbols/resources/IEC_60617/IEC_60617_Switch.svg";
    const QString breakerSource = ":/symbols/resources/IEC_60617/IEC_60617_Breaker.svg";

    QGridLayout* switchLayout1 = qobject_cast<QGridLayout*>(ui->switchLayout1->layout());

    QSvgWidget* switchSvg1 = new QSvgWidget(switchSource);

    switchLayout1->addWidget(switchSvg1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
