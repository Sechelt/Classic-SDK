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

#ifndef H_WSizeConstraintsWidget
#define H_WSizeConstraintsWidget

#include "W.h"

/*!
 * \brief Manage mininum and maximum size.
 *  
 * Here we manage the; 
 *  
 * - minimum and maximum Width
 * - minimum and maximum Height
 *  
 * The values entered are *requested* via a signal sent to the object.
 * The actual values (if changed) come in via signal from the object. 
 *  
 * The interface is; 
 *  
 * - a pair of spin boxs for Width 
 * - a pair of spin boxs for Height 
 *  
 * \param  sizeMinumum - min Width,Height 
 * \param  sizeMaximum - max Width,Height
 *  
 * \author pharvey (7/25/20)
 */
class WSizeConstraintsWidget : public QWidget
{
    Q_OBJECT
public:
    WSizeConstraintsWidget( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum, QWidget *pParent, bool bToolBar = false );

    void setValue( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );
    void setMinimum( const QSizeF &size );
    void setMaximum( const QSizeF &size );

    QSizeF getMinimum() { return QSize( pSpinBoxMinWidth->value(), pSpinBoxMinHeight->value() ); }
    QSizeF getMaximum() { return QSize( pSpinBoxMaxWidth->value(), pSpinBoxMaxHeight->value() ); }

signals:
    void signalChanged( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );

public slots:
    void slotValue( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );

protected:
    QDoubleSpinBox *pSpinBoxMinWidth;
    QDoubleSpinBox *pSpinBoxMinHeight;

    QDoubleSpinBox *pSpinBoxMaxWidth;
    QDoubleSpinBox *pSpinBoxMaxHeight;

protected slots:
    void slotChanged();
};

#endif 

