#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
#include <vector>
#include "myprofile.h"
#include "rosetta.h"
#include "counter.h"
#include "gamer.h"

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

    // Signals & Slots
    QMessageBox *timeupMessageBox = new QMessageBox(this);
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
