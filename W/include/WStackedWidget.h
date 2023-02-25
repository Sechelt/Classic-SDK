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

#ifndef H_WStackedWidget
#define H_WStackedWidget

#include "W.h"

/*!
 * \class WStackedWidget 
 * \brief A stacked widget with a combobox for selecting which widget to show. 
 * 
 * \author pharvey (2/6/20)
 */
class WStackedWidget : public QWidget
{
    Q_OBJECT
public:
    WStackedWidget( QWidget *pParent );

    void setName( int nIndex, const QString &stringName );
    void addWidget( const QString &stringName, QWidget *pWidget );
    void removeWidget( const QString &stringName );
    void removeWidget( QWidget *pWidget );
    void setCurrent( const QString &stringName );
    void setCurrent( QWidget *pWidget );
    int count();
    QWidget *widget( int nIndex );

signals:
    void signalCurrentChanged( QWidget *pWidget );
    void signalCurrentChanged( const QString &stringName );

protected:
    QComboBox *     pComboBox;
    QStackedWidget *pStackedWidget;

    QVector<QWidget*> vectorWidgets;

protected slots:
    void slotIndex( int nIndex );
};

#endif 

