#ifndef H_WPaletteColorWidget
#define H_WPaletteColorWidget

#include "WColorWidget.h"

/*!
 * \brief Presents the global color palette for color selection/modification.
 *  
 * Display is a matrix of cells with each cell providing an example of a color. 
 *  
 * <single click><right mouse> will select brush. 
 * <double click><right mouse> will select brush and invoke a brush editor. 
 *  
 * Selecting a color will update current color in g_Palette-> 
 *  
 * The selected color (QColor) should be copied to PPen or PBrush or whatever is using it. It 
 * is not meant to be used, in-place, like (for example) WPaletteBrushMatrix::brush.
 *  
 * \sa g_Palette 
 *  
 * \author pharvey (11/30/22)
 */
class WPaletteColorMatrix : public QWidget
{
    Q_OBJECT
public:
    WPaletteColorMatrix( QWidget *pParent );

public slots:
    void slotRefresh(); // connect to g_Palette->colors.signalModified()

protected:
    QVector<QColor> vectorColors;

    void mousePressEvent( QMouseEvent *pEvent ) override;
    void mouseMoveEvent( QMouseEvent *pEvent ) override;
    void mouseReleaseEvent( QMouseEvent *pEvent ) override;
    void mouseDoubleClickEvent( QMouseEvent *pEvent ) override;
    void paintEvent( QPaintEvent *pEvent ) override;

private:
    int getIndex( const QPoint & );
};

/*!
 * \brief Combines a WPaletteColorMatrix with a tool bar to allow save/load. 
 * 
 * \author pharvey (12/3/22)
 */
class WPaletteColorWidget : public QWidget
{
    Q_OBJECT
public:
    WPaletteColorWidget( QWidget *pParent, bool bShowCurrent = true );

protected:
    WColorWidget *  pCurrent = nullptr;
    QToolButton *   pLoad;  
    QToolButton *   pSave;  
    QToolButton *   pSaveAs;
    QToolButton *   pReset; 
    QLabel *        pModified;

protected slots:
    void slotRefresh();

};

#endif 

