#!/bin/sh

# program to display the number of users and today's date

# echo "Today's date is `date` and the number of users are `who|wc -l`"

# check if the user has logged in or not

read -p "Enter the name to check: " name
echo "`who | grep -n $name`"
echo $?
