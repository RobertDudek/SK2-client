#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket, &QIODevice::readyRead, this, &MainWindow::readData);
    typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error), this, &MainWindow::displayError);

    connect(&quizUi, &QuizChoice::destroyedSig, this, &MainWindow::showFromQuizUI);
    connect(&quizUi, &QuizChoice::quizChosenSig, this, &MainWindow::onQuizChosenSig);
    connect(&quizDetailUi, &QuizDetail::quizCreateSig, this, &MainWindow::onQuizCreateSig);
    connect(&quizDetailUi, &QuizDetail::quizDetailCloseSig, this, &MainWindow::onQuizDetailCLoseSig);
    connect(&newQuestionUi, &NewQuestion::newQuestionCloseSig, this, &MainWindow::onNewQuestionCloseSig);
    connect(&quizDetailUi, &QuizDetail::addQuestionSig, this, &MainWindow::onAddQuestionSig);
    connect(&newQuestionUi, &NewQuestion::createQuestionSig, this, &MainWindow::onCreateQuestionSig);
    connect(this, &MainWindow::newQuestionToQuizDetailSig, &quizDetailUi, &QuizDetail::onNewQuestionToQuizDetailSig);
    connect(&gamesListUi, &GamesList::gamesListCloseSig, this, &MainWindow::onGamesListCloseSig);
    connect(&newGameUi, &NewGame::createGameButtonSig, this, &MainWindow::onCreateGameButtonSig);
    connect(&gameLobbyUi, &GameLobby::gameLobbyCloseSig, this, &MainWindow::onGameLobbyCloseSig);
    connect(&gamesListUi, &GamesList::newGameButtonSig, this, &MainWindow::onNewGameButtonSig);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setIpPortNick(QString ip, quint16 port, QString nick){
    this->ip = ip;
    this->port = port;
    this->nick = nick;
    tryToConnect();
}

bool MainWindow::tryToConnect(){
    tcpSocket->connectToHost(ip,port);
    writeMessage(nick);
    return true;
}

void MainWindow::writeMessage(QString qstr){
    if(tcpSocket->state() > 2){
    QByteArray m;
    m.append(qstr);
    dataToSendLength = sizeof(m);
    dataToSend.setNum(dataToSendLength);
    dataToSend.append(m);
    int bytesSend = 0;
    uint32_t n = 0;
    while(n!=(dataToSendLength+4)){
        bytesSend += tcpSocket->write(dataToSend);
        if(bytesSend == -1) return;
        dataToSend = dataToSend.right(dataToSend.length()-bytesSend);
        n+=bytesSend;
    }
    dataToSendLength = 0;
    dataToSend.clear();
    }
}
void MainWindow::readData(){
    buffer.append(tcpSocket->readAll());
    tryProcessData();
}
void MainWindow::tryProcessData(){
    forever{
        if(dataLength == 0) {
            dataLength = buffer.left(4).toUShort();
        }
        //convert from network to host byte order
        dataLength = qFromBigEndian(dataLength);

        if(buffer.size()<(dataLength+4)){
            ProcessMessage(buffer.mid(4,dataLength));
            buffer = buffer.right(buffer.length()-(dataLength+4));
            dataLength = 0;
        } else {
            return;
        }
    }
}

void MainWindow::ProcessMessage(QByteArray m){
    message = m.toStdString();
    std::string command = message.substr(0,2);
    std::string record = message.substr(2);

    if(command == "gi"){

    }

}

void MainWindow::displayError(QAbstractSocket::SocketError err){
    qInfo() << err;
}

void MainWindow::on_addQuizButton_clicked()
{
    this->hide();
    quizUi.show();
}
void MainWindow::showFromQuizUI(){
    quizUi.hide();
    this->show();
}
void MainWindow::onQuizChosenSig(int a){
    quizUi.hide();
    //config quizDetailUi to show quiz of index a+1 or new for 0

    quizDetailUi.refreshNewQuiz();
    quizDetailUi.show();
}
void MainWindow::onQuizCreateSig(QString q){
    quizDetailUi.hide();
    //send New Quiz message
    writeMessage(q);
    this->show();
}
void MainWindow::onQuizDetailCLoseSig(){
    quizDetailUi.hide();
    this->show();
}
void MainWindow::onNewQuestionCloseSig(){
    newQuestionUi.hide();

    quizDetailUi.show();
}
void MainWindow::onAddQuestionSig(){
    quizDetailUi.hide();

    newQuestionUi.show();
}
void MainWindow::onCreateQuestionSig(QString q, QString a1, QString a2, QString a3, QString a4){
    newQuestionUi.hide();
    emit newQuestionToQuizDetailSig(q,a1,a2,a3,a4);
    quizDetailUi.show();
}

void MainWindow::on_playButton_clicked()
{
    this->hide();

    gamesListUi.show();
}
void MainWindow::onGamesListCloseSig(){
    gamesListUi.hide();
    this->show();
}
void MainWindow::onCreateGameButtonSig(){
    newGameUi.hide();

    gameLobbyUi.show();
}
void MainWindow::onGameLobbyCloseSig(){
    gameLobbyUi.hide();

    gamesListUi.show();
}
void MainWindow::onNewGameButtonSig(){
    gamesListUi.hide();

    newGameUi.show();
}
