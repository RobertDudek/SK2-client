#include "gameslist.h"
#include "ui_gameslist.h"

GamesList::GamesList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamesList)
{
    ui->setupUi(this);
}

GamesList::~GamesList()
{
    delete ui;
}

void GamesList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

void GamesList::on_GamesList_rejected()
{
    emit gamesListCloseSig();
}

void GamesList::on_pushButton_clicked()
{
    emit newGameButtonSig();
}
