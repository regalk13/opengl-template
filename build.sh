#!/bin/sh

set -xe

CC=cc
LIBS="-lglfw -lGL -lm -lglad"

$CC -o main src/cube.c src/glad.c -Llib $LIBS
