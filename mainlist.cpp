#include "mainlist.h"

MainList::MainList(QObject *parent)
    : QAbstractListModel(parent)
{
    m_items =
    {
        {"Item 1", "Type A"},
        {"Item 2", "Type B"},
        {"Item 3", "Type C"}
    };
}

QVariant MainList::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

int MainList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

QVariant MainList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_items.size())
        return QVariant();

    const auto &item = m_items.at(index.row());

    switch (role) {
    case Qt::UserRole + 1 :
        return item.name;
        break;
    case Qt::UserRole + 2 :
        return item.type;
        break;
    default:
        return QVariant();
        break;
    }
}

QHash<int, QByteArray> MainList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "name";
    roles[Qt::UserRole + 2] = "type";

    return roles;
}
