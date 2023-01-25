#ifndef H_WSizeDialog
#define H_WSizeDialog

#include "W.h"

class WSizeWidgetI;

class WSizeDialogI : public QDialog
{
    Q_OBJECT
public:
    WSizeDialogI( const QSize &size, QWidget *pParent = nullptr );

    QSize getSize();
    static QSize getSize( bool *pOk, const QSize &size, QWidget *pParent );

protected:
    WSizeWidgetI *pSizeWidget;
};

#endif 

