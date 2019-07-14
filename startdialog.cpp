#include "startdialog.h"
#include "ui_startdialog.h"


StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_pushButton_clicked()
{
    emit start_signal();
    this->close();
}
