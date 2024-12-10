#ifndef MAINLIST_H
#define MAINLIST_H

#include <QAbstractListModel>

class MainList : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MainList(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    struct Item {
        QString name;
        QString type;
    };

    QList<Item> m_items;
};

#endif // MAINLIST_H
