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

#ifndef H_WSizeDialog
#define H_WSizeDialog

#include "W.h"

class WSizeWidgetInt;

class WSizeDialogInt : public QDialog
{
    Q_OBJECT
public:
    WSizeDialogInt( const QSize &size, QWidget *pParent = nullptr );

    QSize getSize();
    static QSize getSize( bool *pOk, const QSize &size, QWidget *pParent );

protected:
    WSizeWidgetInt *pSizeWidget;
};

#endif 

