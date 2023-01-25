#ifndef H_WBrushButton
#define H_WBrushButton

#include "W.h"

class WBrushSwatch : public QWidget
{
    Q_OBJECT
public:
    WBrushSwatch( const QBrush &brush, QWidget *pParent );

    void setBrush( const QBrush & );

protected:
    void paintEvent( QPaintEvent *pEvent );
    QSize sizeHint() const;

private:
    QBrush  brush;
};

/*!
 * \class WBrushButton 
 * \brief A button that can be used to configure a brush. 
 *  
 * Clicking this will invoke a \sa WBrushDialog. 
 * The button will display a sample of the current brush under an icon indicating a brush. 
 * 
 * \author pharvey (4/19/22)
 */
class WBrushButton : public QToolButton
{
    Q_OBJECT
public:
    WBrushButton( const QBrush &brush, QWidget *pParent );

    void setBrush( const QBrush &brush );

signals:
    void signalChanged( QBrush brush );

protected:
    QBrush  brush;

    WBrushSwatch *pSwatch;
    QPushButton *pButton;

protected slots:
    void slotClicked();
};

#endif 

