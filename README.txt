automator   version: 1.0    author:  Chenggang Tang(OItisTang@gmail.com)

A light wrapper of expect that makes expect more handy.
It reads and translates lines from a file into expect commands.

Usage:
    <file> Execute automator script.
    -h     Print this help message.
    -e     Print command file example.

Example:
    automator -h
    automator -e | tee example.atm
    automator work.atm; or
    chmod +x work.atm; ./work.atm


Installation / Uninstallation:
Run "./INSTALL.sh" to install. If the current user is root, autotest will be
installed into /usr, otherwise in $HOME.
"./UNINSTALL.sh" will remove the installed files from /usr if the current user
is root, else from $HOME.
