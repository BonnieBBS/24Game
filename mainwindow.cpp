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

void MainWindow::forConnections()
{
    timeupMessageBox->setText("Time's up !!!");
}

void MainWindow::makeConnections()
{
    connect(this, SIGNAL(userLoggedIn(QString)), ui->currentGamerLabel, SLOT(setText(QString)));

    connect(timer, SIGNAL(timeout()), counter, SLOT(decrease()));
    connect(counter, SIGNAL(valueChanged()), timer, SLOT(start(int)));
    connect(counter, SIGNAL(timeout()), timer, SLOT(stop()));
    connect(counter, SIGNAL(timeout()), timeupMessageBox, SLOT(exec()));

    connect(this, SIGNAL(submitted()), timer, SLOT(stop()));
    connect(this, SIGNAL(noMoreChance()), timer, SLOT(stop()));
}

void MainWindow::on_actionAbout_triggered()
{
    MyProfile *mp = new MyProfile(this);
    mp->show();
}

void MainWindow::on_actionContent_triggered()
{

}

void MainWindow::on_actionNew_Game_triggered()
{

}
//void MainWindow::userLoggedIn(QString s)
//{
//    std::cout << std::endl;
//}
void MainWindow::on_action_New_Gamer_triggered()
{
    std::cout << "new gamer" << std::endl;
    ui->currentGamerLabel->setText("test");
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Name"),tr("User name:"), QLineEdit::Normal,"", &ok);
    ///connect(this, SIGNAL(userLoggedIn(QString)), ui->currentGamerLabel, SLOT(hide()));
    login = true;
    currentGamer = new Gamer(text.toStdString());
    allGamers->addGamer(currentGamer);
    emit userLoggedIn(text);
    //Gamer *temp = new Gamer(text.toStdString());
    //allGamers->addGamer(*temp);
    //int index = allGamers->searchGamerName(temp->Gamername);
    //currentGamerPointer = &(allGamers->allGamers[index]);
    std::cout << "Check " << currentGamer->Gamername << std::endl;
    //NewGamerDialog* newGamerDialog = new NewGamerDialog( this );
    //loginDialog->setUsername( "Luca" );  // optional
    //connect( loginDialog,SIGNAL(acceptLogin(QString&,QString&,int&)),this,SLOT(slotAcceptUserLogin(QString&,QString&)));
    //newGamerDialog->exec();

    //Gamer* newGamer = new Gamer();
}

void MainWindow::on_action_Login_triggered()
{

}

void MainWindow::on_action_Rankings_triggered()
{

}

multiset<int> digits1;
bool flag;

void MainWindow::on_startButton_clicked()
{
    /////timer.restart();
    if(!login)
        QMessageBox::warning(this, tr("Warning"), tr("You need to login first!"));
    else
    {
        if(currentGamer->getGameTimes()==3)
        {
            emit noMoreChance();
            QMessageBox::warning(this, tr("Warning"), tr("Everyone only has three chances!"));
        }
        else
        {
            currentGamer->addGameTimes();
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

            ui->progressBar->setValue(wholeLength);
            counter->setCount(100);
            counter->setBar(ui->progressBar);

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
    }
}

void MainWindow::on_submitButton_clicked()
{
    emit submitted();
    flag = false;
    cout << "Sumbit was pushed." << endl;
    string ans = (ui->lineEdit->text()).toStdString();
    cout << "The input is: " << ans << endl;
    // showMultisetInt(digits1);
    string judgeans = judgeAns(ans, digits1);
    QString QSpoint = QString::number(currentGamer->getPoint());
    if(getCorrectness())
    {
        currentGamer->addPoint(counter->getCount());
        ui->currentPointsLabel->setText(QSpoint);
    }
    cout << "The judge is: " << judgeans << endl;
    QString judge = QString::fromStdString(judgeans);
    ui->label->setText(ui->label->text() + " " + judge);
    cout << "*********************TIME*********************" << endl;
    /////cout << timer.elapsed();
    cout << "here" << endl;

    if(currentGamer->getGameTimes()==3)
    {
        emit noMoreChance();
        QMessageBox::information(this, tr("Final Points"), tr("Your points is ")+QSpoint);
    }
}
