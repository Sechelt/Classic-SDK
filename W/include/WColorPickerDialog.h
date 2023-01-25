#ifndef H_WColorPickerDialog
#define H_WColorPickerDialog

#include "W.h"

class WColorPickerWidget;

class WColorPickerDialog : public QDialog
{
    Q_OBJECT
public:
    WColorPickerDialog( const QColor &color, QWidget *pParent = nullptr, bool bShowPaletteColor = false );
    ~WColorPickerDialog();

    QColor getColor();
    static QColor getColor( bool *pOk, const QColor &color, QWidget *pParent, bool bShowPaletteColor = false );

protected:
    bool                    bShowPaletteColor;
    WColorPickerWidget *    pColorPickerWidget;

    void doLoadState();
    void doSaveState();
};

#endif 

