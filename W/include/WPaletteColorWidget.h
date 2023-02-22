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

