#ifndef LOSEDIALOG_H
#define LOSEDIALOG_H

#include <QDialog>

namespace Ui {
class LoseDialog;
}

class LoseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoseDialog(QWidget *parent = nullptr);
    ~LoseDialog();

signals:
    void continue_signal();

    void quit_signal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoseDialog *ui;
};

#endif // LOSEDIALOG_H
