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
#include "WTextHAlignComboBox.h"

WTextHAlignComboBox::WTextHAlignComboBox( Qt::AlignmentFlag n, QWidget *pParent, bool bText )
    : QComboBox( pParent )
{
    addItem( ( bText ? tr("Left") : "" ), (int)Qt::AlignLeft  );
    setItemIcon( 0, QIcon( ":W/AlignLeft16x16" ) );

    addItem( ( bText ? tr("Center") : "" ), (int)Qt::AlignHCenter );
    setItemIcon( 1, QIcon( ":W/AlignHCenter16x16" ) );

    addItem( ( bText ? tr("Right") : "" ), (int)Qt::AlignRight );
    setItemIcon( 2, QIcon( ":W/AlignRight16x16" ) );

    setValue( n );

//    connect( this, SIGNAL(currentIndexChanged(int)), SLOT(slotChanged(int)) );
    connect( this, SIGNAL(activated(int)), SLOT(slotChanged(int)) );
}

void WTextHAlignComboBox::setValue( Qt::AlignmentFlag n )
{
    setCurrentIndex( findData( int(n), int(Qt::UserRole) ) );
}

Qt::AlignmentFlag WTextHAlignComboBox::getValue()
{
    return Qt::AlignmentFlag(itemData( currentIndex(), Qt::UserRole ).toInt());
}

void WTextHAlignComboBox::slotValue( Qt::AlignmentFlag n )
{
    setValue( n );
}

void WTextHAlignComboBox::slotChanged( int nIndex )
{
    if ( itemData( nIndex ).isNull() ) return;
    Qt::AlignmentFlag n = Qt::AlignmentFlag(itemData( nIndex ).toInt());
    emit signalChanged( n );
}

 
