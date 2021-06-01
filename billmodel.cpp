#include "billmodel.h"
#include <QDateTime>
BillModel::BillModel(QObject *parent) : QAbstractTableModel(parent)
{
    this->initBill();
}

void BillModel::initBill(){
    this->shopId = 1;
    this->billId = random();
    this->datetime = new QDateTime(QDateTime::currentDateTime());
    this->itemName << "";
    this->price << 0.00;
    this->qty << 0;
}

void BillModel::resetBill() {
    this->beginResetModel();
    this->removeRows(0,this->rowCount());
    this->endResetModel();
    this->initBill();
}

QString BillModel::getEncoded(){
    QString data{"hello"};
    return data;
}
long BillModel::getTotalPrice(){
    long total = 0;
    for(int i=0;i<this->itemName.length();i++){
        total += this->price[i]*this->qty[i];
    }
    return total;
}

int BillModel::rowCount(const QModelIndex &parent) const
{
    return this->itemName.length();
}
int BillModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}
QVariant BillModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();
    if(row>=this->itemName.length())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch(column){
            case 0:
                return this->itemName[row];
            case 1:
                return this->price[row];
            case 2:
                return this->qty[row];
            case 3:
                return this->price[row] * this->qty[row];
        }
    }
    return QVariant();
}
bool BillModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int column = index.column();
    QString totalPriceData;
    if(row == (this->itemName.length()-1) && column == 2){
        this->insertRow(this->itemName.length());
    }
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch(column){
            case 0:
                this->itemName[row] = value.toString();
                return true;
            case 1:
                this->price[row] = value.toDouble();
                totalPriceData = QString::number(this->getTotalPrice());
                emit totalPriceChanged(totalPriceData);
                return true;
            case 2:
                this->qty[row] = value.toUInt();
                totalPriceData = QString::number(this->getTotalPrice());
                emit totalPriceChanged(totalPriceData);
                return true;
        }
    }
    return false;
}

Qt::ItemFlags BillModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
   if(index.column() == 3)
       return QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant BillModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Item Name");
        case 1:
            return QString("Price");
        case 2:
            return QString("Qty");
        case 3:
            return QString("Total Price");
        }
    }
    return QVariant();
}
bool BillModel::insertRows(int row, int count, const QModelIndex &parent){
    this->beginInsertRows(parent,row,row+count-1);
    for(int i=row;i<(row+count);i++){
        this->itemName.insert(i,"");
        this->price.insert(i,0.00);
        this->qty.insert(i,0);
    }
    this->endInsertRows();
    return true;
}
bool BillModel::removeRows(int row, int count, const QModelIndex &parent){
    this->beginRemoveRows(parent,row,row+count-1);
    this->itemName.remove(row,count);
    this->price.remove(row,count);
    this->qty.remove(row,count);
    this->endRemoveRows();
    return true;
}
