#ifndef MACROSTRINGEDITDIALOG_H
#define MACROSTRINGEDITDIALOG_H

#include <QDialog>

namespace Ui {
class MacroStringEditDialog;
}

class MacroStringEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MacroStringEditDialog(const QString& text, QWidget* parent = nullptr);
    ~MacroStringEditDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MacroStringEditDialog* ui;
};

#endif // MACROSTRINGEDITDIALOG_H
