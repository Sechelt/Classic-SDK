#include "WScratchTool.h"

WScratchSwatch::WScratchSwatch( QWidget *pParent )
    : QWidget( pParent )
{
}

void WScratchSwatch::setImage( const QImage &i )
{
    image = i;
    update();
}

void WScratchSwatch::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    if ( image.isNull() ) return;
    QPainter painter( this );
    painter.drawImage( QRect( 0, 0, rect().width(), rect().height() ), image );
}

WScratchTool::WScratchTool( QWidget *pParent )
    : QWidget( pParent )
{
    QVBoxLayout *pLayoutTop = new QVBoxLayout( this );

    // main
    {
        QHBoxLayout *pLayoutMain = new QHBoxLayout();

        pSwatch  = new WScratchSwatch( this );
        pSlider  = new QSlider( Qt::Vertical, this );
        pSlider->setMinimum( 0 );
        pSlider->setMaximum( 0 );

        pLayoutMain->addWidget( pSwatch );
        pLayoutMain->addWidget( pSlider );

        pLayoutTop->addLayout( pLayoutMain );

        connect( pSlider, SIGNAL(valueChanged(int)), SLOT(slotSlider(int)) );
    }

    // tool bar
    {
        QHBoxLayout *pLayoutToolBar = new QHBoxLayout();
        pAdd       = new QToolButton( this );
        pRemove    = new QToolButton( this );
        pPaste     = new QToolButton( this );

        pAdd->setText( "+" );
        pRemove->setText( "-" );
        pPaste->setIcon( QIcon( ":W/Paste48x48" ) );

        pAdd->setEnabled( false );
        pRemove->setEnabled( false );
        pPaste->setEnabled( true );

        pLayoutToolBar->addWidget( pAdd );
        pLayoutToolBar->addWidget( pRemove );
        pLayoutToolBar->addWidget( pPaste );
        pLayoutToolBar->addStretch( 10 );

        pLayoutTop->addLayout( pLayoutToolBar );

        connect( pAdd, SIGNAL(clicked()), SIGNAL(signalAdd()) );
        connect( pRemove, SIGNAL(clicked()), SLOT(slotRemove()) );
        connect( pPaste, SIGNAL(clicked()), SLOT(slotPaste()) );
    }
}

void WScratchTool::setMax( int n )
{
    if ( n < 1 ) return;
    if ( n > 100 ) n = 100;
    nMax = n;
}

void WScratchTool::doAppend( const QImage &image )
{
    vectorImages.append( image );
    pSlider->setMaximum( pSlider->maximum() + 1 );
    pSlider->setValue( pSlider->maximum() );
    pRemove->setEnabled( true );
    pSwatch->setImage( image );
}

void WScratchTool::doClear()
{
    pSlider->setMaximum( 0 );
    vectorImages.clear();
    pRemove->setEnabled( false );
}

void WScratchTool::doEnableAdd( bool b )
{
    pAdd->setEnabled( b );
}

void WScratchTool::slotSlider( int n )
{
// qInfo() << "[" << __FILE__ << "][" << __FUNCTION__ << "][" << __LINE__ <<"] Slider:" << n << " Count:" << vectorImages.count();
    if ( n >= vectorImages.count() ) return;
    pSwatch->setImage( vectorImages.at( n ) );
}

void WScratchTool::slotRemove()
{
    int n = pSlider->value();
    if ( n >= vectorImages.count() ) return;
    vectorImages.remove( n );
    if ( pSlider->maximum() > 0 ) pSlider->setMaximum( pSlider->maximum() - 1 );
}

void WScratchTool::slotPaste()
{
    int n = pSlider->value();
    if ( n >= vectorImages.count() ) return;
    emit signalPaste( vectorImages.at( n ) );
}


