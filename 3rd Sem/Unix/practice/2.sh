#!/bin/sh

echo "this is another program"

echo -e "what does this do ?"

var=32
echo $var

read name
echo "this is "$name
echo "this is how you take input from the command line"
echo $0 $1

# $0 is the file name itself and $1 is the first command line arguement you pass
