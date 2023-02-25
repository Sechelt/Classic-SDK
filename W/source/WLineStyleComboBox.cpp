/*
 * Copyright 2022-2023, Peter Harvey <pharvey@codebydesign.com>
 *
 * This file is part of Euphemia-SDK.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "LibInfo.h"
#include "WLineStyleComboBox.h"

WLineStyleComboBox::WLineStyleComboBox( Qt::PenStyle n, QWidget *pParent )
    : QComboBox( pParent )
{
    setIconSize( QSize( 64, 16 ) );

    addItem( "", (int)Qt::NoPen  );
    setItemIcon( 0, getIcon( Qt::NoPen ) );

    addItem( "", (int)Qt::SolidLine );
    setItemIcon( 1, getIcon( Qt::SolidLine ) );

    addItem( "", (int)Qt::DashLine );
    setItemIcon( 2, getIcon( Qt::DashLine ) );

    addItem( "", (int)Qt::DotLine );
    setItemIcon( 3, getIcon( Qt::DotLine ) );

    addItem( "", (int)Qt::DashDotLine );
    setItemIcon( 4, getIcon( Qt::DashDotLine ) );

    addItem( "", (int)Qt::DashDotDotLine );
    setItemIcon( 5, getIcon( Qt::DashDotDotLine ) );

/*
    addItem( "NoPen", (int)Qt::NoPen  );                 
    setItemIcon( 0, getIcon( Qt::NoPen ) );              
                                                         
    addItem( "Solid", (int)Qt::SolidLine );              
    setItemIcon( 1, getIcon( Qt::SolidLine ) );          
                                                         
    addItem( "DashLine", (int)Qt::DashLine );            
    setItemIcon( 2, getIcon( Qt::DashLine ) );           
                                                         
    addItem( "DotLine", (int)Qt::DotLine );              
    setItemIcon( 3, getIcon( Qt::DotLine ) );            
                                                         
    addItem( "DashDotLine", (int)Qt::DashDotLine );      
    setItemIcon( 4, getIcon( Qt::DashDotLine ) );        
                                                         
    addItem( "DashDotDotLine", (int)Qt::DashDotDotLine );
    setItemIcon( 5, getIcon( Qt::DashDotDotLine ) );     
*/

    setValue( n );

//    connect( this, SIGNAL(currentIndexChanged(int)), SLOT(slotChanged(int)) );
    connect( this, SIGNAL(activated(int)), SLOT(slotChanged(int)) );
}

void WLineStyleComboBox::setValue( Qt::PenStyle n )
{
    setCurrentIndex( findData( int(n), int(Qt::UserRole) ) );
}

Qt::PenStyle WLineStyleComboBox::getValue()
{
    return Qt::PenStyle(itemData( currentIndex(), Qt::UserRole ).toInt());
}

QPixmap WLineStyleComboBox::getIcon( Qt::PenStyle nStyle, int nWidth, int nHeight )
{
    QPixmap pixmap( nWidth, nHeight );
    QPainter painter( &pixmap );

    QBrush brush;
    brush.setColor( Qt::white );
    brush.setStyle( Qt::SolidPattern );
    painter.fillRect( 0, 0, nWidth, nHeight, brush );

    QPen pen;
    pen.setColor( Qt::black );
    pen.setStyle( nStyle );
    painter.setPen( pen );
    painter.drawLine( 0, nHeight / 2, nWidth, nHeight / 2 );

    return pixmap;
}

void WLineStyleComboBox::slotChanged( int nIndex )
{
    if ( itemData( nIndex ).isNull() ) return;
    Qt::PenStyle n = Qt::PenStyle(itemData( nIndex ).toInt());
    emit signalChanged( n );
}

 
