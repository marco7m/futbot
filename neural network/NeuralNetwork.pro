HEADERS += neuron.h\
            neuralnetwork.h\
            my_ptr.h

SOURCES += neuron.cpp\
            neuralnetwork.cpp\
            main.cpp

DESTDIR = bin
TARGET = neuralnetwork

CONFIG += c++11

QMAKE_CXXFLAGS  -= -O
QMAKE_CXXFLAGS  -= -O1
QMAKE_CXXFLAGS  += -O2 -ansi

OBJECTS_DIR = tmp/obj
 
