

# cf. dwm

A Fork of suckless' dynamic window [dwm](https://dwm.suckless.org), forked from [Luke's build of dwm](https://github.com/LukeSmithxyz/dwm).

Read the [config](./config.h) or diff the original repos..
For more details, RTFM: [dwm(1)](./dwm.1) 😃

I maintain this fork from time to time, whenever I feel like hacking
on my config or want it on fresh installs.

I'd recommend forking your own, but you're welcome to use mine as starting point.


# DISCLAIMER

I'm not a programmer, I just enjoy customizing my computing
environment.  That being said, I usually keep the master in a
working state, for my use case; I can't say for sure that my code
is bug free or that it will work for yours.

Send me a PR if you have any problems with it or if you'd like to
share tips for improvement, I'll help you if I can, when I can.


# Luke's built-in features

-   A [Clickable statusbar](https://dwm.suckless.org/patches/statuscmd/) with his build of [dwmblocks](https://github.com/lukesmithxyz/dwmblocks).
-   Support for [Xresources](https://dwm.suckless.org/patches/xresources/) colors/variables (i.e. works with `pywal`, etc.).
-   Scratchpad: Accessible with (<kbd>Super</kbd>+<kbd>Enter</kbd>).
-   True fullscreen (<kbd>Super</kbd>+<kbd>f</kbd>) and prevents focus shifting.
-   Windows can be made sticky (<kbd>Super</kbd>+<kbd>s</kbd>).
-   [pertag](https://dwm.suckless.org/patches/pertag/): More general approach to taglayouts patch.
    This patch keeps layout, mfact, bar pos and nmaster per tag.
-   [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/): hides tags with no windows.
-   [stacker](https://dwm.suckless.org/patches/stacker/): Move windows up the stack manually (<kbd>Super</kbd>+<kbd>Shift</kbd>+<kbd>[k,j]</kbd>).
-   [shiftview](https://dwm.suckless.org/patches/nextprev/): Cycle
-   through tags (<kbd>Super</kbd>+<kbd>g</kbd> and <kbd>s</kbd><kbd>;</kbd>).
-   [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Gaps allowed across all layouts.
-   [swallow patch](https://dwm.suckless.org/patches/swallow/): if a program run from a terminal would make it inoperable,
    it temporarily takes its place to save space.
-   New layouts: bstack, fibonacci, deck, centered master and more.
    All bound to keys (<kbd>Super</kbd>+<kbd>Shift</kbd>/<kbd>Control</kbd> prefixes + <kbd>t</kbd>,<kbd>y</kbd>,<kbd>u</kbd>,<kbd>i</kbd>) combos.
-   [dwm-alpha](https://dwm.suckless.org/patches/alpha/): Allow dwm to have translucent bars, while keeping all the
    text on it opaque.


## FUNDING

Credit to [Luke Smith](https://lukesmith.xyz/donate.html) for LARBS work, support him if you have the wherewithal.


# cf. Added bloat

-   [dwm-dynamicswallow-patch](https://dwm.suckless.org/patches/dynamicswallow/): Introduces "dynamic" window swallowing to dwm.
    - Provides (<kbd>Super</kbd>+<kbd>Shift</kbd>+<kbd>Mouse Drag 1</kbd>) for mouse dragging swallows.
    - The [dwmswallow](./dwmswallow) script allows scripting of dynamic swallows.
      For example:
      - swallow-in-direction: (<kbd>Super</kbd>+<kbd>↓</kbd>, <kbd>←</kbd>, <kbd>↑</kbd>, <kbd>→</kbd>)
      - barf-from-swallower: (<kbd>Super</kbd>+<kbd>Shift</kbd>+<kbd>↓</kbd>)
      - xdotool shell scripts example included in [swallowsc](./swallowsc).
-   [cfacts](https://dwm.suckless.org/patches/cfacts/): Patched [vanitygaps](./vanitygaps.c) with support for cfacts (in addition to mfacts)
    ~~FIXME 25-07-07: needs proper cfacts/mfacts updates.~~
-   [defaulttransparency](https://dwm.suckless.org/patches/defaulttransparency/): This patch adds a default transparency parameter to config.h.
    FIXME 2025-07-07: conflicts with manual transparency and xresources.
-   [KeyChords](https://dwm.suckless.org/patches/keychord/dwm-keychord-6.4.diff): I discovered Emacs.
-   [barpadding](https://dwm.suckless.org/patches/barpadding/dwm-barpadding-20211020-a786211.diff): Round corners look awkful without bar padding.
    (Waste of space for my taste, but option is there for shifting picom configs)
-  Added Scratpads for `emacsclient` frames :W.I.P: 2025-08-02

# TODOs : 2025-08-02

-   [X] ~~Fix cfacts/mfacts for pertag and swallow patches 2025-07-07~~
-   [X] ~~Add script symlinks deployment to Makefile.~~
  -   [2025-08-01] Makefile installation is now per user:
  -   dwm binary and swallowscripts are installed in `~/.local/bin` removing need for
      privilege escalation to customize and rebuild
      (i.e. `make clean install` instead of `sudo make install`) ;
      allows for per user customizations
      (e.g. for creating different user builds running on parallel ttys)
-   [ ] Improve handling of emacsclient scratchpads [2025-08-02]
-   [ ] Update the man [2025-08-01]
-   [ ] Make it a Nix flake.
