#include "LibInfo.h"
#include "WTextButton.h"

//
// WTextSwatch
//
WTextSwatch::WTextSwatch( const QFont &font, QWidget *pParent )
    : QLabel( pParent )
{
    setFont( font );
    setText( tr("Quick brown fox.") );
}

//
// WTextButton
//
WTextButton::WTextButton( const QFont &font, QWidget *pParent )
    : QPushButton( pParent )
{
    this->font = font;
    setText( font.family() );
    QFont f;
    f.setFamily( font.family() );
    f.setBold( font.bold() );
    f.setItalic( font.italic() );
    f.setUnderline( font.underline() );
    setFont( f );
    connect( this, SIGNAL(clicked()), this, SLOT(slotClicked()) );
}

void WTextButton::setValue( const QFont &font )
{
    this->font = font;
    setText( font.family() );
    // display a subset as we do not want the UI controls to look whacky
    QFont f;
    f.setFamily( font.family() );
    f.setBold( font.bold() );
    f.setItalic( font.italic() );
    f.setUnderline( font.underline() );
    setFont( f );
}

void WTextButton::slotClicked()
{
    bool bOk = false;
    QFont fontNew = QFontDialog::getFont( &bOk, font, this );
    if ( bOk ) 
    {
        font = fontNew;
/*
        QFont f;                           
        f.setFamily( font.family() );      
        f.setBold( font.bold() );          
        f.setItalic( font.italic() );      
        f.setUnderline( font.underline() );
*/
//        setText( font.family() );
        setFont( font );

        emit signalChanged( font );
    } 
}


