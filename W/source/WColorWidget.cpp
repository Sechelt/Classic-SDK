#include "LibInfo.h"
#include "WColorWidget.h"

#include "WPaletteColor.h"

WColorWidget::WColorWidget( QWidget *pParent )
    : QWidget( pParent )
{
    // get current - we must have one!
    QColor color = g_PaletteColors->getCurrent();

    QHBoxLayout *pLayoutTop = new QHBoxLayout( this );

    pColor = new WColorButton( color, this, WColorButton::Color );
    pLayoutTop->addWidget( pColor );
    connect( pColor, SIGNAL(signalChanged(const QColor &)), SLOT(slotChanged(const QColor &)) );

    pLayoutTop->addStretch( 11 );

    connect( g_PaletteColors, SIGNAL(signalModifiedCurrent()), this, SLOT(slotRefresh()) );
}

void WColorWidget::slotRefresh()
{
    QColor color = g_PaletteColors->getCurrent();
    pColor->setValue( color );
}

void WColorWidget::slotChanged( const QColor &color )
{
    g_PaletteColors->setCurrent( color );
}



