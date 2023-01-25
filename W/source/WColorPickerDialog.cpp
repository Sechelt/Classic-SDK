#include "LibInfo.h"
#include "WColorPickerDialog.h"
#include "W.h"

#include "WColorPickerWidget.h"

WColorPickerDialog::WColorPickerDialog( const QColor &color, QWidget *pParent, bool bShowPaletteColor )
    : QDialog( pParent )
{
    setWindowTitle( tr("Color Picker") );

    this->bShowPaletteColor = bShowPaletteColor;

    QVBoxLayout *pLayout = new QVBoxLayout( this );
    pColorPickerWidget = new WColorPickerWidget( color, this, bShowPaletteColor );
    pLayout->addWidget( pColorPickerWidget );

    // buttons
    QDialogButtonBox *pButtonBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this );
    pLayout->addWidget( pButtonBox ); 

    connect( pButtonBox, &QDialogButtonBox::accepted, this, &QDialog::accept );
    connect( pButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject );
    doLoadState();
}

WColorPickerDialog::~WColorPickerDialog()
{
    doSaveState();
}

QColor WColorPickerDialog::getColor()
{
    return pColorPickerWidget->getColor();
}

QColor WColorPickerDialog::getColor( bool *pOk, const QColor &color, QWidget *pParent, bool bShowPaletteColor )
{
    QColor colorOriginal = color;

    *pOk = true;

    WColorPickerDialog dialog( color, pParent, bShowPaletteColor );
    if ( dialog.exec() == QDialog::Accepted )
        return dialog.getColor();

    *pOk = false;
    return colorOriginal;
}

void WColorPickerDialog::doSaveState()
{
    if ( bShowPaletteColor ) 
    {
        QString s = metaObject()->className();
        if ( !objectName().isEmpty() ) s = s + "/" + objectName();

        QSettings settings;
        settings.setValue( s + "/width1", width() );
        settings.setValue( s + "/height1", height() );
    }
    else
    {
        QString s = metaObject()->className();
        if ( !objectName().isEmpty() ) s = s + "/" + objectName();

        QSettings settings;
        settings.setValue( s + "/width2", width() );
        settings.setValue( s + "/height2", height() );
    }
}

void WColorPickerDialog::doLoadState()
{
    if ( bShowPaletteColor ) 
    {
        QString s = metaObject()->className();
        if ( !objectName().isEmpty() ) s = s + "/" + objectName();

        QSettings settings;
        int nWidth = settings.value( s + "/width1", width() ).toInt();
        int nHeight= settings.value( s + "/height1", height() ).toInt();
        resize( nWidth, nHeight );
    }
    else
    {
        QString s = metaObject()->className();
        if ( !objectName().isEmpty() ) s = s + "/" + objectName();

        QSettings settings;
        int nWidth = settings.value( s + "/width2", width() ).toInt();
        int nHeight= settings.value( s + "/height2", height() ).toInt();
        resize( nWidth, nHeight );
    }
}


