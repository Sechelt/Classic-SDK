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
#include "WSizeWidget.h"
#include "W.h"

WSizeWidgetDouble::WSizeWidgetDouble( const QSizeF &size, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxWidth = new QDoubleSpinBox( this );
    pSpinBoxWidth->setMinimum( 0 );
    pSpinBoxWidth->setMaximum( 10000 );
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxWidth->setToolTip( tr("width") );
    connect( pSpinBoxWidth, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    pSpinBoxHeight = new QDoubleSpinBox( this );
    pSpinBoxHeight->setMinimum( 0 );
    pSpinBoxHeight->setMaximum( 10000 );
    pSpinBoxHeight->setValue( size.height() );
    pSpinBoxHeight->setToolTip( tr("height") );
    connect( pSpinBoxHeight, SIGNAL(valueChanged(double)), SLOT(slotChanged()) );

    if ( bToolBar )
    { 
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxWidth, 0, 0 );
        pLayout->addWidget( pSpinBoxHeight, 1, 0 );
    }
    else
    {
        QFormLayout *pLayoutF = new QFormLayout( this );
        pLayoutF->addRow( new QLabel( tr("Width:"), this ), pSpinBoxWidth );
        pLayoutF->addRow( new QLabel( tr("Height:"), this ), pSpinBoxHeight );
    }
}

void WSizeWidgetDouble::setValue( const QSizeF &size )
{
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxHeight->setValue( size.height() );
}

QSizeF WSizeWidgetDouble::getValue() 
{ 
    return QSizeF( pSpinBoxWidth->value(), pSpinBoxHeight->value() ); 
}

void WSizeWidgetDouble::slotValue( const QSizeF &size )
{
    setValue( size );
}

void WSizeWidgetDouble::slotChanged()
{
    emit signalChanged( getValue() );
}

//
//
//

WSizeWidgetInt::WSizeWidgetInt( const QSize &size, QWidget *pParent, bool bToolBar )
    : QWidget( pParent )
{
    pSpinBoxWidth = new QSpinBox( this );
    pSpinBoxWidth->setMinimum( 0 );
    pSpinBoxWidth->setMaximum( 10000 );
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxWidth->setToolTip( tr("width") );
    connect( pSpinBoxWidth, SIGNAL(valueChanged(int)), SLOT(slotChanged()) );

    pSpinBoxHeight = new QSpinBox( this );
    pSpinBoxHeight->setMinimum( 0 );
    pSpinBoxHeight->setMaximum( 10000 );
    pSpinBoxHeight->setValue( size.height() );
    pSpinBoxHeight->setToolTip( tr("height") );
    connect( pSpinBoxHeight, SIGNAL(valueChanged(int)), SLOT(slotChanged()) );

    if ( bToolBar )
    { 
        QGridLayout *pLayout = new QGridLayout( this );
        pLayout->addWidget( pSpinBoxWidth, 0, 0 );
        pLayout->addWidget( pSpinBoxHeight, 1, 0 );
    }
    else
    {
        QFormLayout *pLayoutF = new QFormLayout( this );
        pLayoutF->addRow( new QLabel( tr("Width:"), this ), pSpinBoxWidth );
        pLayoutF->addRow( new QLabel( tr("Height:"), this ), pSpinBoxHeight );
    }
}

void WSizeWidgetInt::setValue( const QSize &size )
{
    pSpinBoxWidth->setValue( size.width() );
    pSpinBoxHeight->setValue( size.height() );
}

QSize WSizeWidgetInt::getValue() 
{ 
    return QSize( pSpinBoxWidth->value(), pSpinBoxHeight->value() ); 
}

void WSizeWidgetInt::slotValue( const QSize &size )
{
    setValue( size );
}

void WSizeWidgetInt::slotChanged()
{
    emit signalChanged( getValue() );
}


