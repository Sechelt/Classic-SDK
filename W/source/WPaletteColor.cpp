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

#include "LibInfo.h"
#include "WPaletteColor.h"

#include "WPersist.h"

//
// WPaletteColor
//

WPaletteColor::WPaletteColor()
{
    // \sa doInit()
}

WPaletteColor::~WPaletteColor()
{
    // \sa doFini()
}


// set color
void WPaletteColor::setValue( int nIndex, const QColor &color )
{
    Q_ASSERT( nIndex >= 0 );
    
    // need to pad?
    for ( int n = vectorColors.count() - 1; n < nIndex; n++ )
    {
        vectorColors.append( QColor( 255, 255, 255, 0 ) ); // white but fully transparent
    }

    // assume we changed color
    vectorColors[nIndex] = color;
    setModifiedPalette( true );
}

QVector<QColor> WPaletteColor::getDefaultColors()
{
    QVector<QColor> vectorColors;

    // Create some default colours.
      
    // r,g,b,a

    // gray
    vectorColors.append( QColor( 255, 255, 255 ) );
    vectorColors.append( QColor( 204, 204, 204 ) );
    vectorColors.append( QColor( 153, 153, 153 ) );
    vectorColors.append( QColor( 102, 102, 102 ) );
    vectorColors.append( QColor( 51, 51, 51 ) );
    vectorColors.append( QColor( 0, 0, 0 ) );

    // red
    vectorColors.append( QColor( 255, 106, 106 ) );
    vectorColors.append( QColor( 255, 48, 48 ) );
    vectorColors.append( QColor( 255, 0, 0 ) );
    vectorColors.append( QColor( 238, 0, 0 ) );
    vectorColors.append( QColor( 205, 0, 0 ) );
    vectorColors.append( QColor( 139, 0, 0 ) );

    // green
    vectorColors.append( QColor( 192, 255, 192 ) );
    vectorColors.append( QColor( 128, 255, 128 ) );
    vectorColors.append( QColor( 0, 255, 0 ) );
    vectorColors.append( QColor( 0, 238, 0 ) );
    vectorColors.append( QColor( 0, 205, 0 ) );
    vectorColors.append( QColor( 0, 139, 0 ) );

    // blue
    vectorColors.append( QColor( 65, 105, 225 ) );
    vectorColors.append( QColor( 58, 95, 205 ) );
    vectorColors.append( QColor( 0, 0, 255 ) );
    vectorColors.append( QColor( 0, 0, 238 ) );
    vectorColors.append( QColor( 0, 0, 205 ) );
    vectorColors.append( QColor( 0, 0, 139 ) );

    // purple 1
    vectorColors.append( QColor( 224, 102, 255 ) );
    vectorColors.append( QColor( 209, 95, 238 ) );
    vectorColors.append( QColor( 155, 48, 255 ) );
    vectorColors.append( QColor( 145, 44, 238 ) );
    vectorColors.append( QColor( 125, 38, 205 ) );
    vectorColors.append( QColor( 85, 26, 139 ) );

    // tan
    vectorColors.append( QColor( 255, 239, 219 ) );
    vectorColors.append( QColor( 255, 228, 196 ) );
    vectorColors.append( QColor( 238, 213, 183 ) );
    vectorColors.append( QColor( 222, 198, 171 ) );
    vectorColors.append( QColor( 205, 183, 158 ) );
    vectorColors.append( QColor( 139, 125, 107 ) );

    // purple 2
    vectorColors.append( QColor( 255, 192, 203 ) );
    vectorColors.append( QColor( 238, 169, 184 ) );
    vectorColors.append( QColor( 255, 0, 255 ) );
    vectorColors.append( QColor( 238, 0, 238 ) );
    vectorColors.append( QColor( 205, 0, 205 ) );
    vectorColors.append( QColor( 139, 0, 139 ) );

    // yellow
    vectorColors.append( QColor( 255, 250, 205 ) );
    vectorColors.append( QColor( 255, 246, 143 ) );
    vectorColors.append( QColor( 255, 255, 0 ) );
    vectorColors.append( QColor( 238, 238, 0 ) );
    vectorColors.append( QColor( 205, 205, 0 ) );
    vectorColors.append( QColor( 139, 139, 0 ) );

    // cyan
    vectorColors.append( QColor( 224, 255, 255 ) );
    vectorColors.append( QColor( 192, 255, 255 ) );
    vectorColors.append( QColor( 0, 255, 255 ) );
    vectorColors.append( QColor( 0, 238, 238 ) );
    vectorColors.append( QColor( 0, 205, 205 ) );
    vectorColors.append( QColor( 0, 139, 139 ) );

    // orange
    vectorColors.append( QColor( 255, 228, 181 ) );
    vectorColors.append( QColor( 255, 211, 155 ) );
    vectorColors.append( QColor( 255, 165, 0 ) );
    vectorColors.append( QColor( 238, 154, 0 ) );
    vectorColors.append( QColor( 205, 133, 0 ) );
    vectorColors.append( QColor( 139, 90, 0 ) );

    return vectorColors;
}

void WPaletteColor::doInit()
{
    // init with hard-coded defaults
    vectorColors = getDefaultColors();

    // restore last palette
    QSettings settings;
    stringFileName = settings.value( WPALETTE_COLOR_DOC_CLASS ).toString();

    if ( stringFileName.isEmpty() )
    {
        // Last palette used was a default. 
        // Any customizations would have been saved to the default file. 
        // Try to load it.
        QString stringDir = QStandardPaths::writableLocation( QStandardPaths::ConfigLocation );
        stringDir += ("/" SDK_ORG);

        QDir dir;
        if ( !dir.exists( stringDir ) ) dir.mkdir( stringDir );
        stringDir += ("/" LIB_NAME);
        if ( !dir.exists( stringDir ) ) dir.mkdir( stringDir );

        stringFileName += stringDir + ("/" WPALETTE_COLOR_DOC_CLASS ".xml");
        if ( QFileInfo::exists( stringFileName ) )
        {
            doLoad( stringFileName );
            stringFileName.clear();
        }
    }
    else
    {
        // Last palette used was a User specified file. Try to load it.
        if ( !doLoad( stringFileName ) ) stringFileName.clear();
    }
}

void WPaletteColor::doFini()
{
    QSettings settings;
    settings.setValue( metaObject()->className(), stringFileName );

    // IF no file name THEN use default
    if ( stringFileName.isEmpty() )
    {
        QString stringDir = QStandardPaths::writableLocation( QStandardPaths::ConfigLocation );
        stringDir += ("/" SDK_ORG);
        stringDir += ("/" LIB_NAME);
        stringFileName += stringDir + ("/" WPALETTE_COLOR_DOC_CLASS ".xml");
    }

    doSave( stringFileName );
}

void WPaletteColor::slotLoad()
{
    // todo save any changes first

    QFileInfo   FileInfo( stringFileName );
    QString     stringDir       = FileInfo.absoluteFilePath();
    QString     stringFilter    = tr("Colors") + " (*." WPALETTE_COLOR_DOC_CLASS ")";
    QString     s               = QFileDialog::getOpenFileName( qApp->activeWindow(), tr( "Open" ), stringDir, stringFilter );
    if ( s.isEmpty() ) return;

    doLoad( s );
}

void WPaletteColor::slotSave()
{
    if ( stringFileName.isEmpty() ) return slotSaveAs();

    doSave( stringFileName );
}

void WPaletteColor::slotSaveAs()
{
    QFileInfo   FileInfo( stringFileName );
    QString     stringWindowTitle   = tr("Save Color Palette As");
    QString     stringDir           = FileInfo.absoluteFilePath();
    QString     stringFilter        = tr("Colors") + " (*." WPALETTE_COLOR_DOC_CLASS ")";

    QString s = QFileDialog::getSaveFileName( qApp->activeWindow(), stringWindowTitle, stringDir, stringFilter );
    if ( s.isEmpty() ) return;

    FileInfo.setFile( s );
    if ( FileInfo.suffix().isEmpty() ) s += "." WPALETTE_COLOR_DOC_CLASS;

    doSave( s );
}

void WPaletteColor::slotReset()
{
    // \TODO lose changes?

    // current stays the same
    vectorColors = getDefaultColors();
    setFileName( QString() );
    setModifiedPalette( false );
}

void WPaletteColor::setFileName( const QString &s )
{
    stringFileName = s;
    emit signalModifiedFileName();
}

void WPaletteColor::setModifiedPalette( bool b )
{
    bModifiedPalette = b;
    emit signalModifiedPalette();
}

bool WPaletteColor::doLoad( const QString &s )
{
    // open a file...
    QFile file( s );
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QMessageBox::information( qApp->activeWindow(), tr("Open Color Palette"), tr("Could not open file.\n\n") + s, QMessageBox::Ok );
        return false;
    }

    // read file into XML document...
    QDomDocument domDoc( metaObject()->className() );
    {
        QString stringErrorMsg;
        int nErrorLine;
        int nErrorColumn;
        if ( !domDoc.setContent( &file, false, &stringErrorMsg, &nErrorLine, &nErrorColumn ) )
        {
            QMessageBox::information( qApp->activeWindow(), tr("Open Color Palette"), tr("Invalid file format.\nCould not create an XML document from file.\n\n") + file.fileName() );
            file.close();
            return false;
        }
    }
    file.close();

    // validate XML...
    // Root element is only used to check that class in XML matches this class.
    QDomElement domElemRoot = domDoc.documentElement();
    if ( domElemRoot.isNull() )
    {
        QMessageBox::information( qApp->activeWindow(), tr("Open Color Palette"), tr("Invalid file format.\nCould not find a document element.\n\n") + s );
        return false;
    }
    if ( domElemRoot.tagName() != metaObject()->className() )
    {
        QMessageBox::information( qApp->activeWindow(), tr("Open Color Palette"), tr("Invalid file format.\nFile does not appear to be a ") + QString( metaObject()->className() ) + "\n\n" + s );
        return false;
    }
    if ( domElemRoot.attribute( "DocVer" ) != SDK_DOC_VER ) 
    {
        QMessageBox::information( qApp->activeWindow(), tr("Open Color Palette"), tr("Invalid file format.\nFile is not Version ") + SDK_DOC_VER );
        return false;
    }

    // Its our data so lets start processing starting at first child...
    setFileName( s );
    vectorColors.clear();
    QDomNode domNode = domElemRoot.firstChild();

    while ( !domNode.isNull() )
    {
        if ( domNode.nodeType() != QDomNode::ElementNode )
        {
            domNode = domNode.nextSibling();
            continue;
        }

        QDomElement domElem = domNode.toElement();
        if ( domElem.isNull() )
        {
            domNode = domNode.nextSibling();
            continue;
        }

        if ( domElem.tagName() == "Color" )
        { 
            QColor brush = WPersistNative::doLoadColor( &domElem );
            vectorColors.append( brush );
        }

        domNode = domNode.nextSibling();
    }
    setModifiedPalette( false );
    return true;
}

bool WPaletteColor::doSave( const QString &s )
{
    // create
    QFile file( s );
    if ( !file.open( QIODevice::WriteOnly ) )
    {
        QMessageBox::information( qApp->activeWindow(), tr("Save Color Palette"), tr("Could not open ") + file.fileName() );
        return false;
    }

    // this could be a SaveAs so...
    setFileName( s );

    // create an XML document with class name and document version...
    QDomDocument domDoc( metaObject()->className() );
    QDomElement domElementRoot = domDoc.createElement( metaObject()->className() );
    domElementRoot.setAttribute( "DocVer", SDK_DOC_VER );

    domDoc.appendChild( domElementRoot );

    for ( int n = 0; n < vectorColors.count(); n++ )
    {
        domElementRoot.appendChild( WPersistNative::doSaveColor( vectorColors.at( n ), &domDoc, "Color" ) );
    }

    // write
    QString stringXML = domDoc.toString();
    file.write( stringXML.toLatin1(), stringXML.length() );

    // close
    file.close();

    setModifiedPalette( false );

    return true;
}

/*!
 * \brief Global for palette.
 *  
 * We avoid auto initialization so we can control exactly when this gets 
 * created, initialized, finalized, and deleted. 
 *  
 * \sa main() 
 * 
 * \author pharvey (12/23/22)
 */
WPaletteColor *g_PaletteColors;


