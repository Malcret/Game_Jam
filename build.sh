#!/bin/bash

PROG_NAME="prog"
CC_FlAGS="std=c17 -Wall"

# Directories
SRC_DIR="src"
BUILD_DIR="bin"
OBJ_DIR="$BUILD_DIR/obj"
INC_DIR="-I/usr/include"
LIB_DIR="-L/usr/lib"

# Files
CC_FILE=$(find $SRC_DIR -type f -name *.c)
LIB_FILE="-lSDL2main -lSDL2"
BIN_FILE="$BUILD_DIR/$PROG_NAME"

LD_FLAGS="$INC_DIR ""$LIB_DIR ""$LIB_FILE"

function build_cc () {
    mkdir -p $OBJ_DIR
    for file in $CC_FILE; do
        gcc $CC_FLAGS -c $file -o $file.o && \
        mv $file.o $OBJ_DIR
    done
}

function build_bin () {
    gcc $LD_FLAGS $OBJ_DIR/*.o -o $BIN_FILE
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
