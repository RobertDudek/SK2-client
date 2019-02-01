#ifndef GAMELOBBY_H
#define GAMELOBBY_H

#include <QDialog>

namespace Ui {
class GameLobby;
}

class GameLobby : public QDialog
{
    Q_OBJECT

public:
    explicit GameLobby(QWidget *parent = nullptr);
    ~GameLobby();
signals:
    void gameLobbyCloseSig();
private slots:
    void on_GameLobby_rejected();

private:
    Ui::GameLobby *ui;
};

#endif // GAMELOBBY_H
