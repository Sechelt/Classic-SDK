#include "LibInfo.h"
#include "WSizeDialog.h"
#include "W.h"

#include "WSizeWidget.h"

WSizeDialogInt::WSizeDialogInt( const QSize &size, QWidget *pParent )
    : QDialog( pParent )
{
    setWindowTitle( tr("Size") );

    QVBoxLayout *pLayout = new QVBoxLayout( this );
    pSizeWidget = new WSizeWidgetInt( size, this );
    pLayout->addWidget( pSizeWidget ); 

    QDialogButtonBox *pButtonBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );
    pLayout->addWidget( pButtonBox ); 

    connect( pButtonBox, &QDialogButtonBox::accepted, this, &QDialog::accept );
    connect( pButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject );
}

QSize WSizeDialogInt::getSize() 
{ 
    return pSizeWidget->getValue(); 
}

QSize WSizeDialogInt::getSize( bool *pOk, const QSize &size, QWidget *pParent )
{
    QSize sizeOriginal = size;

    *pOk = true;

    WSizeDialogInt dialog( size, pParent );
    if ( dialog.exec() == QDialog::Accepted )
        return dialog.getSize();

    *pOk = false;
    return sizeOriginal;
}


