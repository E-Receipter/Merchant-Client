#ifndef BILLMODEL_H
#define BILLMODEL_H

#include <QAbstractTableModel>

class BillModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BillModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void resetBill();
    void initBill();
    double getTotalPrice();
    QImage* getEncoded();
signals:
    void totalPriceChanged(QString &);
private:
    long shopId;
    long billId;
    QDateTime *datetime;
    QStringList itemName;
    QList<double> price;
    QList<uint> qty;

    QByteArray getProtoBufEncoded();
    QImage *getJABImage(QByteArray &);
};

#endif // BILLMODEL_H
