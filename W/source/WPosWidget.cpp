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
#include "WPosWidget.h"
#include "W.h"

WPosWidget::WPosWidget( const QPointF &pointPos, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxX = new QDoubleSpinBox( this );
    pSpinBoxX->setMinimum( -10000 );
    pSpinBoxX->setMaximum( 10000 );
    pSpinBoxX->setValue( pointPos.x() );
    pSpinBoxX->setToolTip( tr("x coordinate") );
    connect( pSpinBoxX, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxY = new QDoubleSpinBox( this );
    pSpinBoxY->setMinimum( -10000 );
    pSpinBoxY->setMaximum( 10000 );
    pSpinBoxY->setValue( pointPos.y() );
    pSpinBoxY->setToolTip( tr("y coordinate") );
    connect( pSpinBoxY, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    if ( bToolBar )
    { 
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxX, 0, 0 );
        pLayout->addWidget( pSpinBoxY, 1, 0 );
    }
    else
    {
        QFormLayout *pLayoutF = new QFormLayout( this );
        pLayoutF->addRow( new QLabel( tr("x:"), this ), pSpinBoxX );
        pLayoutF->addRow( new QLabel( tr("y:"), this ), pSpinBoxY );
    }
}

void WPosWidget::setValue( const QPointF &pointPos )
{
    pSpinBoxX->setValue( pointPos.x() );
    pSpinBoxY->setValue( pointPos.y() );
}

QPointF WPosWidget::getValue() 
{ 
    return QPointF( pSpinBoxX->value(), pSpinBoxY->value() ); 
}

void WPosWidget::slotValue( const QPointF &pointPos )
{
    setValue( pointPos );
}

void WPosWidget::slotChanged()
{
    emit signalChanged( getValue() );
}


