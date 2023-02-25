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
#include "WDirSelectWidget.h"
#include "W.h"

WDirSelectWidget::WDirSelectWidget( const QString &stringDirectory, QWidget *pWidgetParent )
    : QWidget( pWidgetParent )
{
    QHBoxLayout *pLayout = new QHBoxLayout( this );
    pDirectory = new QLineEdit( stringDirectory, this );
    pLayout->addWidget( pDirectory );

    pSelect = new QPushButton( QIcon( ":DATAW/Open" ),  QString(), this );
    pLayout->addWidget( pSelect );
    connect( pSelect, SIGNAL(clicked()), SLOT(slotSelect()) );
}

void WDirSelectWidget::slotSelect()
{
    QString stringDirectory = QFileDialog::getExistingDirectory( this, tr("Select directory...") );                                                                                                                                      
    if ( stringDirectory.isEmpty() ) return;

    setDirectory( stringDirectory );
}


