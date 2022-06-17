#!/bin/sh

# program to check if a = b

echo "enter two numbers"
read a b

if [ $a == $b ]
then 
echo $a" == "$b
else
echo $a" != "$b
fi
