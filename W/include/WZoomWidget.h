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
    void setInc( int n );
    void setZoom( int n );
    void setFit( FitTypes n );

    void setVisibleFit( bool b = true );

    int getZoom();
    FitTypes getFit();


signals:
    void signalZoom( int nFit, int nZoom );

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
