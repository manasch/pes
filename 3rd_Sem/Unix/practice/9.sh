#!/bin/sh

# for loops

#for file in *
#do
#echo $file
#done


for file in *.txt
do
lname=`basename $file txt`
mv $file ${lname}bak
done
