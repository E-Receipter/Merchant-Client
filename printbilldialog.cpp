#include "printbilldialog.h"
#include "ui_printbilldialog.h"
#include <QLabel>
#include <QPixmap>
PrintBillDialog::PrintBillDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintBillDialog)
{
    ui->setupUi(this);
}

PrintBillDialog::~PrintBillDialog()
{
    delete ui;
}

void PrintBillDialog::setData(QImage *data){
    QLabel* display = this->findChild<QLabel*>("JABImage");
    display->setPixmap(QPixmap::fromImage(*data));
}
