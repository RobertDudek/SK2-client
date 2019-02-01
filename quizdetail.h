#ifndef QUIZDETAIL_H
#define QUIZDETAIL_H

#include <QDialog>

namespace Ui {
class QuizDetail;
}

class QuizDetail : public QDialog
{
    Q_OBJECT

public:
    explicit QuizDetail(QWidget *parent = nullptr);
    ~QuizDetail();
    void refreshNewQuiz();
signals:
    void quizCreateSig(QString);
    void quizDetailCloseSig();
    void addQuestionSig();
public slots:
    void onNewQuestionToQuizDetailSig(QString,QString,QString,QString,QString);

private slots:
    void on_createQuizButton_clicked();

    void on_QuizDetail_rejected();

    void on_addQuestionButton_clicked();



private:
    Ui::QuizDetail *ui;

    QString newQuiz = "nq";
};

#endif // QUIZDETAIL_H
