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

#include "WPersist.h"

#ifdef Q_OS_WIN
    #include <QtZlib/zlib.h>
//    #include <QtZlib>
#else
    #include <zlib.h>
#endif

//
// WPersist
//

/*
QDomElement WPersist::doSaveText( const PiText &text, QDomDocument *pdomDoc, const QString &stringName )
{                                                                                                       
    QDomElement domElem = pdomDoc->createElement( stringName.isEmpty() ? "PiText" : stringName );       
                                                                                                        
    domElem.appendChild( WPersistNative::doSaveFont( text.font, pdomDoc ) );                            
    domElem.appendChild( WPersistNative::doSaveColor( text.color, pdomDoc ) );                          
    domElem.appendChild( WPersistNative::doSaveBrush( text.brush, pdomDoc ) );                          
                                                                                                        
    return domElem;                                                                                     
}                                                                                                       
*/

/*
PiText WPersist::doLoadText( QDomElement *pdomElem )             
{                                                                
    PiText text;                                                 
                                                                 
    // load additional nodes...                                  
    QDomNode domNode = pdomElem->firstChild();                   
    while( !domNode.isNull() )                                   
    {                                                            
        QDomElement domElem = domNode.toElement();               
        if( domElem.isNull() )                                   
        {                                                        
            domNode = domNode.nextSibling();                     
            continue;                                            
        }                                                        
                                                                 
        if ( domElem.tagName() == "Font" )                       
            text.font = WPersistNative::doLoadFont( &domElem );  
        else if ( domElem.tagName() == "Color" )                 
            text.color = WPersistNative::doLoadColor( &domElem );
        else if ( domElem.tagName() == "Brush" )                 
            text.brush = WPersistNative::doLoadBrush( &domElem );
                                                                 
        domNode = domNode.nextSibling();                         
    }                                                            
                                                                 
    return text;                                                 
}                                                                
*/

//
// WPersistNative
//

QDomElement WPersistNative::doSaveFont( const QFont &font, QDomDocument *pdomDoc, const QString &stringName )
{
    QDomElement domElem = pdomDoc->createElement( stringName.isEmpty() ? "Font" : stringName );
    domElem.setAttribute( "Bold", font.bold() );
    domElem.setAttribute( "Caps", font.capitalization() );
    domElem.setAttribute( "Family", font.family() );
    domElem.setAttribute( "FixedPitch", font.fixedPitch() );
    domElem.setAttribute( "HintingPreference", font.hintingPreference() );
    domElem.setAttribute( "Italic", font.italic() );
    domElem.setAttribute( "Kerning", font.kerning() );
    // domElem.setAttribute( "letterSpacing", font.letterSpacing() );
    domElem.setAttribute( "Overline", font.overline() );
    if ( font.pixelSize() >= 0 )
        domElem.setAttribute( "PixelSize", font.pixelSize() );
    domElem.setAttribute( "PointSize", font.pointSize() );
    domElem.setAttribute( "Stretch", font.stretch() );
    domElem.setAttribute( "StrikeOut", font.strikeOut() );
    domElem.setAttribute( "Style", font.style() );
    // domElem.setAttribute( "styleHint", font.styleHint() );
    domElem.setAttribute( "StyleStrategy", font.styleStrategy() );
    domElem.setAttribute( "Underline", font.underline() );
    domElem.setAttribute( "Weight", font.weight() );
    domElem.setAttribute( "WordSpacing", font.wordSpacing() );

    return domElem;
}

QDomElement WPersistNative::doSavePen( const QPen &pen, QDomDocument *pdomDoc, const QString &stringName )
{
    QDomElement domElem = pdomDoc->createElement(  stringName.isEmpty() ? "Pen" : stringName );
    domElem.setAttribute( "CapStyle", pen.capStyle() );
    domElem.setAttribute( "Cosmetic", pen.isCosmetic() );
    domElem.setAttribute( "DashOffset", pen.dashOffset() );
    // domElem.setAttribute( "dashPattern", pen.dashPattern() );
    domElem.setAttribute( "JoinStyle", pen.joinStyle() );
    domElem.setAttribute( "MiterLimit", pen.miterLimit() );
    domElem.setAttribute( "Style", pen.style() );
    domElem.setAttribute( "Width", pen.width() );

    domElem.appendChild( doSaveBrush( pen.brush(), pdomDoc ) );
    if ( pen.color().isValid() )
        domElem.appendChild( doSaveColor( pen.color(), pdomDoc ) );

    return domElem;
}

QDomElement WPersistNative::doSaveBrush( const QBrush &brush, QDomDocument *pdomDoc, const QString &stringName )
{
    QDomElement domElem = pdomDoc->createElement( stringName.isEmpty() ? "Brush" : stringName );
    // domElem.setAttribute( "matrix", brush.matrix() );
    domElem.setAttribute( "Style", brush.style() );
    // domElem.setAttribute( "transform", brush.transform() );

    if ( brush.color().isValid() )
        domElem.appendChild( doSaveColor( brush.color(), pdomDoc ) );
    if ( !brush.textureImage().isNull() )
        domElem.appendChild( doSaveImage( brush.textureImage(), pdomDoc, "Texture" ) );

    return domElem;
}

QDomElement WPersistNative::doSaveColor( const QColor &color, QDomDocument *pdomDoc, const QString &stringName )
{
    QColor c = color.convertTo( QColor::Rgb );

    QDomElement domElem = pdomDoc->createElement( stringName.isEmpty() ? "Color" : stringName );
    domElem.setAttribute( "Alpha", c.alpha() );
    domElem.setAttribute( "Red", c.red() );
    domElem.setAttribute( "Green", c.green() );
    domElem.setAttribute( "Blue", c.blue() );

    return domElem;
}

/*!
 * \brief Saves a QImage into XML. 
 *  
 * \note Avoid saving QPixmap because they need a qApp and, in most cases, a destructor will 
 *       not have a qApp.... the app will segfault in such a case.
 * 
 * \author pharvey (12/10/22)
 * 
 * \param image 
 * \param pdomDoc 
 * \param stringName 
 * 
 * \return QDomElement 
 */
QDomElement WPersistNative::doSaveImage( const QImage &image, QDomDocument *pdomDoc, const QString &stringName )
{
    Q_UNUSED(image);

    QDomElement domElem = pdomDoc->createElement( stringName.isEmpty() ? "Image" : stringName );

    ulong nBytesCompressed = 0;
    QString stringEncodedImage = WPersistUtility::getEncodedImage( image, &nBytesCompressed );
    domElem.setAttribute( "Size", QString::number( nBytesCompressed ) );
    domElem.setAttribute( "Data", stringEncodedImage );

    return domElem;
}

QFont WPersistNative::doLoadFont( QDomElement *pdomElem )
{
    QFont font;

    font.setBold( pdomElem->attribute( "Bold" ).toInt() );
    font.setCapitalization( (QFont::Capitalization)pdomElem->attribute( "Caps" ).toInt() );
    font.setFamily( pdomElem->attribute( "Family" ) );
    font.setFixedPitch( pdomElem->attribute( "FixedPitch" ).toInt() );
    font.setHintingPreference( (QFont::HintingPreference)pdomElem->attribute( "HintingPreference" ).toInt() );
    font.setItalic( pdomElem->attribute( "Italic" ).toInt() );
    font.setKerning( pdomElem->attribute( "Kerning" ).toInt() );
    // font.setLetterSpacing( (QFont::SpacingType)pdomElem->attribute( "letterSpacing" ).toInt() );
    font.setOverline( pdomElem->attribute( "Overline" ).toInt() );
    if ( !pdomElem->attribute( "PixelSize" ).isEmpty() )
        font.setPixelSize( pdomElem->attribute( "PixelSize" ).toInt() );
    font.setPointSize( pdomElem->attribute( "PointSize" ).toInt() );
    font.setStretch( pdomElem->attribute( "Stretch" ).toInt() );
    font.setStrikeOut( pdomElem->attribute( "StrikeOut" ).toInt() );
    font.setStyle( (QFont::Style)pdomElem->attribute( "Style" ).toInt() );
    // pdomElem->attribute( "styleHint" );
    font.setStyleStrategy( (QFont::StyleStrategy)pdomElem->attribute( "StyleStrategy" ).toInt() );
    font.setUnderline( pdomElem->attribute( "Underline" ).toInt() );
#if QT_VERSION < 0x060000
    font.setWeight( pdomElem->attribute( "Weight" ).toInt() );
#else
    font.setWeight( (QFont::Weight)pdomElem->attribute( "Weight" ).toInt() );
#endif
    font.setWordSpacing( pdomElem->attribute( "WordSpacing" ).toLong() );

    return font;
}

QPen WPersistNative::doLoadPen( QDomElement *pdomElem )
{
    QPen pen;

    pen.setCapStyle( (Qt::PenCapStyle)pdomElem->attribute( "CapStyle" ).toInt() );
    pen.setCosmetic( pdomElem->attribute( "Cosmetic" ).toInt() );
    pen.setDashOffset( pdomElem->attribute( "DashOffset" ).toLong() );
    // pdomElem->attribute( "dashPattern", pen.dashPattern() );
    pen.setJoinStyle( (Qt::PenJoinStyle)pdomElem->attribute( "JoinStyle" ).toInt() );
    pen.setMiterLimit( pdomElem->attribute( "MiterLimit" ).toLong() );
    pen.setStyle( (Qt::PenStyle)pdomElem->attribute( "Style" ).toInt() );
    pen.setWidth( pdomElem->attribute( "Width" ).toInt() );

    // load child nodes (of interest)
    QDomElement         domElem;
    QDomNode            domNode;
    domNode = pdomElem->firstChild();
    while( !domNode.isNull() ) 
    {
        domElem = domNode.toElement();
        if( domElem.isNull() ) 
        {
            domNode = domNode.nextSibling();
            continue;
        }

        if ( domElem.tagName() == "Brush" )
            pen.setBrush( doLoadBrush( &domElem ) );
        else if ( domElem.tagName() == "Color" )
            pen.setColor( doLoadColor( &domElem ) );

        domNode = domNode.nextSibling();
    }

    return pen;
}

QBrush WPersistNative::doLoadBrush( QDomElement *pdomElem )
{
    QBrush brush;

    Qt::BrushStyle nStyle = (Qt::BrushStyle)pdomElem->attribute( "Style" ).toInt();
    QImage imageTexture;

    // domElem.setAttribute( "matrix", brush.matrix() );
    // domElem.setAttribute( "transform", brush.transform() );

    // load child nodes (of interest)
    QDomElement         domElem;
    QDomNode            domNode;
    domNode = pdomElem->firstChild();
    while( !domNode.isNull() ) 
    {
        domElem = domNode.toElement();
        if( domElem.isNull() ) 
        {
            domNode = domNode.nextSibling();
            continue;
        }

        if ( domElem.tagName() == "Color" )
            brush.setColor( doLoadColor( &domElem ) );
        else if ( domElem.tagName() == "Texture" )
           imageTexture = doLoadImage( &domElem );

        domNode = domNode.nextSibling();
    }

    brush.setTextureImage( imageTexture );
    brush.setStyle( nStyle );

    return brush;
}

QColor WPersistNative::doLoadColor( QDomElement *pdomElem )
{
    int nRed    = pdomElem->attribute( "Red" ).toInt();
    int nGreen  = pdomElem->attribute( "Green" ).toInt();
    int nBlue   = pdomElem->attribute( "Blue" ).toInt();
    int nAlpha  = pdomElem->attribute( "Alpha" ).toInt();

    return QColor( nRed, nGreen, nBlue, nAlpha );
}

QImage WPersistNative::doLoadImage( QDomElement *pdomElem )
{
    QImage image;

    ulong nBytesCompressed = pdomElem->attribute( "Size", "0" ).toULong();
    if ( nBytesCompressed )
    { 
        QString stringAttribute = pdomElem->attribute( "Data" );
        if ( !stringAttribute.isEmpty() )
            image = WPersistUtility::getDecodedImage( stringAttribute, nBytesCompressed );
    }

    return image;
}

//
// WPersistUtility
//

/*!
 * \brief Encode a QImage so it can be safely saved in a text file (ie XML, JSON,...).
 *  
 * This is done by; 
 *  
 * 1 - compressing the image data using zlib
 * 2 - uuencoding the compressed data 
 *  
 * The resulting string can be saved in a text file. The number of bytes will need 
 * to be saved with it in order to call \sa getDecodedImage() later. 
 *  
 * \note Saved in PNG format.
 *  
 * \note The number of bytes processed can not exceed capacity of a 'ulong'. 
 *  
 * \author pharvey (11/24/19)
 * 
 * \param image 
 * \param pnBytes The number of bytes required by getDecodeImage().
 * 
 * \return QString 
 */
QString WPersistUtility::getEncodedImage( const QImage &image, ulong *pnBytes )
{
    QByteArray bytes;
    {
        QBuffer buffer( &bytes );
        buffer.open( QIODevice::WriteOnly );
        image.save( &buffer, "PNG" );
    }

    return getEncodedBinary( bytes, pnBytes );
}

/*!
 * \brief Decode a QImage. 
 *  
 * See \sa getEncodedImage() for details. 
 * 
 * \author pharvey (11/24/19)
 * 
 * \param stringEncoded The encoded string as provided by getEncodedImage(). 
 * \param nBytes The number of bytes needed for the image. This was provided by getEncodedImage(). 
 * 
 * \return QImage 
 */
QImage WPersistUtility::getDecodedImage( const QString &stringEncoded, ulong nBytes )
{
    QImage image;
    image.loadFromData( getDecodedBinary( stringEncoded, nBytes ) );
    return image;
}

QString WPersistUtility::getEncodedBinary( const QByteArray &bytes, ulong *pnBytes )
{
    *pnBytes = bytes.size(); 

    // compress using zlib...
    ulong nBufferSize = bytes.size() * 2;  // larger than we need but safer?   
    QByteArray bytesCompressed( nBufferSize, '\0' );
    ::compress( (uchar*)bytesCompressed.data(), &nBufferSize, (uchar*)bytes.data(), bytes.size() );

    // double duty for nBufferSize: buffer size IN and bytes compressed OUT
    int nBytesCompressed = int(nBufferSize); 

    // encode bytearray 
    // - make all chars safe for a string
    // - result in a string that can be saved to text (ie XML) file
    QString stringEncodedImage;
    static const char szHexChars[] = "0123456789abcdef";
    for ( int nIndex = 0; nIndex < nBytesCompressed; ++nIndex )
    {
        uchar s = (uchar)bytesCompressed[nIndex];
        stringEncodedImage += szHexChars[s >> 4];
        stringEncodedImage += szHexChars[s & 0x0f];
    }

    return stringEncodedImage;
}

QByteArray WPersistUtility::getDecodedBinary( const QString &stringEncoded, ulong nBytes )
{
    // uudecode (string to bytearray)
    // - stringEncoded will have 2 chars for each original byte so the
    //   bytesCompressed will be half the len
    char *bytesCompressed = new char[ stringEncoded.length() / 2 ];
    for ( int nIndex = 0; nIndex < stringEncoded.length() / 2; ++nIndex )
    {
        char cHi = stringEncoded[ 2 * nIndex ].toLatin1();
        char cLo = stringEncoded[ 2 * nIndex  + 1 ].toLatin1();

        uchar cDecoded = 0;
        if ( cHi <= '9' ) cDecoded += cHi - '0';
        else cDecoded += cHi - 'a' + 10;
        cDecoded = cDecoded << 4;

        if ( cLo <= '9' ) cDecoded += cLo - '0';
        else cDecoded += cLo - 'a' + 10;

        bytesCompressed[ nIndex ] = cDecoded;
    }

    // uncompress
    // - we need to be told how big the data was hence nBytes
    QByteArray bytes( nBytes, '\0' );
    ::uncompress( (uchar*) bytes.data(), &nBytes, (uchar*) bytesCompressed, stringEncoded.length()/2 );

    delete [] bytesCompressed;

    return bytes;
}

/*!
    getEncoded
    
    Encode data so we can safely save it in an XML document.
    
    The given string is compressed and then uuencoded.
*/    
QString WPersistUtility::getEncodedText( const QString &string, ulong *pnLen )
{
    QString stringEncoded;

    // into a bytearray...
    QByteArray ba = string.toLocal8Bit();

    // compress bytearray...
    *pnLen = ba.size() * 2;
    QByteArray bazip( (int)*pnLen, ' ' );
    ::compress( (uchar*) bazip.data(), pnLen, (uchar*) ba.data(), ba.size() );

    // encode bytearray to a string where all chars are safe
    static const char hexchars[] = "0123456789abcdef";
    for ( int i = 0; i < (int)(*pnLen); ++i )
    {
        uchar s = (uchar) bazip[i];
        stringEncoded += hexchars[s >> 4];
        stringEncoded += hexchars[s & 0x0f];
    }
    *pnLen = ba.size();

    return stringEncoded;
}

/*!
    getDecoded
    
    Decode data. 
    
    Presumably the data was encoded with getEncoded() so it is
    uudecoded and then uncompressed.
*/
QString WPersistUtility::getDecodedText( const QString &string, ulong nLen )
{
    char *ba = new char[ string.length() / 2 ];
    for ( int i = 0; i < (int)string.length() / 2; ++i )
    {
        char h = string[ 2 * i ].toLatin1();
        char l = string[ 2 * i  + 1 ].toLatin1();
        uchar r = 0;
        if ( h <= '9' )
            r += h - '0';
        else
            r += h - 'a' + 10;
        r = r << 4;
        if ( l <= '9' )
            r += l - '0';
        else
            r += l - 'a' + 10;
        ba[ i ] = r;
    }
    if ( (int)nLen < string.length() * 5 )
        nLen = string.length() * 5;
    QByteArray baunzip( (int)nLen, ' ' );
    ::uncompress( (uchar*) baunzip.data(), &nLen, (uchar*) ba, string.length()/2 );

    QString stringDecoded( baunzip );

    delete [] ba;

    return stringDecoded;
}

