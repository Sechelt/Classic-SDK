#ifndef H_WCoordWidget
#define H_WCoordWidget

#include "W.h"

#include "W.h"

class WCoordWidget : public QLabel
{
    Q_OBJECT
public:
    WCoordWidget( QWidget *pParent );

public slots:
    void slotCoord( int nCellX, int nCellY );
    void slotCoord( qreal nPixelX, qreal nPixelY );
    void slotCoord( const QPoint &pointCell );
    void slotCoord( const QPointF &pointPixel );
};

#endif 

