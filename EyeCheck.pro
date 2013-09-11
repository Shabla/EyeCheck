TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += \
           MainWindow.h \
           MenuAbout.h \
           MenuSequence.h \
           MenuSettings.h \
           PortSettings.h \
           Regex.h \
           ThreadSequence.h \
           Port.h

FORMS += \
         MainWindow.ui \
         MenuAbout.ui \
         MenuSequence.ui \
         MenuSettings.ui

SOURCES += \
           main.cpp \
           MainWindow.cpp \
           MenuAbout.cpp \
           MenuSequence.cpp \
           MenuSettings.cpp \
           PortSettings.cpp \
           ThreadSequence.cpp \
           Port.cpp

RESOURCES   += ressources.qrc
RC_FILE     += icon.rc
OTHER_FILES += icon.rc

debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}

INCLUDEPATH += C:/dev/projects/EyeCheck/libs/qserialdevice-2.0/include

# DYNAMIC DEBUG BUILD
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug

    DESTDIR     = debug
    OBJECTS_DIR = debug/obj
    MOC_DIR     = debug/moc
    TARGET      = EyeCheckDebug
    LIBS       += -LC:/dev/projects/EyeCheck/libs/qserialdevice-2.0/src/debug -lSerialPort
}

# STATIC RELEASE BUILD
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release

    DESTDIR     = release
    OBJECTS_DIR = release/obj
    MOC_DIR     = release/moc
    TARGET      = EyeCheck
    INCLUDEPATH += C:/dev/projects/EyeCheck/libs/qserialdevice-2.0/src
    HEADERS     += C:/dev/projects/EyeCheck/libs/qserialdevice-2.0/include/serialport.h \
                   C:/dev/projects/EyeCheck/libs/qserialdevice-2.0/include/serialportinfo.h
    include("C:/dev/projects/EyeCheck/libs/qserialdevice-2.0/src/src.pri")
}


