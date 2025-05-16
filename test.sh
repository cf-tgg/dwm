#!/usr/bin/env bash

# Xephyr -br -ac -reset -screen 1680x1050 :1 &
# export DISPLAY=:1
# Xephyr -resizeable -br -ac -reset -screen 2256x1504 :1 &
# sleep 1s
# exec dwm :1
# setbg &

export HOST_DISPLAY=${DISPLAY:-:1}
export DISPLAY=$HOST_DISPLAY
xhost +SI:localuser:"$(whoami)"
Xephyr -resizeable -br -ac -reset -screen 2560x1440 :2 &
XEPHYR_PID=$!

while ! xdpyinfo -display :2 >/dev/null 2>&1; do
    sleep 0.1
done
export DISPLAY=:2
export EDITOR=nvim
setbg &
remaps
exec dwm
kill $XEPHYR_PID
