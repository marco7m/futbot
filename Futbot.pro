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
    src/controlsystem/gameplay.cpp \
    src/controlsystem/referee.cpp \
    src/controlsystem/controlsystem.cpp \
    src/controlsystem/moverobots.cpp \
    src/controlsystem/feedforward.cpp \
    src/controlsystem/fitness.cpp \
    src/geneticalgorithm/crossover.cpp \
    src/geneticalgorithm/evolutioncontrol.cpp \
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
    src/controlsystem/gameplay.h \
    src/controlsystem/referee.h \
    src/controlsystem/controlsystem.h \
    src/controlsystem/moverobots.h \
    src/controlsystem/feedforward.h \
    src/controlsystem/fitness.h \
    src/geneticalgorithm/crossover.h \
    src/geneticalgorithm/evolutioncontrol.h \
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
    src/wrsim/src/WRSim/interface.h \
# NeuralNetwork header files
    src/neuralnetwork/neuron.h\
    src/neuralnetwork/neuralnetwork.h\
    src/neuralnetwork/random.h
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

