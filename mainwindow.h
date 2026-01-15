#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QtSvgWidgets/QSvgWidget>

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

    void drawBasicMicroScada();
    void simulationStep();

private:
    Ui::MainWindow *ui;
    QList<PowerNode*> powerDistribution_A{};
};
#endif // MAINWINDOW_H
