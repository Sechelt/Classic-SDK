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

#ifndef H_WZoomWidget
#define H_WZoomWidget

#include "W.h"

/*!
 * \class WZoomWidget 
 * \brief Allows zoom to be specified using a variety of controls. 
 *  
 * The controls that can be used are any combination of; 
 *  
 * - slider 
 * - +/- 
 * - to fit (width/height/all) 
 * 
 * \author pharvey (2/6/20)
 */
class WZoomWidget : public QWidget
{
    Q_OBJECT
public:
    enum FitTypes
    {
        FitWidth = 0,
        FitHeight,
        FitAll,
        FitIgnore
    };

    WZoomWidget( QWidget *pParent = nullptr, int nZoom = 100 );

    void setMin( int n );
    void setMax( int n );
    void setPage( int n );
    void setInc( int n );
    void setZoom( int n );
    void setFit( FitTypes n );

    void setVisibleFit( bool b = true );

    int getZoom();
    FitTypes getFit();


signals:
    void signalZoom( WZoomWidget::FitTypes nFit, int nZoom );

public slots:
    void slotRefresh( WZoomWidget::FitTypes nFit, int nZoom );

protected:
    int         nMin;
    int         nMax;
    int         nInc;
    int         nZoom;
    FitTypes    nFit;

    QSlider *       pSlider;
    QLabel *        pLabel;
    QToolButton *   pPlus;
    QToolButton *   pMinus;
    QComboBox *     pFit;

protected slots:
    void slotSlider( int nValue );
    void slotPlus();
    void slotMinus();
    void slotFit( int nIndex );
};

#endif 

