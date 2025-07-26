#!/usr/bin/env sh

PYTHON=python3

if [ "$#" -ge 1 ]; then
	PYTHON=$1
fi

if [ -d html ]; then
	cd html
	$PYTHON -m http.server
fi

