#include "WarningDialog.h"
#include "ui_WarningDialog.h"

WarningDialog::WarningDialog(QDialog *parent)
    : ui(new Ui::WarningDialog)
{
    resize(400,400);
    ui->setupUi(this);
}
