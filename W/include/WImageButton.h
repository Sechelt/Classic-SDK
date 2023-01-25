#ifndef H_WImageButton
#define H_WImageButton

#include "W.h"

#include "W.h"

class WImageButton : public QWidget
{
    Q_OBJECT
public:
    WImageButton( const QImage &image, QWidget *pParent );

    void setImage( const QImage &image );
    QImage getImage() { return image; }

signals:
    void signalClick();

protected:
    QImage image;

    void paintEvent( QPaintEvent *pEvent );
    void mouseDoubleClickEvent( QMouseEvent *pEvent );
};

#endif 

