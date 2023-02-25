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

#ifndef AWVALUELISTWIDGET_H
#define AWVALUELISTWIDGET_H

#include "W.h"

/*!
 * \class WValueListWidget 
 * \brief Edit a string list. 
 *  
 * This presents a list of the given strings. 
 * Allows the values to be; edited, added, and removed. 
 *  
 * \author pharvey (12/25/19)
 */
class WValueListWidget : public QMainWindow
{
    Q_OBJECT
public:
    WValueListWidget( const QStringList &listStrings, QWidget *pwidgetParent, const QString &stringName = QString() );
    virtual ~WValueListWidget();

    virtual QStringList getValues();

signals:
    void signalChanged( const QStringList & );

public slots:
    void slotRowChanged( int );
    void slotNew();
    void slotDelete();
    void slotUp();
    void slotDown();

protected:
    QAction *pActionNew;
    QAction *pActionDelete;
    QAction *pActionUp;
    QAction *pActionDown;

    QListWidget *pListWidget;
};

#endif 



