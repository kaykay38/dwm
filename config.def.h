/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int baralpha = 0xCC;
static const unsigned int borderalpha = OPAQUE;
//static const int usealtbar          = 1;        /* 1 means use non-dwm bar */
//static const char *altbarclass = "Polybar";     /* Alternate bar class name */
//static const char *altbarcmd  = "sh $HOME/.config/polyar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = {"siji:size=13",  /* For Iconic Glyphs */
                                       "notosans nerd font:size=11"}; /* For Normal Text */
static const char dmenufont[]       = "notosans nerd font:size=10.5";
static const char col_gray0[]       = "#393939";
static const char col_gray1[]       = "#212121";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_gray5[]       = "#636363";
//static const char col_gray6[]       = "#2d2d2d"; //border?
//static const char col_urgent1[]       ="#c9695f";
//static const char col_urgent2[]       ="#d14434";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray0 },
	[SchemeSel]  = { col_gray4, col_gray0, col_gray5 },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "","", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
                                            // tag mask= 3 = (1<<2) the tag/workspace the window will spawn
	/* class      instance    title        tags            switchtotag        floating   monitor */
	{ "Gcolor",     NULL,       NULL,       0,                 0,             1,           -1 },
	{ "Gcr-prompter", NULL,     NULL,       0,                 0,             1,           -1 },
	{ "Pavucontrol",NULL,       NULL,       0,                 0,             1,           -1 },
	{ "kitty",      NULL,       NULL,       0,                 0,             1,           -1 },
	{ "Gimp",       NULL,       NULL,       1<<3,              1,             0,           -1 },
	{ "Spotify",    NULL,       NULL,       1<<4,              1,             0,           -1 },
	{ "discord",    "discord",  NULL,       1<<2,              1,             0,           -1 },
	{ "zoom",       NULL,       NULL,       1<<2,              1,             0,           -1 },
	{ "Microsoft Teams - Preview", NULL, NULL, 1<<2,           1,             0,           -1 },
	{ "Steam",      NULL,       NULL,       1<<6,              1,             0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",     tile },    /* first entry is default */
	{ "",     NULL },    /* no layout function means floating behavior */
	{ "",     monocle },
	{ "",     grid }, /**/
	{ NULL,      NULL },
};

/* key definitions */
//#define MODKEY Mod1Mask // Mod1Mask=ALT DEFAULT SETTING
#define MODKEY Mod4Mask // Mod4Mask=Windows/Super key 
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_gray0, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "/usr/bin/alacritty", NULL };
static const char *termTabbedCMD[]  = { "tabbed","-c","-r","2","alacritty","--embed","\"\"", NULL };
static const char *termAltCMD[]  = { "/usr/bin/kitty", NULL };
static const char *rofiCMD[] = { "rofi", "-show","drun","-show-icons", NULL };
static const char *rofiRunCMD[] = { "rofi", "-show","run", NULL };
static const char *browserCMD[]  = { "/usr/bin/brave", "%U", NULL };
static const char *youtubeCMD[]  = { "/usr/bin/brave", "https://www.youtube.com", NULL };
static const char *fileExplorerCMD[]  = { "/usr/bin/pcmanfm", NULL };
static const char *pavucontrolCMD[]  = { "/usr/bin/pavucontrol", NULL };
static const char *spotifyCMD[]  = { "/usr/local/bin/spotify", NULL };
static const char *spotifyInfoCMD[]  = { "/usr/local/bin/spotify-song-info", NULL };
static const char *discordCMD[]  = { "/usr/bin/discord", NULL };
static const char *zoomCMD[]  = { "/usr/bin/zoom", NULL };
static const char *fullScreenshotCMD[]  = { "/home/mia/.config/.system/fullScreenshot.sh", NULL };
static const char *curWindowScreenshotCMD[]  = { "/home/mia/.config/.system/curWindowScreenshot.sh", NULL };
/* static const char *todoListCMD[] = { "kitty","-e","/home/mia/OneDrive/CodeWorkspace/Scripts/todo", NULL }; */
static const char *canvasCMD[] = { "/usr/bin/brave", "https://canvas.ewu.edu/", NULL};
static const char *dualMonitorCMD[]  = { "dual-vertical-left-monitor", NULL };
static const char *greenclipCMD[] = { "rofi", "-modi","'Clipboard:greenclip print'","-show","Clipboard","-run-command","'{cmd}'", NULL};

#include "keybindings.h"

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
