#!/bin/sh

. ./include.sh

REDIRECT=/dev/null
$PYTHON samples.py 2> $REDIRECT > $REDIRECT
rm -f out.samples.grib || true
