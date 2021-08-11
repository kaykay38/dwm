/* KEY BINDINGS */

#include <X11/XF86keysym.h>

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
static const char *rofiWindowCMD[] = { "rofi", "-show","window", "-show-icons", NULL };
static const char *browserCMD[]  = { "/usr/bin/brave", "%U", NULL };
static const char *youtubeCMD[]  = { "/usr/bin/brave", "https://www.youtube.com", NULL };
static const char *fileExplorerCMD[]  = { "/usr/bin/pcmanfm", NULL };
static const char *pavucontrolCMD[]  = { "/usr/bin/pavucontrol", NULL };
static const char *spotifyCMD[]  = { "spotify", NULL };
static const char *playerctlInfoCMD[]  = { "/usr/local/bin/playerctl-info", NULL };
static const char *discordCMD[]  = { "/usr/bin/discord", NULL };
static const char *zoomCMD[]  = { "/usr/bin/zoom", NULL };
static const char *fullScreenshotCMD[]  = { "/home/mia/.config/.system/fullScreenshot.sh", NULL };
static const char *curWindowScreenshotCMD[]  = { "/home/mia/.config/.system/curWindowScreenshot.sh", NULL };
/* static const char *selectionScreenshotCMD[]  = { "/home/mia/.config/.system/selectionScreenshot.sh", NULL }; */
/* static const char *todoListCMD[] = { "kitty","-e","/home/mia/OneDrive/CodeWorkspace/Scripts/todo", NULL }; */
static const char *canvasCMD[] = { "/usr/bin/brave", "https://canvas.ewu.edu/", NULL};
static const char *dualMonitorCMD[]  = { "dual-vertical-left-monitor", NULL };

/* key definitions */
#define ALT Mod1Mask // Mod1Mask=ALT DEFAULT SETTING
#define MODKEY Mod4Mask // Mod4Mask=Windows/Super key 
// MOD = Super/Windows Key
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                     key        function        argument    */
    { MODKEY,              		    XK_s,      spawn,          SHCMD("/usr/local/bin/dwmkeybindings")},
	//utility,       MOD + s,                          show dwm key bindings
	{ MODKEY|ALT,              		XK_p,      spawn,          {.v = dmenucmd } },
	//utility,       MOD + Alt + p,                    dmenu run
	{ ALT,                     		XK_space,  spawn,          {.v = rofiCMD } },
	//utility,       Alt + Space,                      Rofi drun
	{ MODKEY,                       XK_r,      spawn,          {.v = rofiRunCMD } },
	//utility,       MOD + r,                          Rofi run
	{ MODKEY,                       XK_w,      spawn,          {.v = rofiWindowCMD } },
	//utility,       MOD + w,                          Rofi windows
	{ MODKEY,                       XK_Return, spawn,          {.v = termTabbedCMD } },
	//utility,       MOD + Enter,                      Alacritty tabbed
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = termcmd } },
	//utility,       MOD + Control + Enter,            Alacritty terminal
	{ MODKEY|ControlMask|ShiftMask, XK_Return, spawn,          {.v = termAltCMD } },
	//utility,       MOD + Control + Shift + Enter,    Kitty terminal
	{ MODKEY|ALT,              		XK_space,  spawn,          {.v = browserCMD } },
	//app,           MOD + Alt + Space,                Brave browser
	{ MODKEY|ALT,              		XK_Return, spawn,          {.v = canvasCMD } },
	//app,           MOD + Alt + Enter,                Canvas
	{ MODKEY|ALT,                   XK_s,      spawn,          {.v = spotifyCMD } },
	//music,         MOD + Alt + s,                    Spotify
	{ MODKEY,                       XK_p,      spawn,          SHCMD("/usr/local/bin/mpvplaylist") },
	//music,         MOD + p,                          music/video playlists (Rofi,mpv)
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = playerctlInfoCMD } },
	//music,         MOD + Shift + s,                  Playterctl info
    { MODKEY,                       XK_v,      spawn,          SHCMD("rofi -modi 'Clipboard:greenclip print' -show Clipboard -run-command '{cmd}'") },
	//utility,       MOD + v,                          Greenclip clipboard
	{ MODKEY,                       XK_z,      spawn,          {.v = zoomCMD } },
	//app,           MOD + z,                          Zoom Video Conferencing
	{ MODKEY,                       XK_F1,     spawn,          {.v = youtubeCMD } },
	//app,           MOD + F1,                         Youtube
	{ MODKEY,                       XK_F2,     spawn,          {.v = fileExplorerCMD } },
	//app,           MOD + F2,                         Pcmanfm file browser
	{ MODKEY,                       XK_F3,     spawn,          SHCMD("/home/mia/Security/autovpn") },
	//system,        MOD + F3,                         EWU VPN
	{ MODKEY,                       XK_F4,     spawn,          {.v = discordCMD } },
	//app,           MOD + F4,                         Discord
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dualMonitorCMD } },
	//system,        MOD + Shift + d,                  dual vertical monitor toggle
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = pavucontrolCMD } },
	//utility,       MOD + Shift + m,                  Pavucontrol
	{ 0,                            XK_Print,  spawn,          {.v = fullScreenshotCMD } },
	//utility,       Print,                            screenshot full screen
	{ MODKEY,                       XK_Print,  spawn,          {.v = curWindowScreenshotCMD } },
	//utility,       MOD + Print,                      screenshot window
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          SHCMD("flameshot gui") },
	//utility,       MOD + Shift + Print,              screenshot selection (Flameshot)
	{ ALT,                     		XK_Print,  spawn,          SHCMD("killall -9 '/usr/bin/flameshot' && notify-send 'Flameshot' 'Quit Successfuly'") },
	//utility,       Alt + Print,                      quit Flameshot
	{ MODKEY|ControlMask|ALT,  		XK_space,  spawn,          SHCMD("skippy-xd") },
	//system,        MOD + Control + Alt + Space,      dashboard view
    { 0,                            XF86XK_AudioNext, spawn,   SHCMD("playerctl --player=spotify,spotifyd,mpv,%any next") },
	//function,      XF86XK_AudioNext,                 Playerctl next
	{ 0,                            XF86XK_AudioPrev, spawn,   SHCMD("playerctl --player=spotify,spotifyd,mpv,%any previous") },
	//function,      XF86XK_AudioPrev,                 Playerctl previous
	{ 0,                            XF86XK_AudioPlay, spawn,   SHCMD("playerctl --player=spotify,spotifyd,mpv,%any play-pause") },
	//function,      XF86XK_AudioPlay,                 play/pause
    { 0,                            XF86XK_AudioLowerVolume, spawn, SHCMD("volume-down") },
	//function,      XF86XK_AudioLowerVolume,          decrease volume
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, SHCMD("volume-up") },
	//function,      XF86XK_AudioRaiseVolume,          increase volume
	{ 0,                            XF86XK_AudioMute, spawn,   SHCMD("pamixer -t; volume-notify") },
	//function,      XF86XK_AudioMute,                 mute/unmute
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	//appearance,    MOD + b,                          toggle bar
	{ MODKEY|ALT,              		XK_h,      shiftviewtag,   {.i = -1 } },
	//tag,           MOD + Alt + h,                    next tag
	{ MODKEY|ALT,              		XK_l,      shiftviewtag,   {.i = +1 } },
	//tag,           MOD + Alt + l,                    previous tag
	/* { MODKEY,                       XK_j,      focusstack,  {.i = +1 } }, */
	/* //window,        MOD + j,                          focus next visible window */
	/* { MODKEY,                       XK_k,      focusstack,  {.i = -1 } }, */
	/* //window,        MOD + k,                          focus previous visible window */
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	//window,        MOD + j,                          focus next visible window
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	//window,        MOD + k,                          focus previous visible window
	{ MODKEY|ALT,                   XK_j,      focusstackhid,  {.i = +1 } },
	//window,        MOD + Alt + j,                    focus next hidden window
	{ MODKEY|ALT,              		XK_k,      focusstackhid,  {.i = -1 } },
	//window,        MOD + Alt + k,                    focus previous hidden window
	{ MODKEY|ShiftMask,             XK_n,      show,           {0} },
	//window,        MOD + Shift + n,                  show hidden window
	{ MODKEY,                       XK_n,      hide,           {0} },
	//window,        MOD + n,                          hidden window
   	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	//window,        MOD + Shift + j,                  move window up stack
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	//window,        MOD + Shift + k,                  move window down stack
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	//layout,        MOD + i,                          increase master stack
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	//layout,        MOD + d,                          decrease master stack
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	//window,        MOD + h,                          decrease window width
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	//window,        MOD + l,                          increase window width
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	//window,        MOD + Shift + Enter,              move to master stack
	{ MODKEY,                       XK_Tab,    view,           {0} },
	//tag,           MOD + Tab,                        go to previously navigated tag 
	{ MODKEY,                       XK_q,      killclient,     {0} },
	//window,        MOD + q,                          kill window
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//layout,        MOD + t,                          tiling master/stack layout
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//layout,        MOD + f,                          floating layout
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	//layout,        MOD + m,                          monocle layout
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	//layout,        MOD + g,                          grid layout
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	//layout,        MOD + Space,                      toggle between most recently used two layouts
    { MODKEY|ALT,     		        XK_comma,  cyclelayout,    {.i = -1 } },
	//layout,        MOD + Alt + , ,                   cycle layouts previous
	{ MODKEY|ALT,                   XK_period, cyclelayout,    {.i = +1 } },
	//layout,        MOD + Alt + . ,                   cycle layouts next
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	//window,        MOD + Shift + f,                  toggle fullscreen
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	//window,        MOD + Shift + Space,              toggle floating
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//window,        MOD + 0,                          view
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	/* //window,        MOD + Shift + 0,                  show on every tag */
	{ MODKEY|ShiftMask,             XK_0,      toggletag,      {.ui = ~0 } },
	//window,        MOD + Shift + 0,                  toggle show on every tag
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    //screen,        MOD + , ,                         focus previous monitor
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//screen,        MOD + . ,                         focus next monitor
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//window,        MOD + Shift + , ,                 move window to previous monitor
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	//window,        MOD + Shift + . ,                 move window to next monitor
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	//gap,           MOD + -,                          decrease gap
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	//gap,           MOD + =,                          increase gaps
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = 0  } },
	//gap,           MOD + Shift + -,                  remove gaps
	TAGKEYS(                        XK_1,                      0)
	//tag,           MOD + 1,                          tag 1
	TAGKEYS(                        XK_2,                      1)
	//tag,           MOD + 2,                          tag 2
	TAGKEYS(                        XK_3,                      2)
	//tag,           MOD + 3,                          tag 3
	TAGKEYS(                        XK_4,                      3)
	//tag,           MOD + 4,                          tag 4
	TAGKEYS(                        XK_5,                      4)
	//tag,           MOD + 5,                          tag 5
	TAGKEYS(                        XK_6,                      5)
	//tag,           MOD + 6,                          tag 6
	TAGKEYS(                        XK_7,                      6)
	//tag,           MOD + 7,                          tag 7
	TAGKEYS(                        XK_8,                      7)
	//tag,           MOD + 8,                          tag 8

	/*TAGKEYS(                        XK_9,                      8)*/
	{ MODKEY|ShiftMask,             XK_Escape, spawn,          SHCMD("/home/mia/.config/.system/sysmenu") },
	//system,        MOD + Shift + Escape,             power menu
	{ MODKEY|ShiftMask,             XK_r,      quit,     	   {1} },
	//system,        MOD + Shift + r,                  restart dwm
	/* { ControlMask|ShiftMask,        XK_Escape, quit,     	   {0} }, */
	/* //system,        Control + Shift + Escape,         logout/quit dwm */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button3,        killclient,     {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
