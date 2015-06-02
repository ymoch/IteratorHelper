TEMPLATE = app
QT += core
QT -= gui

DESTDIR = $$PWD/bin

CONFIG += console c++11
CONFIG -= app_bundle

CONFIG(debug, debug|release) {
  TARGET = IteratorHelperTestd
} else {
  TARGET = IteratorHelperTest
}

INCLUDEPATH += $$PWD/include

SOURCES += test/main.cpp \
    test/array_list_test.cpp

HEADERS += \
    include/iterator_helper/array/array_iterator.hpp \
    include/iterator_helper/array/array_list.hpp \
    include/iterator_helper/array/const_array_iterator.hpp \
    include/iterator_helper/array/const_array_list.hpp \
    test/tests.h \
    test/tester.hpp

