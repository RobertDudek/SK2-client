#ifndef QUIZCHOICE_H
#define QUIZCHOICE_H

#include <QDialog>

namespace Ui {
class QuizChoice;
}

class QuizChoice : public QDialog
{
    Q_OBJECT

public:
    explicit QuizChoice(QWidget *parent = nullptr);
    ~QuizChoice();

signals:
    void destroyedSig();
    void quizChosenSig(int);

private slots:
    void on_QuizChoice_rejected();

    void on_pushButton_clicked();

private:
    Ui::QuizChoice *ui;
};

#endif // QUIZCHOICE_H
