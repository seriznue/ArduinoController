INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

PUBLIC_HEADERS         += $$PWD/ArduinoController.h \
                          $$PWD/qtarduinocontrollerlib_global.h

HEADERS                += $$PUBLIC_HEADERS 

SOURCES                += $$PWD/ArduinoController.cpp \

linux*{
    !qesp_linux_udev:DEFINES += QESP_NO_UDEV
    qesp_linux_udev: LIBS += -ludev
}

macx:LIBS              += -framework IOKit -framework CoreFoundation
win32:LIBS             += -lsetupapi -ladvapi32 -luser32

# moc doesn't detect Q_OS_LINUX correctly, so add this to make it work
linux*:DEFINES += __linux__
