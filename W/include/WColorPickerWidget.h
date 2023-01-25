#ifndef H_WColorPickerWidget
#define H_WColorPickerWidget

#include "W.h"
#include <qmath.h>

#include "W.h"

class WPaletteColorWidget;

class WColorPickerWidget1 : public QWidget
{
    Q_OBJECT
public:
    WColorPickerWidget1( const QColor &color, QWidget *pParent );

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
        qreal angle;
    };

    Polar cartesianToPolar(qreal x, qreal y);
};

class WColorPickerWidget2 : public QWidget
{
    Q_OBJECT
public:
    WColorPickerWidget2( const QColor &color, QWidget *pParent );

    void setColor( const QColor & ); 

    QColor getColor() { return color; }

protected:
    QColor color;

    void paintEvent( QPaintEvent *pEvent ) override;
};

class WColorPickerWidget : public QWidget
{
    Q_OBJECT
public:
    WColorPickerWidget( const QColor &color, QWidget *pParent, bool bShowPaletteColor = false );

    QColor getColor() { return pColorPickerWidget->getColor(); }

protected:
    WColorPickerWidget1 *pColorPickerWidget;
    WColorPickerWidget2 *pSwatch;
    WPaletteColorWidget *pPaletteColor = nullptr;

    QSlider *pSliderHue;
    QSlider *pSliderSat;
    QSlider *pSliderVal;
    QSlider *pSliderAlp;

    QSpinBox *pSpinHue;
    QSpinBox *pSpinSat;
    QSpinBox *pSpinVal;
    QSpinBox *pSpinAlp;

protected slots:
    void slotPicker( const QColor & );
    void slotPaletteColor();
     
    void slotHue( int );
    void slotSat( int );
    void slotVal( int );
    void slotAlp( int );
};

#endif 

