#include "LibInfo.h"
#include "WDirSelectWidget.h"
#include "W.h"

WDirSelectWidget::WDirSelectWidget( const QString &stringDirectory, QWidget *pWidgetParent )
    : QWidget( pWidgetParent )
{
    QHBoxLayout *pLayout = new QHBoxLayout( this );
    pDirectory = new QLineEdit( stringDirectory, this );
    pLayout->addWidget( pDirectory );

    pSelect = new QPushButton( QIcon( ":DATAW/Open" ),  QString(), this );
    pLayout->addWidget( pSelect );
    connect( pSelect, SIGNAL(clicked()), SLOT(slotSelect()) );
}

void WDirSelectWidget::slotSelect()
{
    QString stringDirectory = QFileDialog::getExistingDirectory( this, tr("Select directory...") );                                                                                                                                      
    if ( stringDirectory.isEmpty() ) return;

    setDirectory( stringDirectory );
}


