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

#ifndef H_WCanvasSizeWidget
#define H_WCanvasSizeWidget

#include "W.h"

/*!
 * \brief Manage canvas size. 
 *  
 * The canvas size can be; 
 *  
 * - based upon current printer page size
 * - set manually in pixels 
 * - fixed  
 *  
 * Size can not be changed when 'fixed' which makes this a view-only. Just disable this widget.
 *  
 * \author pharvey (8/1/20)
 */
class WCanvasSizeWidget : public QWidget
{
    Q_OBJECT
public:
    WCanvasSizeWidget( const QSizeF &size, bool bPrinter, QWidget *pParent );

signals:
    // to request change in object
    void signalSize( const QSizeF &size );
    void signalPrinter( bool );

public slots:
    // to register value in object (may be different than requested)
    void slotSize( const QSizeF &size );
    void slotPrinter( bool );

protected:
    QCheckBox *     pUsePrinter;
    QLineEdit *     pLineEditX;
    QLineEdit *     pLineEditY;

protected slots:
    void slotSize( const QString & );
};

#endif


