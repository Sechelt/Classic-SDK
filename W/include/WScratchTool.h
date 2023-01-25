#ifndef H_WScratchTool
#define H_WScratchTool

#include "W.h"

#include "W.h"

class WScratchTool : public QWidget
{
    Q_OBJECT
public:
    WScratchTool( QWidget *pParent );

protected:
    QVector<QImage> vectorImages;

    QStackedWidget *    pStackedWidget;
    QSlider *           pSlider;

protected slots:
    void slotRemove();
    void slotAdd();
};

#endif 

