#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "ui_dialog.h"

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    MyDialog(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QWidget *parent;
};

#endif // MYDIALOG_H
