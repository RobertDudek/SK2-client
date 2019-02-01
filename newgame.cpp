#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_NewGame_rejected()
{
    emit newGameCloseSig();
}


void NewGame::on_pushButton_clicked()
{
    emit createGameButtonSig();
}
