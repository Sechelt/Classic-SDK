#ifndef H_WTextButton
#define H_WTextButton

#include <QtWidgets>

class WTextSwatch : public QLabel
{
public:
    WTextSwatch( const QFont &font, QWidget *pParent );
};

class WTextButton : public QPushButton
{
    Q_OBJECT
public:
    WTextButton( const QFont &font, QWidget *pParent );

    void setValue( const QFont &font );
    QFont getValue() { return font; }

signals:
    void signalChanged( const QFont &font );

protected:
    QFont font;

protected slots:
    void slotClicked();
};

#endif 

