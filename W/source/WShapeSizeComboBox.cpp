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
#include "WShapeSizeComboBox.h"

WShapeSizeComboBox::WShapeSizeComboBox( QWidget *pParent )
    : QComboBox( pParent )
{
    addItem( "", 0 );
    addItem( "16", 16 );
    addItem( "32", 32 );
    addItem( "48", 48 );
    addItem( "64", 64 );
    addItem( "96", 96 );
    addItem( "128", 128 );

    setValue( 0 );

    connect( this, SIGNAL(activated(int)), SLOT(slotChanged(int)) );

    setToolTip( tr("common shape sizes") );
}

void WShapeSizeComboBox::setValue( int n )
{
    setCurrentIndex( findData( n, int(Qt::UserRole) ) );
}

int WShapeSizeComboBox::getValue()
{
    return itemData( currentIndex(), Qt::UserRole ).toInt();
}

void WShapeSizeComboBox::slotValue( int n )
{
    setValue( n );
}

void WShapeSizeComboBox::slotChanged( int nIndex )
{
    if ( itemData( nIndex ).isNull() ) return;
    int n = itemData( nIndex ).toInt();
    emit signalChanged( n );
}

 
