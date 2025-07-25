let
  pkgs = import <nixpkgs> {};
in pkgs.stdenv.mkDerivation {
  pname = "dwm";
  version = "6.4";

  src = ./.;

  buildInputs = [
    pkgs.xorg.libX11
    pkgs.xorg.libXinerama
    pkgs.xorg.libXft
    pkgs.pkg-config
  ];

  installPhase = ''
    mkdir -p $out/bin
    cp dwm $out/bin/
  '';
}
