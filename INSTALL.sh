#!/bin/bash

HERE=`dirname $0`
DEST=$HOME
ME=`whoami`

echo "current user is: $ME"

if [ "$ME" == "root" ]; then
    DEST="/usr"
fi

echo "will install into $DEST"

cp -rf -t $DEST $HERE/bin/ $HERE/share/

echo "install OK"
