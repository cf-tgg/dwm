# dwm version
VERSION = 6.4

# Install paths
PREFIX = /home/cf/.local
MANPREFIX = ${PREFIX}/share/man

# Header/library paths
X11INC = /usr/include
X11LIB = /usr/lib
FREETYPEINC = /usr/include/freetype2

# Optional: FreeType & fontconfig libs
FREETYPELIBS = -lfontconfig -lXft

# Optional: Xinerama support (enabled by default)
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# Includes and linking
INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS} -lXrender -lX11-xcb -lxcb -lxcb-res

# Compiler and linker flags (extendable via environment)
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# Tools
CC = cc
