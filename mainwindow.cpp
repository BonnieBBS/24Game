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

void MainWindow::on_actionAbout_triggered()
{
    MyProfile *mp = new MyProfile(this);
    mp->show();
}

multiset<int> digits1;
bool flag;

void MainWindow::on_startButton_clicked()
{
    /////timer.restart();
    digits1 = rosetta();
    string fournumbers;
    for(auto iter = digits1.begin(); iter != digits1.end(); iter++)
    {
        //cout << *iter << " ";
        fournumbers += '0'+(*iter);
        fournumbers += ' ';
    }
    cout << "fournumbers is: " << fournumbers << endl;
    //cout << "HHHHHEEEEEEEEEEERRRRRRRRRRRRRRRRRREEEEEEEEEEEEEE" << endl;
    ui->label->setText(fournumbers.c_str());
    double wholeLength = 100;

    QMessageBox *timeupMessageBox = new QMessageBox(this);
    timeupMessageBox->setText("Time's up !!!");

    ui->progressBar->setValue(wholeLength);
    counter->setCount(100);
    counter->setBar(ui->progressBar);
    connect(timer, SIGNAL(timeout()), counter, SLOT(decrease()));
    connect(counter, SIGNAL(valueChanged()), timer, SLOT(start(int)));
    connect(counter, SIGNAL(timeout()), timer, SLOT(stop()));
    connect(counter, SIGNAL(timeout()), timeupMessageBox, SLOT(exec()));
    timer->start(400);
    //while(wholeLength>0)
    /*{
        //connect(timer, SIGNAL(timeout()), ui->progressBar, SLOT(setValue(wholeLength)));
        connect(timer, SIGNAL(timeout), ui->label_2, SLOT(setText(wholeLength)));
        wholeLength--;
        timer->start(400);
        cout << wholeLength << endl;
    }*/
    /*
     flag = true;
    while(wholeLength>0 && flag)
    {
        wholeLength -= 0.00000001;
        ui->progressBar->setValue(wholeLength);
    }////////////////THREAD!!!!!!!!!!!!!!!!!!!!!!!!!
*/
}

void MainWindow::on_submitButton_clicked()
{
    flag = false;
    cout << "Sumbit was pushed." << endl;
    string ans = (ui->lineEdit->text()).toStdString();
    cout << "The input is: " << ans << endl;
    // showMultisetInt(digits1);
    string judgeans = judgeAns(ans, digits1);
    cout << "The judge is: " << judgeans << endl;
    QString judge = QString::fromStdString(judgeans);
    ui->label->setText(ui->label->text() + " " + judge);
    cout << "*********************TIME*********************" << endl;
    /////cout << timer.elapsed();
    cout << "here" << endl;
}
