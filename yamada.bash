#!/bin/bash

ng () {
        echo ${1}gyoume
        ret=1
}

ret=0
a=yama
[ "$a" = ueama ] || ng "$LINENO"
[ "$a" = yama ] || ng "$LINENO"

exit $ret

