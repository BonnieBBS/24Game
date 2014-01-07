#ifndef NEWGAMERDIALOG_H
#define NEWGAMERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class NewGamerDialog: public QDialog
{
    Q_OBJECT
private:
    QLabel *gamerNameLabel;
    QLineEdit *gamerNameLineEdit;
    QDialogButtonBox* buttons;

    void setUpGUI();

public:
    /////////////////////// problem !!!
    explicit NewGamerDialog(QWidget *parent):
        QDialog(parent)
{
    setUpGUI();
    setWindowTitle( tr("Add New Gamer") );
    setModal( true );
}

    ~NewGamerDialog();
    QString getGamerName();

signals:
    void acceptNewGamer(QString& gamerName);

public slots:
    // void slotAcceptNewGamer();
};

#endif // NEWGAMERDIALOG_H
