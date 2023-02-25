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
#include "WCanvasSizeWidget.h"

WCanvasSizeWidget::WCanvasSizeWidget( const QSizeF &size, bool bPrinter, QWidget *pParent )
    : QWidget( pParent )
{
    QVBoxLayout *pLayout = new QVBoxLayout( this );

    // printer
    {
        pUsePrinter = new QCheckBox( tr("Use Printer Page Size"), this );
        pUsePrinter->setChecked( bPrinter );
        pLayout->addWidget( pUsePrinter );
    }
    // manual size
    {
        QFormLayout *pLayoutForm = new QFormLayout();

        pLineEditX = new QLineEdit( this );
        pLineEditX->setText( QString::number( size.width() ) );
        pLineEditX->setValidator( new QDoubleValidator( 10.0, 10000.0, 2, pLineEditX ) );
        pLayoutForm->addRow( tr("&Width:"), pLineEditX );

        pLineEditY = new QLineEdit( this );
        pLineEditY->setText( QString::number( size.height() ) );
        pLineEditY->setValidator( new QDoubleValidator( 10.0, 10000.0, 2, pLineEditY ) );
        pLayoutForm->addRow( tr("&Height:"), pLineEditY );

        pLayout->addLayout( pLayoutForm );
    }

    if ( bPrinter )
    {
         pLineEditX->setEnabled( false );
         pLineEditY->setEnabled( false );
    }

    connect( pUsePrinter, SIGNAL(clicked(bool)), SIGNAL(signalPrinter(bool)) );
    connect( pLineEditX, SIGNAL(textEdited(const QString &)), SLOT(slotSize(const QString &)) );
    connect( pLineEditY, SIGNAL(textEdited(const QString &)), SLOT(slotSize(const QString &)) );
}

void WCanvasSizeWidget::slotSize( const QSizeF &size )
{
    pLineEditX->setText( QString::number( size.width() ) );
    pLineEditY->setText( QString::number( size.height() ) );
}

void WCanvasSizeWidget::slotPrinter( bool bPrinter )
{
    if ( bPrinter )
    {
         pLineEditX->setEnabled( false );
         pLineEditY->setEnabled( false );
    }
    else
    {
        pLineEditX->setEnabled( true );
        pLineEditY->setEnabled( true );
    }

    pUsePrinter->setChecked( bPrinter );
}

void WCanvasSizeWidget::slotSize( const QString & )
{
    QSizeF size( pLineEditX->text().toDouble(), pLineEditY->text().toDouble() );
    emit signalSize( size );
}























