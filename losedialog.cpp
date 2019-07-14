#include "losedialog.h"
#include "ui_losedialog.h"

LoseDialog::LoseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

LoseDialog::~LoseDialog()
{
    delete ui;
}

void LoseDialog::on_pushButton_clicked()
{
    emit continue_signal();
    this->close();
}

void LoseDialog::on_pushButton_2_clicked()
{
    emit quit_signal();
    this->close();
}
