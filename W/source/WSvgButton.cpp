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
#include "WSvgButton.h"

WSvgButton::WSvgButton( const QByteArray &ba, QWidget *pParent )
    : QWidget( pParent )
{
    ByteArray = ba;
    pRenderer = new QSvgRenderer( this );

    if ( !ba.isEmpty() && !pRenderer->load( ByteArray ) )
    { 
        QMessageBox::critical( this, tr("Load"), tr("Encountered an error while loading vector.") );
    }
}

WSvgButton::~WSvgButton()
{
    delete pRenderer;
}

void WSvgButton::setVector( const QByteArray &ba  )
{
    ByteArray = ba;
    if ( !pRenderer->load( ByteArray ) )
    { 
        QMessageBox::critical( this, tr("Load"), tr("Encountered an error while loading vector.") );
    }
    update();
}

void WSvgButton::paintEvent( QPaintEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QPainter painter( this );

    if ( !ByteArray.isEmpty() ) pRenderer->render( &painter );
    else painter.drawText( QPoint( width() / 2, height() / 2), tr("Double Click\nTo Select Image") );
}

void WSvgButton::mouseDoubleClickEvent( QMouseEvent *pEvent )
{
    Q_UNUSED(pEvent);

    QFileDialog fileDialog( nullptr );
    fileDialog.setAcceptMode( QFileDialog::AcceptOpen );
    fileDialog.setMimeTypeFilters( QStringList() << "image/svg+xml" << "image/svg+xml-compressed" );
    fileDialog.setWindowTitle(tr("Select Vector Image..."));
    // if (m_currentPath.isEmpty())
    //  fileDialog.setDirectory(picturesLocation());

    if ( fileDialog.exec() != QDialog::Accepted ) return;

    QString stringFileName = fileDialog.selectedFiles().constFirst();
    QFile file( stringFileName );
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        return;
    }
    QFileInfo FileInfo( file );

    setVector( file.readAll() );

    emit signalChanged( ByteArray );
}

