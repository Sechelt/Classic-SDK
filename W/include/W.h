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

#ifndef W_H
#define W_H

#include <QtGui>
#include <QtWidgets>

namespace W 
{

    enum WLineEndStyles
    {
        // Common LineEnd styles.
        WLineEndNone,
        WLineEndArrow,
        WLineEndBall,
        // This indicates that some other factors will be used to determine
        // the style of the LineEnd. For example; an ERD may
        WLineEndComposed        
    };

    enum WImagePlacements
    {
        WImagePlacementNormal,
        WImagePlacementTiled,
        WImagePlacementScaled
    };

/*! 
 * \brief Set combox item current based upon the user data. 
 *  
 * The user data must be an int. This works will for Qt enum values 
 * such as Qt::PenStyle etc. 
 *  
 * \note Could use QComboBox::findData() 
 *  
 */
#define WSetComboBox( pComboBox, nUserData )                        \
    for ( int n = 0; n < pComboBox->count(); n++ )                  \
    {                                                               \
        if ( pComboBox->itemData( n ).toInt() == nUserData )        \
        {                                                           \
            pComboBox->setCurrentIndex( n );                        \
            break;                                                  \
        }                                                           \
    }                                                           

}; // namespace


#endif



