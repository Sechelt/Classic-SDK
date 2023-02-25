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

#ifndef WICONWIDGET_H
#define WICONWIDGET_H

#include "W.h"

/*!
 * \brief Base class for shape icon to be used in tool box.
 *  
 * Derived classes will provide an icon, be able to draw a shape for dragging, etc 
 * The idea is that instances of derived classes can come from a plugin. 
 *  
 * \author pharvey (4/3/19)
 */
class WIconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WIconWidget( const QString &stringText, const QPixmap &pixmapIcon, QWidget *pWidget, const QString &stringTip = QString() );
    virtual ~WIconWidget();

    virtual void setSelected( bool b = true );

    virtual QString getText() { return pLabelText->text(); }
    virtual bool isSelected() { return bSelected; }
      
signals:
    void signalClicked( WIconWidget * );

protected:
    bool bSelected;
    QLabel *pLabelIcon; 
    QLabel *pLabelText; 

    void mousePressEvent( QMouseEvent *pMouseEvent ) override;
};


#endif


