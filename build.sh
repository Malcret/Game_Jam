#!/usr/bin/env bash

PROG_NAME="prog"
CC_FlAGS="std=c17 -Wall -O2"

# Directories
SRC_DIR="src"
BUILD_DIR="bin"
OBJ_DIR="$BUILD_DIR/obj"
INC_DIR="-I/usr/include"
LIB_DIR="-L/usr/lib"

# Files
SRC_FILE=$(find $SRC_DIR -type f -name *.c)
LIB_FILE="-lSDL2main"

function build_cc () {
    mkdir -p $OBJ_DIR
    for file in $CC_FILE; do
        gcc $CC_FLAGS -c $file -o $OBJ_DIR/$file.o
    done
}

function build_bin () {
    gcc $INC_DIR $LIB_DIR $LIB_FILE $OBJ_DIR/*.o -o $BUILD_DIR/$PROG_NAME
}

function build () {
    build_cc && \
    build_bin
}

function run () {
    ./$BUILD_DIR/$PROG_NAME
}

function cleanup () {
    rm -Rf $BUILD_DIR/*
}

for arg in $@; do
    if [[ $arg == 'build' ]]; then
        build
    elif [[ $arg == 'run' ]]; then
        run
    elif [[ $arg == 'cleanup' ]]; then
        cleanup
    else
        echo "$arg isn't a valide argument"
    fi
done
