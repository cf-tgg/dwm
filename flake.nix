{
  description = "DWM build with patches, bin export, and Home Manager integration";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
    home-manager.url = "github:nix-community/home-manager";
    home-manager.inputs.nixpkgs.follows = "nixpkgs";

    dwm-src = {
      url = "github:cf-tgg/dwm";
      flake = false;
    };
  };

  outputs = { self, nixpkgs, home-manager, dwm-src }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};

      patchedSrc = pkgs.lib.cleanSourceWith {
        src = dwm-src;
        filter = path: _type:
          !pkgs.lib.hasSuffix ".rej" path;
      };

      patchFiles = builtins.filter
        (name: pkgs.lib.hasSuffix ".diff" name || pkgs.lib.hasSuffix ".patch" name)
        (builtins.attrNames (builtins.readDir ./patches));
    in {
      packages.${system}.dwm = pkgs.stdenv.mkDerivation {
        pname = "dwm";
        version = "6.4";

        src = patchedSrc;

        patches = builtins.map (name: ./patches/${name}) patchFiles;

        buildInputs = [
          pkgs.xorg.libX11
          pkgs.xorg.libXinerama
          pkgs.xorg.libXft
          pkgs.pkg-config
        ];

        preBuild = ''
          substituteInPlace config.mk \
            --replace /usr/X11R6/include ${pkgs.xorg.libX11.dev}/include \
            --replace /usr/X11R6/lib ${pkgs.xorg.libX11.out}/lib
        '';

        installPhase = ''
          mkdir -p $out/bin
          cp dwm $out/bin/
          mkdir -p ~/.local/bin
          cp $out/bin/dwm ~/.local/bin/dwm
        '';
      };

      defaultPackage.${system} = self.packages.${system}.dwm;

      devShells.${system}.default = pkgs.mkShell {
        buildInputs = [
          pkgs.xorg.libX11
          pkgs.xorg.libXinerama
          pkgs.xorg.libXft
          pkgs.pkg-config
        ];
      };

      homeManagerModules.dwm = {
        config,
        lib,
        pkgs,
        ...
      }: {
        options.dwm.enable = lib.mkEnableOption "Enable custom dwm build";

        config = lib.mkIf config.dwm.enable {
          home.packages = [ self.packages.${system}.dwm ];
          xsession.windowManager.command = "${self.packages.${system}.dwm}/bin/dwm";
        };
      };
    };
}
