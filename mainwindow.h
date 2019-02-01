#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <string>
#include <QtEndian>
#include "quizchoice.h"
#include "quizdetail.h"
#include "newquestion.h"
#include "gameslist.h"
#include "newgame.h"
#include "gamelobby.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setIpPortNick(QString, quint16, QString);
    bool tryToConnect();
    void tryProcessData();
    void ProcessMessage(QByteArray);
    void writeMessage(QString);
private slots:
    void readData();
    void displayError(QAbstractSocket::SocketError socketError);
    void on_addQuizButton_clicked();
    void showFromQuizUI();
    void onQuizChosenSig(int);
    void onQuizCreateSig(QString);
    void onQuizDetailCLoseSig();
    void onNewQuestionCloseSig();
    void onAddQuestionSig();
    void onCreateQuestionSig(QString,QString,QString,QString,QString);
    void on_playButton_clicked();
    void onGamesListCloseSig();
    void onCreateGameButtonSig();
    void onGameLobbyCloseSig();
    void onNewGameButtonSig();

signals:
    void newQuestionToQuizDetailSig(QString,QString,QString,QString,QString);
private:
    Ui::MainWindow *ui;
    QuizChoice quizUi;
    QuizDetail quizDetailUi;
    NewQuestion newQuestionUi;
    GamesList gamesListUi;
    NewGame newGameUi;
    GameLobby gameLobbyUi;

    QTcpSocket *tcpSocket;
    QString ip;
    quint16 port;
    QString nick;
    std::string message = "";
    uint32_t dataLength = 0;
    uint32_t dataToSendLength = 0;
    QByteArray dataToSend;
    QByteArray buffer;
};

#endif // MAINWINDOW_H
