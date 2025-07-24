# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c dwm.c util.c
OBJ = ${SRC:.c=.o}
BIN = dwm
SCRIPTS = dwmswallow swallowup swallowleft swallowright swallowdown

all: options ${BIN}

options:
	@echo ${BIN} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} "$<" -o "$@"

${OBJ}: config.h config.mk

${BIN}: ${OBJ}
	${CC} -o "$@" ${OBJ} ${LDFLAGS}

clean:
	rm -f ${BIN} ${OBJ} ${BIN}-${VERSION}.tar.gz *.orig *.rej

dist: clean
	mkdir -p ${BIN}-${VERSION}
	cp -R LICENSE Makefile README config.mk \
		dwm.1 drw.h util.h ${SRC} transient.c ${BIN}-${VERSION}
	tar -cf ${BIN}-${VERSION}.tar ${BIN}-${VERSION}
	gzip ${BIN}-${VERSION}.tar
	rm -rf ${BIN}-${VERSION}

install: all
	mkdir -p "${DESTDIR}${PREFIX}/bin"
	install -Dm755 ./${BIN} "${DESTDIR}${PREFIX}/bin/${BIN}"
	for s in ${SCRIPTS}; do \
		install -Dm755 "./swallowsc/$$s" "${DESTDIR}${PREFIX}/bin/$$s"; \
	done
	mkdir -p "${DESTDIR}${MANPREFIX}/man1"
	sed "s/VERSION/${VERSION}/g" < dwm.1 > "${DESTDIR}${MANPREFIX}/man1/${BIN}.1"
	chmod 644 "${DESTDIR}${MANPREFIX}/man1/${BIN}.1"
	mkdir -p "${DESTDIR}${PREFIX}/share/${BIN}"
	install -Dm644 ./larbs.mom "${DESTDIR}${PREFIX}/share/${BIN}/larbs.mom"

uninstall:
	rm -f "${DESTDIR}${PREFIX}/bin/${BIN}"
	for s in ${SCRIPTS}; do \
		rm -f "${DESTDIR}${PREFIX}/bin/$$s"; \
	done
	rm -f "${DESTDIR}${PREFIX}/share/${BIN}/larbs.mom"
	rm -f "${DESTDIR}${MANPREFIX}/man1/${BIN}.1"

.PHONY: all options clean dist install uninstall
