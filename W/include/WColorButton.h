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

#ifndef H_WColorButton
#define H_WColorButton

#include "W.h"

/*!
 * \class WColorButton 
 * \brief A button that can be used to select a color. 
 *  
 * The button can be used to set; pen, brush, or font color. 
 * This does not set other attributes of a; pen, brush or font... there are alternatives if needed.
 *  
 * Clicking this will invoke a \sa QColorDialog. 
 * The button will display the current color under an icon indicating type. 
 *  
 * \sa WPenButton 
 * \sa WTextButton 
 * \sa WBrushButton 
 * 
 * \author pharvey (4/19/22)
 */
class WColorButton : public QToolButton
{
    Q_OBJECT
public:
    enum Types
    {
        Font,
        Pen,
        Brush,
        Fill,
        Color
    };

    WColorButton( const QColor &color, QWidget *pParent, Types n );

    void setValue( const QColor &color );

    QColor getValue() { return color; }

signals:
    void signalChanged( const QColor &color );

protected:
    Types nType;
    QColor color;
    QPixmap getIcon( int nSize = 32 );

protected slots:
    void slotClicked();
};

#endif 

