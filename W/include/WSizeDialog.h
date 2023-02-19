#ifndef H_WSizeDialog
#define H_WSizeDialog

#include "W.h"

class WSizeWidgetInt;

class WSizeDialogInt : public QDialog
{
    Q_OBJECT
public:
    WSizeDialogInt( const QSize &size, QWidget *pParent = nullptr );

    QSize getSize();
    static QSize getSize( bool *pOk, const QSize &size, QWidget *pParent );

protected:
    WSizeWidgetInt *pSizeWidget;
};

#endif 

