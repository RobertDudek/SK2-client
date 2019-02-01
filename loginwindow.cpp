#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{


    this->hide();

    mainUI.setIpPortNick(ui->lineEdit->text(),ui->lineEdit_2->text().toUShort(),ui->lineEdit_3->text());

    mainUI.show();

}
