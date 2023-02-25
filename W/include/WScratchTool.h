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

#ifndef H_WScratchTool
#define H_WScratchTool

#include "W.h"

class WScratchSwatch : public QWidget
{
    Q_OBJECT
public:
    WScratchSwatch( QWidget *pParent );

    void setImage( const QImage &image );

protected:
    void paintEvent( QPaintEvent *pEvent );

private:
    QImage image;
};


class WScratchTool : public QWidget
{
    Q_OBJECT
public:
    WScratchTool( QWidget *pParent );

    void setMax( int );

    QImage getImage();

    void doAppend( const QImage & );
    void doClear();
    void doEnableAdd( bool b = true );

signals:
    void signalAdd();
    void signalPaste( const QImage & );

protected:
    QVector<QImage> vectorImages;

    WScratchSwatch *    pSwatch;
    QSlider *           pSlider;
    QToolButton *pAdd;
    QToolButton *pRemove;
    QToolButton *pPaste;

    int nMax = 10;

protected slots:
    void slotSlider( int );
    void slotRemove();
    void slotPaste();
};

#endif 

