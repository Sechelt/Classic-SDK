#ifndef H_WFileSelectWidget
#define H_WFileSelectWidget

#include "W.h"

class WFileSelectWidget : public QWidget
{
    Q_OBJECT
public:
    WFileSelectWidget( const QString &stringFileName, const QString &stringFileSpec, QWidget *pWidgetParent );

    void setFileName( const QString &s ) { pFileName->setText( s ); }

    QString getFileName() { return pFileName->text(); }

protected:
    QString         stringFileSpec;
    QLineEdit *     pFileName;
    QPushButton *   pNew;
    QPushButton *   pOpen;

protected slots:
    void slotNew();
    void slotOpen();
};

#endif 

