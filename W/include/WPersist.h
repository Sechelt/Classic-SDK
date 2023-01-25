#ifndef H_WPersist
#define H_WPersist

#include "W.h"

#include <QDomDocument>

/*!
 * \brief Methods to persist extended classes to xml.
 * 
 * \author pharvey (12/11/22)
 */
class WPersist
{
public:
//    static QDomElement doSaveText( const PiText &text, QDomDocument *pdomDoc, const QString &stringName = QString() );

//    static PiText       doLoadText( QDomElement *pdomElem );
};

/*!
 * \brief Methods to persist standard Qt objects in xml.
 * 
 * \author pharvey (12/11/22)
 */
class WPersistNative
{
public:
    static QDomElement doSaveFont( const QFont &font, QDomDocument *pdomDoc, const QString &stringName = QString() );
    static QDomElement doSavePen( const QPen &pen, QDomDocument *pdomDoc, const QString &stringName = QString() );
    static QDomElement doSaveBrush( const QBrush &brush, QDomDocument *pdomDoc, const QString &stringName = QString() );
    static QDomElement doSaveColor( const QColor &color, QDomDocument *pdomDoc, const QString &stringName = QString() );
    static QDomElement doSaveImage( const QImage &image, QDomDocument *pdomDoc, const QString &stringName = QString() );

    static QFont       doLoadFont( QDomElement *pdomElem );
    static QPen        doLoadPen( QDomElement *pdomElem );
    static QBrush      doLoadBrush( QDomElement *pdomElem );
    static QColor      doLoadColor( QDomElement *pdomElem );
    static QImage      doLoadImage( QDomElement *pdomElem );
};

/*!
 * \brief Methods to support persisting binary format in xml.
 * 
 * \author pharvey (12/11/22)
 */
class WPersistUtility
{
public:
    static  QString     getEncodedImage( const QImage &image, ulong *pnBytes );
    static  QImage      getDecodedImage( const QString &stringData, ulong nBytes );
    static  QString     getEncodedBinary( const QByteArray &ba, ulong *pnBytes );
    static  QByteArray  getDecodedBinary( const QString &stringData, ulong nBytes );
    static  QString     getEncodedText( const QString &string, ulong *pnLen );
    static  QString     getDecodedText( const QString &string, ulong nLen );
};

#endif

