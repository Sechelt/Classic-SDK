#include "LibInfo.h"
#include "WColorButton.h"
#include "W.h"

#include "WColorPickerDialog.h"

WColorButton::WColorButton( const QColor &c, QWidget *pParent, Types n )
    : QToolButton( pParent )
{
    nType = n;
    color = c;

    setIcon( getIcon() );
    connect( this, SIGNAL(clicked()), SLOT(slotClicked()) );
}

void WColorButton::setValue( const QColor &color )
{
    this->color = color;
    setIcon( getIcon() );
}

QPixmap WColorButton::getIcon( int nSize )
{
    Q_UNUSED(nSize);

    switch ( nType )
    {
        case Font:
            {
                // font color (foreground or background)
                QPixmap pixmap( ":W/Font16" );
                QPainter p( &pixmap );
                p.fillRect( QRect(0,12,16,5), color);
                return pixmap;
            }
            break;
        case Pen:
            {
                // pen color
                QPixmap pixmap( ":W/Pen16" );
                QPainter p( &pixmap );
                p.fillRect( QRect(0,13,16,5), color);
                return pixmap;
            }
            break;
        case Brush:
            {
                // brush color
                QPixmap pixmap( ":W/Brush" );
                QPainter p( &pixmap );
                p.fillRect( QRect(0,13,16,5), color );
                return pixmap;
            }
            break;
        case Fill:
            {
                // fill color
                QPixmap pixmap( ":W/Brush" );
                QPainter p( &pixmap );
                p.fillRect( QRect(0,13,16,5), color );
                return pixmap;
            }
            break;
        case Color:
        default:
            {
                QPixmap pixmap( nSize, nSize );
                pixmap.fill( color );
                return pixmap;
            }
            break;
    }

    return QPixmap();
}

void WColorButton::slotClicked()
{
    bool bOk = false;

    QColor colorNew = WColorPickerDialog::getColor( &bOk, color, this, true );
    if ( bOk )
    {
        color = colorNew;
        setIcon( getIcon() );
        emit signalChanged( color );
    }

/*

    QColor c = QColorDialog::getColor( color, this );
    if ( c.isValid() ) 
    {
        color = c;
        setIcon( getIcon() );
        emit signalChanged( color );
    } 
*/
}


