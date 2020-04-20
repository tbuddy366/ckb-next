#ifndef MACROTABLEMODEL_H
#define MACROTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "macroline.h"
#include <QDebug>

class MacroTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MacroTableModel(QObject* parent = nullptr) : QAbstractTableModel(parent) {}
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    inline void append(const macroLine& ml) {
        emit beginInsertRows(QModelIndex(), macroLines.length(), macroLines.length());
        macroLines.append(ml);
        emit endInsertRows();
    }
    inline void clear() {
        emit beginRemoveRows(QModelIndex(), 0, macroLines.length() - 1);
        macroLines.clear();
        emit endRemoveRows();
    }
    /*inline macroLine last() const {
        return macroLines.last();
    }*/
    inline macroLine at(int i) const {
        return macroLines.at(i);
    }
    inline int length() const {
        return macroLines.length();
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
private:
    QVector<macroLine> macroLines;
};

#include <QComboBox>
class MacroDropdown : public QComboBox
{
    Q_OBJECT
public:
    MacroDropdown(QWidget* p) : QComboBox(p) {
        insertItem(0, "↓");
        insertItem(1, "↑");
    }
};

#include <QStyledItemDelegate>
class MacroDropdownDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                          const QModelIndex& index) const {
        QWidget* editor = new MacroDropdown(parent);
        /*connect(editor, &MacroDropdown::currentIndexChanged,
                this, &MacroDropdownDelegate::commitAndCloseEditor);*/
        return editor;
    }
private slots:
    void commitAndCloseEditor();
};

#endif // MACROTABLEMODEL_H
