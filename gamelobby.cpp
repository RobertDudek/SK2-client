#include "gamelobby.h"
#include "ui_gamelobby.h"

GameLobby::GameLobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameLobby)
{
    ui->setupUi(this);
}

GameLobby::~GameLobby()
{
    delete ui;
}

void GameLobby::on_GameLobby_rejected()
{
    emit gameLobbyCloseSig();
}
