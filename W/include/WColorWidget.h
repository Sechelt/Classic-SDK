#ifndef H_WColorWidget
#define H_WColorWidget

#include "WColorButton.h"

class WColorWidget : public QWidget
{
    Q_OBJECT
public:
    WColorWidget( QWidget *pParent );

public slots:
    void slotRefresh();

protected:
    WColorButton *pColor;

protected slots:
    void slotChanged( const QColor &color );
};

#endif 

