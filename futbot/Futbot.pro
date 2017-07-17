# Application info
TEMPLATE = app
DESTDIR = bin
TARGET = WRSim

# Qt config
CONFIG += console
CONFIG -= app_bundle #?
QT += core gui widgets

CONFIG += c++11

# Optimization flags
QMAKE_CXXFLAGS  -= -O
QMAKE_CXXFLAGS  -= -O1
QMAKE_CXXFLAGS  += -O2 -ansi

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Source files
INCLUDEPATH *= . src

SOURCES += \
    src/main.cpp \
#    src/headcontroller/recordgame.cpp \
#    src/headcontroller/simpleia.cpp \
    src/headcontroller/getbperror.cpp \
    src/headcontroller/one_player_alone.cpp \
    src/headcontroller/save_game.cpp \
# WRSim source files
#    src/wrsim/src/WRSim/controle.cpp \
#    src/wrsim/src/WRSim/controlewrsim.cpp \
    src/wrsim/src/WRSim/fisica.cpp \
    src/wrsim/src/WRSim/grafico/grafico.cpp \
    src/wrsim/src/WRSim/grafico/graficobola.cpp \
    src/wrsim/src/WRSim/grafico/graficocampovss.cpp \
    src/wrsim/src/WRSim/grafico/graficoentrada.cpp \
    src/wrsim/src/WRSim/grafico/graficoprobe.cpp \
    src/wrsim/src/WRSim/grafico/graficorobovss.cpp \
    src/wrsim/src/WRSim/objetos/bola.cpp \
    src/wrsim/src/WRSim/objetos/probe.cpp \
    src/wrsim/src/WRSim/objetos/robovss.cpp \
    src/wrsim/src/WRSim/mainwindow.cpp \
    src/wrsim/src/WRSim/interface.cpp \
# NeuralNetwork source files
    src/neuralnetwork/neuron.cpp \
    src/neuralnetwork/neuralnetwork.cpp \
    # src/neuralnetwork/main.cpp \
# utils source files
    src/utils/csv.cpp
  
# Header files
HEADERS  += \
#    src/headcontroller/recordgame.h \
#    src/headcontroller/simpleia.h \
    src/headcontroller/getbperror.h \
    src/headcontroller/one_player_alone.h \
    src/headcontroller/save_game.h \
# WRSim header files
#    src/wrsim/src/WRSim/controle.h \
#    src/wrsim/src/WRSim/controlewrsim.h \
    src/wrsim/src/WRSim/cte.h \
    src/wrsim/src/WRSim/fisica.h \
    src/wrsim/src/WRSim/grafico/grafico.h \
    src/wrsim/src/WRSim/grafico/graficobola.h \
    src/wrsim/src/WRSim/grafico/graficocampovss.h \
    src/wrsim/src/WRSim/grafico/graficoentrada.h \
    src/wrsim/src/WRSim/grafico/graficoprobe.h \
    src/wrsim/src/WRSim/grafico/graficorobovss.h \
    src/wrsim/src/WRSim/objetos/bola.h \
    src/wrsim/src/WRSim/objetos/probe.h \
    src/wrsim/src/WRSim/objetos/robovss.h \
    src/wrsim/src/WRSim/mainwindow.h \
    src/wrsim/src/WRSim/config.h \
    src/wrsim/src/WRSim/interface.h \
# NeuralNetwork header files
    src/neuralnetwork/neuron.h\
    src/neuralnetwork/neuralnetwork.h\
# utils header files
    src/utils/my_ptr.h
    src/utils/csv.h

# Forms
FORMS    += \
    src/wrsim/src/WRSim/mainwindow.ui

# Resources
RESOURCES += \
    src/wrsim/img/recursos.qrc

# Other files
DISTFILES += \
    src/wrsim/Notas.txt

DESTDIR = bin
TARGET = futbot
