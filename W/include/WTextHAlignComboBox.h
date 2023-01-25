#ifndef H_WTextHAlignComboBox
#define H_WTextHAlignComboBox

#include "W.h"

#include "W.h"

class WTextHAlignComboBox : public QComboBox
{
    Q_OBJECT
public:
    WTextHAlignComboBox( Qt::AlignmentFlag n, QWidget *pParent, bool bText = false );

    void setValue( Qt::AlignmentFlag n );
    Qt::AlignmentFlag getValue();

signals:
    void signalChanged( Qt::AlignmentFlag n );

public slots:
    void slotValue( Qt::AlignmentFlag n );

private slots:
    void slotChanged( int nIndex );
};

#endif 

