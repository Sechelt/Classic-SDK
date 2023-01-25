#include "LibInfo.h"
#include "WSizeWidget.h"
#include "W.h"

WSizeWidget::WSizeWidget( const QSizeF &size, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxWidth = new QDoubleSpinBox( this );
    pSpinBoxWidth->setMinimum( 0 );
    pSpinBoxWidth->setMaximum( 10000 );
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxWidth->setToolTip( tr("width") );
    connect( pSpinBoxWidth, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxHeight = new QDoubleSpinBox( this );
    pSpinBoxHeight->setMinimum( 0 );
    pSpinBoxHeight->setMaximum( 10000 );
    pSpinBoxHeight->setValue( size.height() );
    pSpinBoxHeight->setToolTip( tr("height") );
    connect( pSpinBoxHeight, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    if ( bToolBar )
    { 
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxWidth, 0, 0 );
        pLayout->addWidget( pSpinBoxHeight, 1, 0 );
    }
    else
    {
        QFormLayout *pLayoutF = new QFormLayout( this );
        pLayoutF->addRow( new QLabel( tr("Width:"), this ), pSpinBoxWidth );
        pLayoutF->addRow( new QLabel( tr("Height:"), this ), pSpinBoxHeight );
    }
}

void WSizeWidget::setValue( const QSizeF &size )
{
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxHeight->setValue( size.height() );
}

QSizeF WSizeWidget::getValue() 
{ 
    return QSizeF( pSpinBoxWidth->value(), pSpinBoxHeight->value() ); 
}

void WSizeWidget::slotValue( const QSizeF &size )
{
    setValue( size );
}

void WSizeWidget::slotChanged()
{
    emit signalChanged( getValue() );
}

//
//
//

WSizeWidgetI::WSizeWidgetI( const QSize &size, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxWidth = new QSpinBox( this );
    pSpinBoxWidth->setMinimum( 0 );
    pSpinBoxWidth->setMaximum( 10000 );
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxWidth->setToolTip( tr("width") );
    connect( pSpinBoxWidth, SIGNAL(valueChanged(int)), SLOT(slotChanged()) );

    pSpinBoxHeight = new QSpinBox( this );
    pSpinBoxHeight->setMinimum( 0 );
    pSpinBoxHeight->setMaximum( 10000 );
    pSpinBoxHeight->setValue( size.height() );
    pSpinBoxHeight->setToolTip( tr("height") );
    connect( pSpinBoxHeight, SIGNAL(valueChanged(int)), SLOT(slotChanged()) );

    if ( bToolBar )
    { 
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxWidth, 0, 0 );
        pLayout->addWidget( pSpinBoxHeight, 1, 0 );
    }
    else
    {
        QFormLayout *pLayoutF = new QFormLayout( this );
        pLayoutF->addRow( new QLabel( tr("Width:"), this ), pSpinBoxWidth );
        pLayoutF->addRow( new QLabel( tr("Height:"), this ), pSpinBoxHeight );
    }
}

void WSizeWidgetI::setValue( const QSize &size )
{
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxHeight->setValue( size.height() );
}

QSize WSizeWidgetI::getValue() 
{ 
    return QSize( pSpinBoxWidth->value(), pSpinBoxHeight->value() ); 
}

void WSizeWidgetI::slotValue( const QSize &size )
{
    setValue( size );
}

void WSizeWidgetI::slotChanged()
{
    emit signalChanged( getValue() );
}


