#include "WColorPickerWidget.h"

#include "WPaletteColor.h"
#include "WPaletteColorWidget.h"

//
//
//

WColorPickerWidget1::WColorPickerWidget1( const QColor &color, QWidget *pParent )
    : QWidget( pParent )
{
    this->color = color;

    setMinimumWidth( 40 );
    setMinimumHeight( 40 );
}

void WColorPickerWidget1::setColor( const QColor &c )
{
    color =  c;

    // would be nice to find the pos of the color and adjust this->point

    update();
}

void WColorPickerWidget1::mousePressEvent( QMouseEvent *pEvent )
{
    if ( pEvent->button() != Qt::LeftButton )
    {
        QWidget::mousePressEvent( pEvent );
        return;
    }

    point = pEvent->pos();

    // adopt Hue and Sat (but nothing else) from color at point
    {
        QPixmap pixmap = grab();
        QImage image( pixmap.toImage() );
        QColor c( image.pixel( point ) );

        int nH = 0;
        int nS = 0;
        int nV = 0;
        int nA = 0;
        int nHNew = 0;
        int nSNew = 0;
        int nVNew = 0;
        int nANew = 0;

        color.getHsv( &nH, &nS, &nV, &nA );
        c.getHsv( &nHNew, &nSNew, &nVNew, &nANew );

        color.setHsv( nHNew, nSNew, nV, nA );
    }

    emit signalValueChanged( color );
    update();
}

/*!
 * \brief Paint a circle with colors expressed using Hue and Saturation and allow selection. 
 *  
 * The Hue changes based upon the angle. 
 *  
 * The Saturation changes based upon the radius (distance from center). 
 *  
 * Value and Alpha are maintained in a 'current' QColor but are not used or altered here. 
 *  
 * \author pharvey (12/4/22)
 */
void WColorPickerWidget1::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    QPen pen;
    pen.setWidth(1);

    for ( int nX = 0; nX <= width(); nX++ )
    {
        for ( int nY  = 0; nY <= height(); nY++ )
        {
            // coordinate transformation so that the origin is at the centre of the item
            // also y values should increase as you go up and decrease as you go down
            int nXCoord = nX - width() / 2;
            int nYCoord = height() / 2 - nY;

            Polar p = cartesianToPolar( nXCoord, nYCoord );

            // only paint pixels inside the circle
            if ( p.radius <= width() / 2 )
            {
                // Hue is determined by the angle (value must be 0-1).
                // 
                // For some reason 0 is supposed to be presented at NE. Ours is presented at N.
                // We ignore this as it makes no difference to the selection.
                // 
                // ie   NE=0=0              Yellow
                //      SE=300/360=0.83     Purple
                //      S=240/360=0.67      Blue
                //      N=60/360=0.17       Cyan
                //      SW=180/360=0.5      Green
                qreal nHue = p.angle / ( 2 * M_PI );

                // Sat is determined by how far we are from the center (value must be 0-1)
                // ie   0   Center
                //      1   At the circumference
                qreal nSat = p.radius / width() * 2;

                QColor color;
                color.setHsvF( nHue, nSat, 1.0 );
                pen.setColor( color );

                painter.setPen( pen );
                painter.drawPoint( QPoint( nX, nY ) );
            }
        }
    }

    // draw cursor (cross-hair)
    int nOffset = 6;
    pen.setColor( Qt::black );
    painter.setPen( pen );
    painter.drawLine( point.x() - nOffset, point.y(), point.x() - 1, point.y() );
    painter.drawLine( point.x() + 1, point.y(), point.x() + nOffset, point.y() );

    painter.drawLine( point.x(), point.y() - nOffset, point.x(), point.y() - 1 );
    painter.drawLine( point.x(), point.y() + 1, point.x(), point.y() + nOffset );
}

/*! 
 * \brief Convert Cartesian coordinates to Polar position. 
 *  
 * Cartesian is a simple x,y position (in this case - relative to the center of the circle). 
 * Polar is the angle and radius (distance). 
 *  
 * We need to convert from Cartesian to Polar because we want the angle to calc the Hue and we 
 * want the radius to calc the Sat. 
 *  
 * We can then set the pixel Hue/Sat at the x,y position. 
 *  
 * Conersion is done using; 
 *  
 * r = √ ( x2 + y2 ) 
 * θ = inverse-tangent ( y / x ) 
 *  
 * tan with a superscripted -1 has been replaced with inverse-tangent because we can not do superscripted here. 
 * The inverse-tangent calculates the angle from the ratio of x,y (thats not divide there).
 *  
 * \author pharvey (12/4/22)
 * 
 * \param x 
 * \param y 
 * 
 * \return WColorPickerWidget1::Polar 
 */
WColorPickerWidget1::Polar WColorPickerWidget1::cartesianToPolar( qreal x, qreal y )
{
    // θ = tan-1 ( y / x )
    qreal nAngle = qAtan2( y, x );
    if ( nAngle < 0 )
    {
        nAngle += (2* M_PI);
    }

    // r = √ ( x2 + y2 )
    qreal nRadius = qSqrt( (x*x) + (y*y) );
    Polar p;
    p.angle = nAngle;
    p.radius = nRadius;

    return p;
}

//
//
//

WColorPickerWidget2::WColorPickerWidget2( const QColor &color, QWidget *pParent )
    : QWidget( pParent )
{
    this->color = color;

    setMinimumWidth( 16 );
    setFixedHeight( 16 );
}

void WColorPickerWidget2::setColor( const QColor &c )
{
    color =  c;
    update();
}

void WColorPickerWidget2::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    painter.setBrush( QBrush( color ) );
    painter.drawRect( rect() );
}

//
//
//

WColorPickerWidget::WColorPickerWidget( const QColor &color, QWidget *pParent, bool bShowPaletteColor )
    : QWidget( pParent )
{
    int nH = 0;
    int nS = 0;
    int nV = 0;
    int nA = 0;

    color.getHsv( &nH, &nS, &nV, &nA );

    QHBoxLayout *pLayoutTop         = new QHBoxLayout( this );
    QVBoxLayout *pLayoutMain        = new QVBoxLayout();
    QGridLayout *pLayoutControls    = new QGridLayout();

    // picker
    pColorPickerWidget = new WColorPickerWidget1(color, this);
    pColorPickerWidget->setToolTip( tr("select Hue and Saturation") );
    pLayoutMain->addWidget( pColorPickerWidget );

    // controls
    QLabel *pLabelHue = new QLabel( tr("Hue:"), this );
    QLabel *pLabelSat = new QLabel( tr("Sat:"), this );
    QLabel *pLabelVal = new QLabel( tr("Val:"), this );
    QLabel *pLabelAlp = new QLabel( tr("Alp:"), this );

    pLayoutControls->addWidget( pLabelHue, 0, 0 );
    pLayoutControls->addWidget( pLabelSat, 1, 0 );
    pLayoutControls->addWidget( pLabelVal, 2, 0 );
    pLayoutControls->addWidget( pLabelAlp, 3, 0 );

    pSliderHue = new QSlider( Qt::Horizontal, this );
    pSliderSat = new QSlider( Qt::Horizontal, this );
    pSliderVal = new QSlider( Qt::Horizontal, this );
    pSliderAlp = new QSlider( Qt::Horizontal, this );

    pSliderHue->setRange( 0, 359 ); // Hue is 359
    pSliderSat->setRange( 0, 255 );
    pSliderVal->setRange( 0, 255 );
    pSliderAlp->setRange( 0, 255 );

    pSliderHue->setValue( nH );
    pSliderSat->setValue( nS );
    pSliderVal->setValue( nV );
    pSliderAlp->setValue( nA );

    pSliderHue->setToolTip( tr("set Hue") );
    pSliderSat->setToolTip( tr("set Saturation") );
    pSliderVal->setToolTip( tr("set Value") );
    pSliderAlp->setToolTip( tr("set Alpha (transparency)") );

    pLayoutControls->addWidget( pSliderHue, 0, 1 );
    pLayoutControls->addWidget( pSliderSat, 1, 1 );
    pLayoutControls->addWidget( pSliderVal, 2, 1 );
    pLayoutControls->addWidget( pSliderAlp, 3, 1 );

    pSpinHue    = new QSpinBox( this );
    pSpinSat    = new QSpinBox( this );
    pSpinVal    = new QSpinBox( this );
    pSpinAlp    = new QSpinBox( this );

    pSpinHue->setMinimum( 0 );
    pSpinSat->setMinimum( 0 );
    pSpinVal->setMinimum( 0 );
    pSpinAlp->setMinimum( 0 );

    pSpinHue->setMaximum( 359 ); // Hue is 359
    pSpinSat->setMaximum( 255 );
    pSpinVal->setMaximum( 255 );
    pSpinAlp->setMaximum( 255 );

    pSpinHue->setValue( nH );
    pSpinSat->setValue( nS );
    pSpinVal->setValue( nV );
    pSpinAlp->setValue( nA );

    pLayoutControls->addWidget( pSpinHue, 0, 2 );
    pLayoutControls->addWidget( pSpinSat, 1, 2 );
    pLayoutControls->addWidget( pSpinVal, 2, 2 );
    pLayoutControls->addWidget( pSpinAlp, 3, 2 );

    pLayoutMain->addLayout( pLayoutControls );

    // swatch
    pSwatch = new WColorPickerWidget2( color, this );
    pLayoutMain->addWidget( pSwatch );

    pLayoutTop->addLayout( pLayoutMain );

    // Palette Color (optional)
    // - WPaletteColorWidget should never show in response to select a color - others - probably yes
    if ( bShowPaletteColor ) 
    {
        QVBoxLayout *pLayout = new QVBoxLayout();
        pLayout->addWidget( new QLabel( tr("User Defined"), this ) );

        pPaletteColor = new WPaletteColorWidget( this, false );
        pLayout->addWidget( pPaletteColor, 10 );
        pLayoutTop->addLayout( pLayout );

        connect( g_PaletteColors, SIGNAL(signalModifiedCurrent()), SLOT(slotPaletteColor()) );
    }

    // connect stuff
    connect( pColorPickerWidget, SIGNAL(signalValueChanged(const QColor&)), SLOT(slotPicker(const QColor&)) );

    connect( pSliderHue, SIGNAL(valueChanged(int)), SLOT(slotHue(int)) );
    connect( pSliderSat, SIGNAL(valueChanged(int)), SLOT(slotSat(int)) );
    connect( pSliderVal, SIGNAL(valueChanged(int)), SLOT(slotVal(int)) );
    connect( pSliderAlp, SIGNAL(valueChanged(int)), SLOT(slotAlp(int)) );

    connect( pSpinHue, SIGNAL(valueChanged(int)), SLOT(slotHue(int)) );
    connect( pSpinSat, SIGNAL(valueChanged(int)), SLOT(slotSat(int)) );
    connect( pSpinVal, SIGNAL(valueChanged(int)), SLOT(slotVal(int)) );
    connect( pSpinAlp, SIGNAL(valueChanged(int)), SLOT(slotAlp(int)) );
}

/*!
 * \brief Adopt changes to Hue and Sat made by the color picker. 
 *  
 * The color picker does not select Val or Alp but they are maintained in its current color.
 * 
 * \author pharvey (12/4/22)
 * 
 * \param color 
 */
void WColorPickerWidget::slotPicker( const QColor &color )
{
    int nHue    = 0;
    int nSat    = 0;
    int nVal    = 0;
    int nAlp    = 0;

    color.getHsv( &nHue, &nSat, &nVal, &nAlp );

    pSliderHue->setValue( nHue );
    pSliderSat->setValue( nSat );
    pSliderVal->setValue( nVal );
    pSliderAlp->setValue( nAlp );

    pSpinHue->setValue( nHue );
    pSpinSat->setValue( nSat );
    pSpinVal->setValue( nVal );
    pSpinAlp->setValue( nAlp );

    pSwatch->setColor( color );
}

void WColorPickerWidget::slotPaletteColor()
{
    QColor color = g_PaletteColors->getCurrent(); 

    int nHue    = 0;
    int nSat    = 0;
    int nVal    = 0;
    int nAlp    = 0;

    color.getHsv( &nHue, &nSat, &nVal, &nAlp );

    pSliderHue->setValue( nHue );
    pSliderSat->setValue( nSat );
    pSliderVal->setValue( nVal );
    pSliderAlp->setValue( nAlp );

    pSpinHue->setValue( nHue );
    pSpinSat->setValue( nSat );
    pSpinVal->setValue( nVal );
    pSpinAlp->setValue( nAlp );

    pSwatch->setColor( color );
}

void WColorPickerWidget::slotHue( int n )
{
    int nH = 0;
    int nS = 0;
    int nV = 0;
    int nA = 0;

    QColor color = pColorPickerWidget->getColor();
    color.getHsv( &nH, &nS, &nV, &nA );
    color.setHsv( n, nS, nV, nA );

    pSliderHue->setValue( nH );
    pSpinHue->setValue( nH );
    pColorPickerWidget->setColor( color );
    pSwatch->setColor( color );
}

void WColorPickerWidget::slotSat( int n )
{
    int nH = 0;
    int nS = 0;
    int nV = 0;
    int nA = 0;

    QColor color = pColorPickerWidget->getColor();
    color.getHsv( &nH, &nS, &nV, &nA );
    color.setHsv( nH, n, nV, nA );

    pSliderSat->setValue( nS );
    pSpinSat->setValue( nS );
    pColorPickerWidget->setColor( color );
    pSwatch->setColor( color );
}

void WColorPickerWidget::slotVal( int n )
{
    int nH = 0;
    int nS = 0;
    int nV = 0;
    int nA = 0;

    QColor color = pColorPickerWidget->getColor();
    color.getHsv( &nH, &nS, &nV, &nA );
    color.setHsv( nH, nS, n, nA );

    pSliderVal->setValue( nV );
    pSpinVal->setValue( nV );
    pColorPickerWidget->setColor( color );
    pSwatch->setColor( color );
}

void WColorPickerWidget::slotAlp( int n )
{
    int nH = 0;
    int nS = 0;
    int nV = 0;
    int nA = 0;

    QColor color = pColorPickerWidget->getColor();
    color.getHsv( &nH, &nS, &nV, &nA );
    color.setHsv( nH, nS, nV, n );

    pSliderAlp->setValue( nA );
    pSpinAlp->setValue( nA );
    pColorPickerWidget->setColor( color );
    pSwatch->setColor( color );
}



