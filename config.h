/* -*- mode: simpc-mode -*- vim: ft=c:sw=2:ts=2:norl:et:
 *       _
 *    __| |_      ___ __ ___
 *   / _` \ \ /\ / / '_ ` _ \
 *  | (_| |\ V  V /| | | | | |
 *   \__,_| \_/\_/ |_| |_| |_|
 *
 *   Time-stamp: <2025-09-22 02:50:04 cf>
 *   Last compiled: 2025-09-22 02:09:11, duration 1.27 s
 *   Box: [Linux 6.15.2-zen1-1-zen x86_64 GNU/Linux]
 */

#define TERMINAL "st"
#define TERMCLASS "St"
#define STATUSBAR "dwmblocks"
#define BROWSER "qutebrowser"

#define EMACS_SERVER_FILE "/run/user/1000/emacs/server"
#define EMACS_SOCKET_NAME "/run/user/1000/emacs/server"
#define ALTERNATE_EDITOR ""
#define EMACSCLASS "Emacs"
#define EMACSCLIENT "emacsclient"
#define EMACS "emc"

/*     Appearance      */
static unsigned int borderpx =  1; /* border pixel of windows */
static unsigned int snap     = 24; /* snap pixel */

static unsigned int gappih   =  1; /* horiz inner gap between windows */
static unsigned int gappiv   =  2; /* vert inner gap between windows */
static unsigned int gappoh   =  2; /* horiz outer gap between windows and screen edge */
static unsigned int gappov   =  3; /* vert outer gap between windows and screen edge */

static int smartgaps         =  0; /* 1 means no outer gap when there is only one window */
static int swallowfloating   =  1; /* 1 means swallow floating windows by default */

static int showbar           =  1; /* 0 means no bar */
static int topbar            =  1; /* 0 means bottom bar */

static const int vertpad     =  0; /* vertical padding of bar */
static const int sidepad     =  0; /* horizontal padding of bar */
static const int user_bh     = 48; /* 0: dwm calculate bar height, */
                                   /* >= 1: user_bh as bar height */

static const char *fonts[] = {
    "Iosevka Nerd Font:size=11:style=Regular:antialias=true:autohint=true",
    "Iosevka Nerd Font Mono:size=11:style=Regular:antialias=true:autohint=true",
    "IosevkaTerm Nerd Font:size=11:antialias=true:autohint=true",
    "CaskaydiaCove Nerd Font:size=9:style=Book:antialias=true:autohint=true",
    "Symbols Nerd Font Mono:pixelsize=64:antialias=true:autohint=true",
    "FontAwesome:pixelsize=64:antialias=true:autohint=true",
    "Noto Color Emoji:pixelsize=22:antialias=true:autohint=true",
    "Material Icons:pixelsize=64:antialias=true:autohint=true",
    "Weather Icons:pixelsize=64:antialias=true:autohint=true",
    "Iosevka Comfy:style=Regular:antialias=true:autohint=true",
    "Aporetic Serif:style=Regular:antialias=true:autohint=true",
    "Aporetic Sans:style=Regular:antialias=true:autohint=true",
    "Aporetic Serif Mono:size=9:style=Regular:antialias=true:autohint=true",
    "Aporetic Sans Mono:style=Regular:antialias=true:autohint=true",
    "Iosevka Comfy Duo:style=Regular:antialias=true:autohint=true"
};

static char normfgcolor[]     = "#e4e4ef";
static char normbgcolor[]     = "#101010";
static char normbordercolor[] = "#00000b";

static char selfgcolor[]       = "#ffffff";
static char selbgcolor[]       = "#141414";
static char selbordercolor[]   = "#1f1f1e";

static const double defaultopacity = 0.96;
static const double activeopacity = 0.98;   /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity = 0.95; /* Window opacity when it's inactive (0 <= opacity <= 1) */

static const unsigned int borderalpha = OPAQUE;
static const unsigned int baralpha = 204;

static const char *colors[][3] = {
    /*                 fg            bg              border        */
    [SchemeNorm] = { normfgcolor,   normbgcolor,    normbordercolor },
    [SchemeSel]  = { selfgcolor,    selbgcolor,     selbordercolor  },
};

static const unsigned int alphas[][3] = {
    /*                fg     bg       border    */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel]  = {OPAQUE, baralpha, borderalpha},
};

typedef struct {
  const char *name;
  const void *cmd;
} Sp;

const char *spcmd1[] = {TERMINAL, "-n", "spterm",  "-g", "100x30", NULL};
const char *spcmd2[] = {TERMINAL, "-n", "spcalc",  "-f", "monospace:size=40", "-g", "30x3", "-e", "bc", "-lq", NULL};
const char *spcmd3[] = {TERMINAL, "-n", "spvclp",  "-f", "monospace:size=40", "-g", "100x30", "-e", "seledit", NULL};
const char *spcmd4[] = {TERMINAL, "-n", "spmpvq",  "-f", "monospace:size=20", "-g", "85x30", "-e",  "mpvqdl",  NULL};
const char *spcmd5[] = {TERMINAL, "-n", "spmpvf",  "-f", "monospace:size=30", "-g", "90x30", "-e",  "mpvqfzf", NULL};

/* Emacsclient frames (./cf-spmacs.el)  */
const char *spcmd6[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"scratch-macs\")'", NULL};
const char *spcmd7[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"eww-browser\")'",  NULL};
const char *spcmd8[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"elfeed-frame\")'", NULL};
const char *spcmd9[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"minibuffer\")'",   NULL};
const char *spcmd10[] = {"xcurzui", NULL};
const char *spcmd11[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc1\")'",  NULL};
const char *spcmd12[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc2\")'",  NULL};
const char *spcmd13[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc3\")'",  NULL};
const char *spcmd14[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc4\")'",  NULL};
const char *spcmd15[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc5\")'",  NULL};
const char *spcmd16[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc6\")'",  NULL};
const char *spcmd17[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc7\")'",  NULL};
const char *spcmd18[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc8\")'",  NULL};
const char *spcmd19[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc9\")'",  NULL};
const char *spcmd20[] = {EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-e", "'(spmacs/toggle-frame \"Emc0\")'",  NULL};

static Sp scratchpads[] = {
    /* name     cmd  */
    {"spterm",  spcmd1},   /* floating term  */
    {"spcalc",  spcmd2},   /* floating calc  */
    {"spvclp",  spcmd3},   /* xseledit macs  */
    {"spmpvq",  spcmd4},   /* mpdl           */
    {"spmpvf",  spcmd5},   /* mpvqfzf        */
    {"spmacs",  spcmd6},   /* scratch-macs   */
    {"spewwb",  spcmd7},   /* eww-browser    */
    {"spfeed",  spcmd8},   /* elfeed-frame   */
    {"spmini",  spcmd9},   /* minibuffer     */
    {"spxmag",  spcmd10},  /* xcurzui        */
    {"spemc1",  spcmd11},  /* Emc1           */
    {"spemc2",  spcmd12},  /* Emc2           */
    {"spemc3",  spcmd13},  /* Emc3           */
    {"spemc4",  spcmd14},  /* Emc4           */
    {"spemc5",  spcmd15},  /* Emc5           */
    {"spemc6",  spcmd16},  /* Emc6           */
    {"spemc7",  spcmd17},  /* Emc7           */
    {"spemc8",  spcmd18},  /* Emc8           */
    {"spemc9",  spcmd19},  /* Emc9           */
    {"spemc0",  spcmd20},  /* Emc0          */
};

/* static const char *tags[] = {"1", "2", "3", "4",  "5", "6", "7", "8 ", "9"}; */
static const char *tags[] = {"", "", "󰌀",  "", "", "󰘧", "", "󰑫", ""};

static const Rule rules[] = {
    /* class          instance      title          tags mask  isfloating  fopacity unfopacity isterminal  noswallow  monitor */
    {"Gimp",          NULL,         NULL,           1 << 4,     0,          1,             0,       1,          0,          -1},
    {"Blender",       NULL,         NULL,           1 << 4,     0,          1,          0.95,       0,          0,          -1},
    {"firefox",       NULL,         NULL,           1 << 2,     0,          1,          0.95,       0,          0,          -1},
    {"brave-browser", NULL,         NULL,           1 << 9,     0,          1,          0.95,       0,          0,          -1},
    {"chromium",      NULL,         NULL,           1 << 6,     0,          1,          0.95,       0,          0,          -1},
    {"surf",          NULL,         NULL,           1 << 2,     0,          1,          0.95,       0,          0,          -1},
    {"obs",           NULL,         NULL,           1 << 6,     0,          1,             1,       0,          0,          -1},
    {"qutebrowser",   NULL,         NULL,           0,          0,          1,          0.95,       0,          0,          -1},
    {"Zathura",       NULL,         NULL,           1 << 3,     0,        0.7,          0.65,       0,          0,          -1},
    {TERMCLASS,       "neomutt",    NULL,           1 << 6,     0,          1,           0.9,       1,          1,          -1},
    {TERMCLASS,       NULL,         NULL,           0,          0,          1,             0,       1,          0,          -1},
    {TERMCLASS,       "bg",         NULL,           1 << 7,     0,          1,             0,       0,          0,          -1},
    {TERMCLASS,       "floatterm",  NULL,           0,          1,          1,             0,       0,          0,          -1},
    {TERMCLASS,       "spterm",     NULL,           SPTAG(0),   1,          1,             0,       0,          0,          -1},
    {TERMCLASS,       "spcalc",     NULL,           SPTAG(1),   1,          1,             0,       0,          0,          -1},
    {TERMCLASS,       "spvclp",     NULL,           SPTAG(2),   1,          1,             0,       1,          1,          -1},
    {TERMCLASS,       "spmpvq",     NULL,           SPTAG(3),   1,          1,             0,       1,          1,          -1},
    {TERMCLASS,       "spmpvf",     NULL,           SPTAG(4),   1,          1,             0,       1,          1,          -1},
    {EMACSCLASS,       NULL,        "scratch-macs", SPTAG(5),   1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "eww-browser",  SPTAG(6),   1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "elfeed-frame", SPTAG(7),   1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "minibuffer",   SPTAG(8),   1,          1,             0,       0,          0,          -1},
    {NULL,             NULL,        "Xmagnify",     SPTAG(9),   1,        0.1,             1,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc1",         SPTAG(10),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc2",         SPTAG(11),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc3",         SPTAG(12),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc4",         SPTAG(13),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc5",         SPTAG(14),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc6",         SPTAG(15),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc7",         SPTAG(16),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc8",         SPTAG(17),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc9",         SPTAG(18),  1,          1,             0,       0,          0,          -1},
    {EMACSCLASS,       NULL,        "Emc0",         SPTAG(19),  1,          1,             0,       0,          0,          -1},
    {NULL,             NULL,        "Event Tester", 0,          0,          0,             1,       0,          0,          -1},
};

/* dynamic window swallowing */
static const int  swalretroactive =  15 ;
static const int  swaldecay       =  30 ;
static const char swalsymbol[]    = "👅";

/*  layouts hints */
static float mfact = 0.70;           /* factor of master area size [0.05..0.95] */
static int nmaster = 1;              /* number of clients in master area */
static int resizehints = 0;          /* 1 means respect size hints in tiled resizals */

static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
/*  Symbol           Layout                          Description */
    { "[T]",         bstack },                    /* 00  Master on top, slaves on bottom */
    { "[]=",         tile },                      /* 01  Default: Master on left, slaves on right */
    { "[@]",         spiral },                    /* 02  Fibonacci spiral */
    { "[\\]",        dwindle },                   /* 03  Decreasing in size right and leftward */
    { "[D]",         deck },                      /* 04  Master on left, slaves in monocle-like mode on right */
    { "[M]",         monocle },                   /* 05  All windows on top of eachother */
    { "|M|",         centeredmaster },            /* 06  Master in middle, slaves on sides */
    { ">M>",         centeredfloatingmaster },    /* 07  Same but master floats */
    { "[=]",         bstackhoriz },               /* 08  Same as bstack but horizontal */
    { "[H]",         grid },                      /* 09  Equal grid */
    { "[#]",         nrowgrid },                  /* 10  Numbered row grid, incnmaster (Ctrl-o/Ctrl-O) to add/sub rows */
    { "[-]",         horizgrid },                 /* 11  Horizontal grid */
    { "[:]",         gaplessgrid },               /* 12  Smarter "gap-less" grid */
    { "><>",         NULL },                      /* 13  No layout means floating behavior */
    { NULL,          NULL },
};

/*  <Super> as main modkey */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    &((Keychord){1, {{MODKEY, KEY}},                           view,           {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ControlMask, KEY}},               toggleview,     {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ShiftMask, KEY}},                 tag,            {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},     toggletag,      {.ui = 1 << TAG} }),

/* Stack window push and master focus */
#define STACKKEYS(MOD, ACTION)                                       \
    &((Keychord){1, {{MOD, XK_j}}, ACTION##stack, {.i = INC(+1)} }), \
    &((Keychord){1, {{MOD, XK_k}}, ACTION##stack, {.i = INC(-1)} }), \
    &((Keychord){1, {{MOD, XK_v}}, ACTION##stack, {.i = 0}}),

/* KeyChord Helpers */
#define KC1(MOD, KEY, CMD) \
    &((Keychord){          \
        1, {{ MOD, KEY }}, \
        spawn, {.v = CMD}  \
    })

#define KC2(MOD1, KEY1, MOD2, KEY2, CMD)     \
    &((Keychord){                            \
        2, {{ MOD1, KEY1 }, { MOD2, KEY2 }}, \
        spawn, {.v = CMD}                    \
    })

#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define KC(...) GET_MACRO(__VA_ARGS__, KC2, KC2, KC1)(__VA_ARGS__)

/* Helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL } }

/* Declared Commands */
static const char *termcmd[] = { TERMINAL, NULL};
static const char *browser[] = { BROWSER, NULL};
static const char *nmtui[] = { TERMINAL, "-e", "sudo", "nmtui", NULL};
static const char *newsboat[] = { TERMINAL, "-e", "newsboat", NULL};
static const char *ncmpcpp[] = { TERMINAL, "-e", "ncmpcpp ; pkill -RTMIN+6 dwmblocks", NULL};
static const char *tmux[] = { TERMINAL, "-e", "tmux-attach", NULL};
static const char *neovim[] = { TERMINAL, "-e", "nvim", NULL};
static const char *htop[] = { TERMINAL, "-e", "htop", NULL};
static const char *sysact[] = {"sysact", NULL};
static const char *togglekbd[] = {"kb-toggle", NULL};
static const char *toggleblur[] = {"toggleblur", NULL};
static const char *togglecrnr[] = {"togglecrnr", NULL};
static const char *dx2x[] = {"dx2x", NULL};
static const char *dmenuunicode[] = {"dmenuunicode", NULL};
static const char *pipertgpt[] = {"piper-tgpt", NULL};
static const char *wmreup[] = {"wmreup", NULL};
static const char *scratchbuf[] = { EMACSCLIENT, "-s", EMACS_SOCKET_NAME, "-c", "-n", "--alternate-editor=", "-f", "scratch-buffer", NULL};
static const char *primarypaste[] = {"xdotool", "click", "2", NULL};
static const char *bmpaste[] = {"bmpaste", NULL};
static const char *bmcommand[] = {"bmcommand", NULL};
static const char *vscreen[] = {"vscreen", NULL};
static const char *unswal[] = {"unswal", "1", NULL};
static const char *dmenurun[] = {"dmenu_run", NULL};
static const char *dmenurecord[] = {"dmenurecord", NULL};
static const char *scrncast[] = {"scrncast", NULL};
static const char *passmenu[] = {"passmenu", NULL};
static const char *camcast[] = {"camcast", NULL};
static const char *ewwbrowser[] = {"ewww-browse", "-d", NULL};
static const char *dsurfraw[] = {"dsurfraw", "-d", NULL};
static const char *dsryt[] = {"dsurfraw", "-d", "-e", "youtube", NULL};
static const char *dsrarchwiki[] = {"dsurfraw", "-d", "-e", "archwiki", NULL};
static const char *dsrghub[] = {"dsurfraw", "-d", "-e", "github", NULL};
static const char *dsrimdb[] = {"dsurfraw", "-d", "-e", "imdb", NULL};
static const char *dsrreddit[] = {"dsurfraw", "-d", "-e", "reddit", NULL};
static const char *dsrdiscog[] = {"dsurfraw", "-d", "-e", "discog", NULL};
static const char *dsrgglchrome[] = {"dsurfraw", "-d", "-e", "google", "chromium", NULL};
static const char *dsrddgtor[] = {"dsurfraw", "-d", "-e", "duckduckgo", "torbrowser-launcher", NULL};
static const char *ewwselprim[] = {"ewww-browse", "-p", NULL};
static const char *ewwselclip[] = {"ewww-browse", "-c", NULL};
static const char *ewwclip[]  = {"ewww-browse", "%CLIPBOARD%", NULL};
static const char *brave[] = {"brave", NULL};
static const char *chromium[] = {"chromium", "--kiosk", NULL};
static const char *firefox[] = {"firefox", "--kiosk", NULL};
static const char *qtbpriv[] = {"qutebrowser", "--target", "private-window", NULL};
static const char *rssadd[] = {"/bin/sh", "-c", "rssadd \"$(xclip -sel clipboard -o)\" || rssadd \"$(xclip -sel primary -o)\"", NULL};
static const char *sd[] = {"sd", NULL};                                  /* cwd terminal          */
static const char *yankmon[] = {"yankmon", "1", NULL};                   /* Monitor 1 (xclip)     */
static const char *xmouse[] = {"xmouse", NULL};                          /* xmouseless            */
static const char *linkclip[] = {"linkhandler", "%CLIPBOARD%", NULL};    /* clipboard linkhandler */
static const char *killrecording[] = {"dmenurecord", "kill", NULL};      /* kill active recording */
static const char *screenconf[] = {"screenconf", NULL};                  /* xrandr autoconf       */
static const char *boomer[] = {"boomer", NULL};                          /* zoomer app            */
static const char *mpcvoicesearch[] = {"mpc-voice-search", NULL};        /* mpc voice search      */
static const char *weztermyt[] = {"wezterm", "-e", "yazi", "~/Videos/yt", NULL};
static const char *screenkeys[] = {"/bin/sh", "-c", "killall screenkey || screenkey -M -s small -M -g 640x1550+1600+0 --opacity 0.6 --bak-mode full --mods-mode emacs", NULL};
static const char *calcurse[] = { TERMINAL, "-e", "calcurse", NULL};

/* Audio */
static const char *volumeup[] = {"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)", NULL};
static const char *togglemute[] = {"/bin/sh", "-c", "wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)", NULL};
static const char *volumedown[] = {"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)", NULL};
static const char *volumelower[] = {"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; kill -44 $(pidof dwmblocks)", NULL};
static const char *volumeraise[] = {"/bin/sh", "-c", "wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; kill -44 $(pidof dwmblocks)", NULL};
static const char *mpcnext[] = {"mpc", "next", NULL};
static const char *mpcprev[] = {"mpc", "prev",  NULL};
static const char *mpcrepeat[] = {"mpc", "repeat", NULL};
static const char *mpcstart[] = {"mpc", "seek",  "0%", NULL};
static const char *mpcseekback[] = {"mpc", "seek", "-10", NULL};
static const char *mpcseekrewind[] = {"mpc", "seek", "-60", NULL};
static const char *mpcseekfwd[] = {"mpc", "seek", "+10", NULL};
static const char *mpcseekforward[] = {"mpc", "seek", "+60", NULL};

static const char *monrotleft[] = {"/bin/sh", "-c", "xrandr --output eDP --rotate left && walfeh -reset", NULL};
static const char *monrotright[] = {"/bin/sh", "-c", "xrandr --output eDP --rotate right && walfeh -reset", NULL};
static const char *monrotinvert[] = {"/bin/sh", "-c", "xrandr --output eDP --rotate inverted && walfeh -reset", NULL};
static const char *monrotnormal[] = {"/bin/sh", "-c", "xrandr --output eDP --rotate normal && walfeh -reset", NULL};

static const char *swallowup[] = {"swallowup", NULL};
static const char *swallowdown[] = {"swallowdown", NULL};
static const char *swallowright[] = {"swallowright", NULL};
static const char *swallowleft[] = {"swallowleft", NULL};

static const char *kp0[] = {"kp0", NULL};
static const char *kp1[] = {"kp1", NULL};
static const char *kp2[] = {"kp2", NULL};
static const char *kp3[] = {"kp3", NULL};
static const char *kp4[] = {"kp4", NULL};
static const char *kp5[] = {"kp5", NULL};
static const char *kp6[] = {"kp6", NULL};
static const char *kp7[] = {"kp7", NULL};
static const char *kp8[] = {"kp8", NULL};
static const char *kp9[] = {"kp9", NULL};

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
    {"color0",           STRING,     &normbordercolor },
    {"color8",           STRING,     &selbordercolor },
    {"color0",           STRING,     &normbgcolor },
    {"color4",           STRING,     &normfgcolor },
    {"color0",           STRING,     &selfgcolor },
    {"color4",           STRING,     &selbgcolor },
    {"borderpx",         INTEGER,    &borderpx },
    {"snap",             INTEGER,    &snap },
    {"showbar",          INTEGER,    &showbar },
    {"topbar",           INTEGER,    &topbar },
    {"nmaster",          INTEGER,    &nmaster },
    {"resizehints",      INTEGER,    &resizehints },
    {"mfact",            FLOAT,      &mfact },
    {"gappih",           INTEGER,    &gappih },
    {"gappiv",           INTEGER,    &gappiv },
    {"gappoh",           INTEGER,    &gappoh },
    {"gappov",           INTEGER,    &gappov },
    {"swallowfloating",  INTEGER,    &swallowfloating },
    {"smartgaps",        INTEGER,    &smartgaps },
};

#include "shiftview.c"
#include <X11/XF86keysym.h>

static Keychord *keychords[] = {
    /* Stack --> [Super|Super+Shift] & Tags --> [1-9] workspaces [0] groups all windows from all workspaces */
    STACKKEYS(MODKEY, focus) STACKKEYS(MODKEY | ShiftMask, push)
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7) TAGKEYS(XK_9, 8)

    /* Keychord     modifier combos                     key           function       argument */
    &((Keychord){1, {{MODKEY,                           XK_0}},       view,          {.ui = ~0}}),
    &((Keychord){1, {{MODKEY|ShiftMask,                 XK_0}},       tag,           {.ui = ~0}}),

    &((Keychord){1, {{MODKEY|ShiftMask|ControlMask,     XK_q}},       quit,          {0}}),
    &((Keychord){1, {{MODKEY,                           XK_Tab}},     view,          {0}}),
    &((Keychord){1, {{Mod1Mask,                         XK_Tab}},     view,          {0}}),
    &((Keychord){1, {{MODKEY,                           XK_q}},       killclient,    {0}}),

    /* Increment Master-Clients  */
    &((Keychord){1, {{MODKEY,                           XK_o}},       incnmaster,    {.i = +1}}),
    &((Keychord){1, {{MODKEY|ShiftMask,                 XK_o}},       incnmaster,    {.i = -1}}),
    &((Keychord){1, {{MODKEY,                           XK_period}},  incnmaster,    {.i = -1}}),
    &((Keychord){1, {{MODKEY,                           XK_comma}},   incnmaster,    {.i = +1}}),

    /* Layouts Controls  s-[S,C]-[t,y,u,i,o]  */
    &((Keychord){1, {{MODKEY,             XK_t}},      setlayout,     {.v = &layouts[0]}}),  /* bstack */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_t}},      setlayout,     {.v = &layouts[1]}}),  /* tile */
    &((Keychord){1, {{MODKEY,             XK_y}},      setlayout,     {.v = &layouts[2]}}),  /* spiral */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_y}},      setlayout,     {.v = &layouts[3]}}),  /* dwindle */
    &((Keychord){1, {{MODKEY,             XK_u}},      setlayout,     {.v = &layouts[4]}}),  /* deck */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_u}},      setlayout,     {.v = &layouts[5]}}),  /* monocle */
    &((Keychord){1, {{MODKEY,             XK_i}},      setlayout,     {.v = &layouts[6]}}),  /* centeredmaster */
    &((Keychord){1, {{MODKEY|ControlMask, XK_i}},      setlayout,     {.v = &layouts[7]}}),  /* centeredfloatingmaster */
    &((Keychord){1, {{MODKEY|ControlMask, XK_t}},      setlayout,     {.v = &layouts[8]}}),  /* bstackhoriz */
    &((Keychord){1, {{MODKEY|ControlMask, XK_y}},      setlayout,     {.v = &layouts[9]}}),  /* grid */
    &((Keychord){1, {{MODKEY|ControlMask, XK_u}},      setlayout,     {.v = &layouts[10]}}), /* nrowgrid */
    &((Keychord){1, {{MODKEY|ControlMask, XK_i}},      setlayout,     {.v = &layouts[11]}}), /* horizgrid */
    &((Keychord){1, {{MODKEY|ControlMask, XK_o}},      setlayout,     {.v = &layouts[12]}}), /* gaplessgrid */
    &((Keychord){1, {{MODKEY,        XK_Escape}},      setlayout,     {.v = &layouts[13]}}), /* floating behaviour */

    /* Toggles */
    &((Keychord){1, {{MODKEY|ControlMask,   XK_space}},     zoom,           {0}}),
    &((Keychord){1, {{MODKEY,               XK_F12}},       togglefullscr,  {0}}),
    &((Keychord){1, {{MODKEY,               XK_f}},         togglefullscr,  {0}}),
    &((Keychord){1, {{MODKEY,               XK_f}},         togglebar,      {0}}),
    &((Keychord){1, {{MODKEY,               XK_b}},         togglebar,      {0}}),
    &((Keychord){1, {{MODKEY,               XK_s}},         togglesticky,   {0}}),
    &((Keychord){1, {{MODKEY,               XK_a}},         togglegaps,     {0}}),
    &((Keychord){1, {{MODKEY|ShiftMask,     XK_a}},         defaultgaps,    {0}}),
    &((Keychord){1, {{MODKEY|ShiftMask,     XK_space}},     togglefloating, {0}}),

    /* mfacts */
    &((Keychord){1, {{MODKEY,             XK_h}},   setmfact,   {.f = -0.05}}),
    &((Keychord){1, {{MODKEY,             XK_l}},   setmfact,   {.f = +0.05}}),

    /* cfacts */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_h}},   setcfact,   {.f = +0.05}}),
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_l}},   setcfact,   {.f = -0.05}}),
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_o}},   setcfact,   {.f =  0.00}}),

    /* Gap sizing */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_z}},  incrgaps,   {.i = -1}}),
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_x}},  incrgaps,   {.i = +1}}),

    /* Workspaces shifting */
    &((Keychord){1, {{MODKEY,               XK_g}},            shiftview,    {.i = -1}}),
    &((Keychord){1, {{MODKEY,               XK_semicolon}},    shiftview,    {.i =  1}}),
    &((Keychord){1, {{MODKEY|ShiftMask,     XK_g}},            shifttag,     {.i = -1}}),
    &((Keychord){1, {{MODKEY|ShiftMask,     XK_semicolon}},    shifttag,     {.i =  1}}),

    /* Transparency controls */
    &((Keychord){1, {{MODKEY|ControlMask,   XK_a}},   changefocusopacity,    {.f = +0.025}}),
    &((Keychord){1, {{MODKEY|ControlMask,   XK_s}},   changefocusopacity,    {.f = -0.025}}),
    &((Keychord){1, {{MODKEY|ControlMask,   XK_z}},   changeunfocusopacity,  {.f = +0.025}}),
    &((Keychord){1, {{MODKEY|ControlMask,   XK_x}},   changeunfocusopacity,  {.f = -0.025}}),

    /* MOD                             KEYS               CMD      */
    KC(MODKEY,                         XK_BackSpace,      sysact),
    KC(MODKEY|ShiftMask|ControlMask,   XK_BackSpace,      sysact),
    KC(MODKEY,                         XK_Return,         termcmd),
    KC(MODKEY|ShiftMask,               XK_Escape,         termcmd),
    KC(MODKEY|ShiftMask,               XK_q,              wmreup),
    KC(MODKEY|ShiftMask,               XK_r,              htop),
    KC(MODKEY|ShiftMask|ControlMask,   XK_w,              nmtui),
    KC(MODKEY|ShiftMask|ControlMask,   XK_space,          pipertgpt),
    KC(MODKEY|ShiftMask,               XK_grave,          dmenuunicode),
    KC(MODKEY,                         XK_space,          togglekbd),
    KC(MODKEY|ShiftMask|ControlMask,   XK_F12,            dx2x),
    KC(MODKEY|ControlMask,             XK_e,              scratchbuf),
    KC(Mod1Mask|ShiftMask,             XK_p,              primarypaste),
    KC(MODKEY|ShiftMask,               XK_Down,           unswal),
    KC(MODKEY|ControlMask,             XK_w,              camcast),
    KC(MODKEY,                         XK_d,              dmenurun),
    KC(MODKEY|ShiftMask,               XK_d,              passmenu),
    KC(MODKEY|ControlMask,             XK_p,              scrncast),
    KC(MODKEY|ControlMask|ShiftMask,   XK_Return,         dmenurecord),

    /* MOD1    KEY1  MOD2              KEY2                CMD    */
    KC(MODKEY, XK_x, MODKEY,           XK_v,               bmpaste),
    KC(MODKEY, XK_x, MODKEY,           XK_c,               bmcommand),
    KC(MODKEY, XK_x, MODKEY,           XK_s,               vscreen),

    /* ScratchPads */
    &((Keychord){1, {{MODKEY,             XK_r}},          togglescratch,   {.ui = 0}}), /* floatterm    */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_Return}},     togglescratch,   {.ui = 0}}),
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_c}},          togglescratch,   {.ui = 1}}),  /* bc -lq       */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_e}},          togglescratch,   {.ui = 2}}),  /* seledit      */
    &((Keychord){1, {{MODKEY,             XK_e}},          togglescratch,   {.ui = 5}}),  /* scratch-macs */
    &((Keychord){1, {{MODKEY,             XK_grave}},      togglescratch,   {.ui = 6}}),  /* eww-browser  */
    &((Keychord){1, {{MODKEY,             XK_backslash}},  togglescratch,   {.ui = 7}}),  /* elfeed-frame */
    &((Keychord){1, {{MODKEY,             XK_apostrophe}}, togglescratch,   {.ui = 8}}),  /* minibuffer   */
    &((Keychord){1, {{MODKEY|ControlMask, XK_i}},          togglescratch,   {.ui = 9}}),  /* xcurzui      */
    &((Keychord){1, {{MODKEY|ShiftMask,   XK_x}},          togglescratch,   {.ui = 20}}), /* tmux         */

    /* Emacs Popup Frames (cf-popup-frame.el) */
    &((Keychord){1, {{Mod1Mask, XK_F1}},   togglescratch,  {.ui = 10}}), /* Emc1  */
    &((Keychord){1, {{Mod1Mask, XK_F2}},   togglescratch,  {.ui = 11}}), /* Emc2  */
    &((Keychord){1, {{Mod1Mask, XK_F3}},   togglescratch,  {.ui = 12}}), /* Emc3  */
    &((Keychord){1, {{Mod1Mask, XK_F4}},   togglescratch,  {.ui = 13}}), /* Emc4  */
    &((Keychord){1, {{Mod1Mask, XK_F5}},   togglescratch,  {.ui = 14}}), /* Emc5  */
    &((Keychord){1, {{Mod1Mask, XK_F6}},   togglescratch,  {.ui = 15}}), /* Emc6  */
    &((Keychord){1, {{Mod1Mask, XK_F7}},   togglescratch,  {.ui = 16}}), /* Emc7  */
    &((Keychord){1, {{Mod1Mask, XK_F8}},   togglescratch,  {.ui = 17}}), /* Emc8  */
    &((Keychord){1, {{Mod1Mask, XK_F9}},   togglescratch,  {.ui = 18}}), /* Emc9  */
    &((Keychord){1, {{Mod1Mask, XK_F11}},  togglescratch,  {.ui = 19}}), /* Emc0  */

    /* WirePlumber Default Sink Volume Control */
    KC(MODKEY|ControlMask,   XK_m,       togglemute),
    KC(MODKEY,               XK_minus,   volumelower),
    KC(MODKEY,               XK_equal,   volumeup),
    KC(MODKEY|ShiftMask,     XK_minus,   volumedown),
    KC(MODKEY|ShiftMask,     XK_equal,   volumeraise),

    /* Contacts & Mail Apps */
    // &((Keychord){2, {{MODKEY, XK_e},{0, XK_e}},         spawn, SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook 2>/dev/null")}),
    // &((Keychord){2, {{MODKEY, XK_e},{ShiftMask, XK_e}}, spawn, SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook")}),

    /* Browser commands  (`mod-w' prefix):
     * mod-w prefix     MOD2         KEY2    CMD */
    KC(MODKEY, XK_w,    MODKEY,      XK_w,   browser),
    KC(MODKEY, XK_w,    0,           XK_e,   ewwbrowser),
    KC(MODKEY, XK_w,    MODKEY,      XK_e,   ewwbrowser),
    KC(MODKEY, XK_w,    0,           XK_c,   ewwclip),
    KC(MODKEY, XK_w,    MODKEY,      XK_b,   brave),
    KC(MODKEY, XK_w,    MODKEY,      XK_c,   chromium),
    KC(MODKEY, XK_w,    MODKEY,      XK_f,   firefox),
    KC(MODKEY, XK_w,    MODKEY,      XK_p,   qtbpriv),
    KC(MODKEY, XK_w,    0,           XK_p,   ewwselprim),
    KC(MODKEY, XK_w,    0,           XK_s,   ewwselclip),
    KC(MODKEY, XK_w,    0,           XK_r,   rssadd),
    KC(MODKEY, XK_w,    0,           XK_s,   dsurfraw),
    KC(MODKEY, XK_w,    0,           XK_y,   dsryt),
    KC(MODKEY, XK_w,    0,           XK_a,   dsrarchwiki),
    KC(MODKEY, XK_w,    0,           XK_f,   dsrghub),
    KC(MODKEY, XK_w,    0,           XK_d,   dsrdiscog),
    KC(MODKEY, XK_w,    0,           XK_r,   dsrreddit),
    KC(MODKEY, XK_w,    0,           XK_i,   dsrimdb),
    KC(MODKEY, XK_w,    0,           XK_g,   dsrgglchrome),
    KC(MODKEY, XK_w,    0,           XK_t,   dsrddgtor),

    /* Applications  */
    KC(MODKEY|ControlMask|ShiftMask, XK_b,     toggleblur),
    KC(MODKEY|ControlMask|ShiftMask, XK_c,     togglecrnr),
    KC(MODKEY|ControlMask|ShiftMask, XK_e,     sd),
    KC(MODKEY|ControlMask|ShiftMask, XK_h,     yankmon),
    KC(MODKEY|ControlMask|ShiftMask, XK_k,     xmouse),
    KC(MODKEY|ControlMask|ShiftMask, XK_l,     linkclip),
    KC(MODKEY|ControlMask|ShiftMask, XK_m,     ncmpcpp),
    KC(MODKEY|ControlMask|ShiftMask, XK_p,     killrecording),
    KC(MODKEY|ControlMask|ShiftMask, XK_t,     screenconf),
    KC(MODKEY|ControlMask|ShiftMask, XK_grave, mpcvoicesearch),
    KC(MODKEY|ControlMask|ShiftMask, XK_y,     weztermyt),
    KC(MODKEY|ControlMask|ShiftMask, XK_s,     screenkeys),
    KC(MODKEY|ShiftMask,             XK_n,     newsboat),
    KC(MODKEY, XK_c,         MODKEY, XK_c,     calcurse),
    KC(MODKEY|ControlMask,           XK_b,     boomer),
    KC(MODKEY|ControlMask,           XK_n,     neovim),
    KC(MODKEY|ControlMask,           XK_r,     tmux),

    /* Media controls */
    &((Keychord){1, {{MODKEY|ControlMask,    XK_m}},            spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)")}),
    &((Keychord){1, {{MODKEY|ControlMask,    XK_p}},            spawn, {.v = (const char *[]){"mpc", "toggle", NULL}}}),
    &((Keychord){1, {{MODKEY|ControlMask,    XK_bracketleft}},  spawn, {.v = (const char *[]){"mpc", "seek", "-10", NULL}}}),
    &((Keychord){1, {{MODKEY|ControlMask,    XK_bracketright}}, spawn, {.v = (const char *[]){"mpc", "seek", "+10", NULL}}}),

    /* Mod-alt-[u,i] monitor controls  */
    &((Keychord){1, {{MODKEY|Mod1Mask,           XK_i}}, focusmon, {.i = -1}}),
    &((Keychord){1, {{MODKEY|Mod1Mask,           XK_u}}, focusmon, {.i = +1}}),
    &((Keychord){1, {{MODKEY|Mod1Mask|ShiftMask, XK_i}}, tagmon,   {.i = -1}}),
    &((Keychord){1, {{MODKEY|Mod1Mask|ShiftMask, XK_u}}, tagmon,   {.i = +1}}),

    /* Super + Control + [left,right,up,down] to rotate monitor view */
    KC(MODKEY|ControlMask,      XK_Right,     monrotleft),
    KC(MODKEY|ControlMask,      XK_Left,      monrotright),
    KC(MODKEY|ControlMask,      XK_Up,        monrotinvert),
    KC(MODKEY|ControlMask,      XK_Down,      monrotnormal),

    /* Shift Workspaces */
    &((Keychord){1, {{MODKEY|ShiftMask, XK_period}},    shifttag,  {.i = -1}}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_comma}},     shifttag,  {.i = +1}}),
    &((Keychord){1, {{MODKEY,           XK_Page_Up}},   shiftview, {.i = -1}}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Page_Up}},   shifttag,  {.i = -1}}),
    &((Keychord){1, {{MODKEY,           XK_Page_Down}}, shiftview, {.i = +1}}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Page_Down}}, shifttag,  {.i = +1}}),

    /* Dynamic Swallows */
    KC(MODKEY, XK_Left,   swallowleft),
    KC(MODKEY, XK_Up,     swallowup),
    KC(MODKEY, XK_Right,  swallowright),
    KC(MODKEY, XK_Down,   swallowdown),

    &((Keychord){1, {{MODKEY|ShiftMask, XK_apostrophe}},  swalstopsel, {0}}),

    &((Keychord){2, {{MODKEY, XK_n}, {MODKEY, XK_n}}, spawn,    SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+6 dwmblocks")}),

    &((Keychord){1, {{MODKEY|ShiftMask, XK_b}},      spawn, {.v = (const char *[]){"bookmarkthis", NULL}}}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_s}},      spawn, SHCMD("xdotool type $(grep -v '^#' ~/Documents/Notes/snippets | dmenu -i -l 50 |cut -d' ' -f1)")}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Insert}}, spawn, SHCMD("xdotool type --delay 50 \"$(grep -v '^#' ~/Documents/Notes/bmcmd | dmenu -i -l 50 | cut -d' ' -f2-)\"")}),

    /* Super + [F1-F12] scripts and utilities */
    &((Keychord){1, {{MODKEY|ShiftMask,    XK_F1}},  spawn, SHCMD("playmuse")}),
    &((Keychord){2, {{MODKEY,XK_m}, {MODKEY,XK_m}},  spawn, SHCMD(TERMINAL " -e ncmpcpp")}),
    &((Keychord){1, {{MODKEY,               XK_F1}}, spawn, SHCMD("man -k . | dmenu -l 30 | awk '{print $1}' | xargs -r man -Tpdf | zathura -")}),
    &((Keychord){1, {{MODKEY,               XK_F2}}, spawn, SHCMD("tts -t \"$(xclip -selection clipboard -o)\"")}),
    &((Keychord){1, {{MODKEY|ShiftMask,     XK_F2}}, spawn, {.v = (const char *[]){"xcurzui", NULL}}}),
    &((Keychord){1, {{MODKEY,               XK_F3}}, spawn, {.v = (const char *[]){"displayselect", NULL}}}),
    &((Keychord){1, {{MODKEY,               XK_F4}}, spawn, SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)")}),
    &((Keychord){1, {{MODKEY,               XK_F5}}, xrdb,  {.v = NULL}}),
    &((Keychord){1, {{MODKEY,               XK_F6}}, spawn, {.v = (const char *[]){"torwrap", NULL}}}),
    &((Keychord){1, {{MODKEY,               XK_F7}}, spawn, {.v = (const char *[]){"td-toggle", NULL}}}),
    // &((Keychord){1, {{MODKEY,               XK_F8}},       spawn,    {.v = (const char *[]){"mailsync", NULL}}}),
    // &((Keychord){1, {{MODKEY,               XK_F8}},       spawn,    {.v = (const char *[]){"mkwinicon", NULL}}}),
    &((Keychord){1, {{MODKEY,               XK_F9}}, spawn, {.v = (const char *[]){"mounter", NULL}}}),
    &((Keychord){1, {{MODKEY,              XK_F10}}, spawn, {.v = (const char *[]){"unmounter", NULL}}}),
    &((Keychord){1, {{MODKEY,              XK_F11}}, spawn, {.v = (const char *[]){"mpvcam", NULL}}}),
    //  &((Keychord){1, {{MODKEY,               XK_F12}},      spawn,    {.v = (const char *[]){"remaps", NULL}}}),

    /* &((Keychord){2, {{ControlMask|MODKEY, XK_p}, {0,XK_p}},   spawn, SHCMD("shotgun -g $(hacksaw) $(date +%Y-%m-%d-%H%M-%S).png")}), */
    /* &((Keychord){1, {{ControlMask|ShiftMask, XK_p}},          spawn, SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png")}), */
    &((Keychord){1, {{0, XK_Print}},                spawn, SHCMD("mon_prntscrn")}),
    &((Keychord){1, {{Mod1Mask, XK_Print}},         spawn, {.v = (const char *[]){"flameshot", "gui", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_Print}},        spawn, {.v = (const char *[]){"maimpick", NULL}}}),
    &((Keychord){1, {{MODKEY, XK_Print}},           spawn, {.v = (const char *[]){"dmenurecord", NULL}}}),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_Print}}, spawn, {.v = (const char *[]){"dmenurecord", "kill", NULL}}}),
    &((Keychord){1, {{MODKEY, XK_Delete}},          spawn, {.v = (const char *[]){"dmenurecord", "kill", NULL}}}),
    /* &((Keychord){1, {{MODKEY, XK_space}},                     spawn, SHCMD("win_icons_align")}), */


    /* XF86 media/function keys */
    KC(0,        XF86XK_AudioNext,       mpcnext),
    KC(0,        XF86XK_AudioPrev,       mpcprev),
    KC(MODKEY,   XF86XK_AudioPlay,       mpcrepeat),
    KC(0,        XF86XK_AudioPlay,       mpcstart),
    KC(0,        XF86XK_AudioRewind,     mpcseekback),
    KC(MODKEY,   XF86XK_AudioRewind,     mpcseekrewind),
    KC(0,        XF86XK_AudioForward,    mpcseekfwd),
    KC(MODKEY,   XF86XK_AudioForward,    mpcseekforward),
    KC(0,        XF86XK_AudioMedia,      ncmpcpp),

    &((Keychord){1, {{0, XF86XK_AudioMute}},         spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)")}),
    &((Keychord){1, {{0, XF86XK_AudioRaiseVolume}},  spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%+; kill -44 $(pidof dwmblocks)")}),
    &((Keychord){1, {{0, XF86XK_AudioLowerVolume}},  spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%-; kill -44 $(pidof dwmblocks)")}),
    // &((Keychord){1, {{0, XF86XK_AudioPrev}},         spawn, {.v = (const char *[]){"mpc", "prev", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioNext}},         spawn, {.v = (const char *[]){"mpc", "next", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioPause}},        spawn, {.v = (const char *[]){"mpc", "pause", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioPlay}},         spawn, {.v = (const char *[]){"mpc", "play", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioStop}},         spawn, {.v = (const char *[]){"mpc", "stop", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioRewind}},       spawn, {.v = (const char *[]){"mpc", "seek", "-10", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioForward}},      spawn, {.v = (const char *[]){"mpc", "seek", "+10", NULL}}}),
    // &((Keychord){1, {{0, XF86XK_AudioMedia}},        spawn, {.v = (const char *[]){TERMINAL, "-e", "ncmpcpp", NULL}}}),
    &((Keychord){1, {{0, XF86XK_AudioMicMute}},      spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle")}),
    &((Keychord){1, {{0, XF86XK_Calculator}},        spawn, {.v = (const char *[]){TERMINAL, "-e", "bc", "-l", NULL}}}),
    &((Keychord){1, {{0, XF86XK_Sleep}},             spawn, {.v = (const char *[]){"sudo", "-A", "zzz", NULL}}}),
    &((Keychord){1, {{0, XF86XK_WWW}},               spawn, {.v = (const char *[]){BROWSER, NULL}}}),
    &((Keychord){1, {{0, XF86XK_DOS}},               spawn, {.v = termcmd}}),
    &((Keychord){1, {{0, XF86XK_ScreenSaver}},       spawn, SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv")}),
    &((Keychord){1, {{0, XF86XK_TaskPane}},          spawn, {.v = (const char *[]){TERMINAL, "-e", "htop", NULL}}}),
    &((Keychord){1, {{0, XF86XK_Mail}},              spawn, SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks")}),
    &((Keychord){1, {{0, XF86XK_MyComputer}},        spawn, {.v = (const char *[]){TERMINAL, "-e", "lfub", "/", NULL}}}),
    &((Keychord){1, {{0, XF86XK_Launch1}},           spawn, {.v = (const char *[]){"xset", "dpms", "force", "off", NULL}}}),
    &((Keychord){1, {{0, XF86XK_TouchpadToggle}},    spawn, SHCMD("togglepad")}),
    &((Keychord){1, {{0, XF86XK_TouchpadOff}},       spawn, {.v = (const char *[]){"synclient", "TouchpadOff=1", NULL}}}),
    &((Keychord){1, {{0, XF86XK_TouchpadOn}},        spawn, {.v = (const char *[]){"synclient", "TouchpadOff=0", NULL}}}),
    &((Keychord){1, {{0, XF86XK_MonBrightnessUp}},   spawn, SHCMD("bright 12")}),
    &((Keychord){1, {{0, XF86XK_MonBrightnessDown}}, spawn, SHCMD("bright -12")}),

    /*                 Shift + [F1-F12]           for handy scripts and utilities */
    &((Keychord){1, {{ShiftMask, XK_F1}},  spawn, {.v = (const char *[]){"linkhandler", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F2}},  spawn, {.v = (const char *[]){"killall", "pacat", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F3}},  spawn, {.v = (const char *[]){"readit", "-c", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F4}},  spawn, {.v = (const char *[]){"walfeh", "-backward", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F5}},  spawn, {.v = (const char *[]){"walfeh", "-toggle", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F6}},  spawn, {.v = (const char *[]){"walfeh" , "-forward", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F7}},  spawn, {.v = (const char *[]){"toggleblur", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F8}},  spawn, {.v = (const char *[]){"yankmon", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F9}},  spawn, {.v = (const char *[]){"sd", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F10}}, spawn, {.v = (const char *[]){"redunst", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F11}}, spawn, {.v = (const char *[]){"cavabar", NULL}}}),
    &((Keychord){1, {{ShiftMask, XK_F12}}, spawn, {.v = (const char *[]){"remaps", NULL}}}),

    /* &((Keychord){1, {{0, XK_F1}},      spawn, {.v = (const char *[]){"linkhandler", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F2}},      spawn, {.v = (const char *[]){"pkill", "piper-tts", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F3}},      spawn, {.v = (const char *[]){"mpctl", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F4}},      spawn, {.v = (const char *[]){"mpc", "prev", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F5}},      spawn, {.v = (const char *[]){"mpctl", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F6}},      spawn, {.v = (const char *[]){"mpc", "next", NULL}}}), */
    /* &((Keychord){2, {{0, XK_F7}},      spawn, {.v = (const char *[]){"playmuse", NULL}}}), */
    /* &((Keychord){2, {{0, XK_F8}},      spawn, {.v = (const char *[]){"mpc-voice-search", NULL}}}), */
    /* &((Keychord){1, {{0, XK_F11}},     spawn, {.v = (const char *[]){"yankzp", NULL}}}), */
    &((Keychord){1, {{0, XK_F9}},  spawn, {.v = (const char *[]){"togglepad", NULL}}}),
    &((Keychord){1, {{0, XK_F10}}, spawn, {.v = (const char *[]){"unswal", "1", NULL}}}),
    &((Keychord){1, {{0, XK_F12}}, spawn, {.v = (const char *[]){"redunst", NULL}}}),
    &((Keychord){2, {{Mod1Mask, XK_F7}, {0, XK_F7}}, spawn, {.v = (const char *[]){"playmuse", NULL}}}),
    &((Keychord){2, {{Mod1Mask, XK_F8}, {0, XK_F8}}, spawn, {.v = (const char *[]){"mpc-voice-search", NULL}}}),

    /*                 Ctrl + [F1-F12]                    for scripts and utilities */
    &((Keychord){1, {{ControlMask, XK_F1}},               spawn,  {.v = (const char *[]){"cliplink", NULL}}}),
    &((Keychord){1, {{ControlMask, XK_F2}},               spawn,  {.v = (const char *[]){"primarylink", NULL}}}),
    &((Keychord){1, {{ControlMask, XK_F3}},               spawn,  {.v = (const char *[]){"mpv", "-quiet", "/home/cf/.cache/mpvq/mpvq.m3u8", NULL}}}),
    &((Keychord){1, {{ControlMask, XK_F4}},               togglescratch,  {.ui = 3}}),  /* mpvqdl  */
    &((Keychord){1, {{ControlMask, XK_F5}},               spawn,  {.v = (const char *[]){"mpv_ipc", NULL}}}),
    &((Keychord){1, {{ControlMask, XK_F6}},               togglescratch,  {.ui = 4}}),  /* mpvqfzf */
    &((Keychord){1, {{ControlMask, XK_F7}},               togglescratch,  {.ui = 2}}),  /* seledit */
    &((Keychord){1, {{ControlMask, XK_F8}},               togglescratch,  {.ui = 6}}),  /* ewwwbrw */
    &((Keychord){1, {{ControlMask, XK_F9}},               togglescratch,  {.ui = 5}}),  /* ewwwbrw */
    &((Keychord){1, {{ControlMask, XK_F9}},               togglescratch,  {.ui = 7}}),  /* floatmp */
    &((Keychord){1, {{ControlMask, XK_F10}},              togglescratch,  {.ui = 8}}),  /* orgnote */
    &((Keychord){1, {{ControlMask, XK_F11}},              spawn,  {.v = (const char *[]){"maimpick", NULL}}}),
    &((Keychord){1, {{ControlMask, XK_F12}},              spawn,  {.v = (const char *[]){"xkill", NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F1}},     spawn,  {.v = (const char *[]){"cliplink", NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F2}},     spawn,  {.v = (const char *[]){EMACS, NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F3}},     spawn,  {.v = (const char *[]){"mpvqfzf", "play", NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F4}},     spawn,  {.v = (const char *[]){"mpvq", "dnd", NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F5}},     spawn,  {.v = (const char *[]){"mpvqls", NULL}}}),
    &((Keychord){1, {{ControlMask|ShiftMask, XK_F6}},     spawn,  {.v = (const char *[]){"mpvq", "next", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F7}},     spawn,  {.v = (const char *[]){"vcn", "eDP", "1", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F8}},     spawn,  {.v = (const char *[]){"vcn", "DisplayPort-2", "2", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F9}},     spawn,  {.v = (const char *[]){"vcn", "eDP", "3", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F10}},    spawn,  {.v = (const char *[]){"vcn", "DisplayPort-2", "4", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F11}},    spawn,  {.v = (const char *[]){"vcn", "eDP", "5", NULL}}}),
    // &((Keychord){1, {{ControlMask|ShiftMask, XK_F12}},    spawn,  {.v = (const char *[]){"vcn", "DisplayPort-2", "6", NULL}}}),

    /* Single       Ctrl + Keypad [0-9]                          script testenv */
    // &((Keychord){1, {{ControlMask, XK_KP_Insert}},        spawn, {.v = (const char *[]){"kp0", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_End}},           spawn, {.v = (const char *[]){"kp1", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Down}},          spawn, {.v = (const char *[]){"kp2", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Page_Down}},     spawn, {.v = (const char *[]){"kp3", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Left}},          spawn, {.v = (const char *[]){"kp4", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Begin}},         spawn, {.v = (const char *[]){"kp5", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Right}},         spawn, {.v = (const char *[]){"kp6", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Home}},          spawn, {.v = (const char *[]){"kp7", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Up}},            spawn, {.v = (const char *[]){"kp8", NULL}}}),
    // &((Keychord){1, {{ControlMask, XK_KP_Page_Up}},       spawn, {.v = (const char *[]){"kp9", NULL}}}),

    /* ctrl prefix  keypad [0-9]     kpsc */
    KC(ControlMask, XK_KP_Insert,    kp0),
    KC(ControlMask, XK_KP_End,       kp1),
    KC(ControlMask, XK_KP_Down,      kp2),
    KC(ControlMask, XK_KP_Page_Down, kp3),
    KC(ControlMask, XK_KP_Left,      kp4),
    KC(ControlMask, XK_KP_Begin,     kp5),
    KC(ControlMask, XK_KP_Right,     kp6),
    KC(ControlMask, XK_KP_Home,      kp7),
    KC(ControlMask, XK_KP_Up,        kp8),
    KC(ControlMask, XK_KP_Page_Up,   kp9),

    // &((Keychord){2, {{MODKEY, XK_x}, {0, XK_c}},          spawn, SHCMD("prim2clip")}),
    // &((Keychord){2, {{MODKEY, XK_x}, {0, XK_a}},          spawn, SHCMD("clip2prim")}),
    // &((Keychord){2, {{MODKEY, XK_x}, {0, XK_x}},          spawn, SHCMD("clip2sel")}),
    // &((Keychord){2, {{MODKEY, XK_x}, {0, XK_x}},          spawn, SHCMD("xsel -xk")}),
    // &((Keychord){2, {{MODKEY, XK_x}, {0, XK_d}},          spawn, SHCMD("xsel -d")}),

    /* Tests de manipulations par XSelection */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {0, XK_r}},              spawn,          SHCMD("echo \"$(xclip -o)\" >> ~/Notes/clipregisters/r")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {ControlMask, XK_r}},    spawn,          SHCMD("echo \"\" > ~/Notes/clipregisters/r")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {0, XK_a}},              spawn,          SHCMD("echo \"$(xclip -o)\" > ~/Notes/clipregisters/a")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {ControlMask, XK_a}},    spawn,          SHCMD("echo \"\" > ~/Notes/clipregisters/a")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {0, XK_s}},              spawn,          SHCMD("echo \"$(xclip -o)\" >> ~/Notes/clipregisters/s")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {ControlMask, XK_s}},    spawn,          SHCMD("echo \"\" > ~/Notes/clipregisters/s")}), */
    /* &((Keychord){2, {{Mod1Mask,XK_c}, {0, XK_d}},              spawn,          SHCMD("echo \"$(xclip -selection secondary -o)\" > ~/Notes/clipregisters/a")}), */

    /* Lecture des registres */
    /* &((Keychord){1, {{MODKEY|ShiftMask|ControlMask, XK_r}},    spawn,          SHCMD("cat ~/Notes/clipregisters/r | tts")}), */
    /* &((Keychord){1, {{MODKEY|ShiftMask|ControlMask, XK_a}},    spawn,          SHCMD("cat ~/Notes/clipregisters/a | tts -m en_US-libritts-high")}), */
    /* &((Keychord){1, {{MODKEY|ShiftMask|ControlMask, XK_s}},    spawn,          SHCMD("cat ~/Notes/clipregisters/s | tts")}), */

    /*  unused gap keybinds  */
    /* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
    /* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
    /* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
    /* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
    /* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
    /* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
    /* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
    /* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
    /* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
};

static const Button buttons[] = {
/* button definitions click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
#ifndef __OpenBSD__
    /* click         event mask              button          function                argument */
    { ClkWinTitle,   0,                      Button2,        zoom,                   {0}},
    { ClkStatusText, 0,                      Button1,        sigdwmblocks,           {.i = 1}},
    { ClkStatusText, 0,                      Button2,        sigdwmblocks,           {.i = 2}},
    { ClkStatusText, 0,                      Button3,        sigdwmblocks,           {.i = 3}},
    { ClkStatusText, 0,                      Button4,        sigdwmblocks,           {.i = 4}},
    { ClkStatusText, 0,                      Button5,        sigdwmblocks,           {.i = 5}},
    { ClkStatusText, ShiftMask,              Button1,        sigdwmblocks,           {.i = 6}},
#endif
    { ClkWinTitle,   0,                      Button1,        zoom,                   {0}},
    { ClkWinTitle,   0,                      Button2,        togglefloating,         {0}},
    { ClkWinTitle,   0,                      Button3,        togglesticky,           {0}},
    { ClkWinTitle,   0,                      Button4,        spawn,                  SHCMD("xdotool key --clearmodifiers super+j")},
    { ClkWinTitle,   0,                      Button5,        spawn,                  SHCMD("xdotool key --clearmodifiers super+k")},
    { ClkWinTitle,   Mod1Mask,               Button4,        spawn,                  SHCMD("xdotool key --clearmodifiers super+shift+j")},
    { ClkWinTitle,   Mod1Mask,               Button5,        spawn,                  SHCMD("xdotool key --clearmodifiers super+shift+k")},
    { ClkWinTitle,   ControlMask,            Button1,        togglegaps,             {0}},
    { ClkWinTitle,   ControlMask,            Button2,        shiftview,              {0}},
    { ClkWinTitle,   ControlMask,            Button3,        spawn,                  {.v = (const char *[]){"sysact", NULL}}},
    { ClkWinTitle,   ControlMask,            Button4,        incrgaps,               {.i = -1}},
    { ClkWinTitle,   ControlMask,            Button5,        incrgaps,               {.i =  1}},
    { ClkLtSymbol,   0,                      Button1,        spawn,                  SHCMD(TERMINAL " -e fzf-cmd-menu")},
    { ClkLtSymbol,   0,                      Button2,        spawn,                  SHCMD("dmenu_run")},
    { ClkLtSymbol,   0,                      Button3,        spawn,                  SHCMD("emacsclient -s $EMACS_SOCKET_NAME -e \"(cf-window-popup-org-capture)\"")},
    { ClkStatusText, ShiftMask,              Button3,        spawn,                  SHCMD(TERMINAL " -e $EDITOR ~/Templates/dwmblocks/blocks.h")},
    { ClkClientWin,  MODKEY,                 Button1,        movemouse,              {0}},
    { ClkClientWin,  MODKEY,                 Button2,        togglefloating,         {0}},
    { ClkClientWin,  MODKEY,                 Button3,        resizemouse,            {0}},
    { ClkClientWin,  ShiftMask,              Button1,        resizemouse,            {.i = 1}},
    { ClkClientWin,  ControlMask,            Button1,        movemouse,              {0}},
    { ClkClientWin,  ControlMask|ShiftMask,  Button1,        resizemouse,            {0}},
    { ClkClientWin,  ShiftMask,              Button3,        shifttag,               {.i = 1}},
    { ClkClientWin,  ControlMask,            Button2,        togglefloating,         {0}},
    { ClkClientWin,  ControlMask,            Button3,        zoom,                   {0}},
    { ClkClientWin,  ControlMask,            Button4,        setmfact,               {.f = -0.05}},
    { ClkClientWin,  ControlMask,            Button5,        setmfact,               {.f = +0.05}},
    { ClkClientWin,  Mod1Mask|ShiftMask,     Button4,        spawn,                  SHCMD("xdotool key --clearmodifiers super+shift+j")},
    { ClkClientWin,  Mod1Mask|ShiftMask,     Button5,        spawn,                  SHCMD("xdotool key --clearmodifiers super+shift+k")},
    { ClkClientWin,  Mod1Mask|ControlMask,   Button4,        setcfact,               {.f = -0.05}},
    { ClkClientWin,  Mod1Mask|ControlMask,   Button5,        setcfact,               {.f = +0.05}},
    { ClkClientWin,  MODKEY,                 Button5,        changefocusopacity,     {.f = -0.025}},
    { ClkClientWin,  MODKEY,                 Button4,        changefocusopacity,     {.f = +0.025}},
    { ClkClientWin,  MODKEY|ShiftMask,       Button4,        changeunfocusopacity,   {.f = +0.025}},
    { ClkClientWin,  MODKEY|ShiftMask,       Button5,        changeunfocusopacity,   {.f = -0.025}},
    { ClkClientWin,  MODKEY|ShiftMask,       Button1,        swalmouse,              {0}},
    { ClkClientWin,  MODKEY|ControlMask,     Button1,        shifttag,               {.i = -1}},
    { ClkClientWin,  MODKEY|ControlMask,     Button2,        shifttag,               {.i =  1}},
    { ClkTagBar,     0,                      Button1,        view,                   {0}},
    { ClkTagBar,     0,                      Button3,        toggleview,             {0}},
    { ClkTagBar,     MODKEY,                 Button1,        tag,                    {0}},
    { ClkTagBar,     MODKEY,                 Button3,        toggletag,              {0}},
    { ClkTagBar,     0,                      Button4,        shiftview,              {.i = -1}},
    { ClkTagBar,     0,                      Button5,        shiftview,              {.i =  1}},
    { ClkRootWin,    0,                      Button1,        togglescratch,          {.ui = 0}},
    { ClkRootWin,    0,                      Button2,        togglebar,              {0}},
    { ClkRootWin,    0,                      Button3,        spawn,                  SHCMD("eaglemode")},
    { ClkRootWin,    MODKEY,                 Button4,        spawn,                  SHCMD("walfeh -prev")},
    { ClkRootWin,    MODKEY,                 Button5,        spawn,                  SHCMD("walfeh -next")},
    { ClkRootWin,    ShiftMask,              Button1,        shiftview,              {.i =  1}},
    { ClkRootWin,    ShiftMask,              Button2,        shiftview,              {.i = -1}},
};
