#include "newquestion.h"
#include "ui_newquestion.h"

NewQuestion::NewQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewQuestion)
{
    ui->setupUi(this);
}

NewQuestion::~NewQuestion()
{
    delete ui;
}

void NewQuestion::on_NewQuestion_rejected()
{
    emit newQuestionCloseSig();
}

void NewQuestion::on_createQuestionButton_clicked()
{

    emit createQuestionSig(ui->question->toPlainText(),ui->answer1->text(),
                           ui->answer2->text(),ui->answer3->text(),ui->answer4->text());
    ui->question->setText("Question");
    ui->answer1->setText("answer 1");
    ui->answer2->setText("answer 2");
    ui->answer3->setText("answer 3");
    ui->answer4->setText("answer 4");
}
