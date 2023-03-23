#!/bin/zsh

rm *.log
rm *.state_machine
rm *.storage
touch node1_CUSTOMLOG.log node2_CUSTOMLOG.log node3_CUSTOMLOG.log
tmux new-session \; split-window -h \; split-window -v -p 66 \; split-window -v \; select-pane -t 0 \; split-window -v -p 66 \; split-window -v \;