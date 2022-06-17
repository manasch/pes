#!/bin/sh

# while loops

ans=y
c=0
while [ "$ans" == "y" ]
	do
	echo "$c" >> newfile.txt
	c=$((c+1))
	read ans
	done
