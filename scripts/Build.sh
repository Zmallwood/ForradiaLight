#!/usr/bin/env bash
cd ..
mkdir -p ./build/
cd ./build
export CXX=clang++
cmake -G Ninja ..
cmake --build . --parallel 8
