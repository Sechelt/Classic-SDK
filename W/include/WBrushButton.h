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

#ifndef H_WBrushButton
#define H_WBrushButton

#include "W.h"

class WBrushSwatch : public QWidget
{
    Q_OBJECT
public:
    WBrushSwatch( const QBrush &brush, QWidget *pParent );

    void setBrush( const QBrush & );

protected:
    void paintEvent( QPaintEvent *pEvent );
    QSize sizeHint() const;

private:
    QBrush  brush;
};

/*!
 * \class WBrushButton 
 * \brief A button that can be used to configure a brush. 
 *  
 * Clicking this will invoke a \sa WBrushDialog. 
 * The button will display a sample of the current brush under an icon indicating a brush. 
 * 
 * \author pharvey (4/19/22)
 */
class WBrushButton : public QToolButton
{
    Q_OBJECT
public:
    WBrushButton( const QBrush &brush, QWidget *pParent );

    void setBrush( const QBrush &brush );

signals:
    void signalChanged( QBrush brush );

protected:
    QBrush  brush;

    WBrushSwatch *pSwatch;
    QPushButton *pButton;

protected slots:
    void slotClicked();
};

#endif 

