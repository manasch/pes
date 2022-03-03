#!/bin/sh
# changing the file attribute to remove the executable bit

echo $#

ls -la

for file in $*
do
echo $file
chmod -x $file
done

ls -la
