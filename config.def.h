/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int baralpha = 0xF2;
static const unsigned int borderalpha = OPAQUE;
//static const int usealtbar          = 1;        /* 1 means use non-dwm bar */
//static const char *altbarclass = "Polybar";     /* Alternate bar class name */
//static const char *altbarcmd  = "sh $HOME/.config/polyar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "notosans nerd font:size=10.5" };
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
	{ " |-",      tile },    /* first entry is default */
	{ "< >",     NULL },    /* no layout function means floating behavior */
	{ "[M]",    monocle },
	{ "|┼|",      grid },
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
static const char *termTabbedCMD[]  = { "tabbed","-r","2","alacritty","--embed","\"\"", NULL };
static const char *termAltCMD[]  = { "/usr/bin/kitty", NULL };
static const char *rofiCMD[] = { "rofi", "-show","drun","-show-icons", NULL };
static const char *browserCMD[]  = { "/usr/bin/brave", "%U", NULL };
static const char *youtubeCMD[]  = { "/usr/bin/brave", "https://www.youtube.com", NULL };
static const char *fileExplorerCMD[]  = { "/usr/bin/pcmanfm", NULL };
static const char *pavucontrolCMD[]  = { "/usr/bin/pavucontrol", NULL };
static const char *spotifyCMD[]  = { "/usr/bin/spotify", NULL };
static const char *discordCMD[]  = { "/usr/bin/discord", NULL };
static const char *zoomCMD[]  = { "/usr/bin/zoom", NULL };
static const char *fullScreenshotCMD[]  = { "/home/mia/.config/.system/fullScreenshot.sh", NULL };
static const char *curWindowScreenshotCMD[]  = { "/home/mia/.config/.system/curWindowScreenshot.sh", NULL };
static const char *todoListCMD[] = { "kitty","-e","/home/mia/OneDrive/CodeWorkspace/Scripts/todo", NULL };
static const char *canvasCMD[] = { "/usr/bin/brave", "https://canvas.ewu.edu/", NULL};

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod1Mask,                     XK_space,  spawn,          {.v = rofiCMD } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = termTabbedCMD } },
	{ MODKEY|ControlMask|ShiftMask, XK_Return, spawn,          {.v = termAltCMD } },
	{ MODKEY|Mod1Mask,              XK_space,  spawn,          {.v = browserCMD } },
	{ MODKEY|Mod1Mask,              XK_Return, spawn,          {.v = canvasCMD } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = todoListCMD } },
	{ MODKEY,                       XK_s,      spawn,          {.v = spotifyCMD } },
	{ MODKEY,                       XK_z,      spawn,          {.v = zoomCMD } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = youtubeCMD } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = fileExplorerCMD } },
	{ MODKEY,                       XK_F3,     spawn,          SHCMD("/home/mia/Security/autovpn") },
	{ MODKEY,                       XK_F4,     spawn,          {.v = discordCMD } },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = pavucontrolCMD } },
	{ 0,                            XK_Print,  spawn,          {.v = fullScreenshotCMD } },
	{ MODKEY,                       XK_Print,  spawn,          {.v = curWindowScreenshotCMD } },
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          SHCMD("/home/mia/.config/.system/selectionScreenshot.sh") },
    { 0,                            XF86XK_AudioLowerVolume, spawn, SHCMD("volume-down") },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, SHCMD("volume-up") },
	{ 0,                            XF86XK_AudioMute, spawn,    SHCMD("pamixer -t; volume-notify") },
	{ MODKEY,                       XK_F9,     spawn,           SHCMD("pamixer -t; volume-notify") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|Mod1Mask,              XK_h,      shiftviewtag,   {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_l,      shiftviewtag,   {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
   	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	/*TAGKEYS(                        XK_9,                      8)*/
	{ MODKEY|ShiftMask,             XK_Escape, spawn,         SHCMD("/home/mia/.config/.system/sysmenu") },
	{ ControlMask|ShiftMask,        XK_Escape,      quit,     {0} },
};

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
