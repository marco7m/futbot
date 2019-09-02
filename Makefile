#############################################################################
# Makefile for building: bin/futbot
# Generated by qmake (3.0) (Qt 5.7.1)
# Project:  Futbot.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -o Makefile Futbot.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -ansi -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -Isrc -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -Itmp/moc -Itmp/moc -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = futbot1.0.0
DISTDIR = /home/marco/slapy/programação/cpp/futbot/tmp/obj/futbot1.0.0
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -L/usr/X11R6/lib64 -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = tmp/obj/

####### Files

SOURCES       = src/main.cpp \
		src/controlsystem/gameplay.cpp \
		src/controlsystem/referee.cpp \
		src/controlsystem/controlsystem.cpp \
		src/controlsystem/moverobots.cpp \
		src/controlsystem/feedforward.cpp \
		src/controlsystem/fitness.cpp \
		src/geneticalgorithm/crossover.cpp \
		src/geneticalgorithm/evolutioncontrol.cpp \
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
		src/neuralnetwork/neuron.cpp \
		src/neuralnetwork/neuralnetwork.cpp \
		src/utils/csv.cpp tmp/rc/qrc_recursos.cpp \
		tmp/moc/moc_gameplay.cpp \
		tmp/moc/moc_mainwindow.cpp
OBJECTS       = tmp/obj/main.o \
		tmp/obj/gameplay.o \
		tmp/obj/referee.o \
		tmp/obj/controlsystem.o \
		tmp/obj/moverobots.o \
		tmp/obj/feedforward.o \
		tmp/obj/fitness.o \
		tmp/obj/crossover.o \
		tmp/obj/evolutioncontrol.o \
		tmp/obj/fisica.o \
		tmp/obj/grafico.o \
		tmp/obj/graficobola.o \
		tmp/obj/graficocampovss.o \
		tmp/obj/graficoentrada.o \
		tmp/obj/graficoprobe.o \
		tmp/obj/graficorobovss.o \
		tmp/obj/bola.o \
		tmp/obj/probe.o \
		tmp/obj/robovss.o \
		tmp/obj/mainwindow.o \
		tmp/obj/interface.o \
		tmp/obj/neuron.o \
		tmp/obj/neuralnetwork.o \
		tmp/obj/csv.o \
		tmp/obj/qrc_recursos.o \
		tmp/obj/moc_gameplay.o \
		tmp/obj/moc_mainwindow.o
DIST          = src/wrsim/Notas.txt \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		Futbot.pro src/controlsystem/gameplay.h \
		src/controlsystem/referee.h \
		src/controlsystem/controlsystem.h \
		src/controlsystem/moverobots.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h \
		src/geneticalgorithm/crossover.h \
		src/geneticalgorithm/evolutioncontrol.h \
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
		src/neuralnetwork/neuron.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/random.h src/main.cpp \
		src/controlsystem/gameplay.cpp \
		src/controlsystem/referee.cpp \
		src/controlsystem/controlsystem.cpp \
		src/controlsystem/moverobots.cpp \
		src/controlsystem/feedforward.cpp \
		src/controlsystem/fitness.cpp \
		src/geneticalgorithm/crossover.cpp \
		src/geneticalgorithm/evolutioncontrol.cpp \
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
		src/neuralnetwork/neuron.cpp \
		src/neuralnetwork/neuralnetwork.cpp \
		src/utils/csv.cpp
QMAKE_TARGET  = futbot
DESTDIR       = bin/
TARGET        = bin/futbot


first: all
####### Build rules

$(TARGET): tmp/moc/ui_mainwindow.h $(OBJECTS)  
	@test -d bin/ || mkdir -p bin/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Futbot.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		Futbot.pro \
		src/wrsim/img/recursos.qrc \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile Futbot.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
Futbot.pro:
src/wrsim/img/recursos.qrc:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile Futbot.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents src/wrsim/img/recursos.qrc $(DISTDIR)/
	$(COPY_FILE) --parents src/controlsystem/gameplay.h src/controlsystem/referee.h src/controlsystem/controlsystem.h src/controlsystem/moverobots.h src/controlsystem/feedforward.h src/controlsystem/fitness.h src/geneticalgorithm/crossover.h src/geneticalgorithm/evolutioncontrol.h src/wrsim/src/WRSim/cte.h src/wrsim/src/WRSim/fisica.h src/wrsim/src/WRSim/grafico/grafico.h src/wrsim/src/WRSim/grafico/graficobola.h src/wrsim/src/WRSim/grafico/graficocampovss.h src/wrsim/src/WRSim/grafico/graficoentrada.h src/wrsim/src/WRSim/grafico/graficoprobe.h src/wrsim/src/WRSim/grafico/graficorobovss.h src/wrsim/src/WRSim/objetos/bola.h src/wrsim/src/WRSim/objetos/probe.h src/wrsim/src/WRSim/objetos/robovss.h src/wrsim/src/WRSim/mainwindow.h src/wrsim/src/WRSim/interface.h src/neuralnetwork/neuron.h src/neuralnetwork/neuralnetwork.h src/neuralnetwork/random.h $(DISTDIR)/
	$(COPY_FILE) --parents src/main.cpp src/controlsystem/gameplay.cpp src/controlsystem/referee.cpp src/controlsystem/controlsystem.cpp src/controlsystem/moverobots.cpp src/controlsystem/feedforward.cpp src/controlsystem/fitness.cpp src/geneticalgorithm/crossover.cpp src/geneticalgorithm/evolutioncontrol.cpp src/wrsim/src/WRSim/fisica.cpp src/wrsim/src/WRSim/grafico/grafico.cpp src/wrsim/src/WRSim/grafico/graficobola.cpp src/wrsim/src/WRSim/grafico/graficocampovss.cpp src/wrsim/src/WRSim/grafico/graficoentrada.cpp src/wrsim/src/WRSim/grafico/graficoprobe.cpp src/wrsim/src/WRSim/grafico/graficorobovss.cpp src/wrsim/src/WRSim/objetos/bola.cpp src/wrsim/src/WRSim/objetos/probe.cpp src/wrsim/src/WRSim/objetos/robovss.cpp src/wrsim/src/WRSim/mainwindow.cpp src/wrsim/src/WRSim/interface.cpp src/neuralnetwork/neuron.cpp src/neuralnetwork/neuralnetwork.cpp src/utils/csv.cpp $(DISTDIR)/
	$(COPY_FILE) --parents src/wrsim/src/WRSim/mainwindow.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: tmp/rc/qrc_recursos.cpp
compiler_rcc_clean:
	-$(DEL_FILE) tmp/rc/qrc_recursos.cpp
tmp/rc/qrc_recursos.cpp: src/wrsim/img/recursos.qrc \
		/usr/lib/x86_64-linux-gnu/qt5/bin/rcc \
		src/wrsim/img/robovss11.png \
		src/wrsim/img/robovss02.png \
		src/wrsim/img/probei2.png \
		src/wrsim/img/robovss10.png \
		src/wrsim/img/probe.png \
		src/wrsim/img/robovss01.png \
		src/wrsim/img/campoVss.png \
		src/wrsim/img/bola.png \
		src/wrsim/img/robovss00.png \
		src/wrsim/img/probe2.png \
		src/wrsim/img/probei.png \
		src/wrsim/img/robovss.png \
		src/wrsim/img/robovss12.png
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name recursos src/wrsim/img/recursos.qrc -o tmp/rc/qrc_recursos.cpp

compiler_moc_header_make_all: tmp/moc/moc_gameplay.cpp tmp/moc/moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) tmp/moc/moc_gameplay.cpp tmp/moc/moc_mainwindow.cpp
tmp/moc/moc_gameplay.cpp: src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h \
		src/controlsystem/referee.h \
		src/utils/csv.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h \
		src/controlsystem/gameplay.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/marco/slapy/programação/cpp/futbot -I/home/marco/slapy/programação/cpp/futbot -I/home/marco/slapy/programação/cpp/futbot/src -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include src/controlsystem/gameplay.h -o tmp/moc/moc_gameplay.cpp

tmp/moc/moc_mainwindow.cpp: src/wrsim/src/WRSim/mainwindow.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/marco/slapy/programação/cpp/futbot -I/home/marco/slapy/programação/cpp/futbot -I/home/marco/slapy/programação/cpp/futbot/src -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include src/wrsim/src/WRSim/mainwindow.h -o tmp/moc/moc_mainwindow.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: tmp/moc/ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) tmp/moc/ui_mainwindow.h
tmp/moc/ui_mainwindow.h: src/wrsim/src/WRSim/mainwindow.ui \
		/usr/lib/x86_64-linux-gnu/qt5/bin/uic
	/usr/lib/x86_64-linux-gnu/qt5/bin/uic src/wrsim/src/WRSim/mainwindow.ui -o tmp/moc/ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

tmp/obj/main.o: src/main.cpp src/controlsystem/gameplay.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h \
		src/controlsystem/referee.h \
		src/utils/csv.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h \
		src/controlsystem/controlsystem.h \
		src/geneticalgorithm/evolutioncontrol.h \
		src/geneticalgorithm/crossover.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/main.o src/main.cpp

tmp/obj/gameplay.o: src/controlsystem/gameplay.cpp src/controlsystem/gameplay.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h \
		src/controlsystem/referee.h \
		src/utils/csv.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/gameplay.o src/controlsystem/gameplay.cpp

tmp/obj/referee.o: src/controlsystem/referee.cpp src/controlsystem/referee.h \
		src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/utils/csv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/referee.o src/controlsystem/referee.cpp

tmp/obj/controlsystem.o: src/controlsystem/controlsystem.cpp src/controlsystem/controlsystem.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/utils/csv.h \
		src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/controlsystem/gameplay.h \
		src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h \
		src/controlsystem/referee.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h \
		src/geneticalgorithm/evolutioncontrol.h \
		src/geneticalgorithm/crossover.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/controlsystem.o src/controlsystem/controlsystem.cpp

tmp/obj/moverobots.o: src/controlsystem/moverobots.cpp src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/moverobots.o src/controlsystem/moverobots.cpp

tmp/obj/feedforward.o: src/controlsystem/feedforward.cpp src/controlsystem/feedforward.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/utils/csv.h \
		src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/feedforward.o src/controlsystem/feedforward.cpp

tmp/obj/fitness.o: src/controlsystem/fitness.cpp src/controlsystem/fitness.h \
		src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/fitness.o src/controlsystem/fitness.cpp

tmp/obj/crossover.o: src/geneticalgorithm/crossover.cpp src/geneticalgorithm/crossover.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/utils/csv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/crossover.o src/geneticalgorithm/crossover.cpp

tmp/obj/evolutioncontrol.o: src/geneticalgorithm/evolutioncontrol.cpp src/geneticalgorithm/evolutioncontrol.h \
		src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/utils/csv.h \
		src/geneticalgorithm/crossover.h \
		src/controlsystem/gameplay.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h \
		src/controlsystem/referee.h \
		src/controlsystem/feedforward.h \
		src/controlsystem/fitness.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/evolutioncontrol.o src/geneticalgorithm/evolutioncontrol.cpp

tmp/obj/fisica.o: src/wrsim/src/WRSim/fisica.cpp src/wrsim/src/WRSim/fisica.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/probe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/fisica.o src/wrsim/src/WRSim/fisica.cpp

tmp/obj/grafico.o: src/wrsim/src/WRSim/grafico/grafico.cpp src/wrsim/src/WRSim/grafico/grafico.h \
		src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h \
		src/wrsim/src/WRSim/grafico/graficorobovss.h \
		src/wrsim/src/WRSim/grafico/graficobola.h \
		src/wrsim/src/WRSim/grafico/graficoprobe.h \
		src/wrsim/src/WRSim/objetos/probe.h \
		src/wrsim/src/WRSim/grafico/graficocampovss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/grafico.o src/wrsim/src/WRSim/grafico/grafico.cpp

tmp/obj/graficobola.o: src/wrsim/src/WRSim/grafico/graficobola.cpp src/wrsim/src/WRSim/grafico/graficobola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/graficobola.o src/wrsim/src/WRSim/grafico/graficobola.cpp

tmp/obj/graficocampovss.o: src/wrsim/src/WRSim/grafico/graficocampovss.cpp src/wrsim/src/WRSim/grafico/graficocampovss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/graficocampovss.o src/wrsim/src/WRSim/grafico/graficocampovss.cpp

tmp/obj/graficoentrada.o: src/wrsim/src/WRSim/grafico/graficoentrada.cpp src/wrsim/src/WRSim/grafico/graficoentrada.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h \
		src/wrsim/src/WRSim/interface.h \
		src/controlsystem/moverobots.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/graficoentrada.o src/wrsim/src/WRSim/grafico/graficoentrada.cpp

tmp/obj/graficoprobe.o: src/wrsim/src/WRSim/grafico/graficoprobe.cpp src/wrsim/src/WRSim/grafico/graficoprobe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/graficoprobe.o src/wrsim/src/WRSim/grafico/graficoprobe.cpp

tmp/obj/graficorobovss.o: src/wrsim/src/WRSim/grafico/graficorobovss.cpp src/wrsim/src/WRSim/grafico/graficorobovss.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/graficorobovss.o src/wrsim/src/WRSim/grafico/graficorobovss.cpp

tmp/obj/bola.o: src/wrsim/src/WRSim/objetos/bola.cpp src/wrsim/src/WRSim/objetos/bola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/bola.o src/wrsim/src/WRSim/objetos/bola.cpp

tmp/obj/probe.o: src/wrsim/src/WRSim/objetos/probe.cpp src/wrsim/src/WRSim/objetos/probe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/probe.o src/wrsim/src/WRSim/objetos/probe.cpp

tmp/obj/robovss.o: src/wrsim/src/WRSim/objetos/robovss.cpp src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/robovss.o src/wrsim/src/WRSim/objetos/robovss.cpp

tmp/obj/mainwindow.o: src/wrsim/src/WRSim/mainwindow.cpp src/wrsim/src/WRSim/mainwindow.h \
		tmp/moc/ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/mainwindow.o src/wrsim/src/WRSim/mainwindow.cpp

tmp/obj/interface.o: src/wrsim/src/WRSim/interface.cpp src/wrsim/src/WRSim/interface.h \
		src/wrsim/src/WRSim/objetos/robovss.h \
		src/wrsim/src/WRSim/cte.h \
		src/wrsim/src/WRSim/objetos/bola.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/interface.o src/wrsim/src/WRSim/interface.cpp

tmp/obj/neuron.o: src/neuralnetwork/neuron.cpp src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/neuralnetwork/random.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/neuron.o src/neuralnetwork/neuron.cpp

tmp/obj/neuralnetwork.o: src/neuralnetwork/neuralnetwork.cpp src/neuralnetwork/neuralnetwork.h \
		src/neuralnetwork/neuron.h \
		src/utils/my_ptr.h \
		src/utils/csv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/neuralnetwork.o src/neuralnetwork/neuralnetwork.cpp

tmp/obj/csv.o: src/utils/csv.cpp src/utils/csv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/csv.o src/utils/csv.cpp

tmp/obj/qrc_recursos.o: tmp/rc/qrc_recursos.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/qrc_recursos.o tmp/rc/qrc_recursos.cpp

tmp/obj/moc_gameplay.o: tmp/moc/moc_gameplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/moc_gameplay.o tmp/moc/moc_gameplay.cpp

tmp/obj/moc_mainwindow.o: tmp/moc/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/obj/moc_mainwindow.o tmp/moc/moc_mainwindow.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

