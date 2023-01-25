# #########################################################
# COMMON
# #########################################################
TEMPLATE    = lib
TARGET      = W
DESTDIR		= ../lib

include(../Classic-SDK.pri)

CONFIG		+= staticlib

INCLUDEPATH	+= ./include

# #########################################################
# FILES
# #########################################################
RESOURCES   = W.qrc

HEADERS	+= \
        include/W.h \
        include/WBitmapButton.h \
        include/WBitmapWidget.h \
        include/WBrushButton.h \
        include/WBrushStyleComboBox.h \
        include/WCanvasSizeWidget.h \
        include/WColorButton.h \
        include/WColorPickerDialog.h \
        include/WColorPickerWidget.h \
        include/WColorButton.h \
        include/WColorWidget.h \
        include/WCoordWidget.h \
        include/WDirectiveWidget.h \
        include/WDirSelectWidget.h \
        include/WFileSelectWidget.h \
        include/WGeometryWidget.h \
        include/WIconLayout.h \
        include/WIconWidget.h \
        include/WImageButton.h \
        include/WLabelButton.h \
        include/WLayoutWidget.h \
        include/WLineEndComboBox.h \
        include/WLineStyleComboBox.h \
        include/WMarginsWidget.h \
        include/WObjectHAlignComboBox.h \
        include/WObjectVAlignComboBox.h \
        include/WPaletteColor.h \
        include/WPaletteColorWidget.h \
        include/WPersist.h \
        include/WPosWidget.h \
        include/WRulerWidget.h \
        include/WScratchTool.h \
        include/WShapeSizeComboBox.h \
        include/WSizeConstraintsWidget.h \
        include/WSizeDialog.h \
        include/WSizeHintWidget.h \
        include/WSizeWidget.h \
        include/WStackedWidget.h \
        include/WStretchWidget.h \
        include/WSvgButton.h \
        include/WTabDialog.h \
        include/WTextButton.h \
        include/WTextVAlignComboBox.h \
        include/WTextHAlignComboBox.h \
        include/WValueListWidget.h \
        include/WZoomWidget.h

SOURCES	+= \
        source/WBitmapButton.cpp \
        source/WBitmapWidget.cpp \
        source/WBrushButton.cpp \
        source/WBrushStyleComboBox.cpp \
        source/WCanvasSizeWidget.cpp \
        source/WColorButton.cpp \
        source/WColorPickerDialog.cpp \
        source/WColorPickerWidget.cpp \
        source/WColorWidget.cpp \
        source/WCoordWidget.cpp \
        source/WDirectiveWidget.cpp \
        source/WDirSelectWidget.cpp \
        source/WFileSelectWidget.cpp \
        source/WGeometryWidget.cpp \
        source/WIconLayout.cpp \
        source/WIconWidget.cpp \
        source/WImageButton.cpp \
        source/WLabelButton.cpp \
        source/WLayoutWidget.cpp \
        source/WLineEndComboBox.cpp \
        source/WLineStyleComboBox.cpp \
        source/WMarginsWidget.cpp \
        source/WObjectHAlignComboBox.cpp \
        source/WObjectVAlignComboBox.cpp \
        source/WPaletteColor.cpp \
        source/WPaletteColorWidget.cpp \
        source/WPersist.cpp \
        source/WPosWidget.cpp \
        source/WRulerWidget.cpp \
        source/WScratchTool.cpp \
        source/WShapeSizeComboBox.cpp \
        source/WSizeConstraintsWidget.cpp \
        source/WSizeDialog.cpp \
        source/WSizeHintWidget.cpp \
        source/WSizeWidget.cpp \
        source/WStackedWidget.cpp \
        source/WStretchWidget.cpp \
        source/WSvgButton.cpp \
        source/WTabDialog.cpp \
        source/WTextButton.cpp \
        source/WTextVAlignComboBox.cpp \
        source/WTextHAlignComboBox.cpp \
        source/WValueListWidget.cpp \
        source/WZoomWidget.cpp \
        source/LibInfo.h

