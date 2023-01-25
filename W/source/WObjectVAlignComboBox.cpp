#include "LibInfo.h"
#include "WObjectVAlignComboBox.h"

WObjectVAlignComboBox::WObjectVAlignComboBox( Qt::AlignmentFlag n, QWidget *pParent, bool bText )
    : QComboBox( pParent )
{
    addItem( ( bText ? tr("Top") : "" ), (int)Qt::AlignTop );
    setItemIcon( 0, QIcon( ":W/ObjAlignTop16x16" ) );

    addItem( ( bText ? tr("Center") : "" ), (int)Qt::AlignVCenter );
    setItemIcon( 1, QIcon( ":W/ObjAlignVCenter16x16" ) );

    addItem( ( bText ? tr("Bottom") : "" ), (int)Qt::AlignBottom );
    setItemIcon( 2, QIcon( ":W/ObjAlignBottom16x16" ) );

    setValue( n );

//    connect( this, SIGNAL(currentIndexChanged(int)), SLOT(slotChanged(int)) );
    connect( this, SIGNAL(activated(int)), SLOT(slotChanged(int)) );
}

void WObjectVAlignComboBox::setValue( Qt::AlignmentFlag n )
{
    setCurrentIndex( findData( int(n), int(Qt::UserRole) ) );
}

Qt::AlignmentFlag WObjectVAlignComboBox::getValue()
{
    return Qt::AlignmentFlag(itemData( currentIndex(), Qt::UserRole ).toInt());
}

void WObjectVAlignComboBox::slotChanged( int nIndex )
{
    if ( itemData( nIndex ).isNull() ) return;
    Qt::AlignmentFlag n = Qt::AlignmentFlag(itemData( nIndex ).toInt());
    emit signalChanged( n );
}

 
