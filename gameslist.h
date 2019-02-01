#ifndef GAMESLIST_H
#define GAMESLIST_H

#include <QDialog>
//#include <QWidgetItem>
//#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class GamesList;
}

class GamesList : public QDialog
{
    Q_OBJECT

public:
    explicit GamesList(QWidget *parent = nullptr);
    ~GamesList();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_GamesList_rejected();

    void on_pushButton_clicked();

signals:
    void gamesListCloseSig();
    void newGameButtonSig();
private:
    Ui::GamesList *ui;
};

#endif // GAMESLIST_H
