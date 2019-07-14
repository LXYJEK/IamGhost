#ifndef MIDDLEDIALOG_H
#define MIDDLEDIALOG_H

#include <QDialog>

namespace Ui {
class MiddleDialog;
}

class MiddleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MiddleDialog(QWidget *parent = nullptr);
    ~MiddleDialog();

signals:
    void continue_signal();

    void quit_signal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MiddleDialog *ui;
};

#endif // MIDDLEDIALOG_H
