_pkgname=dwm
pkgname=$_pkgname-cf-git
pkgver=6.4.r1888.0ac09e0
pkgrel=1
pkgdesc="cf. dwm"
url=https://github.com/cf-tgg/dwm
arch=(i686 x86_64)
license=(MIT)
makedepends=(git)
depends=(freetype2 libx11 libxft)
optdepends=(
    'dmenu: program launcher'
    'st: terminal emulator'
)
provides=($_pkgname)
conflicts=($_pkgname)
source=("git+https://github.com/cf-tgg/dwm")
sha256sums=('SKIP')

pkgver() {
    cd "$_pkgname" || exit 1
    version=$(awk '/^VERSION =/ {print $3}' config.mk)
    count=$(git rev-list --count HEAD)
    short=$(git rev-parse --short HEAD)
    printf "%s.r%s.%s\n" "${version}" "${count}" "${short}"
}

prepare() {
    cd "$_pkgname" || exit 1
    printf 'CPPFLAGS+=%s\n' "${CPPFLAGS}" >> config.mk
    printf 'CFLAGS+=%s\n' "${CFLAGS}" >> config.mk
    printf 'LDFLAGS+=%s\n' "${LDFLAGS}" >> config.mk
    if [ -f "${SRCDEST}/config.h" ]; then
        cp "${SRCDEST}/config.h" .
    fi
}

build() {
    cd "$_pkgname" || exit 1
    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
    cd "$_pkgname" || exit 1
    make PREFIX=/usr DESTDIR="$pkgdir" install
    install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
