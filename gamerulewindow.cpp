#include "gamerulewindow.h"
#include "ui_gamerulewindow.h"

GameRuleWindow::GameRuleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRuleWindow)
{
    ui->setupUi(this);
}

GameRuleWindow::~GameRuleWindow()
{
    delete ui;
}
