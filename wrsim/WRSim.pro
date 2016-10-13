#
# Warthog Robotics
# University of Sao Paulo (USP) at Sao Carlos
# http://www.warthog.sc.usp.br/
#
# This file is part of WRSim project.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# Application info
TEMPLATE = app
DESTDIR = bin
TARGET = WRSim
VERSION = 0.3
#CONFIG -= c++11

# Qt config
CONFIG += console
CONFIG -= app_bundle
QT += core gui widgets

# Optimization flags
QMAKE_CXXFLAGS  -= -O
QMAKE_CXXFLAGS  -= -O1
QMAKE_CXXFLAGS  += -O2 -ansi

# GEARSystem info
LIBS += -lomniORB4 \
    -lomnithread \
    -lGEARSystem \
    -lprotobuf \
    -lGLU

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Source files
INCLUDEPATH *= . src

SOURCES += \
    src/main.cpp \
    src/WRSim/controle.cpp \
    src/WRSim/fisica.cpp \
    src/WRSim/grafico/grafico.cpp \
    src/WRSim/grafico/graficobola.cpp \
    src/WRSim/grafico/graficocampovss.cpp \
    src/WRSim/grafico/graficoentrada.cpp \
    src/WRSim/grafico/graficoprobe.cpp \
    src/WRSim/grafico/graficorobovss.cpp \
    src/WRSim/objetos/bola.cpp \
    src/WRSim/objetos/probe.cpp \
    src/WRSim/objetos/robovss.cpp \
    src/WRSim/mainwindow.cpp \
    src/WRSim/interface.cpp

# Header files
HEADERS  += \
    src/WRSim/controle.h \
    src/WRSim/cte.h \
    src/WRSim/fisica.h \
    src/WRSim/grafico/grafico.h \
    src/WRSim/grafico/graficobola.h \
    src/WRSim/grafico/graficocampovss.h \
    src/WRSim/grafico/graficoentrada.h \
    src/WRSim/grafico/graficoprobe.h \
    src/WRSim/grafico/graficorobovss.h \
    src/WRSim/objetos/bola.h \
    src/WRSim/objetos/probe.h \
    src/WRSim/objetos/robovss.h \
    src/WRSim/mainwindow.h \
    src/WRSim/config.h \
    src/WRSim/interface.h

# Forms
FORMS    += \
    src/WRSim/mainwindow.ui

# Resources
RESOURCES += \
    img/recursos.qrc

# Other files
DISTFILES += \
    Notas.txt
