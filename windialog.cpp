#include "windialog.h"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_pushButton_clicked()
{
    emit continue_signal();
    this->close();
}

void WinDialog::on_pushButton_2_clicked()
{
    emit quit_signal();
    this->close();
}
