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

#ifndef H_WPaletteColorWidget
#define H_WPaletteColorWidget

#include "W.h"

/*!
 * \brief Presents the global color palette for color selection/modification.
 *  
 * This a UI for WPaletteColor - specifically - its single global instance \sa g_PaletteColors. 
 *  
 * - view state of palette 
 * - add/remove/edit color (triggeres WPaletteColor::signalModified())
 * - select a color (triggers WPaletteColorMatrix::signalSelected())
 * 
 * \author pharvey (11/30/22)
 */
class WPaletteColorMatrix : public QWidget
{
    Q_OBJECT
public:
    WPaletteColorMatrix( QWidget *pParent );

signals:
    void signalSelected( const QColor & );

public slots:
    void slotRefresh(); // connect to g_Palette->colors.signalModified()

protected:
    QVector<QColor> vectorColors;

    void mousePressEvent( QMouseEvent *pEvent ) override;
    void mouseDoubleClickEvent( QMouseEvent *pEvent ) override;
    void paintEvent( QPaintEvent *pEvent ) override;

private:
    int getIndex( const QPoint & );
};

/*!
 * \brief Combines a WPaletteColorMatrix with a tool bar to allow save/load/reset. 
 * 
 * \author pharvey (12/3/22)
 */
class WPaletteColorWidget : public QWidget
{
    Q_OBJECT
public:
    WPaletteColorWidget( QWidget *pParent );

signals:
    void signalSelected( const QColor & );

public slots:
    void slotRefresh( const QColor & );

protected:
    QToolButton *   pLoad;  
    QToolButton *   pSave;  
    QToolButton *   pSaveAs;
    QToolButton *   pReset; 
    QLabel *        pModified;

protected slots:
    void slotRefresh();

};

#endif 

