#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

multiset<int> digits1;

void MainWindow::on_pushButton_clicked()
{
    digits1 = rosetta();
    string fournumbers;
    //cout << "HHHHHEEEEEEEEEEERRRRRRRRRRRRRRRRRREEEEEEEEEEEEEE" << endl;
    for(auto iter = digits1.begin(); iter != digits1.end(); iter++)
    {
        //cout << *iter << " ";
        fournumbers += '0'+(*iter);
        fournumbers += ' ';
    }
    cout << "fournumbers is: " << fournumbers << endl;
    //cout << "HHHHHEEEEEEEEEEERRRRRRRRRRRRRRRRRREEEEEEEEEEEEEE" << endl;
    ui->label->setText(fournumbers.c_str());
}

void MainWindow::on_actionAbout_triggered()
{
    MyProfile *mp = new MyProfile(this);
    mp->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    cout << "Sumbit was pushed." << endl;
    string ans = (ui->lineEdit->text()).toStdString();
    cout << "The input is: " << ans << endl;
    // showMultisetInt(digits1);
    string judgeans = judgeAns(ans, digits1);
    cout << "The judge is: " << judgeans << endl;
    QString judge = QString::fromStdString(judgeans);
    ui->label->setText(ui->label->text() + " " + judge);
}
