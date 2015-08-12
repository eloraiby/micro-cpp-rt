#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T20:54:52
#
#-------------------------------------------------

QT       -= core gui


TARGET = new-delete
CONFIG   += console
CONFIG   -= app_bundle

QMAKE_CXXFLAGS	+= -DBUILDING_MICROCPP_RT_STATIC -std=c++11 -fno-exceptions -fno-rtti -fvisibility=hidden -fvisibility-inlines-hidden -pedantic -ffunction-sections -fdata-sections
QMAKE_LINK	= gcc

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../micro-cpp-rt/release/ -lmicro-cpp-rt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../micro-cpp-rt/debug/ -lmicro-cpp-rt
else:unix: LIBS += -L$$OUT_PWD/../../micro-cpp-rt/ -lmicro-cpp-rt

INCLUDEPATH += $$PWD/../../micro-cpp-rt
DEPENDPATH += $$PWD/../../micro-cpp-rt

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../micro-cpp-rt/release/libmicro-cpp-rt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../micro-cpp-rt/debug/libmicro-cpp-rt.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../micro-cpp-rt/release/micro-cpp-rt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../micro-cpp-rt/debug/micro-cpp-rt.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../micro-cpp-rt/libmicro-cpp-rt.a
