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

#ifndef H_WSizeHintWidget
#define H_WSizeHintWidget

#include "W.h"

/*!
 * \brief Manage position.
 * 
 * \author pharvey (7/25/20)
 */
class WSizeHintWidget : public QWidget
{
    Q_OBJECT
public:
    WSizeHintWidget( const QSizeF &size, QWidget *pParent, bool bToolBar = false );

    void setValue( const QSizeF &size );

    QSizeF getValue();

signals:
    void signalChanged( const QSizeF &size );

public slots:
    void slotValue( const QSizeF &size );

protected:
    QDoubleSpinBox *pSpinBoxWidth;
    QDoubleSpinBox *pSpinBoxHeight;

protected slots:
    void slotChanged();
};

#endif 

