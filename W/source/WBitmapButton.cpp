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
#include "WBitmapButton.h"

WBitmapButton::WBitmapButton( const QPixmap &pm, QWidget *pParent )
    : QWidget( pParent )
{
    pixmap = pm;
}

WBitmapButton::~WBitmapButton()
{
}

void WBitmapButton::setPixmap( const QPixmap &pm  )
{
    pixmap = pm;
    update();
}

void WBitmapButton::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QPainter painter( this );

    if ( pixmap.isNull() ) painter.drawText( QPoint( width() / 2, height() / 2), tr("Double Click\nTo Select Image") );
    else painter.drawPixmap( QPoint( 0, 0 ), pixmap.scaled( width(), height() ) );
}

void WBitmapButton::mouseDoubleClickEvent( QMouseEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QFileDialog fileDialog( nullptr );
    fileDialog.setAcceptMode( QFileDialog::AcceptOpen );
    fileDialog.setNameFilter("Bitmap files (*.png *.xpm *.jpg)");
    fileDialog.setWindowTitle(tr("Select Bitmap..."));

    if ( fileDialog.exec() != QDialog::Accepted ) return;

    QString stringFileName = fileDialog.selectedFiles().constFirst();
    QPixmap pixmap;
    bool b = pixmap.load( stringFileName );
    if ( !b ) return;

    setPixmap( pixmap );

    emit signalChanged( pixmap );
}

