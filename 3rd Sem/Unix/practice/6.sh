#!/bin/sh


# cases and while and stuff

echo "1) Name 2) Date 3) PS"
read -p "Enter your choice: " ch
case "$ch" in
1) whoami;;
2) date;;
3) ps -f;;
*) echo "invalid";;
esac
