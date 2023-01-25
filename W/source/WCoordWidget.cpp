#include "LibInfo.h"
#include "WCoordWidget.h"

WCoordWidget::WCoordWidget( QWidget *pParent )
    : QLabel( pParent )
{
}

void WCoordWidget::slotCoord( int nCellX, int nCellY )
{
    setText( QString("%1,%2").arg( nCellX ).arg( nCellY ) );
}

void WCoordWidget::slotCoord( qreal nPixelX, qreal nPixelY )
{
    setText( QString("%1,%2").arg( nPixelX ).arg( nPixelY ) );
}

void WCoordWidget::slotCoord( const QPoint &pointCell )
{
    setText( QString("%1,%2").arg( pointCell.x() ).arg( pointCell.y() ) );
}

void WCoordWidget::slotCoord( const QPointF &pointPixel )
{
    setText( QString("%1,%2").arg( pointPixel.x() ).arg( pointPixel.y() ) );
}


