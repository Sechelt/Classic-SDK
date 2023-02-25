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
#include "WDirectiveWidget.h"

WDirectiveWidget::WDirectiveWidget( const QIcon &icon, QTableWidget *pTableWidget, QWidget *pParent )
    : QWidget( pParent )
{
    // this is our popup list
    this->pTableWidget = pTableWidget;
    pTableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
    pTableWidget->setSelectionMode( QAbstractItemView::SingleSelection );    
    pTableWidget->setWindowFlag( Qt::Popup /* Qt::WindowType flag, bool on = true */ );
    pTableWidget->hide();
    connect( pTableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), SLOT(slotItemClicked(QTableWidgetItem*)) );

    // we are 2 buttons
    QHBoxLayout *pLayout = new QHBoxLayout( this );
    pLayout->setSpacing( 0 );

    // button to emit signalDo()...
    QTableWidgetItem *pItem = pTableWidget->item( pTableWidget->currentRow(), 0 );
    pButtonDo = new QPushButton( pItem->icon(), pItem->text(), this );
    pLayout->addWidget( pButtonDo );
    connect( pButtonDo, SIGNAL(clicked()), SLOT(slotDo()) );
    // button to popup list to select directive...
    pButtonSelect  = new QToolButton( this );
    pActionSelect = new QAction( icon, "", this );
    pButtonSelect->setDefaultAction( pActionSelect );
    pLayout->addWidget( pButtonSelect );
    connect( pActionSelect, SIGNAL(triggered()), SLOT(slotSelect()) );
}

WDirectiveWidget::~WDirectiveWidget()
{
    delete pTableWidget;
}

void WDirectiveWidget::slotDo()
{
    emit signalDo();
    emit signalDo( pTableWidget->currentRow() );
}

void WDirectiveWidget::slotSelect()
{
    QPoint pointPos = mapToGlobal( pos() );
    // QPoint pointPos = QCursor::pos();
    pTableWidget->move( pointPos.x(), pointPos.y() + height() );
    pTableWidget->show();
}


void WDirectiveWidget::slotItemClicked( QTableWidgetItem *p )
{
    QTableWidgetItem *pItem = pTableWidget->item( p->row(), 0 );
    pButtonDo->setIcon( pItem->icon() );
    pButtonDo->setText( pItem->text() );
    pTableWidget->hide();
}



