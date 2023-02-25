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
#include "WTabDialog.h"

WTabDialog::WTabDialog( QWidget *pwidgetParent, const QString &stringTitle, const QString &stringName, QDialogButtonBox::StandardButtons buttons, bool bModal, Qt::WindowFlags f )
    : QDialog( pwidgetParent, f )
{
    setObjectName( stringName );
    setModal( bModal );
    setWindowTitle( stringTitle );

    QVBoxLayout *pLayout = new QVBoxLayout( this );
    pTabWidget = new QTabWidget( this );
    pLayout->addWidget( pTabWidget );

    pButtonBox = new QDialogButtonBox( buttons /* QDialogButtonBox::Ok | QDialogButtonBox::Cancel */, this );
    pLayout->addWidget( pButtonBox );

    connect(pButtonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(pButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    doLoadState();
}

WTabDialog::~WTabDialog()
{
    doSaveState();
}

/*
void WTabDialog::closeEvent( QCloseEvent *pEvent )
{                                                 
    doSaveState();                                
    QDialog::closeEvent( pEvent );                
}                                                 
*/

void WTabDialog::doSaveState()
{
    QString s = metaObject()->className();
    if ( !objectName().isEmpty() ) s = s + "/" + objectName();

    QSettings settings;
    settings.setValue( s + "/width", width() );
    settings.setValue( s + "/height", height() );

    return;
    // the following is not good when going on and off of a dual display etc
    // QString s = objectName();
    // if ( s.isEmpty() ) s = metaObject()->className();
    // s += "/";
    // QSettings settings;
    // settings.setValue( s + "geometry", saveGeometry() );
}

void WTabDialog::doLoadState()
{
    QString s = metaObject()->className();
    if ( !objectName().isEmpty() ) s = s + "/" + objectName();

    QSettings settings;
    int nWidth = settings.value( s + "/width", width() ).toInt();
    int nHeight= settings.value( s + "/height", height() ).toInt();
    resize( nWidth, nHeight );

    return;
    // the following is not good when going on and off of a dual display etc
    // QString s = objectName();
    // if ( s.isEmpty() ) s = metaObject()->className();
    // s += "/";
    // QSettings settings;
    // restoreGeometry( settings.value( s + "geometry" ).toByteArray() );
}

