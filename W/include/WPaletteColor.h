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

#ifndef H_WPaletteColor
#define H_WPaletteColor

#include "W.h"

/*!
 * \brief A customizable colour palette.
 *  
 * Is a color palette based upon a vector of QColor. 
 *  
 * Has a default palette which can be; 
 *      - edited
 *      - saved
 *      - loaded
 *      - reset
 *  
 * No concept of 'current' color or 'selected' color. 
 *  
 * There should be just one of these and it should be global. The global should be 
 * initialized/finilized explicitly in main.cpp after Qt application and before exec 
 * main widget. 
 *  
 * \sa g_PaletteColors 
 * \sa WPaletteColorWidget 
 *  
 * \author pharvey (11/30/22)
 */
class WPaletteColor : public QObject
{
    Q_OBJECT
public:
    WPaletteColor();
    ~WPaletteColor();

    void setValue( int nIndex, const QColor &color ); 

    QString                 getFileName()   { return stringFileName; }
    QVector<QColor>         getColors()     { return vectorColors;  }
    static QVector<QColor>  getDefaultColors();

    void doInit();
    void doFini();

    bool isModified() { return bModifiedPalette; }

signals:
    void signalModifiedFileName();          // file name modified
    void signalModifiedPalette();           // palette modified

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotReset();

protected:
    QString         stringFileName;
    bool            bModifiedPalette = false;   // is palette modified? (we do not care about current or file name)
    QVector<QColor> vectorColors;               /*!< customizable list of colors                            */

    void setFileName( const QString &s );
    void setModifiedPalette( bool b );

    bool doLoad( const QString &stringFileName );
    bool doSave( const QString &stringFileName );
};

extern WPaletteColor *g_PaletteColors;

#endif

