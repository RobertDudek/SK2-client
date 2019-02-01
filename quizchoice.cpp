#include "quizchoice.h"
#include "ui_quizchoice.h"

QuizChoice::QuizChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizChoice)
{
    ui->setupUi(this);
    ui->comboBox->addItem("New Quiz");
}

QuizChoice::~QuizChoice()
{
    delete ui;
}


void QuizChoice::on_QuizChoice_rejected()
{
    emit destroyedSig();
}

void QuizChoice::on_pushButton_clicked()
{
    emit quizChosenSig(ui->comboBox->currentIndex());
}
