#ifndef H_WSizeWidget
#define H_WSizeWidget

#include "W.h"

/*!
 * \brief Manage position.
 * 
 * \author pharvey (7/25/20)
 */
class WSizeWidget : public QWidget
{
    Q_OBJECT
public:
    WSizeWidget( const QSizeF &size, QWidget *pParent, bool bToolBar = false );

    void setValue( const QSizeF &size );

    QSizeF getValue();

signals:
    void signalChanged( const QSizeF &size );

public slots:
    void slotValue( const QSizeF &size );

protected:
    QDoubleSpinBox *pSpinBoxWidth;
    QDoubleSpinBox *pSpinBoxHeight;

protected slots:
    void slotChanged();
};

class WSizeWidgetI : public QWidget
{
    Q_OBJECT
public:
    WSizeWidgetI( const QSize &size, QWidget *pParent, bool bToolBar = false );

    void setValue( const QSize &size );

    QSize getValue();

signals:
    void signalChanged( const QSize &size );

public slots:
    void slotValue( const QSize &size );

protected:
    QSpinBox *pSpinBoxWidth;
    QSpinBox *pSpinBoxHeight;

protected slots:
    void slotChanged();
};

#endif 

