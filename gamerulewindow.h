#ifndef GAMERULEWINDOW_H
#define GAMERULEWINDOW_H

#include <QDialog>

namespace Ui {
class GameRuleWindow;
}

class GameRuleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameRuleWindow(QWidget *parent = 0);
    ~GameRuleWindow();

private:
    Ui::GameRuleWindow *ui;
};

#endif // GAMERULEWINDOW_H
