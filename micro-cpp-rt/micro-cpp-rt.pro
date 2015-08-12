#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T15:53:02
#
#-------------------------------------------------

QT       -= core gui

TARGET = micro-cpp-rt
TEMPLATE = lib
CONFIG += staticlib

#QMAKE_CXX	= clang-3.5
QMAKE_CXXFLAGS	+= -DBUILDING_MICROCPP_RT_STATIC -std=c++11 -fno-exceptions -fno-rtti -fvisibility=hidden -fvisibility-inlines-hidden -pedantic -ffunction-sections -fdata-sections

SOURCES += microcpprt.cpp \
    system.cpp

HEADERS += microcpprt.hpp \
    system.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}
