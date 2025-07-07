

# cf. A LARBS fork with more bloat

Read [config](./config.h) or diff the rest for any breaking tweaks..
Forked from [Luke Smith's dwm](https://github.com/LukeSmithxyz/dwm).


# Luke's built-in patches and features

-   A [Clickable statusbar](https://dwm.suckless.org/patches/statuscmd/) with his build of [dwmblocks](https://github.com/lukesmithxyz/dwmblocks).
-   Support for [Xresources](https://dwm.suckless.org/patches/xresources/) colors/variables (i.e. works with \`pywal\`, etc.).
-   Scratchpad: Accessible with <kbd>s-S-<return></kbd>.
-   True fullscreen (<kbd>s-f</kbd>) and prevents focus shifting.
-   Windows can be made sticky (<kbd>s-s</kbd>).
-   [pertag](https://dwm.suckless.org/patches/pertag/): More general approach to taglayouts patch. This patch keeps
    layout, mfact, bar pos and nmaster per tag.
-   [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/): hides tags with no windows.
-   [stacker](https://dwm.suckless.org/patches/stacker/): Move windows up the stack manually (<kbd>s-S-[k,j]</kbd>).
-   [shiftview](https://dwm.suckless.org/patches/nextprev/): Cycle through tags (<kbd>s-g</kbd> <kbd>s-;</kbd>).
-   [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Gaps allowed across all layouts.
-   [swallow patch](https://dwm.suckless.org/patches/swallow/): if a program run from a terminal would make it inoperable, it temporarily takes its place to save space.
-   New layouts: bstack, fibonacci, deck, centered master and more. All
    bound to keys <kbd>s-[S,C]-[t,y,u,i]</kbd> combos.
-   [dwm-alpha](https://dwm.suckless.org/patches/alpha/): Allow dwm to have translucent bars, while keeping all the text on it opaque.


## FUNDING

Credit to [Luke Smith](https://lukesmith.xyz/donate.html) for the work ; support him if you have the wherewithal.

# cf. added bloat

-   [Grid Layouts]: Few additional grid layouts to try them out.
-   [dwm-dynamicswallow-patch](https://dwm.suckless.org/patches/dynamicswallow/): Introduces "dynamic" window swallowing to dwm.
    -   the patch provides (<kbd>s-S-\<mouse-drag-1\></kbd>) for mouse dragging swallows.
    -   The [dwmswallow](./dwmswallow) command allows for suckless scripting of custom window swallow behaviours basicly.
        (e.g.:  swallow-in-direction <kbd>s-[\<down\>,\<left\>,\<up\>,\<right\>]</kbd>
                unswallow (barf from SWALLOWER) <kbd>s-S-\<down\></kbd>)
        - xdotool shell scripts example included in [swallows_scripts](./swallow_scripts).
-   [cfacts](https://dwm.suckless.org/patches/cfacts/): Patched [vanitygaps](./vanitygaps.c) with support for cfacts and I believe
    some of the added layouts. FIXME <span class="timestamp-wrapper"><span class="timestamp">2025-07-07</span></span>: needs proper
    cfacts/mfacts updates.
-   [defaulttransparency](https://dwm.suckless.org/patches/defaulttransparency/): This patch adds a default transparency
    parameter to config.h. FIXME <span class="timestamp-wrapper"><span class="timestamp">2025-07-07</span></span>: conflicts with manual
    transparency and xresources.
-   [KeyChords](https://dwm.suckless.org/patches/keychord/dwm-keychord-6.4.diff): I discovered Emacs.
-   [barpadding](https://dwm.suckless.org/patches/barpadding/dwm-barpadding-20211020-a786211.diff): Round corners look awkful without bar padding.
    (DEPRECATED: Waste of space for my taste, but option is there for shifting picom configs)


# TODO: <span class="timestamp-wrapper"><span class="timestamp">2025-07-07</span></span>

-   [ ] Fix cfacts/mfacts for pertag and swallow patches  <span class="timestamp-wrapper"><span class="timestamp">2025-07-07</span></span>
-   [ ] Add script symlinks deployment to Makefile.
-   [ ] Dynamic Org table of keymap changes.
