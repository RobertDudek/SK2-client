#ifndef NEWQUESTION_H
#define NEWQUESTION_H

#include <QDialog>

namespace Ui {
class NewQuestion;
}

class NewQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit NewQuestion(QWidget *parent = nullptr);
    ~NewQuestion();
signals:
    void newQuestionCloseSig();
    void createQuestionSig(QString,QString,QString,QString,QString);
private slots:
    void on_NewQuestion_rejected();

    void on_createQuestionButton_clicked();

private:
    Ui::NewQuestion *ui;
};

#endif // NEWQUESTION_H
