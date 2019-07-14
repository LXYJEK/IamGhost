#include "middledialog.h"
#include "ui_middledialog.h"

MiddleDialog::MiddleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiddleDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

MiddleDialog::~MiddleDialog()
{
    delete ui;
}

void MiddleDialog::on_pushButton_clicked()
{
    emit continue_signal();
    this->close();
}

void MiddleDialog::on_pushButton_2_clicked()
{
    emit quit_signal();
    this->close();
}
