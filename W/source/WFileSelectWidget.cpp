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
#include "WFileSelectWidget.h"
#include "W.h"

WFileSelectWidget::WFileSelectWidget( const QString &stringFileName, const QString &stringFileSpec, QWidget *pWidgetParent )
    : QWidget( pWidgetParent )
{
    this->stringFileSpec = stringFileSpec;

    QHBoxLayout *pLayout = new QHBoxLayout( this );
    pFileName = new QLineEdit( stringFileName, this );
    pLayout->addWidget( pFileName );

    pNew = new QPushButton( QIcon( ":DATAW/New" ),  QString(), this );
    pLayout->addWidget( pNew );
    connect( pNew, SIGNAL(clicked()), SLOT(slotNew()) );

    pOpen = new QPushButton( QIcon( ":DATAW/Open" ),  QString(), this );
    pLayout->addWidget( pOpen );
    connect( pOpen, SIGNAL(clicked()), SLOT(slotOpen()) );
}

void WFileSelectWidget::slotNew()
{
    QString stringFileName = QFileDialog::getExistingDirectory( this, tr("Select directory...") );                                                                                                                                      
    if ( stringFileName.isEmpty() ) return;

    pFileName->setText( stringFileName );
}

void WFileSelectWidget::slotOpen()
{
    QString stringFileName = QFileDialog::getOpenFileName( this, tr("Select file..."), QString(), stringFileSpec );                                                                                                                                      
    if ( stringFileName.isEmpty() ) return;

    pFileName->setText( stringFileName );
}


