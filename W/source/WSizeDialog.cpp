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
#include "WSizeDialog.h"
#include "W.h"

#include "WSizeWidget.h"

WSizeDialogInt::WSizeDialogInt( const QSize &size, QWidget *pParent )
    : QDialog( pParent )
{
    setWindowTitle( tr("Size") );

    QVBoxLayout *pLayout = new QVBoxLayout( this );
    pSizeWidget = new WSizeWidgetInt( size, this );
    pLayout->addWidget( pSizeWidget ); 

    QDialogButtonBox *pButtonBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );
    pLayout->addWidget( pButtonBox ); 

    connect( pButtonBox, &QDialogButtonBox::accepted, this, &QDialog::accept );
    connect( pButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject );
}

QSize WSizeDialogInt::getSize() 
{ 
    return pSizeWidget->getValue(); 
}

QSize WSizeDialogInt::getSize( bool *pOk, const QSize &size, QWidget *pParent )
{
    QSize sizeOriginal = size;

    *pOk = true;

    WSizeDialogInt dialog( size, pParent );
    if ( dialog.exec() == QDialog::Accepted )
        return dialog.getSize();

    *pOk = false;
    return sizeOriginal;
}


