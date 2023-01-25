#ifndef H_WLabelButton
#define H_WLabelButton

#include "W.h"

class WLabelButton : public QLabel
{
    Q_OBJECT
public:
    explicit WLabelButton( QWidget *pParent );

signals:
    void signalClicked();

protected:
    void mouseReleaseEvent( QMouseEvent *pEvent );
};

#endif 

