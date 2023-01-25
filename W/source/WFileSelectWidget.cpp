#include "LibInfo.h"
#include "WFileSelectWidget.h"
#include "W.h"

WFileSelectWidget::WFileSelectWidget( const QString &stringFileName, const QString &stringFileSpec, QWidget *pWidgetParent )
    : QWidget( pWidgetParent )
{
    this->stringFileSpec = stringFileSpec;

    QHBoxLayout *pLayout = new QHBoxLayout( this );
    pFileName = new QLineEdit( stringFileName, this );
    pLayout->addWidget( pFileName );

    pNew = new QPushButton( QIcon( ":DATAW/New" ),  QString(), this );
    pLayout->addWidget( pNew );
    connect( pNew, SIGNAL(clicked()), SLOT(slotNew()) );

    pOpen = new QPushButton( QIcon( ":DATAW/Open" ),  QString(), this );
    pLayout->addWidget( pOpen );
    connect( pOpen, SIGNAL(clicked()), SLOT(slotOpen()) );
}

void WFileSelectWidget::slotNew()
{
    QString stringFileName = QFileDialog::getExistingDirectory( this, tr("Select directory...") );                                                                                                                                      
    if ( stringFileName.isEmpty() ) return;

    pFileName->setText( stringFileName );
}

void WFileSelectWidget::slotOpen()
{
    QString stringFileName = QFileDialog::getOpenFileName( this, tr("Select file..."), QString(), stringFileSpec );                                                                                                                                      
    if ( stringFileName.isEmpty() ) return;

    pFileName->setText( stringFileName );
}


