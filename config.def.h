/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >1: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >1: systray on left of status text */
static const unsigned int systrayspacing = 6;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int user_bh            = 30;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int topbar             = 1;        /* 0 means bottom bar */
#define ICONSIZE 16   /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const unsigned int baralpha = 0xD9;
static const unsigned int borderalpha = OPAQUE;
//static const int usealtbar          = 1;        /* 1 means use non-dwm bar */
//static const char *altbarclass = "Polybar";     /* Alternate bar class name */
//static const char *altbarcmd  = "sh $HOME/.config/polyar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = {"siji:size=14",  /* For Iconic Glyphs */
                                       "notosans nerd font:size=13"}; /* For Normal Text */
static const char dmenufont[]       = "notosans nerd font:size=14";
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
    //Normal        fg:#bbbbbb  bg:#212121 border:#404040
	[SchemeSel]  = { col_gray4, col_gray0, col_gray7 },
    //Active        fg:#efefef  bg:#404040 border:#777777
	[SchemeHid]  = { col_gray3, col_gray6, col_gray0  },
    //Hidden        fg:#bbbbbb  bg:#171717 border:#404040
	// [SchemeSystray] = { col_gray3, col_gray1, col_gray0 },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeHid]  = { OPAQUE, baralpha, borderalpha },
	// [SchemeSystray]  = { baralpha, baralpha, baralpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", ""};

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
	{ "Alacritty",  NULL,       "DWM Key Bindings", 0,         0,             1,           -1 },
	{ "discord",    NULL,       NULL,       1<<1,              1,             0,           -1 },
	{ "zoom",       NULL,       NULL,       1<<1,              1,             0,           -1 },
	{ "Microsoft Teams - Preview", NULL, NULL, 1<<1,           1,             0,           -1 },
	{ "Spotify",    NULL,       NULL,       1<<2,              1,             0,           -1 },
	{ "Gimp",       NULL,       NULL,       1<<3,              1,             0,           -1 },
	{ "Substance Painter", NULL, NULL,      1<<3,              1,             0,           -1 },
	{ "Substance Designer", NULL, NULL,     1<<3,              1,             0,           -1 },
	{ "Substance Architect", NULL, NULL,    1<<3,              1,             0,           -1 },
	{ "Steam",      NULL,       NULL,       1<<5,              1,             0,           -1 },
	{ "ftb-app",    NULL,       NULL,       1<<5,              1,             0,           -1 },
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

#include "keybindings-colemak.h"
