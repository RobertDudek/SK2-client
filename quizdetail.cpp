#include "quizdetail.h"
#include "ui_quizdetail.h"

QuizDetail::QuizDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizDetail)
{
    ui->setupUi(this);
}

QuizDetail::~QuizDetail()
{
    delete ui;
}

void QuizDetail::on_createQuizButton_clicked()
{
    emit quizCreateSig(newQuiz);
}
void QuizDetail::refreshNewQuiz(){
    //newQuiz = process the list into ready New Quiz command
    newQuiz = "nq";

}

void QuizDetail::on_QuizDetail_rejected()
{
    emit quizDetailCloseSig();
}

void QuizDetail::on_addQuestionButton_clicked()
{
    emit addQuestionSig();
}
void QuizDetail::onNewQuestionToQuizDetailSig(QString q, QString a1, QString a2, QString a3, QString a4){
    ui->listWidget->addItem(q);
}
