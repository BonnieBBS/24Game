#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMessageBox>
#include <QTimer>
#include "myprofile.h"
#include "rosetta.h"
#include "counter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Counter *counter = new Counter(100);
    QTimer *timer = new QTimer(counter);

private slots:
    void on_startButton_clicked();
    void on_actionAbout_triggered();
    void on_submitButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
