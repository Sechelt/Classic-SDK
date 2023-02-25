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

#ifndef H_WSvgButton
#define H_WSvgButton

#include <QSvgRenderer>

#include "W.h"

#include "W.h"

class WSvgButton : public QWidget
{
    Q_OBJECT
public:
    explicit WSvgButton( const QByteArray &ba, QWidget *pParent );
    ~WSvgButton();

    void setVector( const QByteArray &ba );
    QByteArray getVector() { return ByteArray; }

signals:
    void signalChanged( const QByteArray & );

protected:
    QByteArray      ByteArray;
    QSvgRenderer *  pRenderer;

    void paintEvent( QPaintEvent *pEvent );
    void mouseDoubleClickEvent( QMouseEvent *pEvent );
};

#endif 

