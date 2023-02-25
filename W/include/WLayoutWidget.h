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

#ifndef H_WLayoutWidget
#define H_WLayoutWidget

#include "W.h"

class WSizeHintWidget;
class WMarginsWidget;
class WStretchWidget;
class WSizeConstraintsWidget;

class WLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    WLayoutWidget( QWidget *pParent, bool bToolBar = false );

    void setSizeHint( const QSizeF &size );
    void setMargins( const QMargins &m );
    void setSizeConstraints( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );
    void setStretch( const QSizeF &sizeStretch );

    QSizeF      getSizeHint();
    QMargins    getMargins();
    QSizeF      getSizeConstraintMinimum();
    QSizeF      getSizeConstraintMaximum();
    QSizeF      getStretch();

signals:
    void signalChangedSizeHint( const QSizeF &size );
    void signalChangedMargins( const QMargins &m );
    void signalChangedSizeConstraints( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );
    void signalChangedStretch( const QSizeF &sizeStretch );

public slots:
    void slotSizeHint( const QSizeF &size );
    void slotMargins( const QMargins &m );
    void slotSizeConstraints( const QSizeF &sizeMinimum, const QSizeF &sizeMaximum );
    void slotStretch( const QSizeF &size );

protected:
    WSizeHintWidget *       pSizeHintWidget;
    WMarginsWidget *        pMarginsWidget;
    WSizeConstraintsWidget *pSizeConstraintsWidget;
    WStretchWidget *        pStretchWidget;
};

#endif 

