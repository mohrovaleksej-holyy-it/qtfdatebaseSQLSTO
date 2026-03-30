QT       += core gui sql printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientadd.cpp \
    infobase.cpp \
    main.cpp \
    mainwindow.cpp \
    ordersadd.cpp \
    partsalesadd.cpp \
    rempogar.cpp \
    reviews.cpp \
    servicesadd.cpp \
    sparapartsadd.cpp \
    staffadd.cpp \
    viewtablesto.cpp \
    warrantycasesadd.cpp \
    warrantyrepairsadd.cpp \
    warsot.cpp \
    workshuduleadd.cpp

HEADERS += \
    clientadd.h \
    infobase.h \
    mainwindow.h \
    ordersadd.h \
    partsalesadd.h \
    rempogar.h \
    reviews.h \
    servicesadd.h \
    sparapartsadd.h \
    staffadd.h \
    viewtablesto.h \
    warrantycasesadd.h \
    warrantyrepairsadd.h \
    warsot.h \
    workshuduleadd.h

FORMS += \
    clientadd.ui \
    infobase.ui \
    mainwindow.ui \
    ordersadd.ui \
    partsalesadd.ui \
    rempogar.ui \
    reviews.ui \
    servicesadd.ui \
    sparapartsadd.ui \
    staffadd.ui \
    viewtablesto.ui \
    warrantycasesadd.ui \
    warrantyrepairsadd.ui \
    warsot.ui \
    workshuduleadd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
