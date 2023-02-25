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
#include "WBrushButton.h"

//
// WBrushSwatch
//
WBrushSwatch::WBrushSwatch( const QBrush &brush, QWidget *pParent )
    : QWidget( pParent )
{
    this->brush = brush;
}

void WBrushSwatch::setBrush( const QBrush &brush )
{
    this->brush = brush;
    update();
}

void WBrushSwatch::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QPainter painter(this);
    painter.fillRect( 0, 0, width(), height(), brush );
}

QSize WBrushSwatch::sizeHint() const
{
    return QSize( 16, 16 );
}

//
// WBrushButton
//
WBrushButton::WBrushButton( const QBrush &brush, QWidget *pParent )
    : QToolButton( pParent )
{
    this->brush = brush;

    QHBoxLayout *pLayout = new QHBoxLayout( this );

    pSwatch = new WBrushSwatch( brush, this );
    pLayout->addWidget( pSwatch, 2 );

    pButton = new QPushButton( "...", this );
    pLayout->addWidget( pButton, 1 );
    connect( pButton, SIGNAL(clicked()), SLOT(slotClicked()) );
}

void WBrushButton::setBrush( const QBrush &brush )
{
    this->brush = brush;
    pSwatch->setBrush( brush );
    emit signalChanged( brush );
}

void WBrushButton::slotClicked()
{
//        bool bOk;
//        brush2 = WBrushDialog::getBrush( &bOk, brush2, this );
//        if ( bOk ) 
//        {
//            pSwatch->setBrush( brush2 );
//            emit signalChanged( brush2 );
//        } 
}


