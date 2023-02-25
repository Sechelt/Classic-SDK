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

#ifndef H_WGeometryWidget
#define H_WGeometryWidget

#include "W.h"

class WPosWidget;
class WSizeWidgetDouble;

class WGeometryWidget : public QWidget
{
    Q_OBJECT
public:
    WGeometryWidget( const QPointF &, const QSizeF &, QWidget *pParent, bool bToolBar = false );

    void setPos( const QPointF &pointPos );
    void setSize( const QSizeF &size );

    QPointF getPos();
    QSizeF  getSize();

signals:
    void signalChangedPos( const QPointF &pointPos );
    void signalChangedSize( const QSizeF &size );

public slots:
    void slotPos( const QPointF &pointPos );
    void slotSize( const QSizeF &size );

protected:
    WPosWidget *  pPosWidget;
    WSizeWidgetDouble * pSizeWidget;
};

#endif 

