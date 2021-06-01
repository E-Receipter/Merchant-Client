#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "billmodel.h"
#include "printbilldialog.h"
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , billData(new BillModel)
{
    ui->setupUi(this);
    ui->billData->setModel(this->billData);

    QLineEdit *totalPriceField = this->findChild<QLineEdit*>("TotalPrice");
    QObject::connect(this->billData,&BillModel::totalPriceChanged,totalPriceField,&QLineEdit::setText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Bill_triggered()
{
    this->billData->resetBill();
}



void MainWindow::on_actionPrint_Bill_triggered()
{
    PrintBillDialog dialog;
    QString data = this->billData->getEncoded();
    dialog.setData(data);
    dialog.setModal(true);
    dialog.exec();

}

