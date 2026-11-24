#!/bin/bash
cd "$(dirname "$0")" || exit 1
clang -c *.c -I../../include/ || exit 1
rm -f libmy.a
ar rc libmy.a *.o
rm -f *.o
