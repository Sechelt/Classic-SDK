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
#include "WValueListWidget.h"
    
WValueListWidget::WValueListWidget( const QStringList &listStrings, QWidget *pwidgetParent, const QString &stringName )
    : QMainWindow( pwidgetParent )
{
    setObjectName( stringName );

    // list widget
    pListWidget = new QListWidget( this );
    pListWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
    pListWidget->setSelectionMode( QAbstractItemView::SingleSelection );

    QString s;
    foreach( s, listStrings )
    {
        QListWidgetItem *pItem = new QListWidgetItem( pListWidget );
        pItem->setText( s );
        pItem->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled );
    }

    setCentralWidget( pListWidget );

    // TOOLBAR
    pActionNew      = new QAction( QIcon( ":W/RowNew16x16" ), tr("New"), this );
    pActionDelete   = new QAction( QIcon( ":W/RowDelete16x16" ), tr("Delete"), this );
    pActionUp       = new QAction( QIcon( ":W/RowUp16x16" ), tr("Up"), this );
    pActionDown     = new QAction( QIcon( ":W/RowDown16x16" ), tr("Down"), this );

    connect( pActionNew, SIGNAL(triggered()), this, SLOT(slotNew()) );
    connect( pActionDelete, SIGNAL(triggered()), this, SLOT(slotDelete()) );
    connect( pActionUp, SIGNAL(triggered()), this, SLOT(slotUp()) );
    connect( pActionDown, SIGNAL(triggered()), this, SLOT(slotDown()) );

    connect( pListWidget, SIGNAL(currentRowChanged(int)), SLOT(slotRowChanged(int)) );

    QToolBar *pToolBar = addToolBar( tr("") );
    pToolBar->addAction( pActionNew );
    pToolBar->addAction( pActionDelete );
    pToolBar->addAction( pActionUp );
    pToolBar->addAction( pActionDown );
}

WValueListWidget::~WValueListWidget()
{
}

QStringList WValueListWidget::getValues()
{
    QStringList listStrings;

    for ( int nRow = 0; nRow < pListWidget->count(); nRow++ ) 
    {
        listStrings.append( pListWidget->item( nRow )->text() );
    }

    return listStrings;
}

void WValueListWidget::slotRowChanged( int )
{
    emit signalChanged( getValues() );
}

void WValueListWidget::slotNew()
{
    QListWidgetItem *pItem = new QListWidgetItem( pListWidget );
    pItem->setText( "" );
    pItem->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled );
    pListWidget->setCurrentRow( pListWidget->count() - 1 );
}

void WValueListWidget::slotDelete()
{
    QListWidgetItem *p = pListWidget->takeItem( pListWidget->currentRow() );
    if ( !p ) return;
    delete p;
}

void WValueListWidget::slotUp()
{
    int nRow = pListWidget->currentRow();
    if ( nRow < 1 ) return;
    QListWidgetItem *p = pListWidget->takeItem( pListWidget->currentRow() );
    if ( !p ) return;
    pListWidget->insertItem( nRow--, p );
}

void WValueListWidget::slotDown()
{
    int nRow = pListWidget->currentRow();
    if ( nRow >= pListWidget->count() - 1 ) return;
    QListWidgetItem *p = pListWidget->takeItem( pListWidget->currentRow() );
    if ( !p ) return;
    pListWidget->insertItem( nRow++, p );
}


