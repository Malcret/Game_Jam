#!/bin/bash

PROG_NAME="prog"
CXX_FlAGS="std=c++20 -Wall"

# Directories
SRC_DIR="src"
BUILD_DIR="bin"
OBJ_DIR="$BUILD_DIR/obj"
INC_DIR="-I/usr/include -I./include"
LIB_DIR="-L/usr/lib"

# Files
CXX_FILE=$(find $SRC_DIR -type f -name *.cpp)
LIB_FILE="-lGL -lGLEW -lglfw"
BIN_FILE="$BUILD_DIR/$PROG_NAME"

LD_FLAGS="$LIB_DIR $LIB_FILE"

function build_cxx () {
    mkdir -p $OBJ_DIR
    for file in $CXX_FILE; do
        g++ $CXX_FLAGS $INC_DIR -c $file -o $file.o && \
        mv $file.o $OBJ_DIR
    done
}

function build_bin () {
    g++ $LD_FLAGS $OBJ_DIR/*.o -o $BIN_FILE
}

function build () {
    cleanup
    build_cxx && \
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
