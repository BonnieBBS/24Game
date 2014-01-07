#include "newGamerDialog[Abandoned].h"

/*
NewGamerDialog::newGamerDialog()//QWidget *parent) :
    //QDialog(parent)
{
    setUpGUI();
    setWindowTitle( tr("Add New Gamer") );
    setModal( true );
}*/

NewGamerDialog::~NewGamerDialog()
{
    delete(this);
}

void NewGamerDialog::setUpGUI(){
    // set up the layout
    QGridLayout* formGridLayout = new QGridLayout( this );

    // initialize the labels
    gamerNameLabel = new QLabel( this );
    gamerNameLabel->setText( tr( "New Gamer Name" ) );
    // labelUsername->setBuddy( gamerNameLineEdit );

    // initialize buttons
    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Add") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Abort") );
/*
    // connects slots
    connect( buttons->button( QDialogButtonBox::Cancel ),
             SIGNAL(clicked()),
             this,
             SLOT(close())
             );

    connect( buttons->button( QDialogButtonBox::Ok ),
             SIGNAL(clicked()),
             this,
             SLOT(slotAcceptLogin()) );
*/
    // place components into the dialog
    formGridLayout->addWidget( gamerNameLabel, 0, 0 );
    formGridLayout->addWidget( gamerNameLineEdit, 1, 0 );
    formGridLayout->addWidget( buttons, 2, 0, 1, 2 );

    setLayout( formGridLayout );


}

    QString NewGamerDialog::getGamerName()
    {
        return gamerNameLineEdit->text();
    }
