#ifndef H_WBitmapButton
#define H_WBitmapButton

#include "W.h"

class WBitmapButton : public QWidget
{
    Q_OBJECT
public:
    explicit WBitmapButton( const QPixmap &pixmap, QWidget *pParent );
    ~WBitmapButton();

    void setPixmap( const QPixmap &pixmap );
    QPixmap getPixmap() { return pixmap; }

signals:
    void signalChanged( const QPixmap & );

protected:
    QPixmap pixmap;

    void paintEvent( QPaintEvent *pEvent );
    void mouseDoubleClickEvent( QMouseEvent *pEvent );
};

#endif 

