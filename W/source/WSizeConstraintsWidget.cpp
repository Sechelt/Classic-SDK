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
#include "WSizeConstraintsWidget.h"
#include "W.h"

WSizeConstraintsWidget::WSizeConstraintsWidget( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxMinWidth = new QDoubleSpinBox( this );
    pSpinBoxMinWidth->setMinimum( 0 );
    pSpinBoxMinWidth->setMaximum( 10000 );
    pSpinBoxMinWidth->setValue( sizeMinimum.width() );
    pSpinBoxMinWidth->setToolTip( tr("minimum width") );
    connect( pSpinBoxMinWidth, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxMaxWidth = new QDoubleSpinBox( this );
    pSpinBoxMaxWidth->setMinimum( 0 );
    pSpinBoxMaxWidth->setMaximum( 10000 );
    pSpinBoxMaxWidth->setValue( sizeMaximum.width() );
    pSpinBoxMaxWidth->setToolTip( tr("maximum width") );
    connect( pSpinBoxMaxWidth, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxMinHeight = new QDoubleSpinBox( this );
    pSpinBoxMinHeight->setMinimum( 0 );
    pSpinBoxMinHeight->setMaximum( 10000 );
    pSpinBoxMinHeight->setValue( sizeMinimum.height() );
    pSpinBoxMinHeight->setToolTip( tr("minimum height") );
    connect( pSpinBoxMinHeight, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxMaxHeight = new QDoubleSpinBox( this );
    pSpinBoxMaxHeight->setMinimum( 0 );
    pSpinBoxMaxHeight->setMaximum( 10000 );
    pSpinBoxMaxHeight->setValue( sizeMaximum.height() );
    pSpinBoxMaxHeight->setToolTip( tr("maximum height") );
    connect( pSpinBoxMaxHeight, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    if ( bToolBar )
    {
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxMinWidth, 0, 0 );
        pLayout->addWidget( pSpinBoxMaxWidth, 1, 0 );
        pLayout->addWidget( pSpinBoxMinHeight, 0, 1 );
        pLayout->addWidget( pSpinBoxMaxHeight, 1, 1 );
    }
    else
    {
        QHBoxLayout *pLayout = new QHBoxLayout( this );
        {
            QGroupBox *     pGroupBox   = new QGroupBox( tr("Minimum"), this );
            QFormLayout *   pLayoutF    = new QFormLayout( pGroupBox );
            pLayoutF->addRow( new QLabel( tr("Width:"), pGroupBox ), pSpinBoxMinWidth );
            pLayoutF->addRow( new QLabel( tr("Height:"), pGroupBox ), pSpinBoxMinHeight );
            pLayout->addWidget( pGroupBox );
        }
        {
            QGroupBox *     pGroupBox   = new QGroupBox( tr("Maximum"), this );
            QFormLayout *   pLayoutF    = new QFormLayout( pGroupBox );
            pLayoutF->addRow( new QLabel( tr("Width:"), pGroupBox ), pSpinBoxMaxWidth );
            pLayoutF->addRow( new QLabel( tr("Height:"), pGroupBox ), pSpinBoxMaxHeight );
            pLayout->addWidget( pGroupBox );
        }
    }
}

void WSizeConstraintsWidget::setValue( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum )
{
    setMinimum( sizeMinimum );
    setMaximum( sizeMaximum );
}

void WSizeConstraintsWidget::setMinimum( const QSizeF &size )
{
    pSpinBoxMinWidth->setValue( size.width() );
    pSpinBoxMinHeight->setValue( size.height() );
}

void WSizeConstraintsWidget::setMaximum( const QSizeF &size )
{
    pSpinBoxMaxWidth->setValue( size.width() );
    pSpinBoxMaxHeight->setValue( size.height() );
}

void WSizeConstraintsWidget::slotValue( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum )
{
    setValue( sizeMinimum, sizeMaximum );
}

void WSizeConstraintsWidget::slotChanged()
{
    emit signalChanged( getMinimum(), getMaximum() );
}


