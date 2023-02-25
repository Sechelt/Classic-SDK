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
#include "WIconWidget.h"

WIconWidget::WIconWidget( const QString &stringText, const QPixmap &pixmapIcon, QWidget *pWidget, const QString &stringTip )
    : QWidget( pWidget )
{
    bSelected = false;

    setAutoFillBackground( true );

    QGridLayout *pLayout = new QGridLayout( this );
    pLabelIcon  = new QLabel( this );
    pLabelText  = new QLabel( this );
    pLabelIcon->setPixmap( pixmapIcon );
    pLabelText->setText( stringText );
    pLayout->addWidget( pLabelIcon, 0, 0, Qt::AlignHCenter );
    pLayout->addWidget( pLabelText, 1, 0, Qt::AlignHCenter );
    setToolTip( stringTip );
}

WIconWidget::~WIconWidget()
{
}

void WIconWidget::setSelected( bool b )
{
    if ( bSelected == b ) return;

    if ( b ) setBackgroundRole( QPalette::Highlight );
    else setBackgroundRole( QPalette::NoRole );
    bSelected = b;
}

void WIconWidget::mousePressEvent( QMouseEvent *pMouseEvent )
{
    if ( pMouseEvent->button() == Qt::LeftButton )
    {
        // so someone could call our setSelected() if they want...
        emit signalClicked( this );
        // initiate drag...
        QDrag *drag = new QDrag( this );
        QMimeData *mimeData = new QMimeData;

        mimeData->setText( pLabelText->text() );
        drag->setMimeData( mimeData );
// #if QT_VERSION < 0x060000
//        drag->setPixmap( *(pLabelIcon->pixmap()) );
// #else
        drag->setPixmap( pLabelIcon->pixmap( (Qt::ReturnByValueConstant)0 ) );
// #endif


        /* Qt::DropAction dropAction = */ drag->exec();
        return;
    }

    QWidget::mousePressEvent( pMouseEvent );
}


