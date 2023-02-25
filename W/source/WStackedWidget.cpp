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
#include "WStackedWidget.h"

WStackedWidget::WStackedWidget( QWidget *pParent )
    : QWidget( pParent )
{
    QVBoxLayout *pLayoutTop = new QVBoxLayout( this );

    pComboBox = new QComboBox( this );
    pLayoutTop->addWidget( pComboBox );
    connect( pComboBox, SIGNAL(currentIndexChanged(int)), SLOT(slotIndex(int)) );

    pStackedWidget = new QStackedWidget( this );
    pLayoutTop->addWidget( pStackedWidget, 10 );
}

void WStackedWidget::setName( int nIndex, const QString &stringName )
{
    pComboBox->setItemText( nIndex, stringName );
}

void WStackedWidget::addWidget( const QString &stringName, QWidget *pWidget )
{
    // scroll bars may be needed so...
    QScrollArea *pScroll = new QScrollArea();
    pScroll->setWidgetResizable( true );
    pScroll->setWidget( pWidget ); // auto reparented

    // we use this to xref pWidget and pScroll... 
    vectorWidgets.append( pWidget );

    //
    pStackedWidget->addWidget( pScroll ); // auto reparented

    // last as it will trigger a call to slotIndex
    pComboBox->addItem( stringName );
}

void WStackedWidget::removeWidget( const QString &stringName )
{
    int nIndex = pComboBox->findText( stringName );
    if ( nIndex < 0 ) return;
    disconnect( pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotIndex(int)) );

    pComboBox->removeItem( nIndex );
    vectorWidgets.remove( nIndex );
    pStackedWidget->removeWidget( pStackedWidget->widget( nIndex ) );

    connect( pComboBox, SIGNAL(currentIndexChanged(int)), SLOT(slotIndex(int)) );
}

void WStackedWidget::removeWidget( QWidget *pWidget )
{
    int nIndex = vectorWidgets.indexOf( pWidget );
    if ( nIndex < 0 ) return;
    disconnect( pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotIndex(int)) );

    pComboBox->removeItem( nIndex );
    vectorWidgets.remove( nIndex );
    pStackedWidget->removeWidget( pWidget );

    connect( pComboBox, SIGNAL(currentIndexChanged(int)), SLOT(slotIndex(int)) );
}

void WStackedWidget::setCurrent( const QString &stringName )
{
    pComboBox->setCurrentIndex( pComboBox->findText( stringName ) );
}

void WStackedWidget::setCurrent( QWidget *pWidget )
{
    pComboBox->setCurrentIndex( vectorWidgets.indexOf( pWidget ) );
}

int WStackedWidget::count() 
{ 
    return vectorWidgets.count(); 
}

QWidget *WStackedWidget::widget( int nIndex ) 
{
    Q_ASSERT( nIndex >= 0 );
    Q_ASSERT( nIndex < vectorWidgets.count() ); 
    return vectorWidgets.at( nIndex ); 
}

void WStackedWidget::slotIndex( int nIndex )
{
   pStackedWidget->setCurrentIndex( nIndex );
   emit signalCurrentChanged( ( nIndex < 0 ? nullptr : vectorWidgets.at( nIndex ) ) );
   emit signalCurrentChanged( pComboBox->currentText() );
}


