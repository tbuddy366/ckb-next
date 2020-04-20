#include "macrotablemodel.h"

int MacroTableModel::rowCount(const QModelIndex& parent) const
{
    return macroLines.length();
}

int MacroTableModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant MacroTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole){
        const macroLine ml = macroLines.at(index.row());
        switch(index.column()){
            case 0:
                return QString((ml.keyDown ? "↓" : "↑"));
            case 1:
                return QString(ml.key);
            case 2:
                return (ml.usTime == -1 ? 0 : ml.usTime);
            default:
                return "Unknown";
        }

       /*return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);*/
    }
    return QVariant();
}
#include <QSize>
QVariant MacroTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation != Qt::Horizontal)
        return QVariant();

    if(role == Qt::DisplayRole) {
        switch(section){
           case 1:
               return QString(tr("Key"));
           case 2:
               return QString(tr("Delay"));
           default:
               return QVariant();
        }
    }/* else if (role == Qt::SizeHintRole) {
        return QSize(6, 6);
    }*/
    return QVariant();

}

Qt::ItemFlags MacroTableModel::flags(const QModelIndex &idx) const
{
    if (!idx.isValid())
        return Qt::ItemIsEnabled;
    else if(idx == index(0, 2))
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

bool MacroTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        qDebug() << value;
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

void MacroDropdownDelegate::commitAndCloseEditor()
{
    MacroDropdown* editor = qobject_cast<MacroDropdown*>(sender());
   // editor->
}
