#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument    */
    { MODKEY|Mod1Mask,              XK_s,      spawn,          SHCMD("alacritty --title 'DWM Key Bindings' -e bat --wrap=never --file-name 'DWM Key Bindings' /home/mia/Suckless/dwm/keybindings.txt")},
	//utility,       MODKEY + Alt + s,                 show DWM key bindings
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	//utility,       MODKEY + p,                       Dmenu run
	{ Mod1Mask,                     XK_space,  spawn,          {.v = rofiCMD } },
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
	{ MODKEY|Mod1Mask,              XK_space,  spawn,          {.v = browserCMD } },
	//app,           MOD + Alt + Space,                Brave browser
	{ MODKEY|Mod1Mask,              XK_Return, spawn,          {.v = canvasCMD } },
	//app,           MOD + Alt + Enter,                Canvas
	{ MODKEY,                       XK_s,      spawn,          {.v = spotifyCMD } },
	//app,           MOD + s,                          Spotify
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = playerctlInfoCMD } },
	//music,         MOD + Shift + s,                  Playterctl info
    { MODKEY,                       XK_v,      spawn,          SHCMD("rofi -modi 'Clipboard:greenclip print' -show Clipboard -run-command '{cmd}'") },
	//utility,       MOD + Alt + v,                    Greenclip clipboard
	{ MODKEY,                       XK_z,      spawn,          {.v = zoomCMD } },
	//app,           MOD + z,                          Zoom Video Conferencing
	{ MODKEY,                       XK_F1,     spawn,          {.v = youtubeCMD } },
	//app,           MOD + F1,                         Youtube
	{ MODKEY,                       XK_F2,     spawn,          {.v = fileExplorerCMD } },
	//utility,       MOD + F2,                         Pcmanfm file browser
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
	{ Mod1Mask,                     XK_Print,  spawn,          SHCMD("killall -9 '/usr/bin/flameshot' && notify-send 'Flameshot' 'Quit Successfuly'") },
	//utility,       Alt + Print,                      quit Flameshot
	{ MODKEY|ControlMask|Mod1Mask,  XK_space,  spawn,          SHCMD("skippy-xd") },
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
	{ MODKEY|Mod1Mask,              XK_h,      shiftviewtag,   {.i = -1 } },
	//tag,           MOD + Alt + h,                    next tag
	{ MODKEY|Mod1Mask,              XK_l,      shiftviewtag,   {.i = +1 } },
	//tag,           MOD + Alt + k,                    previous tag
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	//window,        MOD + j,                          focus next visible window
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	//window,        MOD + k,                          focus previous visible window
	{ MODKEY|Mod1Mask,              XK_j,      focusstackhid,  {.i = +1 } },
	//window,        MOD + Alt + j,                    focus next hidden window
	{ MODKEY|Mod1Mask,              XK_k,      focusstackhid,  {.i = -1 } },
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
    { MODKEY|Mod1Mask,     		    XK_comma,  cyclelayout,    {.i = -1 } },
	//layout,        MOD + Alt + , ,                   cycle layouts previous
	{ MODKEY|Mod1Mask,              XK_period, cyclelayout,    {.i = +1 } },
	//layout,        MOD + Alt + . ,                   cycle layouts next
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	//window,        MOD + Shift + f,                  toggle fullscreen
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	//window,        MOD + Shift + Space,              toggle floating
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//utility,       MOD + 0,                          view
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	/* //window,        MOD + Shift + 0,                  show on every tag */
	{ MODKEY|ShiftMask,             XK_0,      toggletag,            {.ui = ~0 } },
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
	{ MODKEY|ShiftMask,             XK_Escape, spawn,         SHCMD("/home/mia/.config/.system/sysmenu") },
	//system,        MOD + Shift + Escape,             system menu
	{ ControlMask|ShiftMask,        XK_Escape,      quit,     {0} },
	//system,        Control + Shift + Escape,         logout/quit dwm
};
