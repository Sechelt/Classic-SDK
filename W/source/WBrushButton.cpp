#include "LibInfo.h"
#include "WBrushButton.h"

//
// WBrushSwatch
//
WBrushSwatch::WBrushSwatch( const QBrush &brush, QWidget *pParent )
    : QWidget( pParent )
{
    this->brush = brush;
}

void WBrushSwatch::setBrush( const QBrush &brush )
{
    this->brush = brush;
    update();
}

void WBrushSwatch::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QPainter painter(this);
    painter.fillRect( 0, 0, width(), height(), brush );
}

QSize WBrushSwatch::sizeHint() const
{
    return QSize( 16, 16 );
}

//
// WBrushButton
//
WBrushButton::WBrushButton( const QBrush &brush, QWidget *pParent )
    : QToolButton( pParent )
{
    this->brush = brush;

    QHBoxLayout *pLayout = new QHBoxLayout( this );

    pSwatch = new WBrushSwatch( brush, this );
    pLayout->addWidget( pSwatch, 2 );

    pButton = new QPushButton( "...", this );
    pLayout->addWidget( pButton, 1 );
    connect( pButton, SIGNAL(clicked()), SLOT(slotClicked()) );
}

void WBrushButton::setBrush( const QBrush &brush )
{
    this->brush = brush;
    pSwatch->setBrush( brush );
    emit signalChanged( brush );
}

void WBrushButton::slotClicked()
{
//        bool bOk;
//        brush2 = WBrushDialog::getBrush( &bOk, brush2, this );
//        if ( bOk ) 
//        {
//            pSwatch->setBrush( brush2 );
//            emit signalChanged( brush2 );
//        } 
}


