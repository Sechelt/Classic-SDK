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

#ifndef H_WColorPickerWidget
#define H_WColorPickerWidget

#include "W.h"
#include <qmath.h>

#include "W.h"

class WPaletteColorWidget;

class WColorSpectrumWidget : public QWidget
{
    Q_OBJECT
public:
    WColorSpectrumWidget( const QColor &color, QWidget *pParent );

    void setColor( const QColor & ); 

    QColor getColor() { return color; }

signals:
    void signalValueChanged( const QColor & );

protected:
    QPoint point;
    QColor color;

    void mousePressEvent( QMouseEvent *pEvent ) override;
    void paintEvent( QPaintEvent *pEvent ) override;

private:
    struct Polar
    {
        qreal radius;
        qreal angle;    // radians
    };

    Polar cartesianToPolar(qreal x, qreal y);
};

class WColorPickerSwatchWidget : public QWidget
{
    Q_OBJECT
public:
    WColorPickerSwatchWidget( const QColor &color, QWidget *pParent );

public slots:
    void slotColor( const QColor & ); 

protected:
    QColor color;

    void paintEvent( QPaintEvent *pEvent ) override;
};

/*!
 * \brief Color picker widget ie for a color picker dialog.
 *  
 * This combines; 
 *  
 *      - color spectrum widget for picking a color
 *      - color palette widget for picking a color
 *      - controls for selecting HSVA for picking a color
 *      - color swatch to see example of current selection
 *  
 * \author pharvey (2/21/23)
 */
class WColorPickerWidget : public QWidget
{
    Q_OBJECT
public:
    WColorPickerWidget( const QColor &color, QWidget *pParent, bool bShowPaletteColor = false );

    QColor getColor() { return color; }

protected:
    QColor color;
    WColorSpectrumWidget *pSpectrum;
    WColorPickerSwatchWidget *pSwatch;
    WPaletteColorWidget *pPalette = nullptr;

    QSlider *pSliderHue;
    QSlider *pSliderSat;
    QSlider *pSliderVal;
    QSlider *pSliderAlp;

    QSpinBox *pSpinHue;
    QSpinBox *pSpinSat;
    QSpinBox *pSpinVal;
    QSpinBox *pSpinAlp;

protected slots:
    void slotSpectrum( const QColor & );
    void slotPalette( const QColor & );
    void slotHue( int );
    void slotSat( int );
    void slotVal( int );
    void slotAlp( int );
};

#endif 

