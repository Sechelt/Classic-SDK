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

#ifndef H_WBitmapWidget
#define H_WBitmapWidget

#include "W.h"

class WBitmapButton;

/*!
 * \brief Allow selecting a bitmap and its placement. 
 *  
 * \sa W::WImagePlacements 
 * 
 * \author pharvey (7/29/20)
 */
class WBitmapWidget : public QWidget
{
    Q_OBJECT
public:
    WBitmapWidget( bool bUse, const QPixmap &pixmap, W::WImagePlacements nPlacement, QWidget *pParent );

signals:
    // to request change in object
    void signalUse( bool );
    void signalPlacement( W::WImagePlacements nPlacement );
    void signalBitmap( const QPixmap &pixmap );
    
public slots:
    // to register value in object (may be different than requested)
    void slotUse( bool );
    void slotPlacement( W::WImagePlacements nPlacement );
    void slotBitmap( const QPixmap &pixmap );

protected:
    QCheckBox *     pUseBitMap;
    QComboBox *     pPlacement;
    WBitmapButton * pBitmapButton;

protected slots:
    void slotChangedPlacement( int nIndex );
};

#endif


