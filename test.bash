#!/bin/bash -xv
# SPDX-FileCopyright:2023 Sato Takaya
## SPDX-License-Identifier: BSD-3-Clause

ng (){
        echo "NG at line $1"
        res=1
}

res=0

### I/O TEST ###
out=$(seq 5 | ./plus)
[ "${out}" = 14 ] || ng ${LINENO}

[ "$res" = 0 ] && echo "OK"
exit $res

