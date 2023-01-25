#ifndef WTABDIALOG_H
#define WTABDIALOG_H

#include "W.h"

class WTabDialog : public QDialog
{
    Q_OBJECT
public:
    WTabDialog( QWidget *pwidgetParent, const QString &stringTitle, const QString &stringName = QString(), QDialogButtonBox::StandardButtons buttons = QDialogButtonBox::Ok, bool bModal=true, Qt::WindowFlags f = Qt::WindowFlags() );
    ~WTabDialog();

    QTabWidget *getTabWidget() { return pTabWidget; }

protected:
    QTabWidget *        pTabWidget;
    QDialogButtonBox *  pButtonBox;

    // virtual void closeEvent( QCloseEvent *pEvent );
    virtual void doSaveState();
    virtual void doLoadState();
};

#endif

