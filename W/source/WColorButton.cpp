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
    if ( this->color == color ) return;
    this->color = color;
    setIcon( getIcon() );
    emit signalChanged( color );
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
        setValue( colorNew );
    }
}


