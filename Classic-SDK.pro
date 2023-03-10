# #########################################################
# \brief        This is the main qmake project file.
#
#               The qmake command-line tool will use this project
#               file to generate platform specific make files.
#
#               Before running qmake on this you should check the
#               the *.pri files to ensure that the build settings
#               are as desired.
#
# \sa           Classic-SDK.pri
# #########################################################

include(Classic-SDK.pri)

TEMPLATE    = subdirs
SUBDIRS		= \
                    W
		
