#include "LibInfo.h"
#include "WGeometryWidget.h"
#include "W.h"

#include "WPosWidget.h"
#include "WSizeWidget.h"

WGeometryWidget::WGeometryWidget( const QPointF &pointPos, const QSizeF &size, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    QLayout *pLayoutTop;

    if ( bToolBar )
    { 
        QHBoxLayout *p = new QHBoxLayout( this );
        pLayoutTop = p;
    }
    else
    {
        QVBoxLayout *p = new QVBoxLayout( this );
        pLayoutTop = p;
    }
    // pos
    {
        QGroupBox *     pGroupBox    = new QGroupBox( tr("Position"), this );
        QVBoxLayout *   pLayout      = new QVBoxLayout( pGroupBox );

        pPosWidget = new WPosWidget( pointPos, pGroupBox );
        pLayout->addWidget( pPosWidget );

        pLayoutTop->addWidget( pGroupBox );

        connect( pPosWidget, SIGNAL(signalChanged(const QPointF &)), SIGNAL(signalChangedPos(const QPointF &)) );
    }
    // size
    {
        QGroupBox *     pGroupBox    = new QGroupBox( tr("Size"), this );
        QVBoxLayout *   pLayout      = new QVBoxLayout( pGroupBox );

        pSizeWidget = new WSizeWidgetDouble( size, pGroupBox );
        pLayout->addWidget( pSizeWidget );

        pLayoutTop->addWidget( pGroupBox );

        connect( pSizeWidget, SIGNAL(signalChanged(const QSizeF &)), SIGNAL(signalChangedSize(const QSizeF &)) );
    }
}

void WGeometryWidget::setPos( const QPointF &pointPos )
{
    pPosWidget->setValue( pointPos );
}

void WGeometryWidget::setSize( const QSizeF &size )
{
    pSizeWidget->setValue( size );
}

QPointF WGeometryWidget::getPos()                    { return pPosWidget->getValue();                }
QSizeF  WGeometryWidget::getSize()                   { return pSizeWidget->getValue();                }

void WGeometryWidget::slotPos( const QPointF &pointPos )
{
    setPos( pointPos );
}

void WGeometryWidget::slotSize( const QSizeF &size )
{
    setSize( size );
}


