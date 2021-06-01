#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "billmodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionNew_Bill_triggered();

    void on_actionPrint_Bill_triggered();

private:
    Ui::MainWindow *ui;
    BillModel *billData;
};
#endif // MAINWINDOW_H
