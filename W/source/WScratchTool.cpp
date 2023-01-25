#include "WScratchTool.h"

WScratchTool::WScratchTool( QWidget *pParent )
    : QWidget( pParent )
{
    QVBoxLayout *pLayoutTop = new QVBoxLayout( this );

    // main
    {
        QHBoxLayout *pLayoutMain = new QHBoxLayout();

        pStackedWidget  = new QStackedWidget( this );
        pSlider         = new QSlider( Qt::Vertical, this );

        pLayoutMain->addWidget( pStackedWidget );
        pLayoutMain->addWidget( pSlider );

        pLayoutTop->addLayout( pLayoutMain );
    }

    // tool bar
    {
        QHBoxLayout *pLayoutToolBar = new QHBoxLayout();
        QToolButton *pAdd       = new QToolButton( this );
        QToolButton *pRemove    = new QToolButton( this );

        pAdd->setText( "+" );
        pRemove->setText( "-" );

        pLayoutToolBar->addWidget( pAdd );
        pLayoutToolBar->addWidget( pRemove );
        pLayoutToolBar->addStretch( 10 );

        pLayoutTop->addLayout( pLayoutToolBar );

        connect( pAdd, SIGNAL(clicked()), SLOT(slotAdd()) );
        connect( pRemove, SIGNAL(clicked()), SLOT(slotRemove()) );
    }
}

void WScratchTool::slotAdd()
{
qDebug() << "[PAH][" << __FILE__ << "][" << __LINE__ << "]";
}

void WScratchTool::slotRemove()
{
qDebug() << "[PAH][" << __FILE__ << "][" << __LINE__ << "]";
}


