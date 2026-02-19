#!/usr/bin/env bash

cd ..

directory="./bin"

if [ ! -d "$directory" ]; then
    mkdir -p "$directory"
fi

rm -rf ./bin/resources
cp ./build/Forradia ./bin/
cp -r ./resources ./bin/
cd ./bin

./Forradia
