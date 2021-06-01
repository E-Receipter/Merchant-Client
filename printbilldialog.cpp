#include "printbilldialog.h"
#include "ui_printbilldialog.h"

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

void PrintBillDialog::setData(QString &data){
    QTextEdit* dataBox = this->findChild<QTextEdit*>("DataBox");
    dataBox->setText(data);
}
