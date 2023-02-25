/*
 * Copyright 2022-2023, Peter Harvey <pharvey@codebydesign.com>
 *
 * This file is part of Euphemia-SDK.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

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


