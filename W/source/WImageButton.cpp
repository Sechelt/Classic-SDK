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
#include "WImageButton.h"

WImageButton::WImageButton( const QImage &image, QWidget *pParent )
    : QWidget( pParent )
{
    this->image = image;
    setMinimumWidth( 16 );
    setMinimumHeight( 16 );
}

void WImageButton::setImage( const QImage &image  )
{
    this->image = image;
    update();
}

void WImageButton::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QPainter painter( this );
    painter.setPen( Qt::black );
    if ( !image.isNull() )
    { 
        QImage imageScaled = image.scaled( width(), height(), Qt::KeepAspectRatio );
        QRect rectImage( 0, 0, imageScaled.width(), imageScaled.height() );
        rectImage.moveCenter( rect().center() );

        painter.drawImage( rectImage, imageScaled );
    }
    painter.drawRect( rect().x(), rect().y(), rect().width() -1, rect().height() -1 );
}

void WImageButton::mouseDoubleClickEvent( QMouseEvent *pEvent )
{
    Q_UNUSED(pEvent);
    emit signalClick();
}

