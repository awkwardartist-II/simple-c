#!/bin/sh

SRCS="$(find src/ -name '*.c' -o -name '*.cpp')"
OBJS=""

CFLAGS='-w -I./src'

for src in $SRCS; do 
    gcc $src -o "$src.o" -c $CFLAGS
done

OBJS="$(find src/ -name '*.o')"

gcc $OBJS $CFLAGS -o ./smc
rm -f $OBJS