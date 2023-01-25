#include "LibInfo.h"
#include "WLabelButton.h"

WLabelButton::WLabelButton( QWidget *pParent )
    : QLabel( pParent )
{
}

void WLabelButton::mouseReleaseEvent( QMouseEvent *pEvent )
{
    QLabel::mouseReleaseEvent( pEvent );
    emit signalClicked();
}

