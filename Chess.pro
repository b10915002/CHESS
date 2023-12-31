QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HumanPlayer.cpp \
    bishop.cpp \
    board.cpp \
    chessPiece.cpp \
    emptyChess.cpp \
    gameManager.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    pawn.cpp \
    pawnpro.cpp \
    player.cpp \
    queen.cpp \
    rook.cpp

HEADERS += \
    Board.h \
    HumanPlayer.h \
    Record.h \
    bishop.h \
    chessPiece.h \
    emptyChess.h \
    gameManager.h \
    king.h \
    knight.h \
    mainwindow.h \
    pawn.h \
    pawnpro.h \
    pieces.h \
    player.h \
    position.h \
    queen.h \
    rook.h

FORMS += \
    mainwindow.ui \
    pawnpro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Chess.pro.user
