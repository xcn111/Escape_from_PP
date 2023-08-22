#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent):QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("游戏失败！");
    this->parent=parent;
}

void MyDialog::on_pushButton_clicked()
{
    parent->close();
}

