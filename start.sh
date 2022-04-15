#!/bin/sh

BASEDIR=$(dirname "$0")

cd $BASEDIR

echo 'Starting...'

if [ -e ./bin/Lain ]; then
	exec ./bin/Lain
fi
