#ifndef H_WPaletteColor
#define H_WPaletteColor

#include "W.h"

/*!
 * \brief A customizable colour palette.
 * 
 * The current color is the last selected color from this palette. It could be used 
 * as a default color but that is up to the app. 
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

    void setCurrent( const QColor &color ); 
    void setCurrent( int nIndex ); 
    void setCurrent( int nIndex, const QColor &color ); 

    QString                 getFileName()   { return stringFileName; }
    QColor                  getCurrent()    { return color;         }
    QVector<QColor>         getColors()     { return vectorColors;  }
    static QVector<QColor>  getDefaultColors();

    void doInit();
    void doFini();

    bool isModified() { return bModifiedPalette; }

signals:
    void signalModifiedFileName();          // file name modified
    void signalModifiedCurrent();           // current object modified/edited
    void signalModifiedPalette();           // palette modified
    void signalNewCurrent();                // current object is new (type may have changed)

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotReset();

protected:
    QString         stringFileName;
    bool            bModifiedPalette = false;   // is palette modified? (we do not care about current or file name)
    QVector<QColor> vectorColors;               /*!< customizable list of colors                            */
    QColor          color;                      /*!< current color (does not have to be from vectorColors   */

    void setFileName( const QString &s );
    void setModifiedPalette( bool b );

    bool doLoad( const QString &stringFileName );
    bool doSave( const QString &stringFileName );
};

extern WPaletteColor *g_PaletteColors;

#endif

