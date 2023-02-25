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
#include "WBitmapWidget.h"

#include "WBitmapButton.h"

WBitmapWidget::WBitmapWidget( bool bUse, const QPixmap &pixmap, W::WImagePlacements nPlacement, QWidget *pParent )
    : QWidget( pParent )
{
    QVBoxLayout *pLayout = new QVBoxLayout( this );

    {
        QHBoxLayout *pLayout01 = new QHBoxLayout();
        pUseBitMap = new QCheckBox( tr("Use Bitmap"), this );
        pLayout01->addWidget( pUseBitMap );
        pPlacement = new QComboBox( this );
        pPlacement->addItem( "Normal", (int)W::WImagePlacementNormal );
        pPlacement->addItem( "Tiled", (int)W::WImagePlacementTiled );
        pPlacement->addItem( "Scaled", (int)W::WImagePlacementScaled );
        WSetComboBox( pPlacement, nPlacement );
        pLayout01->addWidget( pPlacement );
        pLayout01->addStretch( 10 );
        pLayout->addLayout( pLayout01 );
    }
    {
        pBitmapButton = new WBitmapButton( pixmap, this );
        pLayout->addWidget( pBitmapButton );
    }

    if ( bUse )
    {
        pUseBitMap->setChecked( true );
    }
    else
    {
        pUseBitMap->setChecked( false );
        pPlacement->setEnabled( false );
        pBitmapButton->setEnabled( false );
    }

    connect( pUseBitMap, SIGNAL(clicked(bool)), SIGNAL(signalUse(bool)) );
    connect( pPlacement, SIGNAL(currentIndexChanged(int)), SLOT(slotChangedPlacement(int)) );
    connect( pBitmapButton, SIGNAL(signalChanged(const QPixmap &)), SIGNAL(signalBitmap(const QPixmap &)) );
}

void WBitmapWidget::slotUse( bool b )
{
    if ( b )
    {
        pPlacement->setEnabled( true );
        pBitmapButton->setEnabled( true );
    }
    else
    {
        pPlacement->setEnabled( false );
        pBitmapButton->setEnabled( false );
    }

    pUseBitMap->setChecked( b );
}

void WBitmapWidget::slotPlacement( W::WImagePlacements nPlacement )
{
    WSetComboBox( pPlacement, nPlacement );
}

void WBitmapWidget::slotBitmap( const QPixmap &pixmap )
{
    pBitmapButton->setPixmap( pixmap );
}

void WBitmapWidget::slotChangedPlacement( int nIndex )
{
    emit signalPlacement( W::WImagePlacements(pPlacement->itemData( nIndex ).toInt()) );
}






















