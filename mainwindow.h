#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
#include <vector>
#include "myprofile.h"
#include "gamerulewindow.h"
#include "rosetta.h"
#include "counter.h"
#include "gamer.h"
#include "answersDatabase.h"
#include "infix2postfix.h"

//#include "newGamerDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    AnswerDatabase* answerDatabase = new AnswerDatabase("/home/bonnie/Projects/MyQt/24Game/allAnswers.dat");

    // Signals & Slots
    QMessageBox *timeupMessageBox = new QMessageBox(this);
    QMessageBox *answerMessageBox = new QMessageBox(this);
    void forConnections();
    void makeConnections();

    // Timing
    Counter *counter = new Counter(100);
    QTimer *timer = new QTimer(counter);

    // Gamer Management
    GamersVector *allGamers = new GamersVector();
    bool login = false;
    Gamer *currentGamer;

signals:
    QString userLoggedIn(QString s);
    void submitted();
    void noMoreChance();
    void right();
    void wrong();

private slots:
    void on_actionAbout_triggered();
    void on_actionContent_triggered();
    void on_actionNew_Game_triggered();
    void on_action_New_Gamer_triggered();
    void on_action_Login_triggered();
    void on_action_Rankings_triggered();
    void on_startButton_clicked();
    void on_submitButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
