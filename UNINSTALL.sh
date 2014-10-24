#!/bin/bash

DEST=$HOME
ME=`whoami`

echo "current user is: $ME"

if [ "$ME" == "root" ]; then
    DEST="/usr"
fi

echo "will uninstall from $DEST"

rm -f $DEST/bin/automator
rm -rf $DEST/share/automator

echo "uninstall OK"
