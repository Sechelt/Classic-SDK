#ifndef H_WBrushStyleComboBox
#define H_WBrushStyleComboBox

#include "W.h"

class WBrushStyleComboBox : public QComboBox
{
    Q_OBJECT
public:
    WBrushStyleComboBox( QWidget *pParent, Qt::BrushStyle n );

    void setValue( Qt::BrushStyle n );
    Qt::BrushStyle getValue();

protected:
    QPixmap getIcon( Qt::BrushStyle n, int width = 32, int height = 32 );

signals:
    void signalChanged( Qt::BrushStyle n );

private slots:
    void slotChanged( int nIndex );
};

#endif 

