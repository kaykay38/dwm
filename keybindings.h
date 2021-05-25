#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument    */
    { MODKEY|Mod1Mask,              XK_s,      spawn,          SHCMD("kitty --title 'DWM Key Bindings' -e bat --paging=always --wrap=never --file-name 'DWM Key Bindings' /home/mia/Suckless/dwm/keybindings.txt")},
	//MODKEY + Alt + s,                 utility,    show DWM key bindings
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	//MODKEY + p,                       spawn,      Dmenu run
	{ Mod1Mask,                     XK_space,  spawn,          {.v = rofiCMD } },
	//Alt + Space,                      spawn,      Rofi drun
	{ MODKEY,                       XK_r,      spawn,          {.v = rofiRunCMD } },
	//MOD + r,                          spawn,      Rofi run
	{ MODKEY,                       XK_Return, spawn,          {.v = termTabbedCMD } },
	//MOD + Enter,                      spawn,      Alacritty tabbed
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = termcmd } },
	//MOD + Control + Enter,            spawn,      Alacritty terminal
	{ MODKEY|ControlMask|ShiftMask, XK_Return, spawn,          {.v = termAltCMD } },
	//MOD + Control + Shift + Enter,    spawn,      Kitty terminal
	{ MODKEY|Mod1Mask,              XK_space,  spawn,          {.v = browserCMD } },
	//MOD + Alt + Space,                app,        Brave browser
	{ MODKEY|Mod1Mask,              XK_Return, spawn,          {.v = canvasCMD } },
	//MOD + Alt + Enter,                app,        Canvas
	{ MODKEY,                       XK_s,      spawn,          {.v = spotifyCMD } },
	//MOD + s,                          app,        Spotify
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = spotifyInfoCMD } },
	//MOD + Shift + s,                  music,      Spotify song info
    { MODKEY,                       XK_v,      spawn,          SHCMD("rofi -modi 'Clipboard:greenclip print' -show Clipboard -run-command '{cmd}'") },
	//MOD + Alt + v,                    utility,    Greenclip clipboard
	{ MODKEY,                       XK_z,      spawn,          {.v = zoomCMD } },
	//MOD + z,                          app,        Zoom Video Conferencing
	{ MODKEY,                       XK_F1,     spawn,          {.v = youtubeCMD } },
	//MOD + F1,                         app,        Youtube
	{ MODKEY,                       XK_F2,     spawn,          {.v = fileExplorerCMD } },
	//MOD + F2,                         utility,    Pcmanfm file browser
	{ MODKEY,                       XK_F3,     spawn,          SHCMD("/home/mia/Security/autovpn") },
	//MOD + F3,                         system,     EWU VPN
	{ MODKEY,                       XK_F4,     spawn,          {.v = discordCMD } },
	//MOD + F4,                         app,        Discord
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dualMonitorCMD } },
	//MOD + Shift + d,                  system,     dual vertical monitor toggle
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = pavucontrolCMD } },
	//MOD + Shift + m,                  spawn,      Pavucontrol
	{ 0,                            XK_Print,  spawn,          {.v = fullScreenshotCMD } },
	//Print,                            utility,    screenshot full screen
	{ MODKEY,                       XK_Print,  spawn,          {.v = curWindowScreenshotCMD } },
	//MOD + Print,                      utility,    screenshot window
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          SHCMD("flameshot gui") },
	//MOD + Shift + Print,              utility,    screenshot selection (Flameshot)
	{ Mod1Mask,                     XK_Print,  spawn,          SHCMD("killall -9 '/usr/bin/flameshot' && notify-send 'Flameshot' 'Quit Successfuly'") },
	//Alt + Print,                      utility,    quit Flameshot
	{ MODKEY,                       XK_n,      spawn,          SHCMD("skippy-xd") },
	//MOD + n,                          system,     dashboard view
    { 0,                            XF86XK_AudioNext, spawn,   SHCMD("playerctl next") },
	//XF86XK_AudioNext,                 funciton,   Playerctl next
	{ 0,                            XF86XK_AudioPrev, spawn,   SHCMD("playerctl previous") },
	//XF86XK_AudioPrev,                 function,   Playerctl previous
	{ 0,                            XF86XK_AudioPlay, spawn,   SHCMD("play-pause") },
	//XF86XK_AudioPlay,                 function,   play/pause
    { 0,                            XF86XK_AudioLowerVolume, spawn, SHCMD("volume-down") },
	//XF86XK_AudioLowerVolume,          function,   decrease volume
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, SHCMD("volume-up") },
	//XF86XK_AudioRaiseVolume,          function,   increase volume
	{ 0,                            XF86XK_AudioMute, spawn,   SHCMD("pamixer -t; volume-notify") },
	//XF86XK_AudioMute,                 function,   mute/unmute
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	//MOD + b,                          appearance, toggle bar
	{ MODKEY|Mod1Mask,              XK_h,      shiftviewtag,   {.i = -1 } },
	//MOD + Alt + h,                    tag,        next tag
	{ MODKEY|Mod1Mask,              XK_l,      shiftviewtag,   {.i = +1 } },
	//MOD + Alt + k,                    tag,        previous tag
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	//MOD + j,                          window,     focus next window
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	//MOD + k,                          window,     focus previous window
   	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	//MOD + Shift + j,                  window,     move window up stack
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	//MOD + Shift + k,                  window,     move window down stack
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	//MOD + i,                          layout,     increase master stack
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	//MOD + d,                          layout,     decrease master stack
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	//MOD + h,                          window,     decrease window width
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	//MOD + l,                          window,     increase window width
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	//MOD + Shift + Enter,              window,     move to master stack
	{ MODKEY,                       XK_Tab,    view,           {0} },
	//MOD + Tab,                        tag,        go to previously navigated tag 
	{ MODKEY,                       XK_q,      killclient,     {0} },
	//MOD + q,                          window,     kill window
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//MOD + t,                          layout,     tiling master/stack layout
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//MOD + f,                          layout,     floating layout
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	//MOD + m,                          layout,     monocle layout
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	//MOD + g,                          layout,     grid layout
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	//MOD + Space,                      layout,     toggle between most recently used two layouts
    { MODKEY|Mod1Mask,     		    XK_comma,  cyclelayout,    {.i = -1 } },
	//MOD + Alt + , ,                   spawn,      cycle layouts previous
	{ MODKEY|Mod1Mask,              XK_period, cyclelayout,    {.i = +1 } },
	//MOD + Alt + . ,                   spawn,      cycle layouts next
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	//MOD + Shift + f,                  window,     toggle fullscreen
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	//MOD + Shift + Space,              window,     toggle floating
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//MOD + 0,                          spawn,      view
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	/* //MOD + Shift + 0,                  window,     show on every tag */
	{ MODKEY|ShiftMask,             XK_0,      toggletag,            {.ui = ~0 } },
	//MOD + Shift + 0,                  window,     toggle show on every tag
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    //MOD + , ,                         screen,     focus previous monitor
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//MOD + . ,                         screen,     focus next monitor
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//MOD + Shift + , ,                 window,     move window to previous monitor
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	//MOD + Shift + . ,                 window,     move window to next monitor
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	//MOD + -,                          gap,        decrease gap
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	//MOD + =,                          gap,        increase gaps
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = 0  } },
	//MOD + Shift + -,                  gap,        remove gaps
	TAGKEYS(                        XK_1,                      0)
	//MOD + 1,                          tag,        tag 1
	TAGKEYS(                        XK_2,                      1)
	//MOD + 2,                          tag,        tag 2
	TAGKEYS(                        XK_3,                      2)
	//MOD + 3,                          tag,        tag 3
	TAGKEYS(                        XK_4,                      3)
	//MOD + 4,                          tag,        tag 4
	TAGKEYS(                        XK_5,                      4)
	//MOD + 5,                          tag,        tag 5
	TAGKEYS(                        XK_6,                      5)
	//MOD + 6,                          tag,        tag 6
	TAGKEYS(                        XK_7,                      6)
	//MOD + 7,                          tag,        tag 7
	TAGKEYS(                        XK_8,                      7)
	//MOD + 8,                          tag,        tag 8

	/*TAGKEYS(                        XK_9,                      8)*/
	{ MODKEY|ShiftMask,             XK_Escape, spawn,         SHCMD("/home/mia/.config/.system/sysmenu") },
	//MOD + Shift + Escape,             system,     system menu
	{ ControlMask|ShiftMask,        XK_Escape,      quit,     {0} },
	//Control + Shift + Escape,         system,     logout/quit dwm
};
