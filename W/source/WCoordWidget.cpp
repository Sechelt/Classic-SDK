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
#include "WCoordWidget.h"

WCoordWidget::WCoordWidget( QWidget *pParent )
    : QLabel( pParent )
{
}

void WCoordWidget::slotCoord( int nCellX, int nCellY )
{
    setText( QString("%1,%2").arg( nCellX ).arg( nCellY ) );
}

void WCoordWidget::slotCoord( qreal nPixelX, qreal nPixelY )
{
    setText( QString("%1,%2").arg( nPixelX ).arg( nPixelY ) );
}

void WCoordWidget::slotCoord( const QPoint &pointCell )
{
    setText( QString("%1,%2").arg( pointCell.x() ).arg( pointCell.y() ) );
}

void WCoordWidget::slotCoord( const QPointF &pointPixel )
{
    setText( QString("%1,%2").arg( pointPixel.x() ).arg( pointPixel.y() ) );
}


