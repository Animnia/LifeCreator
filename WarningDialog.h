#ifndef WARNINGDIALOG_H
#define WARNINGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class WarningDialog;
}
QT_END_NAMESPACE

class WarningDialog : public QDialog
{
    Q_OBJECT

public:
    WarningDialog(QDialog *parent = nullptr);
    ~WarningDialog();



private:
    Ui::WarningDialog *ui;
};
#endif // WARNINGDIALOG_H
