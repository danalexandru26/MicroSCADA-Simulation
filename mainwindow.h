#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QtSvgWidgets/QSvgWidget>
#include<QRandomGenerator>

#include"powernode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void drawBasicMicroScada();
    void simulationStep();
    void assignPowerNodes(QList<PowerNode*>& nodeList, QLCDNumber* first, QLCDNumber* second);

private:
    Ui::MainWindow *ui;

    PowerNode* parentLineA;
    PowerNode* parentLineB;
    QList<PowerNode*> powerDistribution_A{};
    QList<PowerNode*> powerDistribution_B{};
};
#endif // MAINWINDOW_H
