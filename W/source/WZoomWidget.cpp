#include "LibInfo.h"
#include "WZoomWidget.h"

WZoomWidget::WZoomWidget( QWidget *pParent, int n )
    : QWidget( pParent )
{
    nMin    = 10;
    nMax    = 300;
    nInc    = 10;
    nZoom   = n;

    QHBoxLayout *pLayout = new QHBoxLayout( this );

    pMinus = new QToolButton( this );
    // pMinus->setAutoRepeat( true  );
    // pMinus->setAutoRepeatInterval( 33 );
    // pMinus->setAutoRepeatDelay( 0 );
    pMinus->setIcon( QIcon( ":W/minus" ) );
    pLayout->addWidget( pMinus );

    pSlider = new QSlider( Qt::Horizontal, this );
    pSlider->setMinimum( nMin );
    pSlider->setMaximum( nMax );
    pSlider->setSingleStep( nInc );
    pSlider->setPageStep( nInc * 2 );
    pSlider->setValue( nZoom );
    pLayout->addWidget( pSlider );

    pPlus = new QToolButton( this );
    // pPlus->setAutoRepeat( true  );
    // pPlus->setAutoRepeatInterval( 33 );
    // pPlus->setAutoRepeatDelay( 0 );
    pPlus->setIcon( QIcon( ":W/plus" ) );
    pLayout->addWidget( pPlus );

    pLabel = new QLabel( this );
    pLabel->setText( QString::number( nZoom ) + "%" );
    pLayout->addWidget( pLabel );

    pFit = new QComboBox( this );
    pFit->addItem( tr("Width") );
    pFit->addItem( tr("Height") );
    pFit->addItem( tr("All") );
    pFit->addItem( tr("") );
    pFit->setCurrentText( "" );
    pLayout->addWidget( pFit );

    connect( pSlider, SIGNAL(valueChanged(int)), SLOT(slotSlider(int)) );
    connect( pPlus, SIGNAL(clicked()), SLOT(slotPlus()) );
    connect( pMinus, SIGNAL(clicked()), SLOT(slotMinus()) );
    connect( pFit, SIGNAL(currentIndexChanged(int)), SLOT(slotFit(int)) );
}

void WZoomWidget::setMin( int n )
{
    nMin = n;
    pSlider->setMinimum( nMin );
}

void WZoomWidget::setMax( int n )
{
    nMax = n;
    pSlider->setMaximum( nMax );
}

void WZoomWidget::setInc( int n )
{
    nInc = n;
    pSlider->setSingleStep( nInc );
    pSlider->setPageStep( nInc * 2 );
}

void WZoomWidget::setZoom( int n )
{
    nZoom = n;
    pSlider->setValue( nZoom );
}

void WZoomWidget::setFit( FitTypes n )
{
    nFit = n;
    pFit->setCurrentIndex( nFit );
}

void WZoomWidget::setVisibleFit( bool b )
{
    pFit->setVisible( b );
}

int WZoomWidget::getZoom()
{
    return nZoom;
}

WZoomWidget::FitTypes WZoomWidget::getFit()
{
    return nFit;
}

void WZoomWidget::slotSlider( int nValue )
{
    nZoom = nValue;

    pLabel->setText( QString::number( nZoom ) + "%" ); 

    emit signalZoom( nFit, nZoom );
}

void WZoomWidget::slotPlus()
{
    pSlider->setValue( pSlider->value() + nInc );
}

void WZoomWidget::slotMinus()
{
    pSlider->setValue( pSlider->value() - nInc );
}

void WZoomWidget::slotFit( int nIndex )
{
    nFit = (FitTypes)nIndex;
    switch ( nIndex )
    {
        case FitWidth:
        case FitHeight:
        case FitAll:
            pSlider->setEnabled( false );
            pPlus->setEnabled( false );
            pMinus->setEnabled( false );
            emit signalZoom( nFit, nZoom );
            break;
        case FitIgnore:
            pSlider->setEnabled( true );
            pPlus->setEnabled( true );
            pMinus->setEnabled( true );
            emit signalZoom( nFit, nZoom );
            break;
    }
}


