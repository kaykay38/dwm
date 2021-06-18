/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 6;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int baralpha = 0xD9;
static const unsigned int borderalpha = OPAQUE;
//static const int usealtbar          = 1;        /* 1 means use non-dwm bar */
//static const char *altbarclass = "Polybar";     /* Alternate bar class name */
//static const char *altbarcmd  = "sh $HOME/.config/polyar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = {"siji:size=13",  /* For Iconic Glyphs */
                                       "notosans nerd font:size=11"}; /* For Normal Text */
static const char dmenufont[]       = "notosans nerd font:size=10.5";
static const char col_gray0[]       = "#404040";
static const char col_gray1[]       = "#212121";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#efefef";
static const char col_gray5[]       = "#636363";
static const char col_gray6[]       = "#171717";
static const char col_gray7[]       = "#777777";
//static const char col_urgent1[]       ="#c9695f";
static const char col_urgent2[]       ="#d14434";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray0 },
	[SchemeSel]  = { col_gray4, col_gray0, col_gray7 },
	/* [SchemeHid]  = { col_gray3, col_gray6, col_gray0  }, */
	/* [SchemeSystray] = { col_gray3, col_gray1, col_gray1 }, */
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	/* [SchemeHid]  = { OPAQUE, baralpha, borderalpha }, */
	/* [SchemeSystray]  = { baralpha, baralpha, baralpha }, */
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
	{ "Alacritty",  NULL,       "DWM Key Bindings",       0,                 0,             1,           -1 },
	{ "Gimp",       NULL,       NULL,       1<<3,              1,             0,           -1 },
	{ "Spotify",    NULL,       NULL,       1<<4,              1,             0,           -1 },
	{ "discord",    NULL,       NULL,       1<<2,              1,             0,           -1 },
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

#include "keybindings.h"
