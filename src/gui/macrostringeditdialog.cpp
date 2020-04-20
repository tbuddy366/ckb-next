#include "macrostringeditdialog.h"
#include "ui_macrostringeditdialog.h"
#include <QDebug>

MacroStringEditDialog::MacroStringEditDialog(const QString& text, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MacroStringEditDialog)
{
    ui->setupUi(this);
    ui->plainTextEdit->insertPlainText(text);
}

MacroStringEditDialog::~MacroStringEditDialog()
{
    delete ui;
}

void MacroStringEditDialog::on_buttonBox_accepted()
{
    // Validate here
    QString macro = ui->plainTextEdit->toPlainText();
    accept();
}
